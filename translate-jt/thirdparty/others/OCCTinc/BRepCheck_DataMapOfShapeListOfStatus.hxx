// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepCheck_DataMapOfShapeListOfStatus_HeaderFile
#define _BRepCheck_DataMapOfShapeListOfStatus_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <TCollection_BasicMap.hxx>
#include <Handle_BRepCheck_DataMapNodeOfDataMapOfShapeListOfStatus.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Address.hxx>
class Standard_DomainError;
class Standard_NoSuchObject;
class TopoDS_Shape;
class BRepCheck_ListOfStatus;
class TopTools_ShapeMapHasher;
class BRepCheck_DataMapNodeOfDataMapOfShapeListOfStatus;
class BRepCheck_DataMapIteratorOfDataMapOfShapeListOfStatus;



class BRepCheck_DataMapOfShapeListOfStatus  : public TCollection_BasicMap
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT BRepCheck_DataMapOfShapeListOfStatus(const Standard_Integer NbBuckets = 1);
  
  Standard_EXPORT   BRepCheck_DataMapOfShapeListOfStatus& Assign (const BRepCheck_DataMapOfShapeListOfStatus& Other) ;
  BRepCheck_DataMapOfShapeListOfStatus& operator = (const BRepCheck_DataMapOfShapeListOfStatus& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT   void ReSize (const Standard_Integer NbBuckets) ;
  
  Standard_EXPORT   void Clear() ;
~BRepCheck_DataMapOfShapeListOfStatus()
{
  Clear();
}
  
  Standard_EXPORT   Standard_Boolean Bind (const TopoDS_Shape& K, const BRepCheck_ListOfStatus& I) ;
  
  Standard_EXPORT   Standard_Boolean IsBound (const TopoDS_Shape& K)  const;
  
  Standard_EXPORT   Standard_Boolean UnBind (const TopoDS_Shape& K) ;
  
  Standard_EXPORT  const  BRepCheck_ListOfStatus& Find (const TopoDS_Shape& K)  const;
 const  BRepCheck_ListOfStatus& operator() (const TopoDS_Shape& K)  const
{
  return Find(K);
}
  
  Standard_EXPORT   BRepCheck_ListOfStatus& ChangeFind (const TopoDS_Shape& K) ;
  BRepCheck_ListOfStatus& operator() (const TopoDS_Shape& K) 
{
  return ChangeFind(K);
}
  
  Standard_EXPORT   Standard_Address Find1 (const TopoDS_Shape& K)  const;
  
  Standard_EXPORT   Standard_Address ChangeFind1 (const TopoDS_Shape& K) ;




protected:





private:

  
  Standard_EXPORT BRepCheck_DataMapOfShapeListOfStatus(const BRepCheck_DataMapOfShapeListOfStatus& Other);




};







#endif // _BRepCheck_DataMapOfShapeListOfStatus_HeaderFile