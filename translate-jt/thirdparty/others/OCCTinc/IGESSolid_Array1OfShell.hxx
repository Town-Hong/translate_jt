// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESSolid_Array1OfShell_HeaderFile
#define _IGESSolid_Array1OfShell_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Integer.hxx>
#include <Standard_Address.hxx>
#include <Standard_Boolean.hxx>
#include <Handle_IGESSolid_Shell.hxx>
class Standard_RangeError;
class Standard_DimensionMismatch;
class Standard_OutOfRange;
class Standard_OutOfMemory;
class IGESSolid_Shell;



class IGESSolid_Array1OfShell 
{
public:

  DEFINE_STANDARD_ALLOC

  
    IGESSolid_Array1OfShell(const Standard_Integer Low, const Standard_Integer Up);
  
    IGESSolid_Array1OfShell(const Handle(IGESSolid_Shell)& Item, const Standard_Integer Low, const Standard_Integer Up);
  
  Standard_EXPORT   void Init (const Handle(IGESSolid_Shell)& V) ;
  
      void Destroy() ;
~IGESSolid_Array1OfShell()
{
  Destroy();
}
  
      Standard_Boolean IsAllocated()  const;
  
  Standard_EXPORT  const  IGESSolid_Array1OfShell& Assign (const IGESSolid_Array1OfShell& Other) ;
 const  IGESSolid_Array1OfShell& operator = (const IGESSolid_Array1OfShell& Other) 
{
  return Assign(Other);
}
  
      Standard_Integer Length()  const;
  
      Standard_Integer Lower()  const;
  
      Standard_Integer Upper()  const;
  
      void SetValue (const Standard_Integer Index, const Handle(IGESSolid_Shell)& Value) ;
  
     const  Handle(IGESSolid_Shell)& Value (const Standard_Integer Index)  const;
   const  Handle(IGESSolid_Shell)& operator () (const Standard_Integer Index)  const
{
  return Value(Index);
}
  
      Handle(IGESSolid_Shell)& ChangeValue (const Standard_Integer Index) ;
    Handle(IGESSolid_Shell)& operator () (const Standard_Integer Index) 
{
  return ChangeValue(Index);
}




protected:





private:

  
  Standard_EXPORT IGESSolid_Array1OfShell(const IGESSolid_Array1OfShell& AnArray);


  Standard_Integer myLowerBound;
  Standard_Integer myUpperBound;
  Standard_Address myStart;
  Standard_Boolean isAllocated;


};

#define Array1Item Handle(IGESSolid_Shell)
#define Array1Item_hxx <IGESSolid_Shell.hxx>
#define TCollection_Array1 IGESSolid_Array1OfShell
#define TCollection_Array1_hxx <IGESSolid_Array1OfShell.hxx>

#include <TCollection_Array1.lxx>

#undef Array1Item
#undef Array1Item_hxx
#undef TCollection_Array1
#undef TCollection_Array1_hxx




#endif // _IGESSolid_Array1OfShell_HeaderFile
