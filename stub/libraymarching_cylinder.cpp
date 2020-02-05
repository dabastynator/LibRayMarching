/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CCylinder

*/

#include "libraymarching_cylinder.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.

using namespace LibRayMarching;
using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CCylinder 
**************************************************************************************************************************/

CCylinder::CCylinder(CylinderPtr cylinder):
	CPrimitive(cylinder), m_Cylinder(cylinder)
{

}

LibRayMarching_double CCylinder::GetRadius ()
{
	return m_Cylinder->GetRadius();
}

void CCylinder::SetRadius (const LibRayMarching_double dRadius)
{
	m_Cylinder->SetRadius((float)dRadius);
}

LibRayMarching_double CCylinder::GetHeight ()
{
	return m_Cylinder->GetHeight();
}

void CCylinder::SetHeight (const LibRayMarching_double dHeight)
{
	m_Cylinder->SetHeight((float)dHeight);
}

