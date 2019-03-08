/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.4.0.

Abstract: This is an autogenerated plain C Header file with basic types in
order to allow an easy use of Ray Marching Library

Interface version: 0.9.0

*/

#ifndef __LIBRAYMARCHING_TYPES_HEADER
#define __LIBRAYMARCHING_TYPES_HEADER

/*************************************************************************************************************************
 Scalar types definition
**************************************************************************************************************************/

#ifdef LIBRAYMARCHING_USELEGACYINTEGERTYPES

typedef unsigned char LibRayMarching_uint8;
typedef unsigned short LibRayMarching_uint16 ;
typedef unsigned int LibRayMarching_uint32;
typedef unsigned long long LibRayMarching_uint64;
typedef char LibRayMarching_int8;
typedef short LibRayMarching_int16;
typedef int LibRayMarching_int32;
typedef long long LibRayMarching_int64;

#else // LIBRAYMARCHING_USELEGACYINTEGERTYPES

#include <stdint.h>

typedef uint8_t LibRayMarching_uint8;
typedef uint16_t LibRayMarching_uint16;
typedef uint32_t LibRayMarching_uint32;
typedef uint64_t LibRayMarching_uint64;
typedef int8_t LibRayMarching_int8;
typedef int16_t LibRayMarching_int16;
typedef int32_t LibRayMarching_int32;
typedef int64_t LibRayMarching_int64 ;

#endif // LIBRAYMARCHING_USELEGACYINTEGERTYPES

typedef float LibRayMarching_single;
typedef double LibRayMarching_double;

/*************************************************************************************************************************
 General type definitions
**************************************************************************************************************************/

typedef LibRayMarching_int32 LibRayMarchingResult;
typedef void * LibRayMarchingHandle;

/*************************************************************************************************************************
 Version for LibRayMarching
**************************************************************************************************************************/

#define LIBRAYMARCHING_VERSION_MAJOR 0
#define LIBRAYMARCHING_VERSION_MINOR 9
#define LIBRAYMARCHING_VERSION_MICRO 0

/*************************************************************************************************************************
 Error constants for LibRayMarching
**************************************************************************************************************************/

#define LIBRAYMARCHING_SUCCESS 0
#define LIBRAYMARCHING_ERROR_NOTIMPLEMENTED 1
#define LIBRAYMARCHING_ERROR_INVALIDPARAM 2
#define LIBRAYMARCHING_ERROR_INVALIDCAST 3
#define LIBRAYMARCHING_ERROR_BUFFERTOOSMALL 4
#define LIBRAYMARCHING_ERROR_GENERICEXCEPTION 5
#define LIBRAYMARCHING_ERROR_COULDNOTLOADLIBRARY 6
#define LIBRAYMARCHING_ERROR_COULDNOTFINDLIBRARYEXPORT 7
#define LIBRAYMARCHING_ERROR_INCOMPATIBLEBINARYVERSION 8
#define LIBRAYMARCHING_ERROR_INDEXOUTOFBOUNDS 9

/*************************************************************************************************************************
 Declaration of handle classes 
**************************************************************************************************************************/

typedef LibRayMarchingHandle LibRayMarching_BaseClass;
typedef LibRayMarchingHandle LibRayMarching_Primitive;
typedef LibRayMarchingHandle LibRayMarching_Sphere;
typedef LibRayMarchingHandle LibRayMarching_Capsule;
typedef LibRayMarchingHandle LibRayMarching_Plane;
typedef LibRayMarchingHandle LibRayMarching_Box;
typedef LibRayMarchingHandle LibRayMarching_PrimitiveGroup;
typedef LibRayMarchingHandle LibRayMarching_RayMarching;

/*************************************************************************************************************************
 Declaration of structs
**************************************************************************************************************************/

#pragma pack (1)

typedef struct {
    LibRayMarching_double m_x;
    LibRayMarching_double m_y;
    LibRayMarching_double m_z;
} sLibRayMarchingVector;

typedef struct {
    LibRayMarching_double m_Red;
    LibRayMarching_double m_Green;
    LibRayMarching_double m_Blue;
    LibRayMarching_double m_Ambient;
    LibRayMarching_double m_Diffuse;
    LibRayMarching_double m_Specular;
    LibRayMarching_double m_SpecularAlpha;
    LibRayMarching_double m_Reflection;
} sLibRayMarchingMaterial;

#pragma pack ()

/*************************************************************************************************************************
 Declaration of function pointers 
**************************************************************************************************************************/

/**
* LibRayMarchingProgressCallback - Callback to report calculation progress and query whether it should be aborted
*
* @param[in] fProgressPercentage - How far has the calculation progressed?
* @param[out] pShouldAbort - Should the calculation be aborted?
*/
typedef void(*LibRayMarchingProgressCallback)(LibRayMarching_single, bool*);

#endif // __LIBRAYMARCHING_TYPES_HEADER
