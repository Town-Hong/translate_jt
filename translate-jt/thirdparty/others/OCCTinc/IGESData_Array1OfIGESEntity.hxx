// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESData_Array1OfIGESEntity_HeaderFile
#define _IGESData_Array1OfIGESEntity_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Integer.hxx>
#include <Standard_Address.hxx>
#include <Standard_Boolean.hxx>
#include <Handle_IGESData_IGESEntity.hxx>
class Standard_RangeError;
class Standard_DimensionMismatch;
class Standard_OutOfRange;
class Standard_OutOfMemory;
class IGESData_IGESEntity;



class IGESData_Array1OfIGESEntity 
{
public:

  DEFINE_STANDARD_ALLOC

  
    IGESData_Array1OfIGESEntity(const Standard_Integer Low, const Standard_Integer Up);
  
    IGESData_Array1OfIGESEntity(const Handle(IGESData_IGESEntity)& Item, const Standard_Integer Low, const Standard_Integer Up);
  
  Standard_EXPORT   void Init (const Handle(IGESData_IGESEntity)& V) ;
  
      void Destroy() ;
~IGESData_Array1OfIGESEntity()
{
  Destroy();
}
  
      Standard_Boolean IsAllocated()  const;
  
  Standard_EXPORT  const  IGESData_Array1OfIGESEntity& Assign (const IGESData_Array1OfIGESEntity& Other) ;
 const  IGESData_Array1OfIGESEntity& operator = (const IGESData_Array1OfIGESEntity& Other) 
{
  return Assign(Other);
}
  
      Standard_Integer Length()  const;
  
      Standard_Integer Lower()  const;
  
      Standard_Integer Upper()  const;
  
      void SetValue (const Standard_Integer Index, const Handle(IGESData_IGESEntity)& Value) ;
  
     const  Handle(IGESData_IGESEntity)& Value (const Standard_Integer Index)  const;
   const  Handle(IGESData_IGESEntity)& operator () (const Standard_Integer Index)  const
{
  return Value(Index);
}
  
      Handle(IGESData_IGESEntity)& ChangeValue (const Standard_Integer Index) ;
    Handle(IGESData_IGESEntity)& operator () (const Standard_Integer Index) 
{
  return ChangeValue(Index);
}




protected:





private:

  
  Standard_EXPORT IGESData_Array1OfIGESEntity(const IGESData_Array1OfIGESEntity& AnArray);


  Standard_Integer myLowerBound;
  Standard_Integer myUpperBound;
  Standard_Address myStart;
  Standard_Boolean isAllocated;


};

#define Array1Item Handle(IGESData_IGESEntity)
#define Array1Item_hxx <IGESData_IGESEntity.hxx>
#define TCollection_Array1 IGESData_Array1OfIGESEntity
#define TCollection_Array1_hxx <IGESData_Array1OfIGESEntity.hxx>

#include <TCollection_Array1.lxx>

#undef Array1Item
#undef Array1Item_hxx
#undef TCollection_Array1
#undef TCollection_Array1_hxx




#endif // _IGESData_Array1OfIGESEntity_HeaderFile