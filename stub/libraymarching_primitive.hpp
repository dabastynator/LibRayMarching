/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CLibRayMarchingPrimitive

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGPRIMITIVE
#define __LIBRAYMARCHING_LIBRAYMARCHINGPRIMITIVE

#include "libraymarching_interfaces.hpp"
#include "vector.h"
#include "matrix.h"

// Include custom headers here.


namespace LibRayMarching {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CLibRayMarchingPrimitive 
**************************************************************************************************************************/

class CLibRayMarchingPrimitive : public virtual ILibRayMarchingPrimitive {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/

	Matrix m_ModelToWorld;

	sLibRayMarchingMaterial m_Material;

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/

	void IdentityPosition ();

	void Translate (const sLibRayMarchingVector Translation);

	void Rotate (const sLibRayMarchingVector Axis, const LibRayMarching_double dRadian);

	void Scale (const sLibRayMarchingVector Scale);

	void SetMaterial (const sLibRayMarchingMaterial Material);

	double DistanceTo(Vector vPoint);

};

} // namespace Impl
} // namespace LibRayMarching

#endif // __LIBRAYMARCHING_LIBRAYMARCHINGPRIMITIVE
