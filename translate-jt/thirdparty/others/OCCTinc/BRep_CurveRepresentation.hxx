// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRep_CurveRepresentation_HeaderFile
#define _BRep_CurveRepresentation_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_BRep_CurveRepresentation.hxx>

#include <TopLoc_Location.hxx>
#include <MMgt_TShared.hxx>
#include <Standard_Boolean.hxx>
#include <Handle_Geom_Surface.hxx>
#include <Handle_Poly_Triangulation.hxx>
#include <Handle_Geom_Curve.hxx>
#include <Handle_Geom2d_Curve.hxx>
#include <Handle_Poly_Polygon3D.hxx>
#include <Handle_Poly_Polygon2D.hxx>
#include <Handle_Poly_PolygonOnTriangulation.hxx>
#include <GeomAbs_Shape.hxx>
class Standard_DomainError;
class TopLoc_Location;
class Geom_Surface;
class Poly_Triangulation;
class Geom_Curve;
class Geom2d_Curve;
class Poly_Polygon3D;
class Poly_Polygon2D;
class Poly_PolygonOnTriangulation;


//! Root class for the curve representations. Contains
//! a location.
class BRep_CurveRepresentation : public MMgt_TShared
{

public:

  
  //! A 3D curve representation.
  Standard_EXPORT virtual   Standard_Boolean IsCurve3D()  const;
  
  //! A curve in the parametric space of a surface.
  Standard_EXPORT virtual   Standard_Boolean IsCurveOnSurface()  const;
  
  //! A continuity between two surfaces.
  Standard_EXPORT virtual   Standard_Boolean IsRegularity()  const;
  
  //! A curve with two parametric   curves  on the  same
  //! surface.
  Standard_EXPORT virtual   Standard_Boolean IsCurveOnClosedSurface()  const;
  
  //! Is it a curve in the parametric space  of <S> with
  //! location <L>.
  Standard_EXPORT virtual   Standard_Boolean IsCurveOnSurface (const Handle(Geom_Surface)& S, const TopLoc_Location& L)  const;
  
  //! Is it  a  regularity between  <S1> and   <S2> with
  //! location <L1> and <L2>.
  Standard_EXPORT virtual   Standard_Boolean IsRegularity (const Handle(Geom_Surface)& S1, const Handle(Geom_Surface)& S2, const TopLoc_Location& L1, const TopLoc_Location& L2)  const;
  
  //! A 3D polygon representation.
  Standard_EXPORT virtual   Standard_Boolean IsPolygon3D()  const;
  
  //! A representation by an array of nodes on a
  //! triangulation.
  Standard_EXPORT virtual   Standard_Boolean IsPolygonOnTriangulation()  const;
  
  //! Is it a polygon in the definition of <T> with
  //! location <L>.
  Standard_EXPORT virtual   Standard_Boolean IsPolygonOnTriangulation (const Handle(Poly_Triangulation)& T, const TopLoc_Location& L)  const;
  
  //! A representation by two arrays of nodes on a
  //! triangulation.
  Standard_EXPORT virtual   Standard_Boolean IsPolygonOnClosedTriangulation()  const;
  
  //! A polygon in the parametric space of a surface.
  Standard_EXPORT virtual   Standard_Boolean IsPolygonOnSurface()  const;
  
  //! Is it a polygon in the parametric space  of <S> with
  //! location <L>.
  Standard_EXPORT virtual   Standard_Boolean IsPolygonOnSurface (const Handle(Geom_Surface)& S, const TopLoc_Location& L)  const;
  
  //! Two   2D polygon  representations  in the  parametric
  //! space of a surface.
  Standard_EXPORT virtual   Standard_Boolean IsPolygonOnClosedSurface()  const;
  
     const  TopLoc_Location& Location()  const;
  
      void Location (const TopLoc_Location& L) ;
  
  Standard_EXPORT virtual  const  Handle(Geom_Curve)& Curve3D()  const;
  
  Standard_EXPORT virtual   void Curve3D (const Handle(Geom_Curve)& C) ;
  
  Standard_EXPORT virtual  const  Handle(Geom_Surface)& Surface()  const;
  
  Standard_EXPORT virtual  const  Handle(Geom2d_Curve)& PCurve()  const;
  
  Standard_EXPORT virtual   void PCurve (const Handle(Geom2d_Curve)& C) ;
  
  Standard_EXPORT virtual  const  Handle(Geom2d_Curve)& PCurve2()  const;
  
  Standard_EXPORT virtual   void PCurve2 (const Handle(Geom2d_Curve)& C) ;
  
  Standard_EXPORT virtual  const  Handle(Poly_Polygon3D)& Polygon3D()  const;
  
  Standard_EXPORT virtual   void Polygon3D (const Handle(Poly_Polygon3D)& P) ;
  
  Standard_EXPORT virtual  const  Handle(Poly_Polygon2D)& Polygon()  const;
  
  Standard_EXPORT virtual   void Polygon (const Handle(Poly_Polygon2D)& P) ;
  
  Standard_EXPORT virtual  const  Handle(Poly_Polygon2D)& Polygon2()  const;
  
  Standard_EXPORT virtual   void Polygon2 (const Handle(Poly_Polygon2D)& P) ;
  
  Standard_EXPORT virtual  const  Handle(Poly_Triangulation)& Triangulation()  const;
  
  Standard_EXPORT virtual  const  Handle(Poly_PolygonOnTriangulation)& PolygonOnTriangulation()  const;
  
  Standard_EXPORT virtual   void PolygonOnTriangulation (const Handle(Poly_PolygonOnTriangulation)& P) ;
  
  Standard_EXPORT virtual  const  Handle(Poly_PolygonOnTriangulation)& PolygonOnTriangulation2()  const;
  
  Standard_EXPORT virtual   void PolygonOnTriangulation2 (const Handle(Poly_PolygonOnTriangulation)& P2) ;
  
  Standard_EXPORT virtual  const  Handle(Geom_Surface)& Surface2()  const;
  
  Standard_EXPORT virtual  const  TopLoc_Location& Location2()  const;
  
  Standard_EXPORT virtual  const  GeomAbs_Shape& Continuity()  const;
  
  Standard_EXPORT virtual   void Continuity (const GeomAbs_Shape C) ;
  
  //! Return a copy of this representation.
  Standard_EXPORT virtual   Handle(BRep_CurveRepresentation) Copy()  const = 0;




  DEFINE_STANDARD_RTTI(BRep_CurveRepresentation)

protected:

  
  Standard_EXPORT BRep_CurveRepresentation(const TopLoc_Location& L);

  TopLoc_Location myLocation;


private: 




};


#include <BRep_CurveRepresentation.lxx>





#endif // _BRep_CurveRepresentation_HeaderFile
