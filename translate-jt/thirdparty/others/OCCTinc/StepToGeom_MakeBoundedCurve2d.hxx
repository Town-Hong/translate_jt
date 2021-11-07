// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepToGeom_MakeBoundedCurve2d_HeaderFile
#define _StepToGeom_MakeBoundedCurve2d_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Boolean.hxx>
#include <Handle_StepGeom_BoundedCurve.hxx>
#include <Handle_Geom2d_BoundedCurve.hxx>
class StepGeom_BoundedCurve;
class Geom2d_BoundedCurve;


//! This class implements the mapping between classes
//! BoundedCurve from
//! StepGeom which describes a BoundedCurve from
//! prostep and BoundedCurve from  Geom2d.
//! As BoundedCurve is an abstract BoundedCurve this class
//! is an access to the sub-class required.
class StepToGeom_MakeBoundedCurve2d 
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT static   Standard_Boolean Convert (const Handle(StepGeom_BoundedCurve)& SC, Handle(Geom2d_BoundedCurve)& CC) ;




protected:





private:





};







#endif // _StepToGeom_MakeBoundedCurve2d_HeaderFile