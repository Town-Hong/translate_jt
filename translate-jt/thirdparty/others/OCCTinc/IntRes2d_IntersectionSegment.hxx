// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IntRes2d_IntersectionSegment_HeaderFile
#define _IntRes2d_IntersectionSegment_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Boolean.hxx>
#include <IntRes2d_IntersectionPoint.hxx>
#include <Standard_Storable.hxx>
#include <Standard_PrimitiveTypes.hxx>
class Standard_DomainError;
class IntRes2d_IntersectionPoint;


Standard_EXPORT const Handle(Standard_Type)& STANDARD_TYPE(IntRes2d_IntersectionSegment);

//! Definition of an intersection curve between
//! two 2D curves.
class IntRes2d_IntersectionSegment 
{

public:

  DEFINE_STANDARD_ALLOC

  
  //! Empty constructor.
  Standard_EXPORT IntRes2d_IntersectionSegment();
  
    IntRes2d_IntersectionSegment(const IntRes2d_IntersectionPoint& P1, const IntRes2d_IntersectionPoint& P2, const Standard_Boolean Oppos, const Standard_Boolean ReverseFlag);
  
    IntRes2d_IntersectionSegment(const IntRes2d_IntersectionPoint& P, const Standard_Boolean First, const Standard_Boolean Oppos, const Standard_Boolean ReverseFlag);
  
  //! Creates an infinite segment of intersection.
    IntRes2d_IntersectionSegment(const Standard_Boolean Oppos);
  
  //! Returns FALSE if the intersection segment has got
  //! the same orientation on both curves.
      Standard_Boolean IsOpposite()  const;
  
  //! Returns True if the segment is  limited by a first
  //! point.   This  point defines  the lowest parameter
  //! admitted on the first  curve for the  segment.  If
  //! IsOpposite  returns  False, it  defines the lowest
  //! parameter on the  second curve, otherwise,  it  is
  //! the highest parameter on the second curve.
      Standard_Boolean HasFirstPoint()  const;
  
  //! Returns the  first point   of the segment    as an
  //! IntersectionPoint (with    a    transition).   The
  //! exception  DomainError  is raised if HasFirstPoint
  //! returns False.
     const  IntRes2d_IntersectionPoint& FirstPoint()  const;
  
  //! Returns True if the segment  is  limited by a last
  //! point.  This point  defines  the highest parameter
  //! admitted on the  first curve for  the segment.  If
  //! IsOpposite returns  False, it  defines the highest
  //! parameter on  the  second curve, otherwise, it  is
  //! the lowest parameter on the second curve.
      Standard_Boolean HasLastPoint()  const;
  
  //! Returns   the  last point  of the    segment as an
  //! IntersectionPoint   (with  a    transition).   The
  //! exception        DomainError     is   raised    if
  //! HasLastExtremity returns False.
     const  IntRes2d_IntersectionPoint& LastPoint()  const;
    Standard_Boolean _CSFDB_GetIntRes2d_IntersectionSegmentoppos() const { return oppos; }
    void _CSFDB_SetIntRes2d_IntersectionSegmentoppos(const Standard_Boolean p) { oppos = p; }
    Standard_Boolean _CSFDB_GetIntRes2d_IntersectionSegmentfirst() const { return first; }
    void _CSFDB_SetIntRes2d_IntersectionSegmentfirst(const Standard_Boolean p) { first = p; }
    Standard_Boolean _CSFDB_GetIntRes2d_IntersectionSegmentlast() const { return last; }
    void _CSFDB_SetIntRes2d_IntersectionSegmentlast(const Standard_Boolean p) { last = p; }
    const IntRes2d_IntersectionPoint& _CSFDB_GetIntRes2d_IntersectionSegmentptfirst() const { return ptfirst; }
    const IntRes2d_IntersectionPoint& _CSFDB_GetIntRes2d_IntersectionSegmentptlast() const { return ptlast; }



protected:




private: 


  Standard_Boolean oppos;
  Standard_Boolean first;
  Standard_Boolean last;
  IntRes2d_IntersectionPoint ptfirst;
  IntRes2d_IntersectionPoint ptlast;


};


#include <IntRes2d_IntersectionSegment.lxx>





#endif // _IntRes2d_IntersectionSegment_HeaderFile
