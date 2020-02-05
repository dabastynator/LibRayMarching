/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CCapsule

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGCAPSULE
#define __LIBRAYMARCHING_LIBRAYMARCHINGCAPSULE

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
 Class declaration of CCapsule 
**************************************************************************************************************************/

class CCapsule : public virtual ICapsule, public virtual CPrimitive {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/
	std::shared_ptr<Capsule> m_Capsule;

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/
	CCapsule(CapsulePtr capsule);

	LibRayMarching_double GetRadius ();

	void SetRadius (const LibRayMarching_double dRadius);

	sLibRayMarchingVector GetPoint1 ();

	void SetPoint1 (const sLibRayMarchingVector Point1);

	sLibRayMarchingVector GetPoint2 ();

	void SetPoint2 (const sLibRayMarchingVector Point2);
};

} // namespace Impl
} // namespace LibRayMarching

#pragma warning( pop )
#endif // __LIBRAYMARCHING_LIBRAYMARCHINGCAPSULE
