/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingPrimitiveGroup

*/

#include "libraymarching_primitivegroup.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.

using namespace LibRayMarching;
using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingPrimitiveGroup 
**************************************************************************************************************************/

CLibRayMarchingPrimitiveGroup::CLibRayMarchingPrimitiveGroup(PrimitiveGroupPtr group):
	CLibRayMarchingPrimitive(group), m_Group(group)
{

}

LibRayMarching_uint32 CLibRayMarchingPrimitiveGroup::GetPrimitiveCount ()
{
	return m_Group->GetCount();
}

ILibRayMarchingPrimitive * CLibRayMarchingPrimitiveGroup::GetPrimitive (const LibRayMarching_uint32 nIndex)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingPrimitiveGroup::AddPrimitive (ILibRayMarchingPrimitive* pPrimitive)
{
	CLibRayMarchingPrimitive* pPrimitiveImpl = dynamic_cast < CLibRayMarchingPrimitive* >(pPrimitive);
	m_Group->AddPrimitive(pPrimitiveImpl->GetPrimitive());
}

void CLibRayMarchingPrimitiveGroup::RemovePrimitive (const LibRayMarching_uint32 nIndex)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CLibRayMarchingPrimitiveGroup::SetGroupAction (const eLibRayMarchingGroupAction eGroupAction)
{
	m_Group->SetCombineAction(LibCAToCA(eGroupAction));
}

eLibRayMarchingGroupAction CLibRayMarchingPrimitiveGroup::GetGroupAction ()
{
	return CAToLibCA(m_Group->GetCombineAction());
}

