// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ShapeExtend_HeaderFile
#define _ShapeExtend_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Integer.hxx>
#include <ShapeExtend_Status.hxx>
#include <Standard_Boolean.hxx>
class ShapeExtend_ComplexCurve;
class ShapeExtend_CompositeSurface;
class ShapeExtend_WireData;
class ShapeExtend_BasicMsgRegistrator;
class ShapeExtend_MsgRegistrator;
class ShapeExtend_Explorer;
class ShapeExtend_DataMapOfShapeListOfMsg;
class ShapeExtend_DataMapOfTransientListOfMsg;
class ShapeExtend_DataMapNodeOfDataMapOfShapeListOfMsg;
class ShapeExtend_DataMapIteratorOfDataMapOfShapeListOfMsg;
class ShapeExtend_DataMapNodeOfDataMapOfTransientListOfMsg;
class ShapeExtend_DataMapIteratorOfDataMapOfTransientListOfMsg;


//! This package provides general tools and data structures common
//! for other packages in SHAPEWORKS and extending CAS.CADE
//! structures.
//! The following items are provided by this package:
//! - enumeration Status used for coding status flags in methods
//! inside the SHAPEWORKS
//! - enumeration Parametrisation used for setting global parametrisation
//! on the composite surface
//! - class CompositeSurface representing a composite surface
//! made of a grid of surface patches
//! - class WireData representing a wire in the form of ordered
//! list of edges
//! - class MsgRegistrator for attaching messages to the objects
//! - tools for exploring the shapes
//! -       tools for creating       new shapes.
class ShapeExtend 
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Inits using of ShapeExtend.
  //! Currently, loads messages output by ShapeHealing algorithms.
  Standard_EXPORT static   void Init() ;
  
  //! Encodes status (enumeration) to a bit flag
  Standard_EXPORT static   Standard_Integer EncodeStatus (const ShapeExtend_Status status) ;
  
  //! Tells if a bit flag contains bit corresponding to enumerated status
  Standard_EXPORT static   Standard_Boolean DecodeStatus (const Standard_Integer flag, const ShapeExtend_Status status) ;




protected:





private:




friend class ShapeExtend_ComplexCurve;
friend class ShapeExtend_CompositeSurface;
friend class ShapeExtend_WireData;
friend class ShapeExtend_BasicMsgRegistrator;
friend class ShapeExtend_MsgRegistrator;
friend class ShapeExtend_Explorer;
friend class ShapeExtend_DataMapOfShapeListOfMsg;
friend class ShapeExtend_DataMapOfTransientListOfMsg;
friend class ShapeExtend_DataMapNodeOfDataMapOfShapeListOfMsg;
friend class ShapeExtend_DataMapIteratorOfDataMapOfShapeListOfMsg;
friend class ShapeExtend_DataMapNodeOfDataMapOfTransientListOfMsg;
friend class ShapeExtend_DataMapIteratorOfDataMapOfTransientListOfMsg;

};







#endif // _ShapeExtend_HeaderFile