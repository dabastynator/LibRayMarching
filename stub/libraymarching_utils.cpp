#include "libraymarching_utils.hpp"
#include <cmath>
#include <algorithm>

using namespace LibRayMarching;

Vector LibRayMarching::LibVecToVector(const sLibRayMarchingVector& libVec)
{
	return Vector(libVec.m_x, libVec.m_y, libVec.m_z);
}

sLibRayMarchingVector LibRayMarching::VectorToLibVec(const Vector& vector)
{
	sLibRayMarchingVector libVec;
	libVec.m_x = vector.x;
	libVec.m_y = vector.y;
	libVec.m_z = vector.z;
	return libVec;
}
