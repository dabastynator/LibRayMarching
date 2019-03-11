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
	};

	struct Lightning
	{
		Vector background;
		int oversampling;
		double soft_shadow;
		double minimal_shadow;
	};

	struct MarcheResult
	{
		Material* material;
		Vector position;
		Vector normal;
		double distance;
		double shadow_factor;
	};
}
