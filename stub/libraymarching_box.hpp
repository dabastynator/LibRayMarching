/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CBox

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGBOX
#define __LIBRAYMARCHING_LIBRAYMARCHINGBOX

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
 Class declaration of CBox 
**************************************************************************************************************************/

class CBox : public virtual IBox, public virtual CPrimitive {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/
	BoxPtr m_Box;

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/

	CBox(BoxPtr box);

	sLibRayMarchingVector GetDimensions ();

	void SetDimensions (const sLibRayMarchingVector Dimensions);

};

} // namespace Impl
} // namespace LibRayMarching

#pragma warning( pop )
#endif // __LIBRAYMARCHING_LIBRAYMARCHINGBOX
