/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingTorus

*/

#include "libraymarching_torus.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingTorus 
**************************************************************************************************************************/

CLibRayMarchingTorus::CLibRayMarchingTorus(TorusPtr torus):
	CLibRayMarchingPrimitive(torus), m_Torus(torus)
{

}

LibRayMarching_double CLibRayMarchingTorus::GetBigRadius ()
{
	return m_Torus->GetRadiusBig();
}

void CLibRayMarchingTorus::SetBigRadius (const LibRayMarching_double dBigRadius)
{
	m_Torus->SetRadiusBig(dBigRadius);
}

LibRayMarching_double CLibRayMarchingTorus::GetSmallRadius ()
{
	return m_Torus->GetRadiusSmall();
}

void CLibRayMarchingTorus::SetSmallRadius (const LibRayMarching_double dSmallRadius)
{
	m_Torus->SetRadiusSmall(dSmallRadius);
}

