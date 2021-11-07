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

#ifndef _JtProperty_LateLoaded_HeaderFile
#define _JtProperty_LateLoaded_HeaderFile

#include <JtProperty_Base.hxx>
#include <JtData_Model.hxx>

class JtProperty_LateLoaded : public JtProperty_Base
{
public:
  //! Read this entity from a JT file.
  Standard_EXPORT virtual Standard_Boolean Read (JtData_Reader& theReader);

  //! Dump this entity.
  Standard_EXPORT virtual Standard_Integer Dump (Standard_OStream& theStream) const;

  //! Load object from the referenced JT file segment.
  void Load() { myDefferedObject = mySegModel->ReadSegment (mySegOffset); }

  Handle(JtData_Object) DefferedObject() { return myDefferedObject; }

  void Unload() { myDefferedObject.Nullify(); }

  DEFINE_STANDARD_RTTI(JtProperty_LateLoaded)
  DEFINE_OBJECT_CLASS (JtProperty_LateLoaded)

protected:
  Handle(JtData_Model) mySegModel;
  Jt_I32               mySegOffset;

  Handle(JtData_Object) myDefferedObject;
};

DEFINE_STANDARD_HANDLE(JtProperty_LateLoaded, JtProperty_Base)

#endif // _JtProperty_LateLoaded_HeaderFile
