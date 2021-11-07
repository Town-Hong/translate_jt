// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _GeomAbs_UVSense_HeaderFile
#define _GeomAbs_UVSense_HeaderFile

#include <Standard_PrimitiveTypes.hxx>


//! This enumeration is used in the class RectangularTrimmedSurface
//! to compare the orientation of the basic surface and the orientation
//! of the trimmed surface and in the class ElementarySurface to know
//! the direction of parametrization by comparison with the default
//! construction mode.
enum GeomAbs_UVSense
{
GeomAbs_SameUV,
GeomAbs_SameU,
GeomAbs_SameV,
GeomAbs_OppositeUV
};

#endif // _GeomAbs_UVSense_HeaderFile