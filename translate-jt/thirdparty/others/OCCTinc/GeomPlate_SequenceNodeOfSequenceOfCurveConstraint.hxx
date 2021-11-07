// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _GeomPlate_SequenceNodeOfSequenceOfCurveConstraint_HeaderFile
#define _GeomPlate_SequenceNodeOfSequenceOfCurveConstraint_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_GeomPlate_SequenceNodeOfSequenceOfCurveConstraint.hxx>

#include <Handle_GeomPlate_CurveConstraint.hxx>
#include <TCollection_SeqNode.hxx>
#include <TCollection_SeqNodePtr.hxx>
class GeomPlate_CurveConstraint;
class GeomPlate_SequenceOfCurveConstraint;



class GeomPlate_SequenceNodeOfSequenceOfCurveConstraint : public TCollection_SeqNode
{

public:

  
    GeomPlate_SequenceNodeOfSequenceOfCurveConstraint(const Handle(GeomPlate_CurveConstraint)& I, const TCollection_SeqNodePtr& n, const TCollection_SeqNodePtr& p);
  
      Handle(GeomPlate_CurveConstraint)& Value()  const;




  DEFINE_STANDARD_RTTI(GeomPlate_SequenceNodeOfSequenceOfCurveConstraint)

protected:




private: 


  Handle(GeomPlate_CurveConstraint) myValue;


};

#define SeqItem Handle(GeomPlate_CurveConstraint)
#define SeqItem_hxx <GeomPlate_CurveConstraint.hxx>
#define TCollection_SequenceNode GeomPlate_SequenceNodeOfSequenceOfCurveConstraint
#define TCollection_SequenceNode_hxx <GeomPlate_SequenceNodeOfSequenceOfCurveConstraint.hxx>
#define Handle_TCollection_SequenceNode Handle_GeomPlate_SequenceNodeOfSequenceOfCurveConstraint
#define TCollection_SequenceNode_Type_() GeomPlate_SequenceNodeOfSequenceOfCurveConstraint_Type_()
#define TCollection_Sequence GeomPlate_SequenceOfCurveConstraint
#define TCollection_Sequence_hxx <GeomPlate_SequenceOfCurveConstraint.hxx>

#include <TCollection_SequenceNode.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_SequenceNode_Type_
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx




#endif // _GeomPlate_SequenceNodeOfSequenceOfCurveConstraint_HeaderFile