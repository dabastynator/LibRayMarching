/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CLibRayMarchingMaterial

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGMATERIAL
#define __LIBRAYMARCHING_LIBRAYMARCHINGMATERIAL

#include "libraymarching_interfaces.hpp"


// Include custom headers here.


namespace LibRayMarching {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CLibRayMarchingMaterial 
**************************************************************************************************************************/

class CLibRayMarchingMaterial : public virtual ILibRayMarchingMaterial {
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

	LibRayMarching_double GetAmbient ();

	void SetAmbient (const LibRayMarching_double dAmbient);

	LibRayMarching_double GetDiffuse ();

	void SetDiffuse (const LibRayMarching_double dDiffuse);

	LibRayMarching_double GetSpecular ();

	void SetSpecular (const LibRayMarching_double dSpecular);

	LibRayMarching_double GetSpecularAlpha ();

	void SetSpecularAlpha (const LibRayMarching_double dSpecularAlpha);

	LibRayMarching_double GetReflection ();

	void SetReflection (const LibRayMarching_double dReflection);

};

} // namespace Impl
} // namespace LibRayMarching

#endif // __LIBRAYMARCHING_LIBRAYMARCHINGMATERIAL
