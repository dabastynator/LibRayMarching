/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CPrimitiveGroup

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGPRIMITIVEGROUP
#define __LIBRAYMARCHING_LIBRAYMARCHINGPRIMITIVEGROUP

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
 Class declaration of CPrimitiveGroup 
**************************************************************************************************************************/

class CPrimitiveGroup : public virtual IPrimitiveGroup, public virtual CPrimitive {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/
	PrimitiveGroupPtr m_Group;

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/
	CPrimitiveGroup(PrimitiveGroupPtr group);

	LibRayMarching_uint32 GetPrimitiveCount ();

	IPrimitive * GetPrimitive (const LibRayMarching_uint32 nIndex);

	void AddPrimitive (IPrimitive* pPrimitive);

	void RemovePrimitive (const LibRayMarching_uint32 nIndex);

	void SetGroupAction (const eLibRayMarchingGroupAction eGroupAction);

	eLibRayMarchingGroupAction GetGroupAction ();

};

} // namespace Impl
} // namespace LibRayMarching

#pragma warning( pop )
#endif // __LIBRAYMARCHING_LIBRAYMARCHINGPRIMITIVEGROUP
