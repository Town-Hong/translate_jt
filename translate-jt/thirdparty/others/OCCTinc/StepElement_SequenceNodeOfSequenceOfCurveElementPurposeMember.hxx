// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepElement_SequenceNodeOfSequenceOfCurveElementPurposeMember_HeaderFile
#define _StepElement_SequenceNodeOfSequenceOfCurveElementPurposeMember_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepElement_SequenceNodeOfSequenceOfCurveElementPurposeMember.hxx>

#include <Handle_StepElement_CurveElementPurposeMember.hxx>
#include <TCollection_SeqNode.hxx>
#include <TCollection_SeqNodePtr.hxx>
class StepElement_CurveElementPurposeMember;
class StepElement_SequenceOfCurveElementPurposeMember;



class StepElement_SequenceNodeOfSequenceOfCurveElementPurposeMember : public TCollection_SeqNode
{

public:

  
    StepElement_SequenceNodeOfSequenceOfCurveElementPurposeMember(const Handle(StepElement_CurveElementPurposeMember)& I, const TCollection_SeqNodePtr& n, const TCollection_SeqNodePtr& p);
  
      Handle(StepElement_CurveElementPurposeMember)& Value()  const;




  DEFINE_STANDARD_RTTI(StepElement_SequenceNodeOfSequenceOfCurveElementPurposeMember)

protected:




private: 


  Handle(StepElement_CurveElementPurposeMember) myValue;


};

#define SeqItem Handle(StepElement_CurveElementPurposeMember)
#define SeqItem_hxx <StepElement_CurveElementPurposeMember.hxx>
#define TCollection_SequenceNode StepElement_SequenceNodeOfSequenceOfCurveElementPurposeMember
#define TCollection_SequenceNode_hxx <StepElement_SequenceNodeOfSequenceOfCurveElementPurposeMember.hxx>
#define Handle_TCollection_SequenceNode Handle_StepElement_SequenceNodeOfSequenceOfCurveElementPurposeMember
#define TCollection_SequenceNode_Type_() StepElement_SequenceNodeOfSequenceOfCurveElementPurposeMember_Type_()
#define TCollection_Sequence StepElement_SequenceOfCurveElementPurposeMember
#define TCollection_Sequence_hxx <StepElement_SequenceOfCurveElementPurposeMember.hxx>

#include <TCollection_SequenceNode.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_SequenceNode_Type_
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx




#endif // _StepElement_SequenceNodeOfSequenceOfCurveElementPurposeMember_HeaderFile
