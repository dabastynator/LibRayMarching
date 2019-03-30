#pragma once

namespace LibRayMarching
{

	struct Light
	{
		Vector position;
		Vector color;
		Light() {};
		Light(const Vector& pos, const Vector& col) { position = pos; color = col; };
	};

	struct Material
	{
		Vector color;
		double ambient;
		double diffuse;
		double specular;
		double specular_alpha;
		double reflection;
		double transparency;
		double refraction;
	};

	struct Lightning
	{
		Vector background;
		int oversampling;
		double soft_shadow;
		double minimal_shadow;
	};

	enum CombineAction
	{
		caUnify, 
		caIntersect, 
		caSubtract
	};

	enum PrimitiveType
	{
		ptSphere, ptBox, ptPlane, ptCapsule, ptCylinder, ptTorus,
		ptMengerSponge, ptQuaternion, ptGroup
	};

	enum Distortion
	{
		pdNone,
		pdSinus
	};

	class Primitive;

	struct MarcheResult
	{
		Primitive* primitive;
		Vector position;
		Vector normal;
		double distance;
		double shadow_factor;
	};
}
