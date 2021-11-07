// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _MAT_SequenceNodeOfSequenceOfArc_HeaderFile
#define _MAT_SequenceNodeOfSequenceOfArc_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_MAT_SequenceNodeOfSequenceOfArc.hxx>

#include <Handle_MAT_Arc.hxx>
#include <TCollection_SeqNode.hxx>
#include <TCollection_SeqNodePtr.hxx>
class MAT_Arc;
class MAT_SequenceOfArc;



class MAT_SequenceNodeOfSequenceOfArc : public TCollection_SeqNode
{

public:

  
    MAT_SequenceNodeOfSequenceOfArc(const Handle(MAT_Arc)& I, const TCollection_SeqNodePtr& n, const TCollection_SeqNodePtr& p);
  
      Handle(MAT_Arc)& Value()  const;




  DEFINE_STANDARD_RTTI(MAT_SequenceNodeOfSequenceOfArc)

protected:




private: 


  Handle(MAT_Arc) myValue;


};

#define SeqItem Handle(MAT_Arc)
#define SeqItem_hxx <MAT_Arc.hxx>
#define TCollection_SequenceNode MAT_SequenceNodeOfSequenceOfArc
#define TCollection_SequenceNode_hxx <MAT_SequenceNodeOfSequenceOfArc.hxx>
#define Handle_TCollection_SequenceNode Handle_MAT_SequenceNodeOfSequenceOfArc
#define TCollection_SequenceNode_Type_() MAT_SequenceNodeOfSequenceOfArc_Type_()
#define TCollection_Sequence MAT_SequenceOfArc
#define TCollection_Sequence_hxx <MAT_SequenceOfArc.hxx>

#include <TCollection_SequenceNode.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_SequenceNode_Type_
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx




#endif // _MAT_SequenceNodeOfSequenceOfArc_HeaderFile
