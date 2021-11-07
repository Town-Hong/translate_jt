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

#include <JtDecode_VertexData.hxx>

#include <JtDecode_VertexData_Quantized.hxx>
#include <JtDecode_VertexData_ExpMant.hxx>
#include <JtDecode_VertexData_Deering.hxx>

JtDecode_VertexData::Handle JtDecode_VertexData::LoadQuantizedCoords (JtData_Reader& theReader)
{
  // Read parameters
  JtDecode_VertexData_Quantized::PointQuantizerData aQuantizerData;
  Jt_I32 aVertexCount;
  if (!aQuantizerData.Read (theReader)
   || !theReader.ReadI32 (aVertexCount))
    return (Handle)0;

  // Create decoder object
  Handle aData (new JtDecode_VertexData_Quantized (aQuantizerData, 3, JtDecode_Unpack_Lag1));

  // Load encoded data
  if (!aData->load (theReader, &JtDecode_Int32CDP::Load1, aVertexCount))
    return (Handle)0;

  // Success
  return aData;
}

JtDecode_VertexData::Handle JtDecode_VertexData::LoadCompressedCoords (JtData_Reader& theReader)
{
  // Read parameters
  Jt_I32 aVertexCount;
  Jt_U8 aNbComponents;
  if (!theReader.ReadI32 (aVertexCount)
   || !theReader.ReadU8 (aNbComponents))
    return (Handle)0;

  JtDecode_VertexData_Quantized::PointQuantizerData aQuantizerData;
  if (!aQuantizerData.Read (theReader))
    return (Handle)0;

  // Create decoder object
  Handle aData;
  if (aQuantizerData.X.bits)
    aData = new JtDecode_VertexData_Quantized (aQuantizerData, aNbComponents, JtDecode_Unpack_Lag1);
  else
    aData = new JtDecode_VertexData_ExpMant (aNbComponents, JtDecode_Unpack_Lag1);

  // Load encoded data
  if (!aData->load (theReader, &JtDecode_Int32CDP::Load2, aVertexCount))
    return (Handle)0;

  // Read hash value
  Jt_I32 aHash;
  if (!theReader.ReadI32 (aHash))
    return (Handle)0;

  // Success
  return aData;
}

JtDecode_VertexData::Handle JtDecode_VertexData::LoadQuantizedNormals (JtData_Reader& theReader)
{
  // Read parameters
  Jt_U8  aNbBits;
  Jt_I32 aNormalsCount;
  if (!theReader.ReadU8  (aNbBits)
   || !theReader.ReadI32 (aNormalsCount))
    return (Handle)0;

  // Create decoder object
  Handle aData (new JtDecode_VertexData_Deering (aNbBits, JtDecode_Unpack_Lag1));

  // Load encoded data
  if (!aData->load (theReader, &JtDecode_Int32CDP::Load1, aNormalsCount))
    return (Handle)0;

  // Success
  return aData;
}

JtDecode_VertexData::Handle JtDecode_VertexData::LoadCompressedNormals (JtData_Reader& theReader)
{
  // Read parameters
  Jt_I32 aNormalsCount;
  Jt_U8  aNbComponents;
  Jt_U8  aNbBits;
  if (!theReader.ReadI32 (aNormalsCount)
   || !theReader.ReadU8  (aNbComponents)
   || !theReader.ReadU8  (aNbBits))
    return (Handle)0;

  // Create decoder object
  Handle aData;
  if (aNbBits)
    aData = new JtDecode_VertexData_Deering (aNbBits);
  else
    aData = new JtDecode_VertexData_ExpMant (aNbComponents);

  // Load encoded data
  if (!aData->load (theReader, &JtDecode_Int32CDP::Load2, aNormalsCount))
    return (Handle)0;

  // Read hash value
  Jt_I32 aHash;
  if (!theReader.ReadI32 (aHash))
    return (Handle)0;

  // Success
  return aData;
}

Standard_Boolean JtDecode_VertexData::load (JtData_Reader&               theReader,
                                            JtDecode_Int32CDP::LoadFnPtr theLoader,
                                            const Jt_I32                 theVertexCount)
{
  for (Standard_Size i = 0; i < myPackages.Count(); i++)
  {
    if (!(myPackages[i].*theLoader) (theReader)
       || myPackages[i].GetOutValCount() != theVertexCount)
      return Standard_False;
  }

  return Standard_True;
}
