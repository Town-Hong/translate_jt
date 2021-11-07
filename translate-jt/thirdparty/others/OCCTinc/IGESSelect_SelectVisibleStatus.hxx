// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESSelect_SelectVisibleStatus_HeaderFile
#define _IGESSelect_SelectVisibleStatus_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_IGESSelect_SelectVisibleStatus.hxx>

#include <IFSelect_SelectExtract.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
#include <Handle_Standard_Transient.hxx>
#include <Handle_Interface_InterfaceModel.hxx>
class Standard_Transient;
class Interface_InterfaceModel;
class TCollection_AsciiString;


//! This selection looks at Blank Status of IGES Entities
//! Direct  selection keeps Visible Entities (Blank = 0),
//! Reverse selection keeps Blanked Entities (Blank = 1)
class IGESSelect_SelectVisibleStatus : public IFSelect_SelectExtract
{

public:

  
  //! Creates a SelectVisibleStatus
  Standard_EXPORT IGESSelect_SelectVisibleStatus();
  
  //! Returns True if <ent> is an IGES Entity with Blank Status = 0
  Standard_EXPORT   Standard_Boolean Sort (const Standard_Integer rank, const Handle(Standard_Transient)& ent, const Handle(Interface_InterfaceModel)& model)  const;
  
  //! Returns the Selection criterium : "IGES Entity, Status Visible"
  Standard_EXPORT   TCollection_AsciiString ExtractLabel()  const;




  DEFINE_STANDARD_RTTI(IGESSelect_SelectVisibleStatus)

protected:




private: 




};







#endif // _IGESSelect_SelectVisibleStatus_HeaderFile