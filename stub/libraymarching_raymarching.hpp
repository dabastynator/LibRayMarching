/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CRayMarching

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGRAYMARCHING
#define __LIBRAYMARCHING_LIBRAYMARCHINGRAYMARCHING

#include "libraymarching_interfaces.hpp"
#include "libraymarching_primitive.hpp"
#include "libraymarching_baseclass.hpp"

#include <vector>
#include <memory>
#include "camera.h"
#include "shader.h"

// Include custom headers here.


namespace LibRayMarching {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CRayMarching 
**************************************************************************************************************************/

class CRayMarching : public virtual IRayMarching, public virtual CBaseClass{
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/

	Shader m_Shader;

	LibRayMarchingProgressCallback m_ProgressCallback;

	unsigned int *m_ColorBuffer;

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/

	CRayMarching();

	~CRayMarching();

	LibRayMarching_uint32 GetLightCount ();

	void GetLight (const LibRayMarching_uint32 nIndex, sLibRayMarchingVector & sPosition, sLibRayMarchingVector & sColor);

	void AddLight (const sLibRayMarchingVector Position, const sLibRayMarchingVector Color);

	void DeleteLight (const LibRayMarching_uint32 nIndex);

	LibRayMarching_uint32 GetPrimitiveCount ();

	IPrimitive * GetPrimitive (const LibRayMarching_uint32 nIndex);

	void AddPrimitive (IPrimitive* pPrimitive);

	void RemovePrimitive (const LibRayMarching_uint32 nIndex);

	void SetScreenSize (const LibRayMarching_uint32 nWidth, const LibRayMarching_uint32 nHeight);

	void SetViewport (const sLibRayMarchingVector Eye, const sLibRayMarchingVector Dir, const sLibRayMarchingVector Up, const LibRayMarching_double dFOV);

	void RenderScene ();

	
	void GetColorBuffer (LibRayMarching_uint64 nColorBufferBufferSize, LibRayMarching_uint64* pColorBufferNeededCount, LibRayMarching_uint64 * pColorBufferBuffer);

	LibRayMarching_uint32 RenderPixel (const LibRayMarching_double dX, const LibRayMarching_double dY);

	void SetProgressCallback (const LibRayMarchingProgressCallback pProgressCallback);

	void SetBackground (const sLibRayMarchingVector Background, const LibRayMarching_double dDistanceStart, const LibRayMarching_double dDistanceEnd);

	void SetShaderProperties (const sLibRayMarchingShaderProperties ShaderProperties);
};

} // namespace Impl
} // namespace LibRayMarching

#endif // __LIBRAYMARCHING_LIBRAYMARCHINGRAYMARCHING
