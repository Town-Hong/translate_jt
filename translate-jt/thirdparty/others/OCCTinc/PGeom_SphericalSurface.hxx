// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _PGeom_SphericalSurface_HeaderFile
#define _PGeom_SphericalSurface_HeaderFile

#include <Standard_Macro.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard.hxx>
#include <Handle_PGeom_SphericalSurface.hxx>

#include <Standard_Real.hxx>
#include <PGeom_ElementarySurface.hxx>
class gp_Ax3;


class PGeom_SphericalSurface : public PGeom_ElementarySurface
{

public:

  
  //! Creates a SphericalSurface with default values.
  Standard_EXPORT PGeom_SphericalSurface();
  
  //! Creates a SphericalSurface with these values.
  Standard_EXPORT PGeom_SphericalSurface(const gp_Ax3& aPosition, const Standard_Real aRadius);
  
  //! Set the field radius with <aRadius>.
  Standard_EXPORT   void Radius (const Standard_Real aRadius) ;
  
  //! Returns the value of the field radius.
  Standard_EXPORT   Standard_Real Radius()  const;

PGeom_SphericalSurface(const Storage_stCONSTclCOM& a) : PGeom_ElementarySurface(a)
{
  
}
    Standard_Real _CSFDB_GetPGeom_SphericalSurfaceradius() const { return radius; }
    void _CSFDB_SetPGeom_SphericalSurfaceradius(const Standard_Real p) { radius = p; }



  DEFINE_STANDARD_RTTI(PGeom_SphericalSurface)

protected:




private: 


  Standard_Real radius;


};







#endif // _PGeom_SphericalSurface_HeaderFile
