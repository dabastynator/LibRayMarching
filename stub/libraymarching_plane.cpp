/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingPlane

*/

#include "libraymarching_plane.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingPlane 
**************************************************************************************************************************/

sLibRayMarchingVector CLibRayMarchingPlane::GetOrigin ()
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingPlane::SetOrigin (const sLibRayMarchingVector Origin)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

sLibRayMarchingVector CLibRayMarchingPlane::GetNormal ()
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingPlane::SetNormal (const sLibRayMarchingVector Normal)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

