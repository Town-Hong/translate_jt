// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _AIS_SequenceNodeOfSequenceOfInteractive_HeaderFile
#define _AIS_SequenceNodeOfSequenceOfInteractive_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_AIS_SequenceNodeOfSequenceOfInteractive.hxx>

#include <Handle_AIS_InteractiveObject.hxx>
#include <TCollection_SeqNode.hxx>
#include <TCollection_SeqNodePtr.hxx>
class AIS_InteractiveObject;
class AIS_SequenceOfInteractive;



class AIS_SequenceNodeOfSequenceOfInteractive : public TCollection_SeqNode
{

public:

  
    AIS_SequenceNodeOfSequenceOfInteractive(const Handle(AIS_InteractiveObject)& I, const TCollection_SeqNodePtr& n, const TCollection_SeqNodePtr& p);
  
      Handle(AIS_InteractiveObject)& Value()  const;




  DEFINE_STANDARD_RTTI(AIS_SequenceNodeOfSequenceOfInteractive)

protected:




private: 


  Handle(AIS_InteractiveObject) myValue;


};

#define SeqItem Handle(AIS_InteractiveObject)
#define SeqItem_hxx <AIS_InteractiveObject.hxx>
#define TCollection_SequenceNode AIS_SequenceNodeOfSequenceOfInteractive
#define TCollection_SequenceNode_hxx <AIS_SequenceNodeOfSequenceOfInteractive.hxx>
#define Handle_TCollection_SequenceNode Handle_AIS_SequenceNodeOfSequenceOfInteractive
#define TCollection_SequenceNode_Type_() AIS_SequenceNodeOfSequenceOfInteractive_Type_()
#define TCollection_Sequence AIS_SequenceOfInteractive
#define TCollection_Sequence_hxx <AIS_SequenceOfInteractive.hxx>

#include <TCollection_SequenceNode.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_SequenceNode_Type_
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx




#endif // _AIS_SequenceNodeOfSequenceOfInteractive_HeaderFile
