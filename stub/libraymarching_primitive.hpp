/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CPrimitive

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGPRIMITIVE
#define __LIBRAYMARCHING_LIBRAYMARCHINGPRIMITIVE

#include <memory>

#include "libraymarching_interfaces.hpp"
#include "libraymarching_baseclass.hpp"
#include "libraymarching_utils.hpp"

#include "vector.h"
#include "types.h"
#include "matrix.h"
#include "primitives.h"

// Include custom headers here.


namespace LibRayMarching {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CPrimitive 
**************************************************************************************************************************/

class CPrimitive : public virtual IPrimitive, public virtual CBaseClass {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/

	PrimitivePtr m_Primitive;

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/

	CPrimitive(PrimitivePtr sPrimitive);

	void IdentityPosition ();

	void Translate (const LibRayMarching::sVector Translation);

	void Rotate (const LibRayMarching::sVector Axis, const LibRayMarching_double dRadian);

	void Scale (const LibRayMarching::sVector Scale);

	void SetMaterial (const  LibRayMarching::sMaterial Material);

	Material* GetMaterial() { return m_Primitive->GetMaterial(); };

	void SetGlow(const LibRayMarching::sGlow Glow);

	void SetSinusDistortion (const LibRayMarching_double dDistortionFactor, const LibRayMarching_double dInterval);

	PrimitivePtr GetPrimitive() { return m_Primitive; };

};

} // namespace Impl
} // namespace LibRayMarching

#endif // __LIBRAYMARCHING_LIBRAYMARCHINGPRIMITIVE
