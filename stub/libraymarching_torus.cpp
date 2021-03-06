/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CTorus

*/

#include "libraymarching_torus.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.

using namespace LibRayMarching;
using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CTorus 
**************************************************************************************************************************/

CTorus::CTorus(TorusPtr torus):
	CPrimitive(torus), m_Torus(torus)
{

}

LibRayMarching_double CTorus::GetBigRadius ()
{
	return m_Torus->GetRadiusBig();
}

void CTorus::SetBigRadius (const LibRayMarching_double dBigRadius)
{
	m_Torus->SetRadiusBig((float)dBigRadius);
}

LibRayMarching_double CTorus::GetSmallRadius ()
{
	return m_Torus->GetRadiusSmall();
}

void CTorus::SetSmallRadius (const LibRayMarching_double dSmallRadius)
{
	m_Torus->SetRadiusSmall((float)dSmallRadius);
}

