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

LibRayMarching_double CLibRayMarchingCapsule::GetRadius ()
{
	return m_Radius;
}

void CLibRayMarchingCapsule::SetRadius (const LibRayMarching_double dRadius)
{
	m_Radius = dRadius;
}

sLibRayMarchingVector CLibRayMarchingCapsule::GetPoint1 ()
{
	return VectorToLibVec(m_Point1);
}

void CLibRayMarchingCapsule::SetPoint1 (const sLibRayMarchingVector Point1)
{
	m_Point1 = LibVecToVector(Point1);
}

sLibRayMarchingVector CLibRayMarchingCapsule::GetPoint2 ()
{
	return VectorToLibVec(m_Point2);
}

void CLibRayMarchingCapsule::SetPoint2 (const sLibRayMarchingVector Point2)
{
	m_Point1 = LibVecToVector(Point2);
}

double CLibRayMarchingCapsule::DistanceTo(Vector vPoint) const
{
	Vector p = m_ModelToWorld * vPoint;
	return 0;
}