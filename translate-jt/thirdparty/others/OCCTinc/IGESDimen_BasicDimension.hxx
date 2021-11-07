// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESDimen_BasicDimension_HeaderFile
#define _IGESDimen_BasicDimension_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_IGESDimen_BasicDimension.hxx>

#include <Standard_Integer.hxx>
#include <gp_XY.hxx>
#include <IGESData_IGESEntity.hxx>
class gp_XY;
class gp_Pnt2d;


//! Defines IGES Basic Dimension, Type 406, Form 31,
//! in package IGESDimen
//! The basic Dimension Property indicates that the referencing
//! dimension entity is to be displayed with a box around text.
class IGESDimen_BasicDimension : public IGESData_IGESEntity
{

public:

  
  Standard_EXPORT IGESDimen_BasicDimension();
  
  Standard_EXPORT   void Init (const Standard_Integer nbPropVal, const gp_XY& lowerLeft, const gp_XY& lowerRight, const gp_XY& upperRight, const gp_XY& upperLeft) ;
  
  //! returns the number of properties = 8
  Standard_EXPORT   Standard_Integer NbPropertyValues()  const;
  
  //! returns coordinates of lower left corner
  Standard_EXPORT   gp_Pnt2d LowerLeft()  const;
  
  //! returns coordinates of lower right corner
  Standard_EXPORT   gp_Pnt2d LowerRight()  const;
  
  //! returns coordinates of upper right corner
  Standard_EXPORT   gp_Pnt2d UpperRight()  const;
  
  //! returns coordinates of upper left corner
  Standard_EXPORT   gp_Pnt2d UpperLeft()  const;




  DEFINE_STANDARD_RTTI(IGESDimen_BasicDimension)

protected:




private: 


  Standard_Integer theNbPropertyValues;
  gp_XY theLowerLeft;
  gp_XY theLowerRight;
  gp_XY theUpperRight;
  gp_XY theUpperLeft;


};







#endif // _IGESDimen_BasicDimension_HeaderFile