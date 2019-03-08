/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CLibRayMarchingRayMarching

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGRAYMARCHING
#define __LIBRAYMARCHING_LIBRAYMARCHINGRAYMARCHING

#include "libraymarching_interfaces.hpp"
#include "libraymarching_primitive.hpp"
#include <vector>


// Include custom headers here.


namespace LibRayMarching {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CLibRayMarchingRayMarching 
**************************************************************************************************************************/

class CLibRayMarchingRayMarching : public virtual ILibRayMarchingRayMarching {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/

	std::vector<CLibRayMarchingPrimitive*> m_Primitives;

	LibRayMarchingProgressCallback m_ProgressCallback;

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/

	LibRayMarching_uint32 GetLightCount ();

	void GetLight (const LibRayMarching_uint32 nIndex, sLibRayMarchingVector & sPosition, sLibRayMarchingVector & sColor);

	void AddLight (const sLibRayMarchingVector Position, const sLibRayMarchingVector Color);

	void DeleteLight (const LibRayMarching_uint32 nIndex);

	LibRayMarching_uint32 GetPrimitiveCount ();

	ILibRayMarchingPrimitive * GetPrimitive (const LibRayMarching_uint32 nIndex);

	void AddPrimitive (ILibRayMarchingPrimitive* pPrimitive);

	void RemovePrimitive (const LibRayMarching_uint32 nIndex);

	void SetScreenSize (const LibRayMarching_uint32 nWidth, const LibRayMarching_uint32 nHeight);

	void SetViewport (const sLibRayMarchingVector Eye, const sLibRayMarchingVector Dir, const sLibRayMarchingVector Up, const LibRayMarching_double dFOV);

	void RenderScene ();

	LibRayMarching_uint32 RenderPixel (const LibRayMarching_double dX, const LibRayMarching_double dY);

	void SetProgressCallback (const LibRayMarchingProgressCallback pProgressCallback);

};

} // namespace Impl
} // namespace LibRayMarching

#endif // __LIBRAYMARCHING_LIBRAYMARCHINGRAYMARCHING
