// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IntSurf_SequenceNodeOfSequenceOfPathPoint_HeaderFile
#define _IntSurf_SequenceNodeOfSequenceOfPathPoint_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_IntSurf_SequenceNodeOfSequenceOfPathPoint.hxx>

#include <IntSurf_PathPoint.hxx>
#include <TCollection_SeqNode.hxx>
#include <TCollection_SeqNodePtr.hxx>
class IntSurf_PathPoint;
class IntSurf_SequenceOfPathPoint;



class IntSurf_SequenceNodeOfSequenceOfPathPoint : public TCollection_SeqNode
{

public:

  
    IntSurf_SequenceNodeOfSequenceOfPathPoint(const IntSurf_PathPoint& I, const TCollection_SeqNodePtr& n, const TCollection_SeqNodePtr& p);
  
      IntSurf_PathPoint& Value()  const;




  DEFINE_STANDARD_RTTI(IntSurf_SequenceNodeOfSequenceOfPathPoint)

protected:




private: 


  IntSurf_PathPoint myValue;


};

#define SeqItem IntSurf_PathPoint
#define SeqItem_hxx <IntSurf_PathPoint.hxx>
#define TCollection_SequenceNode IntSurf_SequenceNodeOfSequenceOfPathPoint
#define TCollection_SequenceNode_hxx <IntSurf_SequenceNodeOfSequenceOfPathPoint.hxx>
#define Handle_TCollection_SequenceNode Handle_IntSurf_SequenceNodeOfSequenceOfPathPoint
#define TCollection_SequenceNode_Type_() IntSurf_SequenceNodeOfSequenceOfPathPoint_Type_()
#define TCollection_Sequence IntSurf_SequenceOfPathPoint
#define TCollection_Sequence_hxx <IntSurf_SequenceOfPathPoint.hxx>

#include <TCollection_SequenceNode.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_SequenceNode_Type_
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx




#endif // _IntSurf_SequenceNodeOfSequenceOfPathPoint_HeaderFile