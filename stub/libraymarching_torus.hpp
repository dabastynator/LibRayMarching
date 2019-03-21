/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CLibRayMarchingTorus

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGTORUS
#define __LIBRAYMARCHING_LIBRAYMARCHINGTORUS

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
 Class declaration of CLibRayMarchingTorus 
**************************************************************************************************************************/

class CLibRayMarchingTorus : public virtual ILibRayMarchingTorus, public virtual CLibRayMarchingPrimitive {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/
	TorusPtr m_Torus;

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/

	CLibRayMarchingTorus(TorusPtr torus);

	LibRayMarching_double GetBigRadius ();

	void SetBigRadius (const LibRayMarching_double dBigRadius);

	LibRayMarching_double GetSmallRadius ();

	void SetSmallRadius (const LibRayMarching_double dSmallRadius);

};

} // namespace Impl
} // namespace LibRayMarching

#pragma warning( pop )
#endif // __LIBRAYMARCHING_LIBRAYMARCHINGTORUS
