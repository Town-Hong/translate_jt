// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _PPoly_Triangle_HeaderFile
#define _PPoly_Triangle_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Integer.hxx>
#include <Standard_Storable.hxx>
#include <Standard_PrimitiveTypes.hxx>


Standard_EXPORT const Handle(Standard_Type)& STANDARD_TYPE(PPoly_Triangle);

//! A Triangle is a triplet of node indices.
class PPoly_Triangle 
{

public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT PPoly_Triangle(const Standard_Integer N1, const Standard_Integer N2, const Standard_Integer N3);
  
  Standard_EXPORT   void Set (const Standard_Integer N1, const Standard_Integer N2, const Standard_Integer N3) ;
  
  Standard_EXPORT   void Get (Standard_Integer& N1, Standard_Integer& N2, Standard_Integer& N3)  const;
PPoly_Triangle( )
{
  
}
    Standard_Integer& _CSFDB_GetPPoly_TrianglemyNodes(const Standard_Integer i1) { return myNodes[i1]; }



protected:




private: 


  Standard_Integer myNodes[3];


};







#endif // _PPoly_Triangle_HeaderFile