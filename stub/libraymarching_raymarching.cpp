/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CRayMarching

*/

#include "libraymarching_raymarching.hpp"
#include "libraymarching_interfaceexception.hpp"
#include "libraymarching_utils.hpp"
#include "libraymarching_box.hpp"
#include "libraymarching_plane.hpp"
#include "libraymarching_sphere.hpp"
#include "libraymarching_capsule.hpp"
#include "libraymarching_torus.hpp"
#include "libraymarching_mengersponge.hpp"
#include "libraymarching_quaternionfractal.hpp"
#include "libraymarching_primitivegroup.hpp"
#include "vector.h"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CRayMarching 
**************************************************************************************************************************/

CRayMarching::CRayMarching():
	m_ColorBuffer(NULL), m_ProgressCallback(NULL)
{

}

CRayMarching::~CRayMarching()
{
	if (m_ColorBuffer != NULL)
	{
		delete m_ColorBuffer;
	}
}

LibRayMarching_uint32 CRayMarching::GetLightCount ()
{
	m_Shader.GetLightCount();
}

void CRayMarching::GetLight (const LibRayMarching_uint32 nIndex, sLibRayMarchingVector & sPosition, sLibRayMarchingVector & sColor)
{
	Light light = m_Shader.GetLight(nIndex);
	sPosition = VectorToLibVec(light.position);
	sColor = VectorToLibVec(light.color);
}

void CRayMarching::AddLight (const sLibRayMarchingVector Position, const sLibRayMarchingVector Color)
{
	Vector pos = LibVecToVector(Position);
	Vector col = LibVecToVector(Color);
	m_Shader.AddLight(Light(pos, col));
}

void CRayMarching::DeleteLight (const LibRayMarching_uint32 nIndex)
{
	m_Shader.DeleteLight(nIndex);
}

LibRayMarching_uint32 CRayMarching::GetPrimitiveCount ()
{
	return m_Shader.GetPrimitiveCount();
}

IPrimitive * CRayMarching::GetPrimitive (const LibRayMarching_uint32 nIndex)
{
	PrimitivePtr primitive = m_Shader.GetPrimitive(nIndex);
	switch(primitive->GetType()){
		case ptBox:
		{
			BoxPtr box( std::dynamic_pointer_cast<Box> (primitive) );
			return new CBox(box);
		}
		case ptSphere:
		{
			SpherePtr sphere( std::dynamic_pointer_cast<Sphere> (primitive) );
			return new CSphere(sphere);
		}
		case ptPlane:
		{
			PlanePtr plane( std::dynamic_pointer_cast<Plane> (primitive) );
			return new CPlane(plane);
		}
		case ptCapsule:
		{
			CapsulePtr capsule( std::dynamic_pointer_cast<Capsule> (primitive) );
			return new CCapsule(capsule);
		}
		case ptTorus:
		{
			TorusPtr torus( std::dynamic_pointer_cast<Torus> (primitive) );
			return new CTorus(torus);
		}
		case ptMengerSponge:
		{
			MengerSpongePtr ms( std::dynamic_pointer_cast<MengerSponge> (primitive) );
			return new CMengerSponge(ms);
		}
		case ptQuaternion:
		{
			QuaternionFractalPtr ms( std::dynamic_pointer_cast<QuaternionFractal> (primitive) );
			return new CQuaternionFractal(ms);
		}
		case ptGroup:
		{
			PrimitiveGroupPtr ms( std::dynamic_pointer_cast<PrimitiveGroup> (primitive) );
			return new CPrimitiveGroup(ms);
		}
	}
	throw new ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDPARAM);
}

void CRayMarching::AddPrimitive (IPrimitive* pPrimitive)
{
	CPrimitive* pPrimitiveImpl = dynamic_cast < CPrimitive* >(pPrimitive);
	m_Shader.AddPrimitive(pPrimitiveImpl->GetPrimitive());
}

void CRayMarching::RemovePrimitive (const LibRayMarching_uint32 nIndex)
{
	m_Shader.DeletePrimitive(nIndex);
}

void CRayMarching::SetScreenSize (const LibRayMarching_uint32 nWidth, const LibRayMarching_uint32 nHeight)
{
	m_Shader.GetCamera()->SetScreen(nWidth, nHeight);
	if (m_ColorBuffer != NULL)
	{
		delete m_ColorBuffer;
	}
	m_ColorBuffer = new unsigned int[nWidth * nHeight];
}

void CRayMarching::SetViewport (const sLibRayMarchingVector Eye, const sLibRayMarchingVector Dir, const sLibRayMarchingVector Up, const LibRayMarching_double dFOV)
{
	Vector eye = LibVecToVector(Eye);
	Vector dir = LibVecToVector(Dir);
	Vector up = LibVecToVector(Up);
	m_Shader.GetCamera()->SetViewPort(eye, dir, up, dFOV);
}

void CRayMarching::RenderScene ()
{
	for (int i=0; i < m_Shader.GetPrimitiveCount(); i++)
	{
		m_Shader.GetPrimitive(i)->Initialize();
	}
	int width = m_Shader.GetCamera()->GetWidth();
	int height = m_Shader.GetCamera()->GetHeight();
	bool running = true;
	for (int x = 0; x < width && running; x++)
	{
		for (int y = 0; y < height; y++)
		{
			m_ColorBuffer[x + y * width] = m_Shader.RenderPixel(x, y);
		}
		if (m_ProgressCallback != NULL)
		{
			m_ProgressCallback(100 * x / width, &running);
		}
	}
}

void CRayMarching::GetColorBuffer (LibRayMarching_uint64 nColorBufferBufferSize, LibRayMarching_uint64* pColorBufferNeededCount, LibRayMarching_uint64 * pColorBufferBuffer)
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

LibRayMarching_uint32 CRayMarching::RenderPixel (const LibRayMarching_double dX, const LibRayMarching_double dY)
{
	for (int i=0; i < m_Shader.GetPrimitiveCount(); i++)
	{
		m_Shader.GetPrimitive(i)->Initialize();
	}
	return m_Shader.RenderPixel(dX, dY);
}

void CRayMarching::SetProgressCallback (const LibRayMarchingProgressCallback pProgressCallback)
{
	m_ProgressCallback = pProgressCallback;
}

void CRayMarching::SetBackground (const sLibRayMarchingVector Background, const LibRayMarching_double dDistanceStart, const LibRayMarching_double dDistanceEnd)
{
	Lightning* lighning = m_Shader.GetLightning();
	lighning->background = LibVecToVector(Background);
	lighning->min_dist_background = dDistanceStart;
	lighning->max_dist_background = dDistanceEnd;
}

void CRayMarching::SetShaderProperties (const sLibRayMarchingShaderProperties ShaderProperties)
{
	Lightning* lighning = m_Shader.GetLightning();
	lighning->oversampling = ShaderProperties.m_Oversampling;
	lighning->soft_shadow = ShaderProperties.m_SoftShadow;
	lighning->normal_by_environment = ShaderProperties.m_FastNormalCalculation;
	m_Shader.SetMaxBouncing(ShaderProperties.m_MaxBouncing);
}

