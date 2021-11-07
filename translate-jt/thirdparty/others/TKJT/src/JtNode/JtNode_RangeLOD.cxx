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

#include <JtNode_RangeLOD.hxx>
#include <JtData_Reader.hxx>

IMPLEMENT_STANDARD_HANDLE (JtNode_RangeLOD, JtNode_LOD)
IMPLEMENT_STANDARD_RTTIEXT(JtNode_RangeLOD, JtNode_LOD)

IMPLEMENT_OBJECT_CLASS(JtNode_RangeLOD, "RangeLOD Object",
                       "10dd104c-2ac8-11d1-9b-6b-00-80-c7-bb-59-97")

//=======================================================================
//function : Read
//purpose  : Read this entity from a translate file
//=======================================================================
Standard_Boolean JtNode_RangeLOD::Read (JtData_Reader& theReader)
{
  if (!JtNode_LOD::Read (theReader))
    return Standard_False;

  myVersion = 0;
  if (theReader.Model()->MajorVersion() > 8
  && !theReader.ReadI16 (myVersion))
    return Standard_False;

  return theReader.ReadVec          <Jt_F32> (myVecR)
      && theReader.ReadUniformStruct<Jt_F32> (myCenter);
}

//=======================================================================
//function : Dump
//purpose  :
//=======================================================================
Standard_Integer JtNode_RangeLOD::Dump (Standard_OStream& theStream) const
{
  theStream << "JtNode_LOD { ";
  for (VectorOfObjects::SizeType i = 0; i < myChildren.Count(); i++)
    theStream << myChildren[i] << " ";
  theStream << "} ";
  return JtNode_Base::Dump (theStream);
}
