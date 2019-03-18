/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CLibRayMarchingPlane

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGPLANE
#define __LIBRAYMARCHING_LIBRAYMARCHINGPLANE

#include "libraymarching_interfaces.hpp"
#include "libraymarching_primitive.hpp"
#include "vector.h"
#pragma warning( push)
#pragma warning( disable : 4250)

// Include custom headers here.
#include "primitives.h"


namespace LibRayMarching {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CLibRayMarchingPlane 
**************************************************************************************************************************/

class CLibRayMarchingPlane : public virtual ILibRayMarchingPlane, public virtual CLibRayMarchingPrimitive {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/

	std::shared_ptr<Plane> m_Plane;

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/

	CLibRayMarchingPlane(PlanePtr plane);

	sLibRayMarchingVector GetNormal ();

	void SetNormal (const sLibRayMarchingVector Normal);
};

} // namespace Impl
} // namespace LibRayMarching

#pragma warning( pop )
#endif // __LIBRAYMARCHING_LIBRAYMARCHINGPLANE
