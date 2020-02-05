#pragma once

#include "primitives.h"
#include "vector.h"
#include "types.h"
#include "libraymarching_types.hpp"

namespace LibRayMarching
{

    Vector LibVecToVector(const LibRayMarching::sVector& libVec);

    LibRayMarching::sVector VectorToLibVec(const Vector& libVec);

    Material LibMaterialToMaterial(const LibRayMarching::sMaterial& libMaterial);

    LibRayMarching::sMaterial MaterialToLibMaterial(const Material& material);

    CombineAction LibCAToCA (const eLibRayMarchingGroupAction& action);

    eLibRayMarchingGroupAction CAToLibCA (const CombineAction& action);
}
