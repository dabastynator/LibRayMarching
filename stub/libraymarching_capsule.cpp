/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingCapsule

*/

#include "libraymarching_capsule.hpp"
#include "libraymarching_interfaceexception.hpp"
#include "libraymarching_utils.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingCapsule 
**************************************************************************************************************************/

CLibRayMarchingCapsule::CLibRayMarchingCapsule(CapsulePtr capsule): CLibRayMarchingPrimitive(capsule), m_Capsule(capsule)
{

}

LibRayMarching_double CLibRayMarchingCapsule::GetRadius ()
{
	return m_Capsule->GetRadius();
}

void CLibRayMarchingCapsule::SetRadius (const LibRayMarching_double dRadius)
{
	m_Capsule->SetRadius(dRadius);
}

sLibRayMarchingVector CLibRayMarchingCapsule::GetPoint1 ()
{
	return VectorToLibVec(m_Capsule->GetPoint1());
}

void CLibRayMarchingCapsule::SetPoint1 (const sLibRayMarchingVector Point1)
{
	m_Capsule->SetPoint1(LibVecToVector(Point1));
}

sLibRayMarchingVector CLibRayMarchingCapsule::GetPoint2 ()
{
	return VectorToLibVec(m_Capsule->GetPoint2());
}

void CLibRayMarchingCapsule::SetPoint2 (const sLibRayMarchingVector Point2)
{
	m_Capsule->SetPoint2(LibVecToVector(Point2));
}