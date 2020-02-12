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
		float ambient;
		float ambient_occlusion;
		float diffuse;
		float specular;
		float specular_alpha;
		float reflection;
		float transparency;
		float refraction;
	};

	struct Glow
	{
		Vector color;
		float intensity;
	};

	struct Lightning
	{
		Vector background;
		int oversampling;
		float soft_shadow;
		float minimal_shadow;
		float max_dist_background;
		float min_dist_background;
		bool normal_by_environment;
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
		Vector glow;
		float glow_factor;
		float distance;
		float shadow_factor;
	};
}
