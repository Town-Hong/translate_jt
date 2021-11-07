// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _PDataStd_IntegerArray_HeaderFile
#define _PDataStd_IntegerArray_HeaderFile

#include <Standard_Macro.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard.hxx>
#include <Handle_PDataStd_IntegerArray.hxx>

#include <Standard_Integer.hxx>
#include <Handle_PColStd_HArray1OfInteger.hxx>
#include <PDF_Attribute.hxx>
class PColStd_HArray1OfInteger;


class PDataStd_IntegerArray : public PDF_Attribute
{

public:

  
  Standard_EXPORT PDataStd_IntegerArray();
  
  Standard_EXPORT   void Init (const Standard_Integer lower, const Standard_Integer upper) ;
  
  Standard_EXPORT   void SetValue (const Standard_Integer Index, const Standard_Integer Value) ;
  
  Standard_EXPORT   Standard_Integer Value (const Standard_Integer Index)  const;
  
  Standard_EXPORT   Standard_Integer Lower()  const;
  
  Standard_EXPORT   Standard_Integer Upper()  const;

PDataStd_IntegerArray(const Storage_stCONSTclCOM& a) : PDF_Attribute(a)
{
  
}
    Handle(PColStd_HArray1OfInteger) _CSFDB_GetPDataStd_IntegerArraymyValue() const { return myValue; }
    void _CSFDB_SetPDataStd_IntegerArraymyValue(const Handle(PColStd_HArray1OfInteger)& p) { myValue = p; }



  DEFINE_STANDARD_RTTI(PDataStd_IntegerArray)

protected:




private: 


  Handle(PColStd_HArray1OfInteger) myValue;


};







#endif // _PDataStd_IntegerArray_HeaderFile