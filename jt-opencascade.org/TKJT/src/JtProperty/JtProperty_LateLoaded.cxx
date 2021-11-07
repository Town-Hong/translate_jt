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

#include <JtProperty_LateLoaded.hxx>
#include <JtData_Reader.hxx>

IMPLEMENT_STANDARD_HANDLE (JtProperty_LateLoaded, JtProperty_Base)
IMPLEMENT_STANDARD_RTTIEXT(JtProperty_LateLoaded, JtProperty_Base)

IMPLEMENT_OBJECT_CLASS(JtProperty_LateLoaded, "LateLoaded Object",
                       "e0b05be5-fbbd-11d1-a3-a7-00-aa-00-d1-09-54")

//=======================================================================
//function : Read
//purpose  : Read this entity from a translate file
//=======================================================================
Standard_Boolean JtProperty_LateLoaded::Read (JtData_Reader& theReader)
{
  if (!JtProperty_Base::Read (theReader))
    return Standard_False;

  Jt_I16 aVersion;
  if (theReader.Model()->MajorVersion() > 8
  && !theReader.ReadI16 (aVersion))
    return Standard_False;

  Jt_GUID aGUID;
  Jt_I32  aType;
  if (!theReader.ReadGUID (aGUID)
   || !theReader.ReadI32  (aType))
  {
    return Standard_False;
  }

  if (theReader.Model()->MajorVersion() > 8)
  {
    Jt_I32 aPayloadObjectID, aReserved;
    if (!theReader.ReadI32 (aPayloadObjectID)
     || !theReader.ReadI32 (aReserved))
    {
      return Standard_False;
    }
  }

  mySegModel = theReader.Model()->FindSegment (aGUID, mySegOffset);

  return Standard_True;
}

//=======================================================================
//function : Dump
//purpose  :
//=======================================================================
Standard_Integer JtProperty_LateLoaded::Dump (Standard_OStream& theStream) const
{
  return JtProperty_Base::Dump (theStream);
}
