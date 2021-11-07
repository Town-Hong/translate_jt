// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TDF_AttributeDataMap_HeaderFile
#define _TDF_AttributeDataMap_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <TCollection_BasicMap.hxx>
#include <Handle_TDF_Attribute.hxx>
#include <Handle_TDF_DataMapNodeOfAttributeDataMap.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Address.hxx>
class Standard_DomainError;
class Standard_NoSuchObject;
class TDF_Attribute;
class TColStd_MapTransientHasher;
class TDF_DataMapNodeOfAttributeDataMap;
class TDF_DataMapIteratorOfAttributeDataMap;



class TDF_AttributeDataMap  : public TCollection_BasicMap
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT TDF_AttributeDataMap(const Standard_Integer NbBuckets = 1);
  
  Standard_EXPORT   TDF_AttributeDataMap& Assign (const TDF_AttributeDataMap& Other) ;
  TDF_AttributeDataMap& operator = (const TDF_AttributeDataMap& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT   void ReSize (const Standard_Integer NbBuckets) ;
  
  Standard_EXPORT   void Clear() ;
~TDF_AttributeDataMap()
{
  Clear();
}
  
  Standard_EXPORT   Standard_Boolean Bind (const Handle(TDF_Attribute)& K, const Handle(TDF_Attribute)& I) ;
  
  Standard_EXPORT   Standard_Boolean IsBound (const Handle(TDF_Attribute)& K)  const;
  
  Standard_EXPORT   Standard_Boolean UnBind (const Handle(TDF_Attribute)& K) ;
  
  Standard_EXPORT  const  Handle(TDF_Attribute)& Find (const Handle(TDF_Attribute)& K)  const;
 const  Handle(TDF_Attribute)& operator() (const Handle(TDF_Attribute)& K)  const
{
  return Find(K);
}
  
  Standard_EXPORT   Handle(TDF_Attribute)& ChangeFind (const Handle(TDF_Attribute)& K) ;
  Handle(TDF_Attribute)& operator() (const Handle(TDF_Attribute)& K) 
{
  return ChangeFind(K);
}
  
  Standard_EXPORT   Standard_Address Find1 (const Handle(TDF_Attribute)& K)  const;
  
  Standard_EXPORT   Standard_Address ChangeFind1 (const Handle(TDF_Attribute)& K) ;




protected:





private:

  
  Standard_EXPORT TDF_AttributeDataMap(const TDF_AttributeDataMap& Other);




};







#endif // _TDF_AttributeDataMap_HeaderFile
