#include "libraymarching_utils.hpp"
#include <cmath>
#include <algorithm>

using namespace LibRayMarching;

Vector LibRayMarching::LibVecToVector(const LibRayMarching::sVector& libVec)
{
<<<<<<< HEAD
	return Vector(libVec.m_X, libVec.m_Y, libVec.m_Z);
=======
	return Vector((float)libVec.m_x, (float)libVec.m_y, (float)libVec.m_z);
>>>>>>> fc2619b712968377c311d79879a477fd8a2487d3
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
	result.color = Vector((float)libMaterial.m_Red, (float)libMaterial.m_Green, (float)libMaterial.m_Blue);
	result.ambient = (float)libMaterial.m_Ambient;
	result.diffuse = (float)libMaterial.m_Diffuse;
	result.specular = (float)libMaterial.m_Specular;
	result.specular_alpha = (float)libMaterial.m_SpecularAlpha;
	result.reflection = (float)libMaterial.m_Reflection;
	result.transparency = (float)libMaterial.m_Transparency;
	result.refraction = (float) libMaterial.m_Refraction;
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
	return eGroupActionUnify;
}