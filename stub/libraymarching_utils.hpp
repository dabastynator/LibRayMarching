#pragma once

#include "vector.h"
#include "libraymarching_types.h"

namespace LibRayMarching
{

Vector LibVecToVector(const sLibRayMarchingVector& libVec);

sLibRayMarchingVector VectorToLibVec(const Vector& libVec);

}
