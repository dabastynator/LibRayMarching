/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CCylinder

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGCYLINDER
#define __LIBRAYMARCHING_LIBRAYMARCHINGCYLINDER

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
 Class declaration of CCylinder 
**************************************************************************************************************************/

class CCylinder : public virtual ICylinder, public virtual CPrimitive {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/
	CylinderPtr m_Cylinder;

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/

	CCylinder(CylinderPtr cylinder);

	LibRayMarching_double GetRadius ();

	void SetRadius (const LibRayMarching_double dRadius);

	LibRayMarching_double GetHeight ();

	void SetHeight (const LibRayMarching_double dHeight);

};

} // namespace Impl
} // namespace LibRayMarching

#pragma warning( pop )
#endif // __LIBRAYMARCHING_LIBRAYMARCHINGCYLINDER
