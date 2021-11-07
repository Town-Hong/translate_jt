// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepBasic_HArray1OfProductDefinition_HeaderFile
#define _StepBasic_HArray1OfProductDefinition_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepBasic_HArray1OfProductDefinition.hxx>

#include <StepBasic_Array1OfProductDefinition.hxx>
#include <MMgt_TShared.hxx>
#include <Handle_StepBasic_ProductDefinition.hxx>
#include <Standard_Integer.hxx>
class Standard_RangeError;
class Standard_DimensionMismatch;
class Standard_OutOfRange;
class Standard_OutOfMemory;
class StepBasic_ProductDefinition;
class StepBasic_Array1OfProductDefinition;



class StepBasic_HArray1OfProductDefinition : public MMgt_TShared
{

public:

  
    StepBasic_HArray1OfProductDefinition(const Standard_Integer Low, const Standard_Integer Up);
  
    StepBasic_HArray1OfProductDefinition(const Standard_Integer Low, const Standard_Integer Up, const Handle(StepBasic_ProductDefinition)& V);
  
      void Init (const Handle(StepBasic_ProductDefinition)& V) ;
  
      Standard_Integer Length()  const;
  
      Standard_Integer Lower()  const;
  
      Standard_Integer Upper()  const;
  
      void SetValue (const Standard_Integer Index, const Handle(StepBasic_ProductDefinition)& Value) ;
  
     const  Handle(StepBasic_ProductDefinition)& Value (const Standard_Integer Index)  const;
  
      Handle(StepBasic_ProductDefinition)& ChangeValue (const Standard_Integer Index) ;
  
     const  StepBasic_Array1OfProductDefinition& Array1()  const;
  
      StepBasic_Array1OfProductDefinition& ChangeArray1() ;




  DEFINE_STANDARD_RTTI(StepBasic_HArray1OfProductDefinition)

protected:




private: 


  StepBasic_Array1OfProductDefinition myArray;


};

#define ItemHArray1 Handle(StepBasic_ProductDefinition)
#define ItemHArray1_hxx <StepBasic_ProductDefinition.hxx>
#define TheArray1 StepBasic_Array1OfProductDefinition
#define TheArray1_hxx <StepBasic_Array1OfProductDefinition.hxx>
#define TCollection_HArray1 StepBasic_HArray1OfProductDefinition
#define TCollection_HArray1_hxx <StepBasic_HArray1OfProductDefinition.hxx>
#define Handle_TCollection_HArray1 Handle_StepBasic_HArray1OfProductDefinition
#define TCollection_HArray1_Type_() StepBasic_HArray1OfProductDefinition_Type_()

#include <TCollection_HArray1.lxx>

#undef ItemHArray1
#undef ItemHArray1_hxx
#undef TheArray1
#undef TheArray1_hxx
#undef TCollection_HArray1
#undef TCollection_HArray1_hxx
#undef Handle_TCollection_HArray1
#undef TCollection_HArray1_Type_




#endif // _StepBasic_HArray1OfProductDefinition_HeaderFile
