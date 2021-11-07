// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IntCurveSurface_TransitionOnCurve_HeaderFile
#define _IntCurveSurface_TransitionOnCurve_HeaderFile

#include <Standard_PrimitiveTypes.hxx>


//! \ Uo     ^        \ U1     ^
//! \       | n       \       | n
//! Surf  ====\======|===   ====\======|===
//! \     .           \     .
//! \    .            \    .
//! U1  \   .          Uo \   .
//!
//! ( In )            ( Out )
//!
//! \           /
//! \         /
//! \       /
//! \     /
//! Surf =====-----=====
//!
//! ( Tangent )
//! Crb and Surf are  C1
enum IntCurveSurface_TransitionOnCurve
{
IntCurveSurface_Tangent,
IntCurveSurface_In,
IntCurveSurface_Out
};

#endif // _IntCurveSurface_TransitionOnCurve_HeaderFile