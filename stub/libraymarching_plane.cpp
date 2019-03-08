/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingPlane

*/

#include "libraymarching_plane.hpp"
#include "libraymarching_interfaceexception.hpp"
#include "libraymarching_utils.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingPlane 
**************************************************************************************************************************/

sLibRayMarchingVector CLibRayMarchingPlane::GetOrigin ()
{
	return VectorToLibVec(m_Origin);
}

void CLibRayMarchingPlane::SetOrigin (const sLibRayMarchingVector Origin)
{
	m_Origin = LibVecToVector(Origin);
}

sLibRayMarchingVector CLibRayMarchingPlane::GetNormal ()
{
	return VectorToLibVec(m_Normal);
}

void CLibRayMarchingPlane::SetNormal (const sLibRayMarchingVector Normal)
{
	m_Normal = LibVecToVector(Normal);
}

