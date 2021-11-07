// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _math_FunctionWithDerivative_HeaderFile
#define _math_FunctionWithDerivative_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <math_Function.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Real.hxx>



//! This abstract class describes the virtual functions associated with
//! a function of a single variable for which the first derivative is
//! available.
class math_FunctionWithDerivative  : public math_Function
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Computes the value <F>of the function for the variable <X>.
  //! Returns True if the calculation were successfully done,
  //! False otherwise.
  Standard_EXPORT virtual   Standard_Boolean Value (const Standard_Real X, Standard_Real& F)  = 0;
  
  //! Computes the derivative <D> of the function
  //! for the variable <X>.
  //! Returns True if the calculation were successfully done,
  //! False otherwise.
  Standard_EXPORT virtual   Standard_Boolean Derivative (const Standard_Real X, Standard_Real& D)  = 0;
  
  //! Computes the value <F> and the derivative <D> of the
  //! function for the variable <X>.
  //! Returns True if the calculation were successfully done,
  //! False otherwise.
  Standard_EXPORT virtual   Standard_Boolean Values (const Standard_Real X, Standard_Real& F, Standard_Real& D)  = 0;
  Standard_EXPORT virtual ~math_FunctionWithDerivative();




protected:





private:





};







#endif // _math_FunctionWithDerivative_HeaderFile
