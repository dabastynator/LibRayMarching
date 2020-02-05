/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CSphere

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGSPHERE
#define __LIBRAYMARCHING_LIBRAYMARCHINGSPHERE

#include "libraymarching_interfaces.hpp"

// Parent classes
#include "libraymarching_primitive.hpp"
#pragma warning( push)
#pragma warning( disable : 4250)

// Include custom headers here.
#include <memory>
#include "primitives.h"

namespace LibRayMarching {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CSphere 
**************************************************************************************************************************/

class CSphere : public virtual ISphere, public virtual CPrimitive {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/
	std::shared_ptr<Sphere> m_Sphere;

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/

	CSphere(SpherePtr sphere);

	LibRayMarching_double GetRadius ();

	void SetRadius (const LibRayMarching_double dRadius);

	void Initialize();

};

} // namespace Impl
} // namespace LibRayMarching

#pragma warning( pop )
#endif // __LIBRAYMARCHING_LIBRAYMARCHINGSPHERE
