/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is the class declaration of CLibRayMarchingBaseClass

*/


#ifndef __LIBRAYMARCHING_LIBRAYMARCHINGBASECLASS
#define __LIBRAYMARCHING_LIBRAYMARCHINGBASECLASS

#include "libraymarching_interfaces.hpp"
#include <vector>


// Include custom headers here.


namespace LibRayMarching {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CLibRayMarchingBaseClass 
**************************************************************************************************************************/

class CLibRayMarchingBaseClass : public virtual ILibRayMarchingBaseClass {
private:

	std::vector<std::string> m_errors;

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

	bool GetLastErrorMessage (std::string & sErrorMessage);

	void ClearErrorMessages ();

	void RegisterErrorMessage (const std::string & sErrorMessage);


	/**
	* Public member functions to implement.
	*/

};

} // namespace Impl
} // namespace LibRayMarching

#endif // __LIBRAYMARCHING_LIBRAYMARCHINGBASECLASS
