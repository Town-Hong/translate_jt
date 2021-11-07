// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TopTools_DataMapNodeOfDataMapOfIntegerListOfShape_HeaderFile
#define _TopTools_DataMapNodeOfDataMapOfIntegerListOfShape_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_TopTools_DataMapNodeOfDataMapOfIntegerListOfShape.hxx>

#include <Standard_Integer.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TCollection_MapNode.hxx>
#include <TCollection_MapNodePtr.hxx>
class TopTools_ListOfShape;
class TColStd_MapIntegerHasher;
class TopTools_DataMapOfIntegerListOfShape;
class TopTools_DataMapIteratorOfDataMapOfIntegerListOfShape;



class TopTools_DataMapNodeOfDataMapOfIntegerListOfShape : public TCollection_MapNode
{

public:

  
    TopTools_DataMapNodeOfDataMapOfIntegerListOfShape(const Standard_Integer& K, const TopTools_ListOfShape& I, const TCollection_MapNodePtr& n);
  
      Standard_Integer& Key()  const;
  
      TopTools_ListOfShape& Value()  const;




  DEFINE_STANDARD_RTTI(TopTools_DataMapNodeOfDataMapOfIntegerListOfShape)

protected:




private: 


  Standard_Integer myKey;
  TopTools_ListOfShape myValue;


};

#define TheKey Standard_Integer
#define TheKey_hxx <Standard_Integer.hxx>
#define TheItem TopTools_ListOfShape
#define TheItem_hxx <TopTools_ListOfShape.hxx>
#define Hasher TColStd_MapIntegerHasher
#define Hasher_hxx <TColStd_MapIntegerHasher.hxx>
#define TCollection_DataMapNode TopTools_DataMapNodeOfDataMapOfIntegerListOfShape
#define TCollection_DataMapNode_hxx <TopTools_DataMapNodeOfDataMapOfIntegerListOfShape.hxx>
#define TCollection_DataMapIterator TopTools_DataMapIteratorOfDataMapOfIntegerListOfShape
#define TCollection_DataMapIterator_hxx <TopTools_DataMapIteratorOfDataMapOfIntegerListOfShape.hxx>
#define Handle_TCollection_DataMapNode Handle_TopTools_DataMapNodeOfDataMapOfIntegerListOfShape
#define TCollection_DataMapNode_Type_() TopTools_DataMapNodeOfDataMapOfIntegerListOfShape_Type_()
#define TCollection_DataMap TopTools_DataMapOfIntegerListOfShape
#define TCollection_DataMap_hxx <TopTools_DataMapOfIntegerListOfShape.hxx>

#include <TCollection_DataMapNode.lxx>

#undef TheKey
#undef TheKey_hxx
#undef TheItem
#undef TheItem_hxx
#undef Hasher
#undef Hasher_hxx
#undef TCollection_DataMapNode
#undef TCollection_DataMapNode_hxx
#undef TCollection_DataMapIterator
#undef TCollection_DataMapIterator_hxx
#undef Handle_TCollection_DataMapNode
#undef TCollection_DataMapNode_Type_
#undef TCollection_DataMap
#undef TCollection_DataMap_hxx




#endif // _TopTools_DataMapNodeOfDataMapOfIntegerListOfShape_HeaderFile