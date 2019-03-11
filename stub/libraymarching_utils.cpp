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

Material LibRayMarching::LibMaterialToMaterial(const sLibRayMarchingMaterial& libMaterial)
{
	Material result;
	result.color = Vector(libMaterial.m_Red, libMaterial.m_Green, libMaterial.m_Blue);
	result.ambient = libMaterial.m_Ambient;
	result.diffuse = libMaterial.m_Diffuse;
	result.specular = libMaterial.m_Specular;
	result.specular_alpha = libMaterial.m_SpecularAlpha;
	result.reflection = libMaterial.m_Reflection;
	return result;
}

sLibRayMarchingMaterial LibRayMarching::MaterialToLibMaterial(const Material& Material)
{
	sLibRayMarchingMaterial result;
	result.m_Red = Material.color.x;
	result.m_Green = Material.color.x;
	result.m_Blue = Material.color.x;
	result.m_Ambient = Material.ambient;
	result.m_Diffuse = Material.diffuse;
	result.m_Specular = Material.specular;
	result.m_SpecularAlpha = Material.specular_alpha;
	result.m_Reflection = Material.reflection;
	return result;
}