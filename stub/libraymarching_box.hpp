/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CLibRayMarchingBox

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGBOX
#define __LIBRAYMARCHING_LIBRAYMARCHINGBOX

#include "libraymarching_interfaces.hpp"

// Parent classes
#include "libraymarching_primitive.hpp"
#include "vector.h"
#pragma warning( push)
#pragma warning( disable : 4250)

// Include custom headers here.


namespace LibRayMarching {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CLibRayMarchingBox 
**************************************************************************************************************************/

class CLibRayMarchingBox : public virtual ILibRayMarchingBox, public virtual CLibRayMarchingPrimitive {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/
	Vector m_Dimension;

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/

	sLibRayMarchingVector GetDimensions ();

	void SetDimensions (const sLibRayMarchingVector Dimensions);

	double DistanceTo(Vector vPoint) const;

};

} // namespace Impl
} // namespace LibRayMarching

#pragma warning( pop )
#endif // __LIBRAYMARCHING_LIBRAYMARCHINGBOX
