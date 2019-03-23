#pragma once

#include "vector.h"
#include "types.h"
#include "libraymarching_types.h"

namespace LibRayMarching
{

    Vector LibVecToVector(const sLibRayMarchingVector& libVec);

    sLibRayMarchingVector VectorToLibVec(const Vector& libVec);

    Material LibMaterialToMaterial(const sLibRayMarchingMaterial& libMaterial);

    sLibRayMarchingMaterial MaterialToLibMaterial(const Material& material);

}
