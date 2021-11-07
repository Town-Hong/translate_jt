// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepToGeom_MakeSurface_HeaderFile
#define _StepToGeom_MakeSurface_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Boolean.hxx>
#include <Handle_StepGeom_Surface.hxx>
#include <Handle_Geom_Surface.hxx>
class StepGeom_Surface;
class Geom_Surface;


//! This class implements the mapping between classes
//! Surface from StepGeom which describes a Surface
//! from prostep and Surface from Geom.
//! As Surface is an abstract
//! Surface this class is an access to the sub-class required.
class StepToGeom_MakeSurface 
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT static   Standard_Boolean Convert (const Handle(StepGeom_Surface)& SS, Handle(Geom_Surface)& CS) ;




protected:





private:





};







#endif // _StepToGeom_MakeSurface_HeaderFile
