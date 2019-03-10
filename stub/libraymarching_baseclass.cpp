/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingBaseClass

*/

#include "libraymarching_baseclass.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingBaseClass 
**************************************************************************************************************************/

bool CLibRayMarchingBaseClass::GetLastErrorMessage (std::string & sErrorMessage)
{
	auto iIterator = m_errors.rbegin();
	if (iIterator != m_errors.rend()) {
		sErrorMessage = *iIterator;
		return true;
	}else {
		sErrorMessage = "";
		return false;
	}
}

void CLibRayMarchingBaseClass::ClearErrorMessages ()
{
	m_errors.clear();
}

void CLibRayMarchingBaseClass::RegisterErrorMessage (const std::string & sErrorMessage)
{
	m_errors.push_back(sErrorMessage);
}

