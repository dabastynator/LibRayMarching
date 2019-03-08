/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CLibRayMarchingSphere

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGSPHERE
#define __LIBRAYMARCHING_LIBRAYMARCHINGSPHERE

#include "libraymarching_interfaces.hpp"

// Parent classes
#include "libraymarching_primitive.hpp"
#pragma warning( push)
#pragma warning( disable : 4250)

// Include custom headers here.


namespace LibRayMarching {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CLibRayMarchingSphere 
**************************************************************************************************************************/

class CLibRayMarchingSphere : public virtual ILibRayMarchingSphere, public virtual CLibRayMarchingPrimitive {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/

	double m_Radius;

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/

	LibRayMarching_double GetRadius ();

	void SetRadius (const LibRayMarching_double dRadius);

};

} // namespace Impl
} // namespace LibRayMarching

#pragma warning( pop )
#endif // __LIBRAYMARCHING_LIBRAYMARCHINGSPHERE
