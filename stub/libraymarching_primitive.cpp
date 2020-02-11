/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CPrimitive

*/

#include "libraymarching_primitive.hpp"
#include "libraymarching_interfaceexception.hpp"
#include "libraymarching_utils.hpp"
// Include custom headers here.

using namespace LibRayMarching;
using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CPrimitive 
**************************************************************************************************************************/

CPrimitive::CPrimitive(PrimitivePtr sPrimitive):
	m_Primitive(sPrimitive)
{

}

void CPrimitive::IdentityPosition ()
{
	m_Primitive->IdentityPosition();
}

void CPrimitive::Translate (const LibRayMarching::sVector Translation)
{
	m_Primitive->Translate(LibVecToVector(Translation));
}

void CPrimitive::Rotate (const LibRayMarching::sVector Axis, const LibRayMarching_double dRadian)
{
	m_Primitive->Rotate(LibVecToVector(Axis), (float)dRadian);
}

void CPrimitive::Scale (const LibRayMarching::sVector Scale)
{
	m_Primitive->Scale(LibVecToVector(Scale));
}

void CPrimitive::SetMaterial (const LibRayMarching::sMaterial Material)
{
	m_Primitive->SetMaterial(LibMaterialToMaterial(Material));
}

void CPrimitive::SetGlow(const LibRayMarching::sGlow Glow)
{
	m_Primitive->SetGlow(LibGlowToGlow(Glow));
}

void CPrimitive::SetSinusDistortion (const LibRayMarching_double dDistortionFactor, const LibRayMarching_double dInterval)
{
	m_Primitive->SetDistortionSinus((float)dDistortionFactor, (float)dInterval);
}