#include <iostream>
#include "shader.h"
#include "libraymarching_primitive.hpp"

using namespace LibRayMarching;

Shader::Shader()
{
	m_Lightning.background = Vector(0.2, 0.2, 0.2);
	m_Lightning.soft_shadow = 50;
	m_Lightning.minimal_shadow = 0.5;
	m_Lightning.oversampling = 1;
}

Vector Shader::CalculateColor(const Vector& position, const Vector& ray, int bouncing)
{
	MarcheResult result;
	Trace(position, ray, result);
	return Vector(result.distance, result.distance, result.distance) * 0.2;
}

double Shader::Trace(const Vector& position, const Vector& ray, MarcheResult& result)
{
	return RayMarche(position, ray, result);
}

double Shader::RayMarche(const Vector& position, const Vector& ray, MarcheResult& result)
{
	double distance = 0;
	result.shadow_factor = 1;
	result.position = position + ray * distance;	
	for (int i = 0; i < m_MaxIteration; i++) {
		double d = GetDistance(result.position, result);
		if (distance > 0) {
			result.shadow_factor = std::min(result.shadow_factor, m_Lightning.soft_shadow * d / distance);
			result.shadow_factor = std::max(result.shadow_factor, m_Lightning.minimal_shadow);
		}
		distance += d;
		result.position = position + ray * distance;		
		if (distance > m_MaxDistance) {
			result.hit = NULL;
			result.distance = distance;
			return distance;
		}
		if (d < m_MinDistance) {
			result.distance = distance;
			return distance;
		}
	}
}

double Shader::GetDistance(const Vector& position, MarcheResult& result)
{
	double minDist = m_MaxDistance;
	for(auto p = m_Primitives.begin(); p != m_Primitives.end(); ++p)
	{		
		Impl::CLibRayMarchingPrimitive* primitive = *p;
		double distance = primitive->DistanceTo(position);
		if (distance < minDist)
		{
			minDist = distance;
			result.hit = primitive->GetMaterial();
		}
	}
	return minDist;
} 

unsigned int Shader::RenderPixel(int x, int y)
{
	Vector pos;
	Vector ray;
	Vector color;
	int oversampling = std::max(1, m_Lightning.oversampling);	
	for (int i = 0; i < oversampling; i++) {
		double offset = i / (double) oversampling;
		m_Camera.CalculateRay(x + offset, y + offset, pos, ray);		
		color += CalculateColor(pos, ray, m_Bouncing);
	}
	color *= 255. / oversampling;
	int red = EnsureRange((int)color.x, 0, 255);
	int green = EnsureRange((int)color.y, 0, 255);
	int blue = EnsureRange((int)color.z, 0, 255);
	return 	(red << 16) |
			(green << 8) |
			(blue);
}