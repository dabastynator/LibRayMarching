/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.6.0.

Abstract: This is an autogenerated C++ Implementation file with the basic internal
 exception type in order to allow an easy use of Ray Marching Library

Interface version: 2.0.0

*/


#include <string>

#include "libraymarching_interfaceexception.hpp"

/*************************************************************************************************************************
 Class ELibRayMarchingInterfaceException
**************************************************************************************************************************/
ELibRayMarchingInterfaceException::ELibRayMarchingInterfaceException(LibRayMarchingResult errorCode)
	: m_errorMessage("LibRayMarching Error " + std::to_string (errorCode))
{
	m_errorCode = errorCode;
}

ELibRayMarchingInterfaceException::ELibRayMarchingInterfaceException(LibRayMarchingResult errorCode, std::string errorMessage)
	: m_errorMessage(errorMessage + " (" + std::to_string (errorCode) + ")")
{
	m_errorCode = errorCode;
}

LibRayMarchingResult ELibRayMarchingInterfaceException::getErrorCode ()
{
	return m_errorCode;
}

const char * ELibRayMarchingInterfaceException::what () const noexcept
{
	return m_errorMessage.c_str();
}

