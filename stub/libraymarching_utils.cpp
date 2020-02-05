#include "libraymarching_utils.hpp"
#include <cmath>
#include <algorithm>

using namespace LibRayMarching;

Vector LibRayMarching::LibVecToVector(const LibRayMarching::sVector& libVec)
{
	return Vector(libVec.m_X, libVec.m_Y, libVec.m_Z);
}

LibRayMarching::sVector LibRayMarching::VectorToLibVec(const Vector& vector)
{
	LibRayMarching::sVector libVec;
	libVec.m_X = vector.x;
	libVec.m_Y = vector.y;
	libVec.m_Z = vector.z;
	return libVec;
}

Material LibRayMarching::LibMaterialToMaterial(const LibRayMarching::sMaterial& libMaterial)
{
	Material result;
	result.color = Vector(libMaterial.m_Red, libMaterial.m_Green, libMaterial.m_Blue);
	result.ambient = libMaterial.m_Ambient;
	result.diffuse = libMaterial.m_Diffuse;
	result.specular = libMaterial.m_Specular;
	result.specular_alpha = libMaterial.m_SpecularAlpha;
	result.reflection = libMaterial.m_Reflection;
	result.transparency = libMaterial.m_Transparency;
	result.refraction = libMaterial.m_Refraction;
	return result;
}

LibRayMarching::sMaterial LibRayMarching::MaterialToLibMaterial(const Material& Material)
{
	LibRayMarching::sMaterial result;
	result.m_Red = Material.color.x;
	result.m_Green = Material.color.x;
	result.m_Blue = Material.color.x;
	result.m_Ambient = Material.ambient;
	result.m_Diffuse = Material.diffuse;
	result.m_Specular = Material.specular;
	result.m_SpecularAlpha = Material.specular_alpha;
	result.m_Reflection = Material.reflection;
	result.m_Transparency = Material.transparency;
	result.m_Refraction = Material.refraction;
	return result;
}

CombineAction LibRayMarching::LibCAToCA (const LibRayMarching::eGroupAction& action)
{
	switch(action)
	{
		case LibRayMarching::eGroupAction::Intersect: return caIntersect;
		case LibRayMarching::eGroupAction::Unify: return caUnify;
		case LibRayMarching::eGroupAction::Subtract: return caSubtract;
	}
}

LibRayMarching::eGroupAction LibRayMarching::CAToLibCA (const CombineAction& action)
{
	switch(action)
	{
		case caIntersect: return LibRayMarching::eGroupAction::Intersect;
		case caUnify: return LibRayMarching::eGroupAction::Unify;
		case caSubtract: return LibRayMarching::eGroupAction::Subtract;
	}
}