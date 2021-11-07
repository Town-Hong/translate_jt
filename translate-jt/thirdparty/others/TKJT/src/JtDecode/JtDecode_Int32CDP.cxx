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

#include <JtDecode_Int32CDP.hxx>

#include <JtDecode_BitReader.hxx>
#include <JtDecode_ProbContext.hxx>

#include <JtDecode_Int32CDP_Null.hxx>
#include <JtDecode_Int32CDP_Bitlength.hxx>
#include <JtDecode_Int32CDP_Bitlength2.hxx>
#include <JtDecode_Int32CDP_Huffman.hxx>
#include <JtDecode_Int32CDP_Arithmetic.hxx>
#include <JtDecode_Int32CDP_Chopper.hxx>

#include <JtData_Message.hxx>

JtDecode_Int32CDP::EncodedDataHandle JtDecode_Int32CDP::loadCDP1 (JtData_Reader& theReader)
{
  // Read codec type
  Standard_Integer aCodec;
  if (!theReader.ReadU8 (aCodec))
    return EncodedDataHandle();

  // Null codec, just read uncoded values
  if (aCodec == 0)
  {
    Jt_VecU32 aCodeText;
    if (!theReader.ReadVec (aCodeText))
      return EncodedDataHandle();

    return EncodedDataHandle (new JtDecode_Int32CDP_Null (aCodeText.Move()));
  }

  // Bits based codec
  JtData_SingleHandle<JtDecode_Int32CDP_Bits> aData;
  switch (aCodec)
  {
  case 1:
    aData = new JtDecode_Int32CDP_Bitlength  (theReader);
    break;
  case 2:
    aData = new JtDecode_Int32CDP_Huffman    (theReader);
    break;
  case 3:
    aData = new JtDecode_Int32CDP_Arithmetic (theReader);
    break;
  default:
    TRACE ("Unknown Codec (" + aCodec + ")!");
    return EncodedDataHandle();
  }

  // Huffman or arithmetic codec: read probability contexts and load OOB data
  Standard_Integer aProbContextTableCount = 0;
  if (aCodec >= 2)
  {
    // read probability contexts
    if (!theReader.ReadU8 (aProbContextTableCount))
      return EncodedDataHandle();

    JtData_Vector<JtDecode_ProbContextI32> aProbContexts (aProbContextTableCount);
    {
      JtDecode_BitReader::Raw aContextReader (theReader);

      if (!aProbContexts[0].ReadFirst (aContextReader))
        return EncodedDataHandle();

      for (Standard_Integer i = 1; i < aProbContextTableCount; i++)
        if (!aProbContexts[i].ReadNext (aContextReader, aProbContexts[0]))
          return EncodedDataHandle();
    }
    aData->SetProbContexts (aProbContexts.Move());

    // load out-of-band data
    Jt_I32 anOutOfBandValueCount;
    theReader.ReadI32 (anOutOfBandValueCount);
    if (anOutOfBandValueCount > 0)
    {
      JtDecode_Int32CDP anOOBData;
      if (!anOOBData.Load1 (theReader))
        return EncodedDataHandle();
      aData->SetOOBData (anOOBData);
    }
  }

  // Read CodeText length and number of output values
  Jt_I32 aCodeTextLength;
  Jt_I32 aValueCount;
  if (!theReader.ReadI32 (aCodeTextLength)
   || !theReader.ReadI32 (aValueCount))
  {
    return EncodedDataHandle();
  }
  aData->SetOutValCount (aValueCount);

  // Read symbol count if present
  if (aProbContextTableCount > 1)
  {
    Jt_I32 aSymbolCount;
    if (!theReader.ReadI32 (aSymbolCount))
      return EncodedDataHandle();
  }

  // Read CodeText data
  if (!aData->LoadVec())
    return EncodedDataHandle();

  return EncodedDataHandle (aData);
}

JtDecode_Int32CDP::EncodedDataHandle JtDecode_Int32CDP::loadCDP2 (JtData_Reader& theReader)
{
  // Read number of output values
  Jt_I32 aValueCount;
  if (!theReader.ReadI32 (aValueCount))
    return EncodedDataHandle();

  if (aValueCount == 0)
    return EncodedDataHandle (new JtDecode_Int32CDP_Null (Jt_VecU32().Move()));

  // Read codec type
  Standard_Integer aCodec;
  if (!theReader.ReadU8 (aCodec))
    return EncodedDataHandle();

  // Chopper pseudo-codec
  if (aCodec == 4)
  {
    Jt_U8 aChop;
    if (!theReader.ReadU8 (aChop))
      return EncodedDataHandle();

    if (aChop == 0)
      return loadCDP2 (theReader);

    Jt_I32 aBias;
    Jt_U8  aSpan;
    if (!theReader.ReadI32 (aBias)
     || !theReader.ReadU8  (aSpan))
      return EncodedDataHandle();

    // load chopped MSB and LSB data
    JtDecode_Int32CDP aMSBData;
    JtDecode_Int32CDP aLSBData;
    if (!aMSBData.Load2 (theReader)
     || !aLSBData.Load2 (theReader))
      return EncodedDataHandle();

    if (aMSBData.GetOutValCount() != aValueCount
     || aLSBData.GetOutValCount() != aValueCount)
    {
      ALARM ("Error: Chopped data size mismatch");
      return EncodedDataHandle();
    }

    return EncodedDataHandle (
      new JtDecode_Int32CDP_Chopper (aMSBData, aLSBData, aChop, aSpan, aBias));
  }

  // Null, bitlength or arithmetic codec: read CodeText length
  Jt_I32 aCodeTextLength;
  if (!theReader.ReadI32 (aCodeTextLength) || aCodeTextLength <= 0)
    return EncodedDataHandle();

  // Null codec
  if (aCodec == 0)
  {
    Jt_VecU32 aCodeText;
    if (!theReader.ReadVec (aCodeText, (aCodeTextLength + 31) / 32))
      return EncodedDataHandle();

    return EncodedDataHandle (new JtDecode_Int32CDP_Null (aCodeText.Move()));
  }

  // Bits based codec
  JtData_SingleHandle<JtDecode_Int32CDP_Bits> aData;
  switch (aCodec)
  {
  case 1: // Bitlength codec
    aData = new JtDecode_Int32CDP_Bitlength2 (theReader);
    break;

  case 3: // Arithmetic codec
    aData = new JtDecode_Int32CDP_Arithmetic (theReader);
    break;

  default: // Unknown codec
    TRACE ("Unknown Codec (" + aCodec + ")!");
    return EncodedDataHandle();
  }

  // Bitlength or arithmetic codec: set expected output values count
  aData->SetOutValCount (aValueCount);

  // Bitlength or arithmetic codec: read CodeText data
  if (!aData->Load ((aCodeTextLength + 31) / 32))
    return EncodedDataHandle();

  // Arithmetic codec: read probability context and load OOB data
  if (aCodec == 3)
  {
    // read probability context
    JtData_Vector<JtDecode_ProbContextI32> aProbContexts (1);
    {
      JtDecode_BitReader::Raw aContextReader (theReader);
      if (!aProbContexts[0].ReadMk2 (aContextReader))
        return EncodedDataHandle();
    }
    aData->SetProbContexts (aProbContexts.Move());

    // load out-of-band data
    JtDecode_Int32CDP anOOBData;
    if (!anOOBData.Load2 (theReader))
      return EncodedDataHandle();

    aData->SetOOBData (anOOBData);
  }

  return EncodedDataHandle (aData);
}
