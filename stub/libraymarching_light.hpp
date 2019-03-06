/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CLibRayMarchingLight

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGLIGHT
#define __LIBRAYMARCHING_LIBRAYMARCHINGLIGHT

#include "libraymarching_interfaces.hpp"


// Include custom headers here.


namespace LibRayMarching {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CLibRayMarchingLight 
**************************************************************************************************************************/

class CLibRayMarchingLight : public virtual ILibRayMarchingLight {
private:

	/**
	* Put private members here.
	*/

protected:

	/**
	* Put protected members here.
	*/

public:

	/**
	* Put additional public members here. They will not be visible in the external API.
	*/


	/**
	* Public member functions to implement.
	*/

	sLibRayMarchingVector GetColor ();

	void SetColor (const sLibRayMarchingVector Color);

	sLibRayMarchingVector GetPosition ();

	void SetPosition (const sLibRayMarchingVector Position);

};

} // namespace Impl
} // namespace LibRayMarching

#endif // __LIBRAYMARCHING_LIBRAYMARCHINGLIGHT
