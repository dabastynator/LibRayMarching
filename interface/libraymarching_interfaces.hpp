/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.5.0.

Abstract: This is an autogenerated C++ header file in order to allow easy
development of Ray Marching Library. The implementer of Ray Marching Library needs to
derive concrete classes from the abstract classes in this header.

Interface version: 0.9.0

*/


#ifndef __LIBRAYMARCHING_CPPINTERFACES
#define __LIBRAYMARCHING_CPPINTERFACES

#include <string>

#include "libraymarching_types.h"

namespace LibRayMarching {
namespace Impl {

/**
 Forward declarations of class interfaces
*/
class ILibRayMarchingBaseClass;
class ILibRayMarchingPrimitive;
class ILibRayMarchingSphere;
class ILibRayMarchingCapsule;
class ILibRayMarchingPlane;
class ILibRayMarchingBox;
class ILibRayMarchingTorus;
class ILibRayMarchingCylinder;
class ILibRayMarchingQuaternionFractal;
class ILibRayMarchingMengerSponge;
class ILibRayMarchingPrimitiveGroup;
class ILibRayMarchingRayMarching;


/*************************************************************************************************************************
 Class interface for LibRayMarchingBaseClass 
**************************************************************************************************************************/

class ILibRayMarchingBaseClass {
public:
	/**
	* ILibRayMarchingBaseClass::~ILibRayMarchingBaseClass - virtual destructor of ILibRayMarchingBaseClass
	*/
	virtual ~ILibRayMarchingBaseClass() {};

	/**
	* IBaseClass::GetLastErrorMessage - Returns the last error registered of this class instance
	* @param[out] sErrorMessage - Message of the last error registered
	* @return Has an error been registered already
	*/
	virtual bool GetLastErrorMessage (std::string & sErrorMessage) = 0;

	/**
	* IBaseClass::ClearErrorMessages - Clears all registered messages of this class instance
	*/
	virtual void ClearErrorMessages () = 0;

	/**
	* IBaseClass::RegisterErrorMessage - Registers an error message with this class instance
	* @param[in] sErrorMessage - Error message to register
	*/
	virtual void RegisterErrorMessage (const std::string & sErrorMessage) = 0;
};


/*************************************************************************************************************************
 Class interface for LibRayMarchingPrimitive 
**************************************************************************************************************************/

class ILibRayMarchingPrimitive : public virtual ILibRayMarchingBaseClass{
public:
	/**
	* IPrimitive::IdentityPosition - Reset the position matrix to identity
	*/
	virtual void IdentityPosition () = 0;

	/**
	* IPrimitive::Translate - Translate the primitive matrix by given movement vector
	* @param[in] Translation - Movement vector
	*/
	virtual void Translate (const sLibRayMarchingVector Translation) = 0;

	/**
	* IPrimitive::Rotate - Rotate the primitive matrix by given axis and angle
	* @param[in] Axis - Rotation axis
	* @param[in] dRadian - Rotation angle in radian
	*/
	virtual void Rotate (const sLibRayMarchingVector Axis, const LibRayMarching_double dRadian) = 0;

	/**
	* IPrimitive::Scale - Scale the primitive matrix by given vector
	* @param[in] Scale - Scale vector for each component
	*/
	virtual void Scale (const sLibRayMarchingVector Scale) = 0;

	/**
	* IPrimitive::SetMaterial - Set material for this primitive
	* @param[in] Material - Material for this primitive
	*/
	virtual void SetMaterial (const sLibRayMarchingMaterial Material) = 0;

};


/*************************************************************************************************************************
 Class interface for LibRayMarchingSphere 
**************************************************************************************************************************/

class ILibRayMarchingSphere : public virtual ILibRayMarchingBaseClass, public virtual ILibRayMarchingPrimitive{
public:
	/**
	* ISphere::GetRadius - Get the current radius
	* @return The radius
	*/
	virtual LibRayMarching_double GetRadius () = 0;

	/**
	* ISphere::SetRadius - Set the current radius
	* @param[in] dRadius - The raidus
	*/
	virtual void SetRadius (const LibRayMarching_double dRadius) = 0;

};


/*************************************************************************************************************************
 Class interface for LibRayMarchingCapsule 
**************************************************************************************************************************/

class ILibRayMarchingCapsule : public virtual ILibRayMarchingBaseClass, public virtual ILibRayMarchingPrimitive{
public:
	/**
	* ICapsule::GetRadius - Get the current radius
	* @return The radius
	*/
	virtual LibRayMarching_double GetRadius () = 0;

	/**
	* ICapsule::SetRadius - Set the current radius
	* @param[in] dRadius - The raidus
	*/
	virtual void SetRadius (const LibRayMarching_double dRadius) = 0;

	/**
	* ICapsule::GetPoint1 - Get the current point 1
	* @return Point 1
	*/
	virtual sLibRayMarchingVector GetPoint1 () = 0;

	/**
	* ICapsule::SetPoint1 - Set the current point 1
	* @param[in] Point1 - Point 1
	*/
	virtual void SetPoint1 (const sLibRayMarchingVector Point1) = 0;

	/**
	* ICapsule::GetPoint2 - Get the current point 2
	* @return Point 2
	*/
	virtual sLibRayMarchingVector GetPoint2 () = 0;

	/**
	* ICapsule::SetPoint2 - Set the current point 2
	* @param[in] Point2 - Point 2
	*/
	virtual void SetPoint2 (const sLibRayMarchingVector Point2) = 0;

};


/*************************************************************************************************************************
 Class interface for LibRayMarchingPlane 
**************************************************************************************************************************/

class ILibRayMarchingPlane : public virtual ILibRayMarchingBaseClass, public virtual ILibRayMarchingPrimitive{
public:
	/**
	* IPlane::GetNormal - Get the current normal
	* @return Normal
	*/
	virtual sLibRayMarchingVector GetNormal () = 0;

	/**
	* IPlane::SetNormal - Set the current normal
	* @param[in] Normal - Normal
	*/
	virtual void SetNormal (const sLibRayMarchingVector Normal) = 0;

};


/*************************************************************************************************************************
 Class interface for LibRayMarchingBox 
**************************************************************************************************************************/

class ILibRayMarchingBox : public virtual ILibRayMarchingBaseClass, public virtual ILibRayMarchingPrimitive{
public:
	/**
	* IBox::GetDimensions - Get the size in x, y and z dimension
	* @return Size in x, y and z dimension
	*/
	virtual sLibRayMarchingVector GetDimensions () = 0;

	/**
	* IBox::SetDimensions - Set the size in x, y and z dimension
	* @param[in] Dimensions - Size in x, y and z dimension
	*/
	virtual void SetDimensions (const sLibRayMarchingVector Dimensions) = 0;

};


/*************************************************************************************************************************
 Class interface for LibRayMarchingTorus 
**************************************************************************************************************************/

class ILibRayMarchingTorus : public virtual ILibRayMarchingBaseClass, public virtual ILibRayMarchingPrimitive{
public:
	/**
	* ITorus::GetBigRadius - Get the bigger outer radius
	* @return Bigger outer radius
	*/
	virtual LibRayMarching_double GetBigRadius () = 0;

	/**
	* ITorus::SetBigRadius - Set the bigger outer radius
	* @param[in] dBigRadius - Bigger outer radius
	*/
	virtual void SetBigRadius (const LibRayMarching_double dBigRadius) = 0;

	/**
	* ITorus::GetSmallRadius - Get the smaller outer radius
	* @return Smaller outer radius
	*/
	virtual LibRayMarching_double GetSmallRadius () = 0;

	/**
	* ITorus::SetSmallRadius - Set the smaller outer radius
	* @param[in] dSmallRadius - Smaller outer radius
	*/
	virtual void SetSmallRadius (const LibRayMarching_double dSmallRadius) = 0;

};


/*************************************************************************************************************************
 Class interface for LibRayMarchingCylinder 
**************************************************************************************************************************/

class ILibRayMarchingCylinder : public virtual ILibRayMarchingBaseClass, public virtual ILibRayMarchingPrimitive{
public:
	/**
	* ICylinder::GetRadius - Get the radius
	* @return radius
	*/
	virtual LibRayMarching_double GetRadius () = 0;

	/**
	* ICylinder::SetRadius - Set the radius
	* @param[in] dRadius - radius
	*/
	virtual void SetRadius (const LibRayMarching_double dRadius) = 0;

	/**
	* ICylinder::GetHeight - Get the Height
	* @return Height
	*/
	virtual LibRayMarching_double GetHeight () = 0;

	/**
	* ICylinder::SetHeight - Set the Height
	* @param[in] dHeight - Height
	*/
	virtual void SetHeight (const LibRayMarching_double dHeight) = 0;

};


/*************************************************************************************************************************
 Class interface for LibRayMarchingQuaternionFractal 
**************************************************************************************************************************/

class ILibRayMarchingQuaternionFractal : public virtual ILibRayMarchingBaseClass, public virtual ILibRayMarchingPrimitive{
public:
	/**
	* IQuaternionFractal::GetQuaternion - Get the current quaternion parameter
	* @param[out] dR - quaternion r part
	* @param[out] dI - quaternion i part
	* @param[out] dJ - quaternion j part
	* @param[out] dK - quaternion k part
	*/
	virtual void GetQuaternion (LibRayMarching_double & dR, LibRayMarching_double & dI, LibRayMarching_double & dJ, LibRayMarching_double & dK) = 0;

	/**
	* IQuaternionFractal::SetQuaternion - Set the current quaternion parameter
	* @param[in] dR - quaternion r part
	* @param[in] dI - quaternion i part
	* @param[in] dJ - quaternion j part
	* @param[in] dK - quaternion k part
	*/
	virtual void SetQuaternion (const LibRayMarching_double dR, const LibRayMarching_double dI, const LibRayMarching_double dJ, const LibRayMarching_double dK) = 0;

	/**
	* IQuaternionFractal::GetIterations - Get the number of maximal iterations
	* @return iterations
	*/
	virtual LibRayMarching_uint32 GetIterations () = 0;

	/**
	* IQuaternionFractal::SetIterations - Set the number of maximal iterations
	* @param[in] nIterations - iterations
	*/
	virtual void SetIterations (const LibRayMarching_uint32 nIterations) = 0;

};


/*************************************************************************************************************************
 Class interface for LibRayMarchingMengerSponge 
**************************************************************************************************************************/

class ILibRayMarchingMengerSponge : public virtual ILibRayMarchingBaseClass, public virtual ILibRayMarchingPrimitive{
public:
	/**
	* IMengerSponge::GetStepCount - Get the number of step count
	* @return StepCount
	*/
	virtual LibRayMarching_uint32 GetStepCount () = 0;

	/**
	* IMengerSponge::SetStepCount - Set the number of step count
	* @param[in] nStepCount - StepCount
	*/
	virtual void SetStepCount (const LibRayMarching_uint32 nStepCount) = 0;

};


/*************************************************************************************************************************
 Class interface for LibRayMarchingPrimitiveGroup 
**************************************************************************************************************************/

class ILibRayMarchingPrimitiveGroup : public virtual ILibRayMarchingBaseClass, public virtual ILibRayMarchingPrimitive{
public:
	/**
	* IPrimitiveGroup::GetPrimitiveCount - Get number of primitives
	* @return Number of primitives
	*/
	virtual LibRayMarching_uint32 GetPrimitiveCount () = 0;

	/**
	* IPrimitiveGroup::GetPrimitive - Get primitive at given index
	* @param[in] nIndex - Index
	* @return Primitive at given index
	*/
	virtual ILibRayMarchingPrimitive * GetPrimitive (const LibRayMarching_uint32 nIndex) = 0;

	/**
	* IPrimitiveGroup::AddPrimitive - Add primitive for this group
	* @param[in] pPrimitive - Primitive for this group
	*/
	virtual void AddPrimitive (ILibRayMarchingPrimitive* pPrimitive) = 0;

	/**
	* IPrimitiveGroup::RemovePrimitive - Remove primitive at given index
	* @param[in] nIndex - Index
	*/
	virtual void RemovePrimitive (const LibRayMarching_uint32 nIndex) = 0;

	/**
	* IPrimitiveGroup::SetGroupAction - Set method to combine primitives
	* @param[in] eGroupAction - Method to combine primitives
	*/
	virtual void SetGroupAction (const eLibRayMarchingGroupAction eGroupAction) = 0;

	/**
	* IPrimitiveGroup::GetGroupAction - Get method to combine primitives
	* @return Method to combine primitives
	*/
	virtual eLibRayMarchingGroupAction GetGroupAction () = 0;

};


/*************************************************************************************************************************
 Class interface for LibRayMarchingRayMarching 
**************************************************************************************************************************/

class ILibRayMarchingRayMarching : public virtual ILibRayMarchingBaseClass{
public:
	/**
	* IRayMarching::GetLightCount - Get number of lights
	* @return Number of lights
	*/
	virtual LibRayMarching_uint32 GetLightCount () = 0;

	/**
	* IRayMarching::GetLight - Get light at given index
	* @param[in] nIndex - Index
	* @param[out] sPosition - Position of the light
	* @param[out] sColor - Color of the light
	*/
	virtual void GetLight (const LibRayMarching_uint32 nIndex, sLibRayMarchingVector & sPosition, sLibRayMarchingVector & sColor) = 0;

	/**
	* IRayMarching::AddLight - Add new light
	* @param[in] Position - Position of the light
	* @param[in] Color - Color of the light
	*/
	virtual void AddLight (const sLibRayMarchingVector Position, const sLibRayMarchingVector Color) = 0;

	/**
	* IRayMarching::DeleteLight - Delete light at given index
	* @param[in] nIndex - Index
	*/
	virtual void DeleteLight (const LibRayMarching_uint32 nIndex) = 0;

	/**
	* IRayMarching::GetPrimitiveCount - Get number of primitives
	* @return Number of primitives
	*/
	virtual LibRayMarching_uint32 GetPrimitiveCount () = 0;

	/**
	* IRayMarching::GetPrimitive - Get primitive at given index
	* @param[in] nIndex - Index
	* @return Primitive at given index
	*/
	virtual ILibRayMarchingPrimitive * GetPrimitive (const LibRayMarching_uint32 nIndex) = 0;

	/**
	* IRayMarching::AddPrimitive - Add primitive
	* @param[in] pPrimitive - Primitive
	*/
	virtual void AddPrimitive (ILibRayMarchingPrimitive* pPrimitive) = 0;

	/**
	* IRayMarching::RemovePrimitive - Remove primitive at given index
	* @param[in] nIndex - Index
	*/
	virtual void RemovePrimitive (const LibRayMarching_uint32 nIndex) = 0;

	/**
	* IRayMarching::SetScreenSize - Set the screen size
	* @param[in] nWidth - Width of the screen
	* @param[in] nHeight - Height of the screen
	*/
	virtual void SetScreenSize (const LibRayMarching_uint32 nWidth, const LibRayMarching_uint32 nHeight) = 0;

	/**
	* IRayMarching::SetViewport - Set viewport by given view vectors and FOV
	* @param[in] Eye - Position of the eye
	* @param[in] Dir - Direction of the view
	* @param[in] Up - Direction of up vector
	* @param[in] dFOV - Field of view angle in radian
	*/
	virtual void SetViewport (const sLibRayMarchingVector Eye, const sLibRayMarchingVector Dir, const sLibRayMarchingVector Up, const LibRayMarching_double dFOV) = 0;

	/**
	* IRayMarching::RenderScene - Renders the current scene
	*/
	virtual void RenderScene () = 0;

	/**
	* IRayMarching::GetColorBuffer - Return the color buffer
	* @param[in] nColorBufferBufferSize - Number of elements in buffer
	* @param[out] pColorBufferNeededCount - will be filled with the count of the written structs, or needed buffer size.
	* @param[out] pColorBufferBuffer - uint64 buffer of Field of colors. One integer represents color as RGBA value of the pixel
	*/
	virtual void GetColorBuffer (LibRayMarching_uint64 nColorBufferBufferSize, LibRayMarching_uint64* pColorBufferNeededCount, LibRayMarching_uint64 * pColorBufferBuffer) = 0;

	/**
	* IRayMarching::RenderPixel - Renders one single pixel
	* @param[in] dX - X position of the pixel
	* @param[in] dY - Y position of the pixel
	* @return RGBA value of the pixel
	*/
	virtual LibRayMarching_uint32 RenderPixel (const LibRayMarching_double dX, const LibRayMarching_double dY) = 0;

	/**
	* IRayMarching::SetProgressCallback - Sets the progress callback function
	* @param[in] pProgressCallback - callback function
	*/
	virtual void SetProgressCallback (const LibRayMarchingProgressCallback pProgressCallback) = 0;

};


/*************************************************************************************************************************
 Global functions declarations
**************************************************************************************************************************/
class CLibRayMarchingWrapper {
public:
	/**
	* Ilibraymarching::GetLastError - Returns the last error recorded on this object
	* @param[in] pInstance - Instance Handle
	* @param[out] sErrorMessage - Message of the last error
	* @return Is there a last error to query
	*/
	static bool GetLastError (ILibRayMarchingBaseClass* pInstance, std::string & sErrorMessage);

	/**
	* Ilibraymarching::ReleaseInstance - Releases the memory of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	static void ReleaseInstance (ILibRayMarchingBaseClass* pInstance);

	/**
	* Ilibraymarching::GetLibraryVersion - retrieves the current version of the library.
	* @param[out] nMajor - returns the major version of the library
	* @param[out] nMinor - returns the minor version of the library
	* @param[out] nMicro - returns the micro version of the library
	*/
	static void GetLibraryVersion (LibRayMarching_uint32 & nMajor, LibRayMarching_uint32 & nMinor, LibRayMarching_uint32 & nMicro);

	/**
	* Ilibraymarching::CreateRayMarching - Creates a new ray marching instance
	* @return New raymarching instance
	*/
	static ILibRayMarchingRayMarching * CreateRayMarching ();

	/**
	* Ilibraymarching::CreateSphere - Create new sphere
	* @param[in] dRadius - Radius of the sphere
	* @return New sphere
	*/
	static ILibRayMarchingSphere * CreateSphere (const LibRayMarching_double dRadius);

	/**
	* Ilibraymarching::CreateCapsule - Create new capsule
	* @param[in] dRadius - Radius of the capsule
	* @param[in] Point1 - Point 1
	* @param[in] Point2 - Point 2
	* @return New capsule
	*/
	static ILibRayMarchingCapsule * CreateCapsule (const LibRayMarching_double dRadius, const sLibRayMarchingVector Point1, const sLibRayMarchingVector Point2);

	/**
	* Ilibraymarching::CreateBox - Create new sphere
	* @param[in] Dimensions - Dimensions of the box
	* @return New box
	*/
	static ILibRayMarchingBox * CreateBox (const sLibRayMarchingVector Dimensions);

	/**
	* Ilibraymarching::CreatePlane - Create new plane
	* @param[in] Origin - Origin of the plane
	* @param[in] Normal - Normal of the plane
	* @return New plane
	*/
	static ILibRayMarchingPlane * CreatePlane (const sLibRayMarchingVector Origin, const sLibRayMarchingVector Normal);

	/**
	* Ilibraymarching::CreateCylinder - Create new cylinder
	* @param[in] dRadius - Radius of the cylinder
	* @param[in] dHeight - Height of the cylinder
	* @return New cylinder
	*/
	static ILibRayMarchingCylinder * CreateCylinder (const LibRayMarching_double dRadius, const LibRayMarching_double dHeight);

	/**
	* Ilibraymarching::CreateTorus - Create new Torus
	* @param[in] dBigRadius - Big Radius of the Torus
	* @param[in] dSmallRadius - Small Radius of the Torus
	* @return New Torus
	*/
	static ILibRayMarchingTorus * CreateTorus (const LibRayMarching_double dBigRadius, const LibRayMarching_double dSmallRadius);

	/**
	* Ilibraymarching::CreateMengerSponge - Create new MengerSponge
	* @param[in] nStepCount - StepCount
	* @return New MengerSponge
	*/
	static ILibRayMarchingMengerSponge * CreateMengerSponge (const LibRayMarching_uint32 nStepCount);

	/**
	* Ilibraymarching::CreateQuaternionFractal - Create new QuaternionFractal
	* @param[in] nIterations - Iterations
	* @return New QuaternionFractal
	*/
	static ILibRayMarchingQuaternionFractal * CreateQuaternionFractal (const LibRayMarching_uint32 nIterations);

	/**
	* Ilibraymarching::CreatePrimitiveGroup - Create new PrimitiveGroup
	* @param[in] eGroupAction - Method to combine primitives
	* @return New PrimitiveGroup
	*/
	static ILibRayMarchingPrimitiveGroup * CreatePrimitiveGroup (const eLibRayMarchingGroupAction eGroupAction);

};

} // namespace Impl
} // namespace LibRayMarching

#endif // __LIBRAYMARCHING_CPPINTERFACES
