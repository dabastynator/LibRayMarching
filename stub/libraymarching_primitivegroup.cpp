/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CPrimitiveGroup

*/

#include "libraymarching_primitivegroup.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CPrimitiveGroup 
**************************************************************************************************************************/

CPrimitiveGroup::CPrimitiveGroup(PrimitiveGroupPtr group):
	CPrimitive(group), m_Group(group)
{

}

LibRayMarching_uint32 CPrimitiveGroup::GetPrimitiveCount ()
{
	return m_Group->GetCount();
}

IPrimitive * CPrimitiveGroup::GetPrimitive (const LibRayMarching_uint32 nIndex)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CPrimitiveGroup::AddPrimitive (IPrimitive* pPrimitive)
{
	CPrimitive* pPrimitiveImpl = dynamic_cast < CPrimitive* >(pPrimitive);
	m_Group->AddPrimitive(pPrimitiveImpl->GetPrimitive());
}

void CPrimitiveGroup::RemovePrimitive (const LibRayMarching_uint32 nIndex)
{
	throw ELibRayMarchingInterfaceException (LIBRAYMARCHING_ERROR_NOTIMPLEMENTED);
}

void CPrimitiveGroup::SetGroupAction (const eLibRayMarchingGroupAction eGroupAction)
{
	m_Group->SetCombineAction(LibCAToCA(eGroupAction));
}

eLibRayMarchingGroupAction CPrimitiveGroup::GetGroupAction ()
{
	return CAToLibCA(m_Group->GetCombineAction());
}

