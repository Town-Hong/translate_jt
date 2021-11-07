// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IntPatch_ALineToWLine_HeaderFile
#define _IntPatch_ALineToWLine_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <IntSurf_Quadric.hxx>
#include <Standard_Real.hxx>
#include <Standard_Integer.hxx>
#include <Handle_IntPatch_WLine.hxx>
#include <Handle_IntPatch_ALine.hxx>
class IntSurf_Quadric;
class IntPatch_WLine;
class IntPatch_ALine;



class IntPatch_ALineToWLine 
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT IntPatch_ALineToWLine(const IntSurf_Quadric& Quad1, const IntSurf_Quadric& Quad2);
  
  Standard_EXPORT IntPatch_ALineToWLine(const IntSurf_Quadric& Quad1, const IntSurf_Quadric& Quad2, const Standard_Real Deflection, const Standard_Real PasMaxUV, const Standard_Integer NbMaxPoints);
  
  Standard_EXPORT   void SetTolParam (const Standard_Real aT) ;
  
  Standard_EXPORT   Standard_Real TolParam()  const;
  
  Standard_EXPORT   void SetTolOpenDomain (const Standard_Real aT) ;
  
  Standard_EXPORT   Standard_Real TolOpenDomain()  const;
  
  Standard_EXPORT   void SetTolTransition (const Standard_Real aT) ;
  
  Standard_EXPORT   Standard_Real TolTransition()  const;
  
  Standard_EXPORT   void SetTol3D (const Standard_Real aT) ;
  
  Standard_EXPORT   Standard_Real Tol3D()  const;
  
  Standard_EXPORT   void SetConstantParameter()  const;
  
  Standard_EXPORT   void SetUniformAbscissa()  const;
  
  Standard_EXPORT   void SetUniformDeflection()  const;
  
  Standard_EXPORT   Handle(IntPatch_WLine) MakeWLine (const Handle(IntPatch_ALine)& aline)  const;
  
  Standard_EXPORT   Handle(IntPatch_WLine) MakeWLine (const Handle(IntPatch_ALine)& aline, const Standard_Real paraminf, const Standard_Real paramsup)  const;




protected:





private:



  IntSurf_Quadric quad1;
  IntSurf_Quadric quad2;
  Standard_Real deflectionmax;
  Standard_Integer nbpointsmax;
  Standard_Integer type;
  Standard_Real myTolParam;
  Standard_Real myTolOpenDomain;
  Standard_Real myTolTransition;
  Standard_Real myTol3D;


};







#endif // _IntPatch_ALineToWLine_HeaderFile