// JT format reading and visualization tools
// Copyright (C) 2013-2015 OPEN CASCADE SAS
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2 of the License, or any later
// version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// Copy of the GNU General Public License is in LICENSE.txt and  
// on <http://www.gnu.org/licenses/>.

#include <JtData_Model.hxx>
#include <JtData_FileReader.hxx>
#include <JtData_Inflate.hxx>

#include <JtData_Message.hxx>

#include <JtNode_Partition.hxx>
#include <JtProperty_LateLoaded.hxx>
#include <JtProperty_String.hxx>

#include <Image_PixMap.hxx>

#include <NCollection_DataMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_SequenceOfInteger.hxx>

const Standard_Boolean JtData_Model::IsLittleEndianHost =
  Image_PixMap::IsBigEndianHost() ? Standard_False : Standard_True;

static const Jt_GUID EOEMarkerGUID ("ffffffff-ffff-ffff-ff-ff-ff-ff-ff-ff-ff-ff");

IMPLEMENT_STANDARD_HANDLE (JtData_Model, MMgt_TShared)
IMPLEMENT_STANDARD_RTTIEXT(JtData_Model, MMgt_TShared)

//=======================================================================
//function : JtData_Model
//purpose  : Constructor
//=======================================================================
JtData_Model::JtData_Model (const TCollection_ExtendedString& theFileName,
                            const Handle(JtData_Model)&       theParent)
: myParent   (theParent)
, myFileName (theFileName)
, myIsFileLE (Standard_False)
, myMajorVersion (0)
, myMinorVersion (0) {}

//=======================================================================
//function : Init
//purpose  : Read JT file header, TOC and LSG and return a handle to the root LSG node
//=======================================================================
Handle(JtNode_Partition) JtData_Model::Init()
{
  // Open the file
  std::ifstream aFile;
  if (!open (aFile))
  {
    ALARM ("Error: Failed to open Jt file");
    return Handle(JtNode_Partition)();
  }

  // Read File Header

  // Read version
  char vstr[81] = {};
  aFile.read (vstr, 80);

  TCollection_AsciiString aMajorVersionStr (vstr);
  Standard_Integer aPos = aMajorVersionStr.Search ("Version");
  if (aPos < 1)
  {
    ALARM ("Error: Failed to read Jt file version");
    return Handle(JtNode_Partition)();
  }

  aMajorVersionStr = aMajorVersionStr.Token (" \t", 2);
  aPos = aMajorVersionStr.Search (".");
  if (aPos <= 1)
  {
    ALARM ("Error: Failed to read Jt file version");
    return Handle(JtNode_Partition)();
  }

  TCollection_AsciiString aMinorVersionStr = aMajorVersionStr.Split (aPos - 1);
  aMinorVersionStr.Remove (1);
  if (!aMajorVersionStr.IsIntegerValue()
   || !aMinorVersionStr.IsIntegerValue())
  {
    ALARM ("Error: Failed to read Jt file version");
    return Handle(JtNode_Partition)();
  }

  myMajorVersion = aMajorVersionStr.IntegerValue();
  myMinorVersion = aMinorVersionStr.IntegerValue();
  TRACE ("\n\nInfo: File version = " + myMajorVersion + "." + myMinorVersion);

  // Read byte order
  char aByteOrder;
  aFile.read (&aByteOrder, 1);
  myIsFileLE = (aByteOrder == 0);
  TRACE ("Info: Byte order = " + (myIsFileLE ? "LE" : "BE"));

  // Read reserved field, TOC offset, LSG Segment ID
  Jt_I32 aReservedField, aTOCOffset;
  Jt_GUID anLSGSegmentGUID;
  {
    JtData_FileReader aReader (aFile, this);
    if (!aReader.ReadI32 (aReservedField)
     || !aReader.ReadI32 (aTOCOffset)
     || !aReader.ReadGUID (anLSGSegmentGUID))
    {
      ALARM ("Error: Failed to read TOC offset and LSG segment ID");
      return Handle(JtNode_Partition)();
    }
  }

  // Read TOC
  if (!readTOC (aFile, aTOCOffset))
  {
    ALARM ("Error: Failed to read TOC");
    return Handle(JtNode_Partition)();
  }

  // Find and read LSG segment
  Jt_I32 anLSGSegmentOffset;
  if (!myTOC.Find (anLSGSegmentGUID, anLSGSegmentOffset))
  {
    ALARM ("Error: No LSG segment");
    return Handle(JtNode_Partition)();
  }
  else
  {
    TRACE ("Info: LSG segment is found at offset " + anLSGSegmentOffset);
  }

  Handle(JtData_Object) aRootNode = readSegment (aFile, anLSGSegmentOffset, Standard_True);

  aFile.close();

  return Handle(JtNode_Partition)::DownCast (aRootNode);
}

//=======================================================================
//function : open
//purpose  : Open the file
//=======================================================================
Standard_Boolean JtData_Model::open (ifstream& aFile) const
{
#ifdef WNT
  aFile.open (reinterpret_cast<const wchar_t*> (myFileName.ToExtString()),
              ios::binary | ios::in);
#else
  TCollection_AsciiString anAsciiName (myFileName, ' ');
  aFile.open (anAsciiName.ToCString(), ios::binary | ios::in);
#endif

  return aFile.is_open();
}

//=======================================================================
//function : readTOC
//purpose  : Read TOC from the JT file
//=======================================================================
Standard_Boolean JtData_Model::readTOC (std::ifstream& theFile, const Jt_I32 theOffset)
{
  JtData_FileReader aReader (theFile, this, theOffset);

  // Read entry count
  Jt_I32 aCount;
  if (!aReader.ReadI32 (aCount) || aCount < 1)
    return Standard_False;
  TRACE ("Info: TOC entries count = " + aCount);

  // Read TOC entries
  typedef NCollection_DataMap<Standard_Integer, Standard_Integer> TypeMap;
  TypeMap aTypeMap;
  while (aCount--)
  {
    // Read Segment ID, offset, length, attributes
    Jt_GUID aGUID;
    Jt_I32 aOffset, aLength;
    Jt_U32 aAttrib;
    if (!aReader.ReadGUID (aGUID)
     || !aReader.ReadI32  (aOffset)
     || !aReader.ReadI32  (aLength)
     || !aReader.ReadU32  (aAttrib))
    {
      return Standard_False;
    }

    const Standard_Integer aType = (aAttrib >> 24) & 0xFF;
    if (aTypeMap.IsBound (aType))
      aTypeMap.ChangeFind (aType)++;
    else
      aTypeMap.Bind (aType, 1);

    myTOC.Bind (aGUID, aOffset);
  }

  TRACE ("Info: Type statistics");
  for (TypeMap::Iterator aMapIter (aTypeMap); aMapIter.More(); aMapIter.Next())
  {
    TRACE ("Type " + aMapIter.Key() + " count " + aMapIter.Value());
  }

  return Standard_True;
}

//=======================================================================
//function : readSegment
//purpose  : Read objects from a JT file segment
//=======================================================================
Handle(JtData_Object) JtData_Model::readSegment (std::ifstream&         theFile,
                                                 const Jt_I32           theOffset,
                                                 const Standard_Boolean theIsLSG) const
{
  JtData_FileReader aReader (theFile, this, theOffset);

  Standard_Size aSegStart = aReader.GetPosition();

  // Read the segment header
  Jt_GUID aGUID;
  Jt_I32  aType;
  Jt_I32  aSize;
  if (!aReader.ReadGUID (aGUID)
   || !aReader.ReadI32  (aType)
   || !aReader.ReadI32  (aSize))
  {
    ALARM ("Error: Failed to read header of segment with offset " + theOffset);
    return Handle(JtData_Object)();
  }

  // Select appropriate reader for reading the segment data:
  // - use the file reader if the segment is not compressed;
  // - use JtData_Inflate is the segment is compressed.
  JtData_Reader* aDataReaderPtr = &aReader;
  switch (aType)
  {
  case 1:
  case 2:
  case 3:
  case 4:
  case 17:
  case 18:
  case 20:
  case 24:
    {
      // read Compression Flag, Data Length, Algorithm
      Jt_I32 aFlag;
      Jt_I32 aDataLength;
      Jt_U8  aAlgorithm;
      if (!aReader.ReadI32 (aFlag)
       || !aReader.ReadI32 (aDataLength)
       || !aReader.ReadU8  (aAlgorithm))
      {
        ALARM ("Error: Failed to read compression flags of segment with offset " + theOffset);
        return Handle(JtData_Object)();
      }

      // if compressed, replace the reader by a JtData_Inflate instance
      if (aFlag == 2 && aAlgorithm == 2)
        aDataReaderPtr = new JtData_Inflate (aReader, aDataLength - sizeof (Jt_U8));
    }
  }

  // Read the segment data
  Handle(JtData_Object) aFirstObject;
  Standard_Boolean      aResult;

  if (theIsLSG)
    aResult = readLSGData (*aDataReaderPtr, aFirstObject);
  else
    aResult = readElement (*aDataReaderPtr, aFirstObject);

  // Free the JtData_Inflate reader if it was used
  if (aDataReaderPtr != &aReader)
    delete aDataReaderPtr;

  // Check the reading result
  if (!aResult)
  {
    ALARM ("Error: Segment data reading failed");
    return Handle(JtData_Object)();
  }

  // Check the loaded data length
  Standard_Size aBytesSpec = aSegStart + aSize;
  Standard_Size aReaderPos = aReader.GetPosition();
  if (aBytesSpec < aReaderPos)
  {
 #ifdef OCCT_DEBUG
    Standard_Size aBytesRest = aBytesSpec - aReaderPos;
    ALARM ("Error: " + (aBytesRest) + " extra bytes were read after end of the segment");
#endif
    return Handle(JtData_Object)();
  }
  if (aBytesSpec > aReaderPos)
  {
#ifdef OCCT_DEBUG
    Standard_Size aBytesRest = aBytesSpec - aReaderPos;
    WARNING ("Warning: " + aBytesRest + " segment bytes remained after reading, ignored");
#endif
  }

  // Return the first object read from the segment
  return aFirstObject;
}

//=======================================================================
//function : readLSGData
//purpose  : Read LSG segment data
//=======================================================================
Standard_Boolean JtData_Model::readLSGData (JtData_Reader&         theReader,
                                            Handle(JtData_Object)& theFirstObject) const
{
  const TCollection_ExtendedString anObjectNameKey = "JT_PROP_NAME";

  // Read graph elements
  JtData_Object::MapOfObjects aMapObjects;
  if (!readElements (theReader, aMapObjects, theFirstObject))
  {
    ALARM ("Error: Failed to read LSG elements");
    return Standard_False;
  }

  // Bind the objects together
  for (JtData_Object::MapOfObjects::Iterator it (aMapObjects); it.More(); it.Next())
    it.ChangeValue()->BindObjects (aMapObjects);

  // Read property atom elements
  JtData_Object::MapOfObjects aMapProperties;
  if (!readElements (theReader, aMapProperties, theFirstObject))
  {
    ALARM ("Error: Failed to read property atom elements");
    return Standard_False;
  }

  // Read Property Table
  Jt_I16 aTableVersion;
  Jt_I32 aTableLength;
  if (!theReader.ReadI16 (aTableVersion)
   || !theReader.ReadI32 (aTableLength))
  {
    ALARM ("Error: Failed to read property table");
    return Standard_False;
  }

  while (aTableLength-- > 0)
  {
    // get an object
    Jt_I32 anObjectId;
    if (!theReader.ReadI32 (anObjectId))
    {
      ALARM ("Error: Failed to read LSG object ID");
      return Standard_False;
    }

    Handle(JtData_Object) anObject;
    aMapObjects.Find (anObjectId, anObject);

    // read (key,value) pairs
    JtData_Object::ListOfLateLoads aLateLoads;
    Jt_I32 aKey, aValue;
    for (;;)
    {
      // read key
      if (!theReader.ReadI32 (aKey))
      {
        ALARM ("Error: Failed to read property key");
        return Standard_False;
      }

      if (aKey == 0)
        break;

      // read value
      if (!theReader.ReadI32 (aValue))
      {
        ALARM ("Error: Failed to read property value");
        return Standard_False;
      }

      // analyse the value
      Handle(JtData_Object) aProperty;
      if (aMapProperties.Find (aValue, aProperty))
      {
        // if this is late loaded property, add it to a list
        Handle(JtProperty_LateLoaded) aLateProp =
          Handle(JtProperty_LateLoaded)::DownCast (aProperty);
        if (!aLateProp.IsNull())
          aLateLoads.Append (aLateProp);
        // if this is a string property with key = "JT_PROP_NAME", bind it to the object
        else
        {
          Handle(JtProperty_String) aStringProp =
            Handle(JtProperty_String)::DownCast (aProperty);
          if (!aStringProp.IsNull())
          {
            Handle(JtData_Object) aKeyProperty;
            if (aMapProperties.Find (aKey, aKeyProperty))
            {
              Handle(JtProperty_String) aKeyStringProp =
                Handle(JtProperty_String)::DownCast (aKeyProperty);
              if (!aKeyStringProp.IsNull() && aKeyStringProp->Value() == anObjectNameKey)
                anObject->BindName (aStringProp->Value());
            }
          }
        }
      }
    }

    // bind the late loaded properties to the object
    if (!anObject.IsNull() && !aLateLoads.IsEmpty())
      anObject->BindLateLoads (aLateLoads);
  }

  return Standard_True;
}

//=======================================================================
//function : readElements
//purpose  : Read a sequence of elements from a JT file segment
//=======================================================================
Standard_Boolean JtData_Model::readElements (JtData_Reader&               theReader,
                                             JtData_Object::MapOfObjects& theMap,
                                             Handle(JtData_Object)&       theFirstObject) const
{
  Handle(JtData_Object) anObject;
  Jt_I32                anObjectID;

  // Read elements while possible until End-Of-Elements marker is reached
  while (readElement (theReader, anObject, &anObjectID))
  {
    // if End-Of-Elements marker is reached, finish the reading
    if (anObject.IsNull())
      return Standard_True;

    // if an object of a known type is read, store it
    if (!anObject->IsInstance (STANDARD_TYPE (JtData_Object)))
    {
      theMap.Bind (anObjectID, anObject);
      if (theFirstObject.IsNull())
        theFirstObject = anObject;
    }
  }

  // Fail if the reading was failed
  return Standard_False;
}

//=======================================================================
//function : readElement
//purpose  : Read an element from a JT file segment
//=======================================================================
Standard_Boolean JtData_Model::readElement (JtData_Reader&         theReader,
                                            Handle(JtData_Object)& theObject,
                                            Jt_I32*                theObjectIDPtr) const
{
  // Read Element Length
  Standard_Integer anElemLength;
  if (!theReader.ReadI32 (anElemLength))
  {
    ALARM ("Error: Failed to read element length");
    return Standard_False;
  }

  // Start reading the element data
  Standard_Size anElemStart = theReader.GetPosition();

  // Read Object Type ID
  Jt_GUID anObjectTypeID;
  if (!theReader.ReadGUID (anObjectTypeID))
  {
    ALARM ("Error: Failed to read element GUID");
    return Standard_False;
  }
  else
  {
    Standard_Character aGuidString[128];
    anObjectTypeID.ToString (aGuidString);
    TRACE ("Info: Reading element with GUID " + aGuidString);
  }

  // Classify and create the object
  const JtData_Object::ClassInfo* aClassInfo = JtData_Object::FindClass (anObjectTypeID);
  if (aClassInfo != NULL)
  {
    // known object
    TRACE (aClassInfo->Name());
    theObject = aClassInfo->Create();
  }
  else if (anObjectTypeID == EOEMarkerGUID)
  {
    // End-Of-Elements marker
    theObject = Handle(JtData_Object)();
    return Standard_True;
  }
  else
  {
    // unknown object
    theObject = new JtData_Object();
    return theReader.Skip (anElemStart + anElemLength - theReader.GetPosition());
  }

  // Read the object data
  Standard_Integer anObjectBaseType;
  if (!theReader.ReadU8 (anObjectBaseType))
    return Standard_False;

  if (theObjectIDPtr)
  {
    // for LSG segment, always read Object ID for elements
    if (!theReader.ReadI32 (*theObjectIDPtr))
      return Standard_False;
  }
  else if (MajorVersion() > 8)
  {
    // for other segments, read Object ID only if JT version is 9.x or higher
    Jt_I32 anObjectID;
    if (!theReader.ReadI32 (anObjectID))
      return Standard_False;
  }

  if (!theObject->Read (theReader))
    return Standard_False;

  // Check the loaded data length
  Standard_Size aBytesSpec = anElemStart + anElemLength;
  Standard_Size aReaderPos = theReader.GetPosition();
  if (aBytesSpec < aReaderPos)
  {
#ifdef OCCT_DEBUG
    Standard_Size aBytesRest = aReaderPos - aBytesSpec;
    ALARM ("Error: " + (aBytesRest) + " extra bytes were read after end of the element");
#endif
    return Standard_False;
  }
  if (aBytesSpec > aReaderPos)
  {
    Standard_Size aBytesRest = aBytesSpec - aReaderPos;
    WARNING ("Warning: " + aBytesRest + " element bytes remained after reading, corrected");
    if (!theReader.Skip (aBytesRest))
      return Standard_False;
  }

  return Standard_True;
}

//=======================================================================
//function : FindSegment
//purpose  : Lookup offset of a segment in TOCs of this model and its ancestor models
//=======================================================================
Handle(JtData_Model) JtData_Model::FindSegment (const Jt_GUID& theGUID,
                                                      Jt_I32&  theOffset) const
{
  if (myTOC.Find (theGUID, theOffset))
    return this;
  else if (!myParent.IsNull())
    return myParent->FindSegment (theGUID, theOffset);
  else
  {
    Standard_Character aGuidString[128];
    theGUID.ToString (aGuidString);
    ALARM ("Error: Failed to find segment with GUID: " + aGuidString);
    return Handle(JtData_Model)();
  }
}

//=======================================================================
//function : ReadSegment
//purpose  : Read object from a late loaded segment
//=======================================================================
Handle(JtData_Object) JtData_Model::ReadSegment (const Jt_I32 theOffset) const
{
  ifstream aFile;
  if (!open (aFile))
  {
    ALARM ("Error: Failed to open Jt file of late-loaded segment");
    return Handle(JtNode_Partition)();
  }

  return readSegment (aFile, theOffset, Standard_False);
}

//=======================================================================
//function : Dump
//purpose  :
//=======================================================================
Standard_Integer JtData_Model::Dump (Standard_OStream& /*theStream*/) const
{
  return 0;
}
