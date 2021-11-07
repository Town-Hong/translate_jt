// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ShapeUpgrade_SplitSurface_HeaderFile
#define _ShapeUpgrade_SplitSurface_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_ShapeUpgrade_SplitSurface.hxx>

#include <Handle_TColStd_HSequenceOfReal.hxx>
#include <Standard_Integer.hxx>
#include <Handle_Geom_Surface.hxx>
#include <Handle_ShapeExtend_CompositeSurface.hxx>
#include <MMgt_TShared.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
#include <ShapeExtend_Status.hxx>
class TColStd_HSequenceOfReal;
class Geom_Surface;
class ShapeExtend_CompositeSurface;


//! Splits a Surface with a criterion.
class ShapeUpgrade_SplitSurface : public MMgt_TShared
{

public:

  
  //! Empty constructor.
  Standard_EXPORT ShapeUpgrade_SplitSurface();
  
  //! Initializes with single supporting surface.
  Standard_EXPORT   void Init (const Handle(Geom_Surface)& S) ;
  
  //! Initializes with single supporting surface with bounding parameters.
  Standard_EXPORT   void Init (const Handle(Geom_Surface)& S, const Standard_Real UFirst, const Standard_Real ULast, const Standard_Real VFirst, const Standard_Real VLast) ;
  
  //! Sets U parameters where splitting has to be done
  Standard_EXPORT   void SetUSplitValues (const Handle(TColStd_HSequenceOfReal)& UValues) ;
  
  //! Sets V parameters where splitting has to be done
  Standard_EXPORT   void SetVSplitValues (const Handle(TColStd_HSequenceOfReal)& VValues) ;
  
  //! Performs splitting of the supporting surface.
  //! If resulting surface is B-Spline and Segment is True,
  //! the result is composed with segments of the surface bounded
  //! by the U and V SplitValues (method Geom_BSplineSurface::Segment
  //! is used).
  //! If Segment is False, the result is composed with
  //! Geom_RectangularTrimmedSurface all based on the same complete
  //! surface.
  //! Fields myNbResultingRow and myNbResultingCol must be set to
  //! specify the size of resulting grid of surfaces.
  Standard_EXPORT virtual   void Build (const Standard_Boolean Segment) ;
  
  //! Calculates points for correction/splitting of the surface.
  Standard_EXPORT virtual   void Compute (const Standard_Boolean Segment = Standard_True) ;
  
  //! Performs correction/splitting of the surface.
  //! First defines splitting values by method Compute(), then calls method Build().
  Standard_EXPORT   void Perform (const Standard_Boolean Segment = Standard_True) ;
  
  //! returns all the U splitting values including the
  //! First and Last parameters of the input surface
  Standard_EXPORT  const  Handle(TColStd_HSequenceOfReal)& USplitValues()  const;
  
  //! returns all the splitting V values including the
  //! First and Last parameters of the input surface
  Standard_EXPORT  const  Handle(TColStd_HSequenceOfReal)& VSplitValues()  const;
  
  //! Returns the status
  //! OK    - no splitting is needed
  //! DONE1 - splitting required and gives more than one patch
  //! DONE2 - splitting is required, but gives only single patch (initial)
  //! DONE3 - geometric form of the surface or parametrisation is modified
  Standard_EXPORT   Standard_Boolean Status (const ShapeExtend_Status status)  const;
  
  //! Returns obtained surfaces after splitting as CompositeSurface
  Standard_EXPORT  const  Handle(ShapeExtend_CompositeSurface)& ResSurfaces()  const;




  DEFINE_STANDARD_RTTI(ShapeUpgrade_SplitSurface)

protected:


  Handle(TColStd_HSequenceOfReal) myUSplitValues;
  Handle(TColStd_HSequenceOfReal) myVSplitValues;
  Standard_Integer myNbResultingRow;
  Standard_Integer myNbResultingCol;
  Handle(Geom_Surface) mySurface;
  Standard_Integer myStatus;
  Handle(ShapeExtend_CompositeSurface) myResSurfaces;


private: 




};







#endif // _ShapeUpgrade_SplitSurface_HeaderFile
