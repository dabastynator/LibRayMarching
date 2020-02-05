/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CBox

*/

#include "libraymarching_box.hpp"
#include "libraymarching_interfaceexception.hpp"
#include "libraymarching_utils.hpp"

// Include custom headers here.

using namespace LibRayMarching;
using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CBox 
**************************************************************************************************************************/

CBox::CBox(BoxPtr box):
	CPrimitive(box), m_Box(box)
{

}

sLibRayMarchingVector CBox::GetDimensions ()
{
	return VectorToLibVec(m_Box->GetDimensions());
}

void CBox::SetDimensions (const sLibRayMarchingVector Dimensions)
{
	m_Box->SetDimensions(LibVecToVector(Dimensions));
}