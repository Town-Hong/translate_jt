// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepFEA_SequenceNodeOfSequenceOfElementRepresentation_HeaderFile
#define _StepFEA_SequenceNodeOfSequenceOfElementRepresentation_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepFEA_SequenceNodeOfSequenceOfElementRepresentation.hxx>

#include <Handle_StepFEA_ElementRepresentation.hxx>
#include <TCollection_SeqNode.hxx>
#include <TCollection_SeqNodePtr.hxx>
class StepFEA_ElementRepresentation;
class StepFEA_SequenceOfElementRepresentation;



class StepFEA_SequenceNodeOfSequenceOfElementRepresentation : public TCollection_SeqNode
{

public:

  
    StepFEA_SequenceNodeOfSequenceOfElementRepresentation(const Handle(StepFEA_ElementRepresentation)& I, const TCollection_SeqNodePtr& n, const TCollection_SeqNodePtr& p);
  
      Handle(StepFEA_ElementRepresentation)& Value()  const;




  DEFINE_STANDARD_RTTI(StepFEA_SequenceNodeOfSequenceOfElementRepresentation)

protected:




private: 


  Handle(StepFEA_ElementRepresentation) myValue;


};

#define SeqItem Handle(StepFEA_ElementRepresentation)
#define SeqItem_hxx <StepFEA_ElementRepresentation.hxx>
#define TCollection_SequenceNode StepFEA_SequenceNodeOfSequenceOfElementRepresentation
#define TCollection_SequenceNode_hxx <StepFEA_SequenceNodeOfSequenceOfElementRepresentation.hxx>
#define Handle_TCollection_SequenceNode Handle_StepFEA_SequenceNodeOfSequenceOfElementRepresentation
#define TCollection_SequenceNode_Type_() StepFEA_SequenceNodeOfSequenceOfElementRepresentation_Type_()
#define TCollection_Sequence StepFEA_SequenceOfElementRepresentation
#define TCollection_Sequence_hxx <StepFEA_SequenceOfElementRepresentation.hxx>

#include <TCollection_SequenceNode.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_SequenceNode_Type_
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx




#endif // _StepFEA_SequenceNodeOfSequenceOfElementRepresentation_HeaderFile