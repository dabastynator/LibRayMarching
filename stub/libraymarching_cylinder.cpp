/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingCylinder

*/

#include "libraymarching_cylinder.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.

using namespace LibRayMarching;
using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingCylinder 
**************************************************************************************************************************/

CLibRayMarchingCylinder::CLibRayMarchingCylinder(CylinderPtr cylinder):
	CLibRayMarchingPrimitive(cylinder), m_Cylinder(cylinder)
{

}

LibRayMarching_double CLibRayMarchingCylinder::GetRadius ()
{
	return m_Cylinder->GetRadius();
}

void CLibRayMarchingCylinder::SetRadius (const LibRayMarching_double dRadius)
{
	m_Cylinder->SetRadius((float)dRadius);
}

LibRayMarching_double CLibRayMarchingCylinder::GetHeight ()
{
	return m_Cylinder->GetHeight();
}

void CLibRayMarchingCylinder::SetHeight (const LibRayMarching_double dHeight)
{
	m_Cylinder->SetHeight((float)dHeight);
}

