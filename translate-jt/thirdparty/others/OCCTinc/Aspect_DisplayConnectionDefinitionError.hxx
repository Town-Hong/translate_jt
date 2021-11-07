// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Aspect_DisplayConnectionDefinitionError_HeaderFile
#define _Aspect_DisplayConnectionDefinitionError_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_DefineException.hxx>
#include <Standard_SStream.hxx>
#include <Standard_OutOfRange.hxx>
#include <Handle_Aspect_DisplayConnectionDefinitionError.hxx>

#if !defined No_Exception && !defined No_Aspect_DisplayConnectionDefinitionError
  #define Aspect_DisplayConnectionDefinitionError_Raise_if(CONDITION, MESSAGE) \
  if (CONDITION) Aspect_DisplayConnectionDefinitionError::Raise(MESSAGE);
#else
  #define Aspect_DisplayConnectionDefinitionError_Raise_if(CONDITION, MESSAGE)
#endif

DEFINE_STANDARD_EXCEPTION(Aspect_DisplayConnectionDefinitionError, Standard_OutOfRange)

#endif // _Aspect_DisplayConnectionDefinitionError_HeaderFile