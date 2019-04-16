/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingPrimitive

*/

#include "libraymarching_primitive.hpp"
#include "libraymarching_interfaceexception.hpp"
#include "libraymarching_utils.hpp"
// Include custom headers here.

using namespace LibRayMarching;
using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingPrimitive 
**************************************************************************************************************************/

CLibRayMarchingPrimitive::CLibRayMarchingPrimitive(PrimitivePtr sPrimitive):
	m_Primitive(sPrimitive)
{

}

void CLibRayMarchingPrimitive::IdentityPosition ()
{
	m_Primitive->IdentityPosition();
}

void CLibRayMarchingPrimitive::Translate (const sLibRayMarchingVector Translation)
{
	m_Primitive->Translate(LibVecToVector(Translation));
}

void CLibRayMarchingPrimitive::Rotate (const sLibRayMarchingVector Axis, const LibRayMarching_double dRadian)
{
	m_Primitive->Rotate(LibVecToVector(Axis), (float)dRadian);
}

void CLibRayMarchingPrimitive::Scale (const sLibRayMarchingVector Scale)
{
	m_Primitive->Scale(LibVecToVector(Scale));
}

void CLibRayMarchingPrimitive::SetMaterial (const sLibRayMarchingMaterial Material)
{
	m_Primitive->SetMaterial(LibMaterialToMaterial(Material));
}

void CLibRayMarchingPrimitive::SetSinusDistortion (const LibRayMarching_double dDistortionFactor, const LibRayMarching_double dInterval)
{
	m_Primitive->SetDistortionSinus((float)dDistortionFactor, (float)dInterval);
}