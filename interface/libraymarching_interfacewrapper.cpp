/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.4.0.

Abstract: This is an autogenerated C++ implementation file in order to allow easy
development of Ray Marching Library. The functions in this file need to be implemented. It needs to be generated only once.

Interface version: 0.9.0

*/

#include "libraymarching.h"
#include "libraymarching_interfaces.hpp"
#include "libraymarching_interfaceexception.hpp"

using namespace LibRayMarching::Impl;

extern "C" {


/*************************************************************************************************************************
 Class implementation for Primitive
**************************************************************************************************************************/
LibRayMarchingResult libraymarching_primitive_identityposition (LibRayMarching_Primitive pPrimitive)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pPrimitive;
		ILibRayMarchingPrimitive* pIPrimitive = dynamic_cast<ILibRayMarchingPrimitive*>(pIBaseClass);
		if (!pIPrimitive)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIPrimitive->IdentityPosition();


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_primitive_translate (LibRayMarching_Primitive pPrimitive, const sLibRayMarchingVector * pTranslation)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pPrimitive;
		ILibRayMarchingPrimitive* pIPrimitive = dynamic_cast<ILibRayMarchingPrimitive*>(pIBaseClass);
		if (!pIPrimitive)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIPrimitive->Translate(*pTranslation);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_primitive_rotate (LibRayMarching_Primitive pPrimitive, const sLibRayMarchingVector * pAxis, LibRayMarching_double dRadian)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pPrimitive;
		ILibRayMarchingPrimitive* pIPrimitive = dynamic_cast<ILibRayMarchingPrimitive*>(pIBaseClass);
		if (!pIPrimitive)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIPrimitive->Rotate(*pAxis, dRadian);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_primitive_scale (LibRayMarching_Primitive pPrimitive, const sLibRayMarchingVector * pScale)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pPrimitive;
		ILibRayMarchingPrimitive* pIPrimitive = dynamic_cast<ILibRayMarchingPrimitive*>(pIBaseClass);
		if (!pIPrimitive)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIPrimitive->Scale(*pScale);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_primitive_setmaterial (LibRayMarching_Primitive pPrimitive, const sLibRayMarchingMaterial * pMaterial)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pPrimitive;
		ILibRayMarchingPrimitive* pIPrimitive = dynamic_cast<ILibRayMarchingPrimitive*>(pIBaseClass);
		if (!pIPrimitive)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIPrimitive->SetMaterial(*pMaterial);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}


/*************************************************************************************************************************
 Class implementation for Sphere
**************************************************************************************************************************/
LibRayMarchingResult libraymarching_sphere_getradius (LibRayMarching_Sphere pSphere, LibRayMarching_double * pRadius)
{
	try {
		if (pRadius == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pSphere;
		ILibRayMarchingSphere* pISphere = dynamic_cast<ILibRayMarchingSphere*>(pIBaseClass);
		if (!pISphere)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		*pRadius = pISphere->GetRadius();


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_sphere_setradius (LibRayMarching_Sphere pSphere, LibRayMarching_double dRadius)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pSphere;
		ILibRayMarchingSphere* pISphere = dynamic_cast<ILibRayMarchingSphere*>(pIBaseClass);
		if (!pISphere)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pISphere->SetRadius(dRadius);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}


/*************************************************************************************************************************
 Class implementation for Capsule
**************************************************************************************************************************/
LibRayMarchingResult libraymarching_capsule_getradius (LibRayMarching_Capsule pCapsule, LibRayMarching_double * pRadius)
{
	try {
		if (pRadius == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pCapsule;
		ILibRayMarchingCapsule* pICapsule = dynamic_cast<ILibRayMarchingCapsule*>(pIBaseClass);
		if (!pICapsule)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		*pRadius = pICapsule->GetRadius();


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_capsule_setradius (LibRayMarching_Capsule pCapsule, LibRayMarching_double dRadius)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pCapsule;
		ILibRayMarchingCapsule* pICapsule = dynamic_cast<ILibRayMarchingCapsule*>(pIBaseClass);
		if (!pICapsule)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pICapsule->SetRadius(dRadius);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_capsule_getpoint1 (LibRayMarching_Capsule pCapsule, sLibRayMarchingVector * pPoint1)
{
	try {
		if (pPoint1 == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pCapsule;
		ILibRayMarchingCapsule* pICapsule = dynamic_cast<ILibRayMarchingCapsule*>(pIBaseClass);
		if (!pICapsule)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		*pPoint1 = pICapsule->GetPoint1();


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_capsule_setpoint1 (LibRayMarching_Capsule pCapsule, const sLibRayMarchingVector * pPoint1)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pCapsule;
		ILibRayMarchingCapsule* pICapsule = dynamic_cast<ILibRayMarchingCapsule*>(pIBaseClass);
		if (!pICapsule)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pICapsule->SetPoint1(*pPoint1);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_capsule_getpoint2 (LibRayMarching_Capsule pCapsule, sLibRayMarchingVector * pPoint2)
{
	try {
		if (pPoint2 == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pCapsule;
		ILibRayMarchingCapsule* pICapsule = dynamic_cast<ILibRayMarchingCapsule*>(pIBaseClass);
		if (!pICapsule)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		*pPoint2 = pICapsule->GetPoint2();


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_capsule_setpoint2 (LibRayMarching_Capsule pCapsule, const sLibRayMarchingVector * pPoint2)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pCapsule;
		ILibRayMarchingCapsule* pICapsule = dynamic_cast<ILibRayMarchingCapsule*>(pIBaseClass);
		if (!pICapsule)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pICapsule->SetPoint2(*pPoint2);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}


/*************************************************************************************************************************
 Class implementation for Plane
**************************************************************************************************************************/
LibRayMarchingResult libraymarching_plane_getorigin (LibRayMarching_Plane pPlane, sLibRayMarchingVector * pOrigin)
{
	try {
		if (pOrigin == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pPlane;
		ILibRayMarchingPlane* pIPlane = dynamic_cast<ILibRayMarchingPlane*>(pIBaseClass);
		if (!pIPlane)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		*pOrigin = pIPlane->GetOrigin();


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_plane_setorigin (LibRayMarching_Plane pPlane, const sLibRayMarchingVector * pOrigin)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pPlane;
		ILibRayMarchingPlane* pIPlane = dynamic_cast<ILibRayMarchingPlane*>(pIBaseClass);
		if (!pIPlane)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIPlane->SetOrigin(*pOrigin);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_plane_getnormal (LibRayMarching_Plane pPlane, sLibRayMarchingVector * pNormal)
{
	try {
		if (pNormal == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pPlane;
		ILibRayMarchingPlane* pIPlane = dynamic_cast<ILibRayMarchingPlane*>(pIBaseClass);
		if (!pIPlane)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		*pNormal = pIPlane->GetNormal();


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_plane_setnormal (LibRayMarching_Plane pPlane, const sLibRayMarchingVector * pNormal)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pPlane;
		ILibRayMarchingPlane* pIPlane = dynamic_cast<ILibRayMarchingPlane*>(pIBaseClass);
		if (!pIPlane)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIPlane->SetNormal(*pNormal);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}


/*************************************************************************************************************************
 Class implementation for Box
**************************************************************************************************************************/
LibRayMarchingResult libraymarching_box_getdimensions (LibRayMarching_Box pBox, sLibRayMarchingVector * pDimensions)
{
	try {
		if (pDimensions == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pBox;
		ILibRayMarchingBox* pIBox = dynamic_cast<ILibRayMarchingBox*>(pIBaseClass);
		if (!pIBox)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		*pDimensions = pIBox->GetDimensions();


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_box_setdimensions (LibRayMarching_Box pBox, const sLibRayMarchingVector * pDimensions)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pBox;
		ILibRayMarchingBox* pIBox = dynamic_cast<ILibRayMarchingBox*>(pIBaseClass);
		if (!pIBox)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIBox->SetDimensions(*pDimensions);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}


/*************************************************************************************************************************
 Class implementation for PrimitiveGroup
**************************************************************************************************************************/
LibRayMarchingResult libraymarching_primitivegroup_getprimitivecount (LibRayMarching_PrimitiveGroup pPrimitiveGroup, LibRayMarching_uint32 * pCount)
{
	try {
		if (pCount == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pPrimitiveGroup;
		ILibRayMarchingPrimitiveGroup* pIPrimitiveGroup = dynamic_cast<ILibRayMarchingPrimitiveGroup*>(pIBaseClass);
		if (!pIPrimitiveGroup)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		*pCount = pIPrimitiveGroup->GetPrimitiveCount();


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_primitivegroup_getprimitive (LibRayMarching_PrimitiveGroup pPrimitiveGroup, LibRayMarching_uint32 nIndex, LibRayMarching_Primitive * pPrimitive)
{
	try {
		if (pPrimitive == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pPrimitiveGroup;
		ILibRayMarchingPrimitiveGroup* pIPrimitiveGroup = dynamic_cast<ILibRayMarchingPrimitiveGroup*>(pIBaseClass);
		if (!pIPrimitiveGroup)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);

		ILibRayMarchingBaseClass* pBasePrimitive(nullptr);

		pBasePrimitive = pIPrimitiveGroup->GetPrimitive(nIndex);

		*pPrimitive = (ILibRayMarchingBaseClass*)(pBasePrimitive);

		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_primitivegroup_addprimitive (LibRayMarching_PrimitiveGroup pPrimitiveGroup, LibRayMarching_Primitive pPrimitive)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pPrimitiveGroup;
		ILibRayMarchingPrimitiveGroup* pIPrimitiveGroup = dynamic_cast<ILibRayMarchingPrimitiveGroup*>(pIBaseClass);
		if (!pIPrimitiveGroup)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);

		ILibRayMarchingBaseClass* pIBaseClassPrimitive = (ILibRayMarchingBaseClass *)pPrimitive;
		ILibRayMarchingPrimitive* pIPrimitive = dynamic_cast<ILibRayMarchingPrimitive*>(pIBaseClassPrimitive);
		if (!pIPrimitive)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIPrimitiveGroup->AddPrimitive(pIPrimitive);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_primitivegroup_removeprimitive (LibRayMarching_PrimitiveGroup pPrimitiveGroup, LibRayMarching_uint32 nIndex)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pPrimitiveGroup;
		ILibRayMarchingPrimitiveGroup* pIPrimitiveGroup = dynamic_cast<ILibRayMarchingPrimitiveGroup*>(pIBaseClass);
		if (!pIPrimitiveGroup)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIPrimitiveGroup->RemovePrimitive(nIndex);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}


/*************************************************************************************************************************
 Class implementation for RayMarching
**************************************************************************************************************************/
LibRayMarchingResult libraymarching_raymarching_getlightcount (LibRayMarching_RayMarching pRayMarching, LibRayMarching_uint32 * pCount)
{
	try {
		if (pCount == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pRayMarching;
		ILibRayMarchingRayMarching* pIRayMarching = dynamic_cast<ILibRayMarchingRayMarching*>(pIBaseClass);
		if (!pIRayMarching)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		*pCount = pIRayMarching->GetLightCount();


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_raymarching_getlight (LibRayMarching_RayMarching pRayMarching, LibRayMarching_uint32 nIndex, sLibRayMarchingVector * pPosition, sLibRayMarchingVector * pColor)
{
	try {
		if (!pPosition)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);
		if (!pColor)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pRayMarching;
		ILibRayMarchingRayMarching* pIRayMarching = dynamic_cast<ILibRayMarchingRayMarching*>(pIBaseClass);
		if (!pIRayMarching)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);

		sLibRayMarchingVector Position;
		sLibRayMarchingVector Color;

		pIRayMarching->GetLight(nIndex, Position, Color);

		*pPosition = Position;
		*pColor = Color;

		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_raymarching_addlight (LibRayMarching_RayMarching pRayMarching, const sLibRayMarchingVector * pPosition, const sLibRayMarchingVector * pColor)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pRayMarching;
		ILibRayMarchingRayMarching* pIRayMarching = dynamic_cast<ILibRayMarchingRayMarching*>(pIBaseClass);
		if (!pIRayMarching)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIRayMarching->AddLight(*pPosition, *pColor);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_raymarching_deletelight (LibRayMarching_RayMarching pRayMarching, LibRayMarching_uint32 nIndex)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pRayMarching;
		ILibRayMarchingRayMarching* pIRayMarching = dynamic_cast<ILibRayMarchingRayMarching*>(pIBaseClass);
		if (!pIRayMarching)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIRayMarching->DeleteLight(nIndex);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_raymarching_getprimitivecount (LibRayMarching_RayMarching pRayMarching, LibRayMarching_uint32 * pCount)
{
	try {
		if (pCount == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pRayMarching;
		ILibRayMarchingRayMarching* pIRayMarching = dynamic_cast<ILibRayMarchingRayMarching*>(pIBaseClass);
		if (!pIRayMarching)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		*pCount = pIRayMarching->GetPrimitiveCount();


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_raymarching_getprimitive (LibRayMarching_RayMarching pRayMarching, LibRayMarching_uint32 nIndex, LibRayMarching_Primitive * pPrimitive)
{
	try {
		if (pPrimitive == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pRayMarching;
		ILibRayMarchingRayMarching* pIRayMarching = dynamic_cast<ILibRayMarchingRayMarching*>(pIBaseClass);
		if (!pIRayMarching)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);

		ILibRayMarchingBaseClass* pBasePrimitive(nullptr);

		pBasePrimitive = pIRayMarching->GetPrimitive(nIndex);

		*pPrimitive = (ILibRayMarchingBaseClass*)(pBasePrimitive);

		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_raymarching_addprimitive (LibRayMarching_RayMarching pRayMarching, LibRayMarching_Primitive pPrimitive)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pRayMarching;
		ILibRayMarchingRayMarching* pIRayMarching = dynamic_cast<ILibRayMarchingRayMarching*>(pIBaseClass);
		if (!pIRayMarching)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);

		ILibRayMarchingBaseClass* pIBaseClassPrimitive = (ILibRayMarchingBaseClass *)pPrimitive;
		ILibRayMarchingPrimitive* pIPrimitive = dynamic_cast<ILibRayMarchingPrimitive*>(pIBaseClassPrimitive);
		if (!pIPrimitive)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIRayMarching->AddPrimitive(pIPrimitive);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_raymarching_removeprimitive (LibRayMarching_RayMarching pRayMarching, LibRayMarching_uint32 nIndex)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pRayMarching;
		ILibRayMarchingRayMarching* pIRayMarching = dynamic_cast<ILibRayMarchingRayMarching*>(pIBaseClass);
		if (!pIRayMarching)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIRayMarching->RemovePrimitive(nIndex);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_raymarching_setscreensize (LibRayMarching_RayMarching pRayMarching, LibRayMarching_uint32 nWidth, LibRayMarching_uint32 nHeight)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pRayMarching;
		ILibRayMarchingRayMarching* pIRayMarching = dynamic_cast<ILibRayMarchingRayMarching*>(pIBaseClass);
		if (!pIRayMarching)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIRayMarching->SetScreenSize(nWidth, nHeight);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_raymarching_setviewport (LibRayMarching_RayMarching pRayMarching, const sLibRayMarchingVector * pEye, const sLibRayMarchingVector * pDir, const sLibRayMarchingVector * pUp, LibRayMarching_double dFOV)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pRayMarching;
		ILibRayMarchingRayMarching* pIRayMarching = dynamic_cast<ILibRayMarchingRayMarching*>(pIBaseClass);
		if (!pIRayMarching)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIRayMarching->SetViewport(*pEye, *pDir, *pUp, dFOV);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_raymarching_renderscene (LibRayMarching_RayMarching pRayMarching)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pRayMarching;
		ILibRayMarchingRayMarching* pIRayMarching = dynamic_cast<ILibRayMarchingRayMarching*>(pIBaseClass);
		if (!pIRayMarching)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIRayMarching->RenderScene();


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_raymarching_renderpixel (LibRayMarching_RayMarching pRayMarching, LibRayMarching_double dX, LibRayMarching_double dY, LibRayMarching_uint32 * pColor)
{
	try {
		if (pColor == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pRayMarching;
		ILibRayMarchingRayMarching* pIRayMarching = dynamic_cast<ILibRayMarchingRayMarching*>(pIBaseClass);
		if (!pIRayMarching)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		*pColor = pIRayMarching->RenderPixel(dX, dY);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_raymarching_setprogresscallback (LibRayMarching_RayMarching pRayMarching, LibRayMarchingProgressCallback pProgressCallback)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClass = (ILibRayMarchingBaseClass *)pRayMarching;
		ILibRayMarchingRayMarching* pIRayMarching = dynamic_cast<ILibRayMarchingRayMarching*>(pIBaseClass);
		if (!pIRayMarching)
			throw ELibRayMarchingInterfaceException(LIBRAYMARCHING_ERROR_INVALIDCAST);


		pIRayMarching->SetProgressCallback(pProgressCallback);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}


/*************************************************************************************************************************
 Global functions implementation
**************************************************************************************************************************/
LibRayMarchingResult libraymarching_releaseinstance (LibRayMarching_BaseClass pInstance)
{
	try {

		ILibRayMarchingBaseClass* pIBaseClassInstance = (ILibRayMarchingBaseClass *)pInstance;
		ILibRayMarchingBaseClass* pIInstance = dynamic_cast<ILibRayMarchingBaseClass*>(pIBaseClassInstance);
		if (!pIInstance)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDCAST);


		CLibRayMarchingWrapper::ReleaseInstance(pIInstance);


		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_getlibraryversion (LibRayMarching_uint32 * pMajor, LibRayMarching_uint32 * pMinor, LibRayMarching_uint32 * pMicro)
{
	try {
		if (!pMajor)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);
		if (!pMinor)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);
		if (!pMicro)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		LibRayMarching_uint32 nMajor;
		LibRayMarching_uint32 nMinor;
		LibRayMarching_uint32 nMicro;

		CLibRayMarchingWrapper::GetLibraryVersion(nMajor, nMinor, nMicro);

		*pMajor = nMajor;
		*pMinor = nMinor;
		*pMicro = nMicro;

		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_createraymarching (LibRayMarching_RayMarching * pInstance)
{
	try {
		if (pInstance == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pBaseInstance(nullptr);

		pBaseInstance = CLibRayMarchingWrapper::CreateRayMarching();

		*pInstance = (ILibRayMarchingBaseClass*)(pBaseInstance);

		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_createsphere (LibRayMarching_double dRadius, LibRayMarching_Sphere * pSphere)
{
	try {
		if (pSphere == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pBaseSphere(nullptr);

		pBaseSphere = CLibRayMarchingWrapper::CreateSphere(dRadius);

		*pSphere = (ILibRayMarchingBaseClass*)(pBaseSphere);

		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_createcapsule (LibRayMarching_double dRadius, const sLibRayMarchingVector * pPoint1, const sLibRayMarchingVector * pPoint2, LibRayMarching_Capsule * pCapsule)
{
	try {
		if (pCapsule == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pBaseCapsule(nullptr);

		pBaseCapsule = CLibRayMarchingWrapper::CreateCapsule(dRadius, *pPoint1, *pPoint2);

		*pCapsule = (ILibRayMarchingBaseClass*)(pBaseCapsule);

		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_createbox (const sLibRayMarchingVector * pDimensions, LibRayMarching_Box * pBox)
{
	try {
		if (pBox == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pBaseBox(nullptr);

		pBaseBox = CLibRayMarchingWrapper::CreateBox(*pDimensions);

		*pBox = (ILibRayMarchingBaseClass*)(pBaseBox);

		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

LibRayMarchingResult libraymarching_createplane (const sLibRayMarchingVector * pOrigin, const sLibRayMarchingVector * pNormal, LibRayMarching_Plane * pPlane)
{
	try {
		if (pPlane == nullptr)
			throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_INVALIDPARAM);

		ILibRayMarchingBaseClass* pBasePlane(nullptr);

		pBasePlane = CLibRayMarchingWrapper::CreatePlane(*pOrigin, *pNormal);

		*pPlane = (ILibRayMarchingBaseClass*)(pBasePlane);

		return LIBRAYMARCHING_SUCCESS;
	}
	catch (ELibRayMarchingInterfaceException & E) {
		return E.getErrorCode();
	}
	catch (...) {
		return LIBRAYMARCHING_ERROR_GENERICEXCEPTION;
	}
}

}

