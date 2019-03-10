/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingPrimitiveGroup

*/

#include "libraymarching_primitivegroup.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingPrimitiveGroup 
**************************************************************************************************************************/

LibRayMarching_uint32 CLibRayMarchingPrimitiveGroup::GetPrimitiveCount ()
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

ILibRayMarchingPrimitive * CLibRayMarchingPrimitiveGroup::GetPrimitive (const LibRayMarching_uint32 nIndex)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingPrimitiveGroup::AddPrimitive (ILibRayMarchingPrimitive* pPrimitive)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingPrimitiveGroup::RemovePrimitive (const LibRayMarching_uint32 nIndex)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

double CLibRayMarchingPrimitiveGroup::DistanceTo(Vector vPoint)
{
	return 0;
}