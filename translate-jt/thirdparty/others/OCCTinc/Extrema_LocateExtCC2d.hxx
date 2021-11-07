// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Extrema_LocateExtCC2d_HeaderFile
#define _Extrema_LocateExtCC2d_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Boolean.hxx>
#include <Standard_Real.hxx>
#include <Extrema_POnCurv2d.hxx>
class Standard_DomainError;
class StdFail_NotDone;
class Adaptor2d_Curve2d;
class Extrema_POnCurv2d;


//! It calculates the distance between two curves with
//! a close point; these distances can be maximum or
//! minimum.
class Extrema_LocateExtCC2d 
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Calculates the distance with a close point. The
  //! close point is defined by a parameter value on each
  //! curve.
  //! The function F(u,v)=distance(C1(u),C2(v)) has an
  //! extremun when gradient(f)=0. The algorithm searchs
  //! the zero near the close point.
  Standard_EXPORT Extrema_LocateExtCC2d(const Adaptor2d_Curve2d& C1, const Adaptor2d_Curve2d& C2, const Standard_Real U0, const Standard_Real V0);
  
  //! Returns True if the distance is found.
  Standard_EXPORT   Standard_Boolean IsDone()  const;
  
  //! Returns the value of the extremum square distance.
  Standard_EXPORT   Standard_Real SquareDistance()  const;
  
  //! Returns the points of the extremum distance.
  //! P1 is on the first curve, P2 on the second one.
  Standard_EXPORT   void Point (Extrema_POnCurv2d& P1, Extrema_POnCurv2d& P2)  const;




protected:





private:



  Standard_Boolean myDone;
  Standard_Real mySqDist;
  Extrema_POnCurv2d myPoint1;
  Extrema_POnCurv2d myPoint2;


};







#endif // _Extrema_LocateExtCC2d_HeaderFile