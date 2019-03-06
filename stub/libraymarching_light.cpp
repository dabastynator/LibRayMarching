/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingLight

*/

#include "libraymarching_light.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingLight 
**************************************************************************************************************************/

sLibRayMarchingVector CLibRayMarchingLight::GetColor ()
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingLight::SetColor (const sLibRayMarchingVector Color)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

sLibRayMarchingVector CLibRayMarchingLight::GetPosition ()
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingLight::SetPosition (const sLibRayMarchingVector Position)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

