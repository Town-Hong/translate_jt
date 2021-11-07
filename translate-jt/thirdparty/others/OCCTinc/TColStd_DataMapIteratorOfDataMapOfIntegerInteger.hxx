// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TColStd_DataMapIteratorOfDataMapOfIntegerInteger_HeaderFile
#define _TColStd_DataMapIteratorOfDataMapOfIntegerInteger_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <TCollection_BasicMapIterator.hxx>
#include <Standard_Integer.hxx>
#include <Handle_TColStd_DataMapNodeOfDataMapOfIntegerInteger.hxx>
class Standard_NoSuchObject;
class TColStd_MapIntegerHasher;
class TColStd_DataMapOfIntegerInteger;
class TColStd_DataMapNodeOfDataMapOfIntegerInteger;



class TColStd_DataMapIteratorOfDataMapOfIntegerInteger  : public TCollection_BasicMapIterator
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT TColStd_DataMapIteratorOfDataMapOfIntegerInteger();
  
  Standard_EXPORT TColStd_DataMapIteratorOfDataMapOfIntegerInteger(const TColStd_DataMapOfIntegerInteger& aMap);
  
  Standard_EXPORT   void Initialize (const TColStd_DataMapOfIntegerInteger& aMap) ;
  
  Standard_EXPORT  const  Standard_Integer& Key()  const;
  
  Standard_EXPORT  const  Standard_Integer& Value()  const;




protected:





private:





};







#endif // _TColStd_DataMapIteratorOfDataMapOfIntegerInteger_HeaderFile