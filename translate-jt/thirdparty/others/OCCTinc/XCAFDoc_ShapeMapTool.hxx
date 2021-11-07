// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _XCAFDoc_ShapeMapTool_HeaderFile
#define _XCAFDoc_ShapeMapTool_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_XCAFDoc_ShapeMapTool.hxx>

#include <TopTools_IndexedMapOfShape.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_Boolean.hxx>
#include <Handle_TDF_Attribute.hxx>
#include <Handle_TDF_RelocationTable.hxx>
class Standard_GUID;
class TDF_Label;
class TopoDS_Shape;
class TDF_Attribute;
class TDF_RelocationTable;
class TopTools_IndexedMapOfShape;


//! attribute containing map of sub shapes
class XCAFDoc_ShapeMapTool : public TDF_Attribute
{

public:

  
  Standard_EXPORT static  const  Standard_GUID& GetID() ;
  
  //! Create (if not exist) ShapeTool from XCAFDoc on <L>.
  Standard_EXPORT static   Handle(XCAFDoc_ShapeMapTool) Set (const TDF_Label& L) ;
  
  //! Creates an empty tool
  Standard_EXPORT XCAFDoc_ShapeMapTool();
  
  //! Checks whether shape <sub> is subshape of shape stored on
  //! label shapeL
  Standard_EXPORT   Standard_Boolean IsSubShape (const TopoDS_Shape& sub)  const;
  
  //! Sets representation (TopoDS_Shape) for top-level shape
  Standard_EXPORT   void SetShape (const TopoDS_Shape& S) ;
  
  Standard_EXPORT  const  Standard_GUID& ID()  const;
  
  Standard_EXPORT   void Restore (const Handle(TDF_Attribute)& with) ;
  
  Standard_EXPORT   Handle(TDF_Attribute) NewEmpty()  const;
  
  Standard_EXPORT   void Paste (const Handle(TDF_Attribute)& into, const Handle(TDF_RelocationTable)& RT)  const;
  
  Standard_EXPORT  const  TopTools_IndexedMapOfShape& GetMap()  const;




  DEFINE_STANDARD_RTTI(XCAFDoc_ShapeMapTool)

protected:




private: 


  TopTools_IndexedMapOfShape myMap;


};







#endif // _XCAFDoc_ShapeMapTool_HeaderFile