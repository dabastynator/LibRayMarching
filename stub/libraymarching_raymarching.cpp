/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingRayMarching

*/

#include "libraymarching_raymarching.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingRayMarching 
**************************************************************************************************************************/

LibRayMarching_uint32 CLibRayMarchingRayMarching::GetLightCount ()
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingRayMarching::GetLight (const LibRayMarching_uint32 nIndex, sLibRayMarchingVector & sPosition, sLibRayMarchingVector & sColor)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingRayMarching::AddLight (const sLibRayMarchingVector Position, const sLibRayMarchingVector Color)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingRayMarching::DeleteLight (const LibRayMarching_uint32 nIndex)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

LibRayMarching_uint32 CLibRayMarchingRayMarching::GetPrimitiveCount ()
{
	return m_Primitives.size();
}

ILibRayMarchingPrimitive * CLibRayMarchingRayMarching::GetPrimitive (const LibRayMarching_uint32 nIndex)
{
	return m_Primitives.at(nIndex);
}

void CLibRayMarchingRayMarching::AddPrimitive (ILibRayMarchingPrimitive* pPrimitive)
{
	CLibRayMarchingPrimitive* pPrimitiveImpl = dynamic_cast < CLibRayMarchingPrimitive* >(pPrimitive);
	m_Primitives.push_back(pPrimitiveImpl);
}

void CLibRayMarchingRayMarching::RemovePrimitive (const LibRayMarching_uint32 nIndex)
{
	m_Primitives.erase(m_Primitives.begin() + nIndex);
}

void CLibRayMarchingRayMarching::SetScreenSize (const LibRayMarching_uint32 nWidth, const LibRayMarching_uint32 nHeight)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingRayMarching::SetViewport (const sLibRayMarchingVector Eye, const sLibRayMarchingVector Dir, const sLibRayMarchingVector Up, const LibRayMarching_double dFOV)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingRayMarching::RenderScene ()
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

LibRayMarching_uint32 CLibRayMarchingRayMarching::RenderPixel (const LibRayMarching_double dX, const LibRayMarching_double dY)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingRayMarching::SetProgressCallback (const LibRayMarchingProgressCallback pProgressCallback)
{
	m_ProgressCallback = pProgressCallback;
}

