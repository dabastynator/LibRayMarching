/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CQuaternionFractal

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGQUATERNIONFRACTAL
#define __LIBRAYMARCHING_LIBRAYMARCHINGQUATERNIONFRACTAL

#include "libraymarching_interfaces.hpp"

// Parent classes
#include "libraymarching_primitive.hpp"
#pragma warning( push)
#pragma warning( disable : 4250)

// Include custom headers here.
#include "primitives.h"


namespace LibRayMarching {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CQuaternionFractal 
**************************************************************************************************************************/

class CQuaternionFractal : public virtual IQuaternionFractal, public virtual CPrimitive {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/
	QuaternionFractalPtr m_Fractal;

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/
	CQuaternionFractal(QuaternionFractalPtr fractal);

	void GetQuaternion (LibRayMarching_double & dR, LibRayMarching_double & dI, LibRayMarching_double & dJ, LibRayMarching_double & dK);

	void SetQuaternion (const LibRayMarching_double dR, const LibRayMarching_double dI, const LibRayMarching_double dJ, const LibRayMarching_double dK);

	LibRayMarching_uint32 GetIterations ();

	void SetIterations (const LibRayMarching_uint32 nIterations);

};

} // namespace Impl
} // namespace LibRayMarching

#pragma warning( pop )
#endif // __LIBRAYMARCHING_LIBRAYMARCHINGQUATERNIONFRACTAL
