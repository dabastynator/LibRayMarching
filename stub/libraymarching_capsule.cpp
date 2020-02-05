/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CCapsule

*/

#include "libraymarching_capsule.hpp"
#include "libraymarching_interfaceexception.hpp"
#include "libraymarching_utils.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CCapsule 
**************************************************************************************************************************/

CCapsule::CCapsule(CapsulePtr capsule): CPrimitive(capsule), m_Capsule(capsule)
{

}

LibRayMarching_double CCapsule::GetRadius ()
{
	return m_Capsule->GetRadius();
}

void CCapsule::SetRadius (const LibRayMarching_double dRadius)
{
	m_Capsule->SetRadius(dRadius);
}

sLibRayMarchingVector CCapsule::GetPoint1 ()
{
	return VectorToLibVec(m_Capsule->GetPoint1());
}

void CCapsule::SetPoint1 (const sLibRayMarchingVector Point1)
{
	m_Capsule->SetPoint1(LibVecToVector(Point1));
}

sLibRayMarchingVector CCapsule::GetPoint2 ()
{
	return VectorToLibVec(m_Capsule->GetPoint2());
}

void CCapsule::SetPoint2 (const sLibRayMarchingVector Point2)
{
	m_Capsule->SetPoint2(LibVecToVector(Point2));
}