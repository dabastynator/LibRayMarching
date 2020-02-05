/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CSphere

*/

#include "libraymarching_sphere.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.

using namespace LibRayMarching;
using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CSphere 
**************************************************************************************************************************/

CSphere::CSphere(SpherePtr sphere): CPrimitive(sphere), m_Sphere(sphere)
{

}

LibRayMarching_double CSphere::GetRadius ()
{
	return m_Sphere->GetRadius();
}

void CSphere::SetRadius (const LibRayMarching_double dRadius)
{
	m_Sphere->SetRadius((float)dRadius);
}