// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Geom2dGcc_FunctionTanCirCu_HeaderFile
#define _Geom2dGcc_FunctionTanCirCu_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <gp_Circ2d.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <Standard_Real.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <Standard_Boolean.hxx>
class gp_Circ2d;
class Geom2dAdaptor_Curve;


//! This abstract class describes a Function of 1 Variable
//! used to find a line tangent to a curve and a circle.
class Geom2dGcc_FunctionTanCirCu  : public math_FunctionWithDerivative
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT Geom2dGcc_FunctionTanCirCu(const gp_Circ2d& Circ, const Geom2dAdaptor_Curve& Curv);
  
  //! Computes the value of the function F for the variable X.
  //! It returns True if the computation is successfully done,
  //! False otherwise.
  Standard_EXPORT   Standard_Boolean Value (const Standard_Real X, Standard_Real& F) ;
  
  //! Computes the derivative of the function F for the variable X.
  //! It returns True if the computation is successfully done,
  //! False otherwise.
  Standard_EXPORT   Standard_Boolean Derivative (const Standard_Real X, Standard_Real& Deriv) ;
  
  //! Computes the value and the derivative of the function F
  //! for the variable X.
  //! It returns True if the computation is successfully done,
  //! False otherwise.
  Standard_EXPORT   Standard_Boolean Values (const Standard_Real X, Standard_Real& F, Standard_Real& Deriv) ;




protected:





private:



  gp_Circ2d TheCirc;
  Geom2dAdaptor_Curve Curve;
  Standard_Real myWeight;


};







#endif // _Geom2dGcc_FunctionTanCirCu_HeaderFile