// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepFEA_DegreeOfFreedomMember_HeaderFile
#define _StepFEA_DegreeOfFreedomMember_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepFEA_DegreeOfFreedomMember.hxx>

#include <Standard_Integer.hxx>
#include <StepData_SelectNamed.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_CString.hxx>


//! Representation of member for  STEP SELECT type CurveElementFreedom
class StepFEA_DegreeOfFreedomMember : public StepData_SelectNamed
{

public:

  
  //! Empty constructor
  Standard_EXPORT StepFEA_DegreeOfFreedomMember();
  
  //! Returns True if has name
  Standard_EXPORT virtual   Standard_Boolean HasName()  const;
  
  //! Returns set name
  Standard_EXPORT virtual   Standard_CString Name()  const;
  
  //! Set name
  Standard_EXPORT virtual   Standard_Boolean SetName (const Standard_CString name) ;
  
  //! Tells if the name of a SelectMember matches a given one;
  Standard_EXPORT virtual   Standard_Boolean Matches (const Standard_CString name)  const;




  DEFINE_STANDARD_RTTI(StepFEA_DegreeOfFreedomMember)

protected:




private: 


  Standard_Integer mycase;


};







#endif // _StepFEA_DegreeOfFreedomMember_HeaderFile