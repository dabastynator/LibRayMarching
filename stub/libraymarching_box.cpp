/*++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

Abstract: This is a stub class definition of CLibRayMarchingBox

*/

#include "libraymarching_box.hpp"
#include "libraymarching_interfaceexception.hpp"
#include "libraymarching_utils.hpp"

// Include custom headers here.


using namespace LibRayMarching::Impl;

/*************************************************************************************************************************
 Class definition of CLibRayMarchingBox 
**************************************************************************************************************************/

sLibRayMarchingVector CLibRayMarchingBox::GetDimensions ()
{
	return VectorToLibVec(m_Dimension);
}

void CLibRayMarchingBox::SetDimensions (const sLibRayMarchingVector Dimensions)
{
	m_Dimension = LibVecToVector(Dimensions);
}

