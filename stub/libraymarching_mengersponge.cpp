/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingMengerSponge

*/

#include "libraymarching_mengersponge.hpp"
#include "libraymarching_interfaceexception.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingMengerSponge 
**************************************************************************************************************************/
CLibRayMarchingMengerSponge::CLibRayMarchingMengerSponge(MengerSpongePtr mengerSonge):
	CLibRayMarchingPrimitive(mengerSonge), m_MengerSonge(mengerSonge)
{

}

LibRayMarching_uint32 CLibRayMarchingMengerSponge::GetStepCount ()
{
	return m_MengerSonge->GetSetpCount();
}

void CLibRayMarchingMengerSponge::SetStepCount (const LibRayMarching_uint32 nStepCount)
{
	m_MengerSonge->SetSetpCount(nStepCount);
}

