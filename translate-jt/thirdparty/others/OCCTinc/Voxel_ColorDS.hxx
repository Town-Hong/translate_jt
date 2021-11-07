// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Voxel_ColorDS_HeaderFile
#define _Voxel_ColorDS_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Voxel_DS.hxx>
#include <Standard_Real.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Byte.hxx>


//! A 3D voxel model keeping 4 bits for each voxel (one of 16 colors).
class Voxel_ColorDS  : public Voxel_DS
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! An empty constructor.
  Standard_EXPORT Voxel_ColorDS();
  
  //! A constructor initializing the voxel model.
  //! (x, y, z) - the start point of the box.
  //! (x_len, y_len, z_len) - lengths in x, y and z directions along axes of a co-ordinate system.
  //! (nb_x, nb_y, nb_z) - number of splits (voxels) along x, y and z directions.
  Standard_EXPORT Voxel_ColorDS(const Standard_Real x, const Standard_Real y, const Standard_Real z, const Standard_Real x_len, const Standard_Real y_len, const Standard_Real z_len, const Standard_Integer nb_x, const Standard_Integer nb_y, const Standard_Integer nb_z);
  
  //! Initialization of the voxel model.
  //! (x, y, z) - the start point of the box.
  //! (x_len, y_len, z_len) - lengths in x, y and z directions along axes of a co-ordinate system.
  //! (nb_x, nb_y, nb_z) - number of splits (voxels) along x, y and z directions.
  Standard_EXPORT virtual   void Init (const Standard_Real x, const Standard_Real y, const Standard_Real z, const Standard_Real x_len, const Standard_Real y_len, const Standard_Real z_len, const Standard_Integer nb_x, const Standard_Integer nb_y, const Standard_Integer nb_z) ;
  
  //! A destructor of the voxel model.
  Standard_EXPORT   void Destroy() ;
~Voxel_ColorDS()
{
  Destroy();
}
  
  //! The method sets all values equal to 0 (false) and
  //! releases the memory.
  Standard_EXPORT   void SetZero() ;
  
  //! Defines a value for voxel with co-ordinates (ix, iy, iz).
  //! Only the first four bits are used!
  //! Initial state of the model is so that all voxels have value 0x0000,
  //! and this data doesn't occupy memory.
  //! Memory for data is allocating during setting non-zero values (0x0101, for example).
  Standard_EXPORT   void Set (const Standard_Integer ix, const Standard_Integer iy, const Standard_Integer iz, const Standard_Byte data) ;
  
  //! Returns the value of voxel with co-ordinates (ix, iy, iz).
  Standard_EXPORT   Standard_Byte Get (const Standard_Integer ix, const Standard_Integer iy, const Standard_Integer iz)  const;




protected:





private:





};







#endif // _Voxel_ColorDS_HeaderFile
