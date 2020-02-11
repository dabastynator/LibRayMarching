/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.6.0.

Abstract: This is an autogenerated C++ Header file with the basic internal
 exception type in order to allow an easy use of Ray Marching Library

Interface version: 2.0.0

*/

#ifndef __LIBRAYMARCHING_INTERFACEEXCEPTION_HEADER
#define __LIBRAYMARCHING_INTERFACEEXCEPTION_HEADER

#include <exception>
#include <stdexcept>
#include "libraymarching_types.hpp"

/*************************************************************************************************************************
 Class ELibRayMarchingInterfaceException
**************************************************************************************************************************/


class ELibRayMarchingInterfaceException : public std::exception {
protected:
	/**
	* Error code for the Exception.
	*/
	LibRayMarchingResult m_errorCode;
	/**
	* Error message for the Exception.
	*/
	std::string m_errorMessage;

public:
	/**
	* Exception Constructor.
	*/
	ELibRayMarchingInterfaceException(LibRayMarchingResult errorCode);

	/**
	* Custom Exception Constructor.
	*/
	ELibRayMarchingInterfaceException(LibRayMarchingResult errorCode, std::string errorMessage);

	/**
	* Returns error code
	*/
	LibRayMarchingResult getErrorCode();
	/**
	* Returns error message
	*/
	const char* what() const noexcept override;
};

#endif // __LIBRAYMARCHING_INTERFACEEXCEPTION_HEADER
