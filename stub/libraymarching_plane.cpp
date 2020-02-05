/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CPlane

*/

#include "libraymarching_plane.hpp"
#include "libraymarching_interfaceexception.hpp"
#include "libraymarching_utils.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CPlane 
**************************************************************************************************************************/

CPlane::CPlane(PlanePtr plane):
	CPrimitive(plane), m_Plane(plane)
{

}

sLibRayMarchingVector CPlane::GetNormal ()
{
	return VectorToLibVec(m_Plane->GetNormal());
}

void CPlane::SetNormal (const sLibRayMarchingVector Normal)
{
	m_Plane->SetNormal(LibVecToVector(Normal));
}