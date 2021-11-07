// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepFill_DataMapIteratorOfDataMapOfShapeHArray2OfShape_HeaderFile
#define _BRepFill_DataMapIteratorOfDataMapOfShapeHArray2OfShape_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <TCollection_BasicMapIterator.hxx>
#include <Handle_TopTools_HArray2OfShape.hxx>
#include <Handle_BRepFill_DataMapNodeOfDataMapOfShapeHArray2OfShape.hxx>
class Standard_NoSuchObject;
class TopoDS_Shape;
class TopTools_HArray2OfShape;
class TopTools_ShapeMapHasher;
class BRepFill_DataMapOfShapeHArray2OfShape;
class BRepFill_DataMapNodeOfDataMapOfShapeHArray2OfShape;



class BRepFill_DataMapIteratorOfDataMapOfShapeHArray2OfShape  : public TCollection_BasicMapIterator
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT BRepFill_DataMapIteratorOfDataMapOfShapeHArray2OfShape();
  
  Standard_EXPORT BRepFill_DataMapIteratorOfDataMapOfShapeHArray2OfShape(const BRepFill_DataMapOfShapeHArray2OfShape& aMap);
  
  Standard_EXPORT   void Initialize (const BRepFill_DataMapOfShapeHArray2OfShape& aMap) ;
  
  Standard_EXPORT  const  TopoDS_Shape& Key()  const;
  
  Standard_EXPORT  const  Handle(TopTools_HArray2OfShape)& Value()  const;




protected:





private:





};







#endif // _BRepFill_DataMapIteratorOfDataMapOfShapeHArray2OfShape_HeaderFile