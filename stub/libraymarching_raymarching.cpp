/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingRayMarching

*/

#include "libraymarching_raymarching.hpp"
#include "libraymarching_interfaceexception.hpp"
#include "libraymarching_utils.hpp"
#include "vector.h"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingRayMarching 
**************************************************************************************************************************/

CLibRayMarchingRayMarching::CLibRayMarchingRayMarching():
	m_ColorBuffer(NULL)
{

}

CLibRayMarchingRayMarching::~CLibRayMarchingRayMarching()
{
	if (m_ColorBuffer != NULL)
	{
		delete m_ColorBuffer;
	}
}

LibRayMarching_uint32 CLibRayMarchingRayMarching::GetLightCount ()
{
	m_Shader.GetLightCount();
}

void CLibRayMarchingRayMarching::GetLight (const LibRayMarching_uint32 nIndex, sLibRayMarchingVector & sPosition, sLibRayMarchingVector & sColor)
{
	Light light = m_Shader.GetLight(nIndex);
	sPosition = VectorToLibVec(light.position);
	sColor = VectorToLibVec(light.color);
}

void CLibRayMarchingRayMarching::AddLight (const sLibRayMarchingVector Position, const sLibRayMarchingVector Color)
{
	Vector pos = LibVecToVector(Position);
	Vector col = LibVecToVector(Color);
	m_Shader.AddLight(Light(pos, col));
}

void CLibRayMarchingRayMarching::DeleteLight (const LibRayMarching_uint32 nIndex)
{
	m_Shader.DeleteLight(nIndex);
}

LibRayMarching_uint32 CLibRayMarchingRayMarching::GetPrimitiveCount ()
{
	return m_Shader.GetPrimitiveCount();
}

ILibRayMarchingPrimitive * CLibRayMarchingRayMarching::GetPrimitive (const LibRayMarching_uint32 nIndex)
{
	return m_Shader.GetPrimitive(nIndex);
}

void CLibRayMarchingRayMarching::AddPrimitive (ILibRayMarchingPrimitive* pPrimitive)
{
	CLibRayMarchingPrimitive* pPrimitiveImpl = dynamic_cast < CLibRayMarchingPrimitive* >(pPrimitive);
	m_Shader.AddPrimitive(pPrimitiveImpl);
}

void CLibRayMarchingRayMarching::RemovePrimitive (const LibRayMarching_uint32 nIndex)
{
	m_Shader.DeletePrimitive(nIndex);
}

void CLibRayMarchingRayMarching::SetScreenSize (const LibRayMarching_uint32 nWidth, const LibRayMarching_uint32 nHeight)
{
	m_Shader.GetCamera()->SetScreen(nWidth, nHeight);
	if (m_ColorBuffer != NULL)
	{
		delete m_ColorBuffer;
	}
	m_ColorBuffer = new unsigned int[nWidth * nHeight];
}

void CLibRayMarchingRayMarching::SetViewport (const sLibRayMarchingVector Eye, const sLibRayMarchingVector Dir, const sLibRayMarchingVector Up, const LibRayMarching_double dFOV)
{
	Vector eye = LibVecToVector(Eye);
	Vector dir = LibVecToVector(Dir);
	Vector up = LibVecToVector(Up);
	m_Shader.GetCamera()->SetViewPort(eye, dir, up, dFOV);
}

void CLibRayMarchingRayMarching::RenderScene ()
{
	for (int i=0; i < m_Shader.GetPrimitiveCount(); i++)
	{
		m_Shader.GetPrimitive(i)->Initialize();
	}
	int width = m_Shader.GetCamera()->GetWidth();
	int height = m_Shader.GetCamera()->GetHeight();
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			m_ColorBuffer[x + y * width] = m_Shader.RenderPixel(x, y);
		}
	}
}

void CLibRayMarchingRayMarching::GetColorBuffer (LibRayMarching_uint64 nColorBufferBufferSize, LibRayMarching_uint64* pColorBufferNeededCount, LibRayMarching_uint64 * pColorBufferBuffer)
{
	int width = m_Shader.GetCamera()->GetWidth();
	int height = m_Shader.GetCamera()->GetHeight();
	unsigned long size = width * height;
	*pColorBufferNeededCount = size;
	if (nColorBufferBufferSize >= size && m_ColorBuffer != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			*pColorBufferBuffer = m_ColorBuffer[i];
			pColorBufferBuffer++;
		}
	}
}

LibRayMarching_uint32 CLibRayMarchingRayMarching::RenderPixel (const LibRayMarching_double dX, const LibRayMarching_double dY)
{
	for (int i=0; i < m_Shader.GetPrimitiveCount(); i++)
	{
		m_Shader.GetPrimitive(i)->Initialize();
	}
	return m_Shader.RenderPixel(dX, dY);
}

void CLibRayMarchingRayMarching::SetProgressCallback (const LibRayMarchingProgressCallback pProgressCallback)
{
	m_ProgressCallback = pProgressCallback;
}

