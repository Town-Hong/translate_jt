// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _XCAFDoc_MaterialTool_HeaderFile
#define _XCAFDoc_MaterialTool_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_XCAFDoc_MaterialTool.hxx>

#include <Handle_XCAFDoc_ShapeTool.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_Boolean.hxx>
#include <Handle_TCollection_HAsciiString.hxx>
#include <Standard_Real.hxx>
#include <Handle_TDF_Attribute.hxx>
#include <Handle_TDF_RelocationTable.hxx>
class XCAFDoc_ShapeTool;
class TDF_Label;
class Standard_GUID;
class TDF_LabelSequence;
class TCollection_HAsciiString;
class TDF_Attribute;
class TDF_RelocationTable;


//! Provides tools to store and retrieve attributes (materials)
//! of TopoDS_Shape in and from TDocStd_Document
//! A Document is intended to hold different
//! attributes of ONE shape and it's sub-shapes
//! Provide tools for management of Materialss section of document.
class XCAFDoc_MaterialTool : public TDF_Attribute
{

public:

  
  Standard_EXPORT XCAFDoc_MaterialTool();
  
  //! Creates (if not exist) MaterialTool.
  Standard_EXPORT static   Handle(XCAFDoc_MaterialTool) Set (const TDF_Label& L) ;
  
  Standard_EXPORT static  const  Standard_GUID& GetID() ;
  
  //! returns the label under which colors are stored
  Standard_EXPORT   TDF_Label BaseLabel()  const;
  
  //! Returns internal XCAFDoc_ShapeTool tool
  Standard_EXPORT  const  Handle(XCAFDoc_ShapeTool)& ShapeTool() ;
  
  //! Returns True if label belongs to a material table and
  //! is a Material definition
  Standard_EXPORT   Standard_Boolean IsMaterial (const TDF_Label& lab)  const;
  
  //! Returns a sequence of materials currently stored
  //! in the material table
  Standard_EXPORT   void GetMaterialLabels (TDF_LabelSequence& Labels)  const;
  
  //! Adds a Material definition to a table and returns its label
  Standard_EXPORT   TDF_Label AddMaterial (const Handle(TCollection_HAsciiString)& aName, const Handle(TCollection_HAsciiString)& aDescription, const Standard_Real aDensity, const Handle(TCollection_HAsciiString)& aDensName, const Handle(TCollection_HAsciiString)& aDensValType)  const;
  
  //! Sets a link with GUID
  Standard_EXPORT   void SetMaterial (const TDF_Label& L, const TDF_Label& MatL)  const;
  
  //! Sets a link with GUID
  //! Adds a Material as necessary
  Standard_EXPORT   void SetMaterial (const TDF_Label& L, const Handle(TCollection_HAsciiString)& aName, const Handle(TCollection_HAsciiString)& aDescription, const Standard_Real aDensity, const Handle(TCollection_HAsciiString)& aDensName, const Handle(TCollection_HAsciiString)& aDensValType)  const;
  
  //! Returns Material assigned to <MatL>
  //! Returns False if no such Material is assigned
  Standard_EXPORT   Standard_Boolean GetMaterial (const TDF_Label& MatL, Handle(TCollection_HAsciiString)& aName, Handle(TCollection_HAsciiString)& aDescription, Standard_Real& aDensity, Handle(TCollection_HAsciiString)& aDensName, Handle(TCollection_HAsciiString)& aDensValType)  const;
  
  //! Find referred material and return density from it
  //! if no material --> return 0
  Standard_EXPORT static   Standard_Real GetDensityForShape (const TDF_Label& ShapeL) ;
  
  Standard_EXPORT  const  Standard_GUID& ID()  const;
  
  Standard_EXPORT   void Restore (const Handle(TDF_Attribute)& with) ;
  
  Standard_EXPORT   Handle(TDF_Attribute) NewEmpty()  const;
  
  Standard_EXPORT   void Paste (const Handle(TDF_Attribute)& into, const Handle(TDF_RelocationTable)& RT)  const;




  DEFINE_STANDARD_RTTI(XCAFDoc_MaterialTool)

protected:




private: 


  Handle(XCAFDoc_ShapeTool) myShapeTool;


};







#endif // _XCAFDoc_MaterialTool_HeaderFile