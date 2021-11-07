// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BOPDS_IndexRange_HeaderFile
#define _BOPDS_IndexRange_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>



//! The class BOPDS_IndexRange is to store
//! the information about range of two indices
class BOPDS_IndexRange 
{
public:

  DEFINE_STANDARD_ALLOC

  

  //! Empty contructor
    BOPDS_IndexRange();
Standard_EXPORT virtual ~BOPDS_IndexRange();
  

  //! Modifier
  //! Sets the first index <theI1>  of the range
      void SetFirst (const Standard_Integer theI1) ;
  

  //! Modifier
  //! Sets the second index <theI2>  of the range
      void SetLast (const Standard_Integer theI2) ;
  

  //! Selector
  //! Returns the first index of the range
      Standard_Integer First()  const;
  

  //! Selector
  //! Returns the second index of the range
      Standard_Integer Last()  const;
  

  //! Modifier
  //! Sets the first index of the range  <theI1>
  //! Sets the second index of the range <theI2>
      void SetIndices (const Standard_Integer theI1, const Standard_Integer theI2) ;
  

  //! Selector
  //! Returns the first index of the range  <theI1>
  //! Returns the second index of the range <theI2>
      void Indices (Standard_Integer& theI1, Standard_Integer& theI2)  const;
  

  //! Query
  //! Returns true if the range contains <theIndex>
      Standard_Boolean Contains (const Standard_Integer theIndex)  const;
  
  Standard_EXPORT   void Dump()  const;




protected:



  Standard_Integer myFirst;
  Standard_Integer myLast;


private:





};


#include <BOPDS_IndexRange.lxx>





#endif // _BOPDS_IndexRange_HeaderFile