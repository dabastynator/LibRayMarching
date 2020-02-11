#include "libraymarching_utils.hpp"
#include <cmath>
#include <algorithm>

using namespace LibRayMarching;

Vector LibRayMarching::LibVecToVector(const LibRayMarching::sVector& libVec)
{
	return Vector((float)libVec.m_X, (float)libVec.m_Y, (float)libVec.m_Z);
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
	result.ambient_occlusion = (float)libMaterial.m_AmbientOcclusion;
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
	result.m_AmbientOcclusion = Material.ambient_occlusion;
	result.m_Diffuse = Material.diffuse;
	result.m_Specular = Material.specular;
	result.m_SpecularAlpha = Material.specular_alpha;
	result.m_Reflection = Material.reflection;
	result.m_Transparency = Material.transparency;
	result.m_Refraction = Material.refraction;
	return result;
}

Vector LibRayMarching::ColorToVector(const LibRayMarching::sColor& libColor)
{
	return Vector(libColor.m_Red, libColor.m_Green, libColor.m_Blue);
}

LibRayMarching::sColor LibRayMarching::VectorToColor(const Vector& vector)
{
	LibRayMarching::sColor color;
	color.m_Red = vector.x;
	color.m_Green = vector.y;
	color.m_Blue = vector.z;
	return color;
}

Glow LibRayMarching::LibGlowToGlow(const LibRayMarching::sGlow& libGlow)
{
	Glow result;
	result.color = Vector((float) libGlow.m_Red, (float) libGlow.m_Green, (float) libGlow.m_Blue);
	result.intensity = libGlow.m_Intensity;
	return result;
}

LibRayMarching::sGlow LibRayMarching::GlowToLibGlow(const Glow& glow)
{
	LibRayMarching::sGlow result;
	result.m_Red = glow.color.x;
	result.m_Green = glow.color.y;
	result.m_Blue = glow.color.z;
	result.m_Intensity = glow.intensity;
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
	return LibRayMarching::eGroupAction::Unify;
}