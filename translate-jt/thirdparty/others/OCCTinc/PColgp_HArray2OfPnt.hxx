// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _PColgp_HArray2OfPnt_HeaderFile
#define _PColgp_HArray2OfPnt_HeaderFile

#include <Standard_Macro.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard.hxx>
#include <Handle_PColgp_HArray2OfPnt.hxx>

#include <Standard_Integer.hxx>
#include <gp_Pnt.hxx>
#include <PColgp_FieldOfHArray2OfPnt.hxx>
#include <Standard_Address.hxx>
#include <Standard_Persistent.hxx>
#include <Handle_PColgp_VArrayNodeOfFieldOfHArray2OfPnt.hxx>
class Standard_RangeError;
class Standard_OutOfRange;
class gp_Pnt;
class PColgp_FieldOfHArray2OfPnt;
class PColgp_VArrayNodeOfFieldOfHArray2OfPnt;
class PColgp_VArrayTNodeOfFieldOfHArray2OfPnt;


class PColgp_HArray2OfPnt : public Standard_Persistent
{

public:

  
  Standard_EXPORT PColgp_HArray2OfPnt(const Standard_Integer R1, const Standard_Integer R2, const Standard_Integer C1, const Standard_Integer C2);
  
  Standard_EXPORT PColgp_HArray2OfPnt(const Standard_Integer R1, const Standard_Integer R2, const Standard_Integer C1, const Standard_Integer C2, const gp_Pnt& V);
  
  Standard_EXPORT   Standard_Integer ColLength()  const;
  
      Standard_Integer LowerCol()  const;
  
      Standard_Integer LowerRow()  const;
  
  Standard_EXPORT   Standard_Integer RowLength()  const;
  
  Standard_EXPORT   void SetValue (const Standard_Integer Row, const Standard_Integer Col, const gp_Pnt& Value) ;
  
      Standard_Integer UpperCol()  const;
  
      Standard_Integer UpperRow()  const;
  
  Standard_EXPORT   gp_Pnt Value (const Standard_Integer Row, const Standard_Integer Col)  const;

PColgp_HArray2OfPnt( )
{
  
}
PColgp_HArray2OfPnt(const Storage_stCONSTclCOM& a) : Standard_Persistent(a)
{
  
}
    Standard_Integer _CSFDB_GetPColgp_HArray2OfPntmyLowerRow() const { return myLowerRow; }
    void _CSFDB_SetPColgp_HArray2OfPntmyLowerRow(const Standard_Integer p) { myLowerRow = p; }
    Standard_Integer _CSFDB_GetPColgp_HArray2OfPntmyLowerCol() const { return myLowerCol; }
    void _CSFDB_SetPColgp_HArray2OfPntmyLowerCol(const Standard_Integer p) { myLowerCol = p; }
    Standard_Integer _CSFDB_GetPColgp_HArray2OfPntmyUpperRow() const { return myUpperRow; }
    void _CSFDB_SetPColgp_HArray2OfPntmyUpperRow(const Standard_Integer p) { myUpperRow = p; }
    Standard_Integer _CSFDB_GetPColgp_HArray2OfPntmyUpperCol() const { return myUpperCol; }
    void _CSFDB_SetPColgp_HArray2OfPntmyUpperCol(const Standard_Integer p) { myUpperCol = p; }
    const PColgp_FieldOfHArray2OfPnt& _CSFDB_GetPColgp_HArray2OfPntData() const { return Data; }



  DEFINE_STANDARD_RTTI(PColgp_HArray2OfPnt)

protected:




private: 

  
  Standard_EXPORT   PColgp_FieldOfHArray2OfPnt Field()  const;
  
  Standard_EXPORT   Standard_Address Datas()  const;

  Standard_Integer myLowerRow;
  Standard_Integer myLowerCol;
  Standard_Integer myUpperRow;
  Standard_Integer myUpperCol;
  PColgp_FieldOfHArray2OfPnt Data;


};

#define Item gp_Pnt
#define Item_hxx <gp_Pnt.hxx>
#define PCollection_FieldOfHArray2 PColgp_FieldOfHArray2OfPnt
#define PCollection_FieldOfHArray2_hxx <PColgp_FieldOfHArray2OfPnt.hxx>
#define PCollection_VArrayNodeOfFieldOfHArray2 PColgp_VArrayNodeOfFieldOfHArray2OfPnt
#define PCollection_VArrayNodeOfFieldOfHArray2_hxx <PColgp_VArrayNodeOfFieldOfHArray2OfPnt.hxx>
#define PCollection_VArrayTNodeOfFieldOfHArray2 PColgp_VArrayTNodeOfFieldOfHArray2OfPnt
#define PCollection_VArrayTNodeOfFieldOfHArray2_hxx <PColgp_VArrayTNodeOfFieldOfHArray2OfPnt.hxx>
#define PCollection_VArrayNodeOfFieldOfHArray2 PColgp_VArrayNodeOfFieldOfHArray2OfPnt
#define PCollection_VArrayNodeOfFieldOfHArray2_hxx <PColgp_VArrayNodeOfFieldOfHArray2OfPnt.hxx>
#define PCollection_VArrayTNodeOfFieldOfHArray2 PColgp_VArrayTNodeOfFieldOfHArray2OfPnt
#define PCollection_VArrayTNodeOfFieldOfHArray2_hxx <PColgp_VArrayTNodeOfFieldOfHArray2OfPnt.hxx>
#define Handle_PCollection_VArrayNodeOfFieldOfHArray2 Handle_PColgp_VArrayNodeOfFieldOfHArray2OfPnt
#define PCollection_VArrayNodeOfFieldOfHArray2_Type_() PColgp_VArrayNodeOfFieldOfHArray2OfPnt_Type_()
#define Handle_PCollection_VArrayNodeOfFieldOfHArray2 Handle_PColgp_VArrayNodeOfFieldOfHArray2OfPnt
#define PCollection_VArrayNodeOfFieldOfHArray2_Type_() PColgp_VArrayNodeOfFieldOfHArray2OfPnt_Type_()
#define PCollection_HArray2 PColgp_HArray2OfPnt
#define PCollection_HArray2_hxx <PColgp_HArray2OfPnt.hxx>
#define Handle_PCollection_HArray2 Handle_PColgp_HArray2OfPnt
#define PCollection_HArray2_Type_() PColgp_HArray2OfPnt_Type_()

#include <PCollection_HArray2.lxx>

#undef Item
#undef Item_hxx
#undef PCollection_FieldOfHArray2
#undef PCollection_FieldOfHArray2_hxx
#undef PCollection_VArrayNodeOfFieldOfHArray2
#undef PCollection_VArrayNodeOfFieldOfHArray2_hxx
#undef PCollection_VArrayTNodeOfFieldOfHArray2
#undef PCollection_VArrayTNodeOfFieldOfHArray2_hxx
#undef PCollection_VArrayNodeOfFieldOfHArray2
#undef PCollection_VArrayNodeOfFieldOfHArray2_hxx
#undef PCollection_VArrayTNodeOfFieldOfHArray2
#undef PCollection_VArrayTNodeOfFieldOfHArray2_hxx
#undef Handle_PCollection_VArrayNodeOfFieldOfHArray2
#undef PCollection_VArrayNodeOfFieldOfHArray2_Type_
#undef Handle_PCollection_VArrayNodeOfFieldOfHArray2
#undef PCollection_VArrayNodeOfFieldOfHArray2_Type_
#undef PCollection_HArray2
#undef PCollection_HArray2_hxx
#undef Handle_PCollection_HArray2
#undef PCollection_HArray2_Type_




#endif // _PColgp_HArray2OfPnt_HeaderFile
