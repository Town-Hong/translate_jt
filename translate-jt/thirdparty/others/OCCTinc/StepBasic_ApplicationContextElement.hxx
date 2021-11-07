// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepBasic_ApplicationContextElement_HeaderFile
#define _StepBasic_ApplicationContextElement_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepBasic_ApplicationContextElement.hxx>

#include <Handle_TCollection_HAsciiString.hxx>
#include <Handle_StepBasic_ApplicationContext.hxx>
#include <MMgt_TShared.hxx>
class TCollection_HAsciiString;
class StepBasic_ApplicationContext;



class StepBasic_ApplicationContextElement : public MMgt_TShared
{

public:

  
  //! Returns a ApplicationContextElement
  Standard_EXPORT StepBasic_ApplicationContextElement();
  
  Standard_EXPORT virtual   void Init (const Handle(TCollection_HAsciiString)& aName, const Handle(StepBasic_ApplicationContext)& aFrameOfReference) ;
  
  Standard_EXPORT   void SetName (const Handle(TCollection_HAsciiString)& aName) ;
  
  Standard_EXPORT   Handle(TCollection_HAsciiString) Name()  const;
  
  Standard_EXPORT   void SetFrameOfReference (const Handle(StepBasic_ApplicationContext)& aFrameOfReference) ;
  
  Standard_EXPORT   Handle(StepBasic_ApplicationContext) FrameOfReference()  const;




  DEFINE_STANDARD_RTTI(StepBasic_ApplicationContextElement)

protected:




private: 


  Handle(TCollection_HAsciiString) name;
  Handle(StepBasic_ApplicationContext) frameOfReference;


};







#endif // _StepBasic_ApplicationContextElement_HeaderFile
