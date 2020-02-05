/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CMengerSponge

*/

#include "libraymarching_mengersponge.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.

using namespace LibRayMarching;
using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CMengerSponge 
**************************************************************************************************************************/
CMengerSponge::CMengerSponge(MengerSpongePtr mengerSonge):
	CPrimitive(mengerSonge), m_MengerSonge(mengerSonge)
{

}

LibRayMarching_uint32 CMengerSponge::GetStepCount ()
{
	return m_MengerSonge->GetSetpCount();
}

void CMengerSponge::SetStepCount (const LibRayMarching_uint32 nStepCount)
{
	m_MengerSonge->SetSetpCount(nStepCount);
}

