// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TColGeom2d_SequenceNodeOfSequenceOfCurve_HeaderFile
#define _TColGeom2d_SequenceNodeOfSequenceOfCurve_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_TColGeom2d_SequenceNodeOfSequenceOfCurve.hxx>

#include <Handle_Geom2d_Curve.hxx>
#include <TCollection_SeqNode.hxx>
#include <TCollection_SeqNodePtr.hxx>
class Geom2d_Curve;
class TColGeom2d_SequenceOfCurve;



class TColGeom2d_SequenceNodeOfSequenceOfCurve : public TCollection_SeqNode
{

public:

  
    TColGeom2d_SequenceNodeOfSequenceOfCurve(const Handle(Geom2d_Curve)& I, const TCollection_SeqNodePtr& n, const TCollection_SeqNodePtr& p);
  
      Handle(Geom2d_Curve)& Value()  const;




  DEFINE_STANDARD_RTTI(TColGeom2d_SequenceNodeOfSequenceOfCurve)

protected:




private: 


  Handle(Geom2d_Curve) myValue;


};

#define SeqItem Handle(Geom2d_Curve)
#define SeqItem_hxx <Geom2d_Curve.hxx>
#define TCollection_SequenceNode TColGeom2d_SequenceNodeOfSequenceOfCurve
#define TCollection_SequenceNode_hxx <TColGeom2d_SequenceNodeOfSequenceOfCurve.hxx>
#define Handle_TCollection_SequenceNode Handle_TColGeom2d_SequenceNodeOfSequenceOfCurve
#define TCollection_SequenceNode_Type_() TColGeom2d_SequenceNodeOfSequenceOfCurve_Type_()
#define TCollection_Sequence TColGeom2d_SequenceOfCurve
#define TCollection_Sequence_hxx <TColGeom2d_SequenceOfCurve.hxx>

#include <TCollection_SequenceNode.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_SequenceNode_Type_
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx




#endif // _TColGeom2d_SequenceNodeOfSequenceOfCurve_HeaderFile
