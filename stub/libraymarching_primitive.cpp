/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingPrimitive

*/

#include "libraymarching_primitive.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingPrimitive 
**************************************************************************************************************************/

void CLibRayMarchingPrimitive::IdentityPosition ()
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingPrimitive::Translate (const sLibRayMarchingVector Translation)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingPrimitive::Rotate (const sLibRayMarchingVector Axis, const LibRayMarching_double dRadian)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingPrimitive::Scale (const sLibRayMarchingVector Scale)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingPrimitive::AssignMaterial (ILibRayMarchingMaterial* pMaterial)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

