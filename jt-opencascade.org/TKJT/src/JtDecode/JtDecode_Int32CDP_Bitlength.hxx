// JT format reading and visualization tools
// Copyright (C) 2014-2015 OPEN CASCADE SAS
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2 of the License, or any later
// version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// Copy of the GNU General Public License is in LICENSE.txt and  
// on <http://www.gnu.org/licenses/>.

#ifndef _JtDecode_Int32CDP_Bitlength_HeaderFile
#define _JtDecode_Int32CDP_Bitlength_HeaderFile

#include <JtDecode_Int32CDP_Bits.hxx>

//! Bitlength mark 1 decoder.
class JtDecode_Int32CDP_Bitlength : public JtDecode_Int32CDP_Bits
{
public:

  //! Initialize the bitlength dedoder by reader.
  JtDecode_Int32CDP_Bitlength (JtData_Reader& theReader) : JtDecode_Int32CDP_Bits (theReader) {}

protected:

  //! Decode the data.
  Standard_EXPORT virtual void decode (int32_t* theResultPtr, int32_t* theResultEnd);

  static const int STEP_SIZE = 2;
};

#endif
