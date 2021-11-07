// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepBasic_DocumentReference_HeaderFile
#define _StepBasic_DocumentReference_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepBasic_DocumentReference.hxx>

#include <Handle_StepBasic_Document.hxx>
#include <Handle_TCollection_HAsciiString.hxx>
#include <MMgt_TShared.hxx>
class StepBasic_Document;
class TCollection_HAsciiString;



class StepBasic_DocumentReference : public MMgt_TShared
{

public:

  
  Standard_EXPORT   void Init0 (const Handle(StepBasic_Document)& aAssignedDocument, const Handle(TCollection_HAsciiString)& aSource) ;
  
  Standard_EXPORT   Handle(StepBasic_Document) AssignedDocument()  const;
  
  Standard_EXPORT   void SetAssignedDocument (const Handle(StepBasic_Document)& aAssignedDocument) ;
  
  Standard_EXPORT   Handle(TCollection_HAsciiString) Source()  const;
  
  Standard_EXPORT   void SetSource (const Handle(TCollection_HAsciiString)& aSource) ;




  DEFINE_STANDARD_RTTI(StepBasic_DocumentReference)

protected:




private: 


  Handle(StepBasic_Document) theAssignedDocument;
  Handle(TCollection_HAsciiString) theSource;


};







#endif // _StepBasic_DocumentReference_HeaderFile