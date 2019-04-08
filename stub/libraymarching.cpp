/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.4.0.

Abstract: This is an autogenerated C++ implementation file in order to allow easy
development of Ray Marching Library. It needs to be generated only once.

Interface version: 0.9.0

*/

#include "libraymarching.h"
#include "libraymarching_interfaces.hpp"
#include "libraymarching_interfaceexception.hpp"
#include "libraymarching_box.hpp"
#include "libraymarching_sphere.hpp"
#include "libraymarching_capsule.hpp"
#include "libraymarching_plane.hpp"
#include "libraymarching_cylinder.hpp"
#include "libraymarching_torus.hpp"
#include "libraymarching_mengersponge.hpp"
#include "libraymarching_quaternionfractal.hpp"
#include "libraymarching_primitivegroup.hpp"
#include "libraymarching_raymarching.hpp"
#include "primitives.h"

using namespace LibRayMarching::Impl;

bool CLibRayMarchingWrapper::GetLastError (ILibRayMarchingBaseClass* pInstance, std::string & sErrorMessage)
{
	pInstance->GetLastErrorMessage(sErrorMessage);
}


void CLibRayMarchingWrapper::ReleaseInstance (ILibRayMarchingBaseClass* pInstance)
{
	delete pInstance;
}

void CLibRayMarchingWrapper::GetLibraryVersion (LibRayMarching_uint32 & nMajor, LibRayMarching_uint32 & nMinor, LibRayMarching_uint32 & nMicro)
{
	nMajor = 1;
	nMinor = 0;
	nMicro = 0;
}

ILibRayMarchingRayMarching * CLibRayMarchingWrapper::CreateRayMarching ()
{
	return new CLibRayMarchingRayMarching();
}

ILibRayMarchingSphere * CLibRayMarchingWrapper::CreateSphere (const LibRayMarching_double dRadius)
{
	SpherePtr sphere (new Sphere(dRadius));
	return new CLibRayMarchingSphere(sphere);
}

ILibRayMarchingCapsule * CLibRayMarchingWrapper::CreateCapsule (const LibRayMarching_double dRadius, const sLibRayMarchingVector Point1, const sLibRayMarchingVector Point2)
{
	CapsulePtr capsule (new Capsule(dRadius));
	capsule->SetPoint1(LibVecToVector(Point1));
	capsule->SetPoint2(LibVecToVector(Point2));
	return new CLibRayMarchingCapsule(capsule);
}

ILibRayMarchingBox * CLibRayMarchingWrapper::CreateBox (const sLibRayMarchingVector Dimensions)
{
	BoxPtr box (new Box());
	box->SetDimensions(LibVecToVector(Dimensions));
	return new CLibRayMarchingBox(box);
}

ILibRayMarchingPlane * CLibRayMarchingWrapper::CreatePlane (const sLibRayMarchingVector Origin, const sLibRayMarchingVector Normal)
{
	PlanePtr plane (new Plane());
	plane->SetNormal(LibVecToVector(Normal));
	plane->Translate(LibVecToVector(Origin));
	return new CLibRayMarchingPlane(plane);
}

ILibRayMarchingCylinder * CLibRayMarchingWrapper::CreateCylinder (const LibRayMarching_double dRadius, const LibRayMarching_double dHeight)
{
	CylinderPtr cylinder (new Cylinder());
	cylinder->SetRadius(dRadius);
	cylinder->SetHeight(dHeight);
	return new CLibRayMarchingCylinder(cylinder);
}

ILibRayMarchingTorus * CLibRayMarchingWrapper::CreateTorus (const LibRayMarching_double dBigRadius, const LibRayMarching_double dSmallRadius)
{
	TorusPtr torus (new Torus());
	torus->SetRadiusBig(dBigRadius);
	torus->SetRadiusSmall(dSmallRadius);
	return new CLibRayMarchingTorus(torus);
}


ILibRayMarchingMengerSponge * CLibRayMarchingWrapper::CreateMengerSponge (const LibRayMarching_uint32 nStepCount)
{
	MengerSpongePtr ms(new MengerSponge());
	ms->SetSetpCount(nStepCount);
	return new CLibRayMarchingMengerSponge(ms);
}

ILibRayMarchingQuaternionFractal * CLibRayMarchingWrapper::CreateQuaternionFractal (const LibRayMarching_uint32 nIterations)
{
	QuaternionFractalPtr ms(new QuaternionFractal());
	ms->SetIterations(nIterations);
	return new CLibRayMarchingQuaternionFractal(ms);
}

ILibRayMarchingPrimitiveGroup * CLibRayMarchingWrapper::CreatePrimitiveGroup (const eLibRayMarchingGroupAction eGroupAction)
{
	PrimitiveGroupPtr group(new PrimitiveGroup());
	group->SetCombineAction(LibCAToCA(eGroupAction));
	return new CLibRayMarchingPrimitiveGroup(group);
}