/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CBaseClass

*/

#include "libraymarching_baseclass.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CBaseClass 
**************************************************************************************************************************/

bool CBaseClass::GetLastErrorMessage (std::string & sErrorMessage)
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

void CBaseClass::ClearErrorMessages ()
{
	m_errors.clear();
}

void CBaseClass::RegisterErrorMessage (const std::string & sErrorMessage)
{
	m_errors.push_back(sErrorMessage);
}

void CBaseClass::IncRefCount()
{
	m_refcount++;
}

bool CBaseClass::DecRefCount()
{
	m_refcount--;
	if (!m_refcount) {
		delete this;
		return true;
	}
	return false;
}