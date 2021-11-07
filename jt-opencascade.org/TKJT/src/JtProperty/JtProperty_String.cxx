// JT format reading and visualization tools
// Copyright (C) 2014-2015 OPEN CASCADE SAS
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

#include <JtProperty_String.hxx>
#include <JtData_Reader.hxx>

IMPLEMENT_STANDARD_HANDLE (JtProperty_String, JtProperty_Base)
IMPLEMENT_STANDARD_RTTIEXT(JtProperty_String, JtProperty_Base)

IMPLEMENT_OBJECT_CLASS(JtProperty_String, "String Object",
                       "10dd106e-2ac8-11d1-9b-6b-00-80-c7-bb-59-97")

//=======================================================================
//function : Read
//purpose  : Read this entity from a translate file
//=======================================================================
Standard_Boolean JtProperty_String::Read (JtData_Reader& theReader)
{
  if (!JtProperty_Base::Read (theReader))
    return Standard_False;

  Jt_I16 aVersion;
  if (theReader.Model()->MajorVersion() > 8
  && !theReader.ReadI16 (aVersion))
    return Standard_False;

  return theReader.ReadMbString (myValue);
}

//=======================================================================
//function : Dump
//purpose  :
//=======================================================================
Standard_Integer JtProperty_String::Dump (Standard_OStream& theStream) const
{
//  theStream << "JtProperty_String { " << myValue << " } ";
  return JtProperty_Base::Dump (theStream);
}
