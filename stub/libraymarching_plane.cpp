/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingPlane

*/

#include "libraymarching_plane.hpp"
#include "libraymarching_interfaceexception.hpp"
#include "libraymarching_utils.hpp"

// Include custom headers here.

using namespace LibRayMarching;
using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingPlane 
**************************************************************************************************************************/

CLibRayMarchingPlane::CLibRayMarchingPlane(PlanePtr plane):
	CLibRayMarchingPrimitive(plane), m_Plane(plane)
{

}

sLibRayMarchingVector CLibRayMarchingPlane::GetNormal ()
{
	return VectorToLibVec(m_Plane->GetNormal());
}

void CLibRayMarchingPlane::SetNormal (const sLibRayMarchingVector Normal)
{
	m_Plane->SetNormal(LibVecToVector(Normal));
}