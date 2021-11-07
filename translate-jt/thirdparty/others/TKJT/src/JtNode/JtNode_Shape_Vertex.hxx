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

#ifndef _JtNode_Shape_Vertex_HeaderFile
#define _JtNode_Shape_Vertex_HeaderFile

#include <JtNode_Shape_Base.hxx>

//! Vertex Shape Node Element defines shapes defined by collections of vertices.
class JtNode_Shape_Vertex : public JtNode_Shape_Base
{
public:
  //! Read this entity from a JT file.
  Standard_EXPORT virtual Standard_Boolean Read (JtData_Reader &theReader);

  //! Dump this entity.
  Standard_EXPORT virtual Standard_Integer Dump (Standard_OStream& S) const;

  DEFINE_STANDARD_RTTI(JtNode_Shape_Vertex)
  DEFINE_OBJECT_CLASS (JtNode_Shape_Vertex)
};

DEFINE_STANDARD_HANDLE(JtNode_Shape_Vertex, JtNode_Shape_Base)

#endif // _JtNode_Shape_Vertex_HeaderFile
