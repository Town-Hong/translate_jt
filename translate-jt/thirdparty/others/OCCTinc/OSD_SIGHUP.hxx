// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _OSD_SIGHUP_HeaderFile
#define _OSD_SIGHUP_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard_DefineException.hxx>
#include <Standard_SStream.hxx>
#include <OSD_Signal.hxx>
#include <Handle_OSD_SIGHUP.hxx>

#if !defined No_Exception && !defined No_OSD_SIGHUP
  #define OSD_SIGHUP_Raise_if(CONDITION, MESSAGE) \
  if (CONDITION) OSD_SIGHUP::Raise(MESSAGE);
#else
  #define OSD_SIGHUP_Raise_if(CONDITION, MESSAGE)
#endif

DEFINE_STANDARD_EXCEPTION(OSD_SIGHUP, OSD_Signal)

#endif // _OSD_SIGHUP_HeaderFile
