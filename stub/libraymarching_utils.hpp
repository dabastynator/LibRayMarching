#pragma once

#include "primitives.h"
#include "vector.h"
#include "types.h"
#include "libraymarching_types.hpp"

namespace LibRayMarching
{

    Vector LibVecToVector(const LibRayMarching::sVector& libVec);

    LibRayMarching::sVector VectorToLibVec(const Vector& vec);

    Vector ColorToVector(const LibRayMarching::sColor& libColor);

    LibRayMarching::sColor VectorToColor(const Vector& vector);

    Material LibMaterialToMaterial(const LibRayMarching::sMaterial& libMaterial);

    LibRayMarching::sMaterial MaterialToLibMaterial(const Material& material);

    Glow LibGlowToGlow(const LibRayMarching::sGlow& libGlow);

    LibRayMarching::sGlow GlowToLibGlow(const Glow& glow);

    CombineAction LibCAToCA (const eLibRayMarchingGroupAction& action);

    eLibRayMarchingGroupAction CAToLibCA (const CombineAction& action);
}
