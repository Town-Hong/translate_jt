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

#include <JtNode_Instance.hxx>
#include <JtData_Reader.hxx>
#include <JtData_DeferredObject.hxx>

IMPLEMENT_STANDARD_HANDLE (JtNode_Instance, JtNode_Base)
IMPLEMENT_STANDARD_RTTIEXT(JtNode_Instance, JtNode_Base)

IMPLEMENT_OBJECT_CLASS(JtNode_Instance, "Instance Object",
                       "10dd102a-2ac8-11d1-9b-6b-00-80-c7-bb-59-97")

//=======================================================================
//function : Read
//purpose  : Read this entity from a translate file
//=======================================================================
Standard_Boolean JtNode_Instance::Read (JtData_Reader& theReader)
{
  if (!JtNode_Base::Read (theReader))
    return Standard_False;

  Jt_I16 aVersion;
  if (theReader.Model()->MajorVersion() > 8
  && !theReader.ReadI16 (aVersion))
    return Standard_False;

  return JtData_DeferredObject::Read (theReader, myObject);
}

//=======================================================================
//function : Dump
//purpose  :
//=======================================================================
Standard_Integer JtNode_Instance::Dump (Standard_OStream& theStream) const
{
  theStream << "JtNode_Instance ";
  return JtNode_Base::Dump (theStream);
}

//=======================================================================
//function : BindObjects
//purpose  : Bind other objects to the object
//=======================================================================
void JtNode_Instance::BindObjects (const MapOfObjects& theObjectsMap)
{
  JtNode_Base::BindObjects (theObjectsMap);
  JtData_DeferredObject::Resolve (myObject, theObjectsMap);
}
