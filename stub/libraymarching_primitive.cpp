/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingPrimitive

*/

#include "libraymarching_primitive.hpp"
#include "libraymarching_interfaceexception.hpp"
#include "libraymarching_utils.hpp"
// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingPrimitive 
**************************************************************************************************************************/

void CLibRayMarchingPrimitive::IdentityPosition ()
{
	m_ModelToWorld = Matrix();
}

void CLibRayMarchingPrimitive::Translate (const sLibRayMarchingVector Translation)
{
	m_ModelToWorld *= MatrixTranslate(LibVecToVector(Translation));
}

void CLibRayMarchingPrimitive::Rotate (const sLibRayMarchingVector Axis, const LibRayMarching_double dRadian)
{
	m_ModelToWorld *= MatrixRotate(LibVecToVector(Axis), dRadian);
}

void CLibRayMarchingPrimitive::Scale (const sLibRayMarchingVector Scale)
{
	m_ModelToWorld *= MatrixScale(LibVecToVector(Scale));
}

void CLibRayMarchingPrimitive::SetMaterial (const sLibRayMarchingMaterial Material)
{
	m_Material = Material;
}
