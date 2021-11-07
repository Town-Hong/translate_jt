// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IntImpParGen_ImpTool_HeaderFile
#define _IntImpParGen_ImpTool_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Real.hxx>
class gp_Pnt2d;
class gp_Vec2d;


//! Template class for an implicit curve.
class IntImpParGen_ImpTool 
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   gp_Pnt2d Value (const Standard_Real U)  const;
  
  Standard_EXPORT   void D1 (const Standard_Real U, gp_Pnt2d& P, gp_Vec2d& T)  const;
  
  Standard_EXPORT   void D2 (const Standard_Real U, gp_Pnt2d& P, gp_Vec2d& T, gp_Vec2d& N)  const;
  
  //! Computes the value of the signed distance between
  //! the point P and the implicit curve.
  Standard_EXPORT   Standard_Real Distance (const gp_Pnt2d& P)  const;
  
  //! Computes the Gradient of the Signed Distance
  //! between a point and the implicit curve, at the
  //! point P.
  Standard_EXPORT   gp_Vec2d GradDistance (const gp_Pnt2d& P)  const;
  
  //! Returns the parameter U of the point on the
  //! implicit curve corresponding to the point P.
  //! The correspondance between P and the point P(U) on
  //! the implicit curve must be coherent with the way
  //! of determination of the signed distance.
  Standard_EXPORT   Standard_Real FindParameter (const gp_Pnt2d& P)  const;




protected:





private:





};







#endif // _IntImpParGen_ImpTool_HeaderFile
