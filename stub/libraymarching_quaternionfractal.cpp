/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingQuaternionFractal

*/

#include "libraymarching_quaternionfractal.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingQuaternionFractal 
**************************************************************************************************************************/
CLibRayMarchingQuaternionFractal::CLibRayMarchingQuaternionFractal(QuaternionFractalPtr fractal):
	CLibRayMarchingPrimitive(fractal), m_Fractal(fractal)
{

}

void CLibRayMarchingQuaternionFractal::GetQuaternion (LibRayMarching_double & dR, LibRayMarching_double & dI, LibRayMarching_double & dJ, LibRayMarching_double & dK)
{
	Quaternion q = m_Fractal->GetQuaternion();
	dR = q.r;
	dI = q.i;
	dJ = q.j;
	dK = q.k;
}

void CLibRayMarchingQuaternionFractal::SetQuaternion (const LibRayMarching_double dR, const LibRayMarching_double dI, const LibRayMarching_double dJ, const LibRayMarching_double dK)
{
	m_Fractal->SetQuaternion(Quaternion(
		dR, dI, dJ, dK
	));
}

LibRayMarching_uint32 CLibRayMarchingQuaternionFractal::GetIterations ()
{
	return m_Fractal->GetIterations();
}

void CLibRayMarchingQuaternionFractal::SetIterations (const LibRayMarching_uint32 nIterations)
{
	m_Fractal->SetIterations(nIterations);
}

