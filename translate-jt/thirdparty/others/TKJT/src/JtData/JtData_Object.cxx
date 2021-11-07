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

#include <JtData_Object.hxx>
#include <JtData_Reader.hxx>

IMPLEMENT_STANDARD_HANDLE (JtData_Object, MMgt_TShared)
IMPLEMENT_STANDARD_RTTIEXT(JtData_Object, MMgt_TShared)

//=======================================================================
//function : Read
//purpose  : Read this entity from a translate file
//=======================================================================
Standard_Boolean JtData_Object::Read (JtData_Reader&)
{
  return Standard_True;
}

//=======================================================================
//function : Dump
//purpose  :
//=======================================================================
Standard_Integer JtData_Object::Dump (Standard_OStream& /*theStream*/) const
{
  return 0;
}

//=======================================================================
//function : BindObjects
//purpose  : Bind other objects to the object
//=======================================================================
void JtData_Object::BindObjects (const MapOfObjects&)
{
}

//=======================================================================
//function : BindLateLoads
//purpose  : Bind a late loaded property to the object
//=======================================================================
void JtData_Object::BindLateLoads (const ListOfLateLoads&)
{
}

//=======================================================================
//function : BindName
//purpose  : Bind a name to the object
//=======================================================================
void JtData_Object::BindName (const TCollection_ExtendedString&)
{
}
