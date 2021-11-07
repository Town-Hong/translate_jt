// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BOPAlgo_BOP_HeaderFile
#define _BOPAlgo_BOP_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <BOPAlgo_Operation.hxx>
#include <Standard_Integer.hxx>
#include <TopoDS_Shape.hxx>
#include <BOPCol_ListOfShape.hxx>
#include <BOPCol_MapOfShape.hxx>
#include <BOPAlgo_Builder.hxx>
#include <BOPCol_BaseAllocator.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_Boolean.hxx>
#include <BOPCol_IndexedDataMapOfShapeListOfShape.hxx>
class TopoDS_Shape;
class TopTools_ListOfShape;
class BOPAlgo_PaveFiller;



class BOPAlgo_BOP  : public BOPAlgo_Builder
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Empty constructor
  Standard_EXPORT BOPAlgo_BOP();
Standard_EXPORT virtual ~BOPAlgo_BOP();
  
  Standard_EXPORT BOPAlgo_BOP(const BOPCol_BaseAllocator& theAllocator);
  
  //! Clears internal fields and arguments
  Standard_EXPORT virtual   void Clear() ;
  
  //! Adds Tool argument of the operation
  Standard_EXPORT virtual   void AddTool (const TopoDS_Shape& theShape) ;
  
  Standard_EXPORT virtual   void SetTools (const TopTools_ListOfShape& theShapes) ;
  
  Standard_EXPORT virtual   void SetTools (const BOPCol_ListOfShape& theShapes) ;
  
  Standard_EXPORT   void SetOperation (const BOPAlgo_Operation theOperation) ;
  
  Standard_EXPORT   BOPAlgo_Operation Operation()  const;
  
  Standard_EXPORT virtual   void Perform() ;




protected:

  
  Standard_EXPORT virtual   void CheckData() ;
  
  //! Provides preparing actions
  Standard_EXPORT virtual   void Prepare() ;
  
  //! Performs calculations using prepared Filler
  //! object <thePF>
  Standard_EXPORT virtual   void PerformInternal1 (const BOPAlgo_PaveFiller& thePF) ;
  
  Standard_EXPORT virtual   void BuildResult (const TopAbs_ShapeEnum theType) ;
  
  Standard_EXPORT   void BuildShape() ;
  
  Standard_EXPORT   void BuildRC() ;
  
  Standard_EXPORT   void BuildSolid() ;
  
  Standard_EXPORT   Standard_Boolean IsBoundSplits (const TopoDS_Shape& theS, BOPCol_IndexedDataMapOfShapeListOfShape& theMEF) ;


  BOPAlgo_Operation myOperation;
  Standard_Integer myDims[2];
  TopoDS_Shape myRC;
  BOPCol_ListOfShape myTools;
  BOPCol_MapOfShape myMapTools;


private:





};







#endif // _BOPAlgo_BOP_HeaderFile