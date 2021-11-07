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

#ifndef _JtAttribute_Material_HeaderFile
#define _JtAttribute_Material_HeaderFile

#include <JtAttribute_Base.hxx>

//! Class representing Jt material attribute.
class JtAttribute_Material : public JtAttribute_Base
{
public:
  //! Default constructor.
  Standard_EXPORT JtAttribute_Material();

  //! Read this entity from a JT file.
  Standard_EXPORT virtual Standard_Boolean Read (JtData_Reader& theReader);

  //! Dump this entity.
  Standard_EXPORT virtual Standard_Integer Dump (Standard_OStream& theStream) const;

  //! Return ambient color.
  const Jt_F32* AmbientColor()  const { return myAmbientColor;  }

  //! Return diffuse color.
  const Jt_F32* DiffuseColor()  const { return myDiffuseColor;  }

  //! Return specular color.
  const Jt_F32* SpecularColor() const { return mySpecularColor; }

  //! Return emission color.
  const Jt_F32* EmissionColor() const { return myEmissionColor; }

  //! Return shininess.
  Jt_F32        Shininess()     const { return myShininess;     }

  //! Return reflectivity.
  Jt_F32        Reflectivity()  const { return myReflectivity;  }

  DEFINE_STANDARD_RTTI(JtAttribute_Material)
  DEFINE_OBJECT_CLASS (JtAttribute_Material)

protected:
  Jt_I16 myVersion;
  Jt_U16 myDataFlags;
  Jt_F32 myAmbientColor[4];
  Jt_F32 myDiffuseColor[4];
  Jt_F32 mySpecularColor[4];
  Jt_F32 myEmissionColor[4];
  Jt_F32 myShininess;
  Jt_F32 myReflectivity;
};

DEFINE_STANDARD_HANDLE(JtAttribute_Material,JtAttribute_Base)

#endif // _JtAttribute_Material_HeaderFile
