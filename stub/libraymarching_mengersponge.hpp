/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CMengerSponge

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGMENGERSPONGE
#define __LIBRAYMARCHING_LIBRAYMARCHINGMENGERSPONGE

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
 Class declaration of CMengerSponge 
**************************************************************************************************************************/

class CMengerSponge : public virtual IMengerSponge, public virtual CPrimitive {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/
	MengerSpongePtr m_MengerSonge;

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/
	CMengerSponge(MengerSpongePtr mengerSonge);

	LibRayMarching_uint32 GetStepCount ();

	void SetStepCount (const LibRayMarching_uint32 nStepCount);

};

} // namespace Impl
} // namespace LibRayMarching

#pragma warning( pop )
#endif // __LIBRAYMARCHING_LIBRAYMARCHINGMENGERSPONGE
