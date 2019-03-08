/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingSphere

*/

#include "libraymarching_sphere.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingSphere 
**************************************************************************************************************************/

LibRayMarching_double CLibRayMarchingSphere::GetRadius ()
{
	return m_Radius;
}

void CLibRayMarchingSphere::SetRadius (const LibRayMarching_double dRadius)
{
	m_Radius = dRadius;
}

