#include <iostream>
#include <cmath>
#include "shader.h"
#include "primitives.h"

using namespace LibRayMarching;

Shader::Shader()
{
	m_Lightning.background = Vector(0, 0, 0);
	m_Lightning.soft_shadow = 50;
	m_Lightning.minimal_shadow = 0.1;
	m_Lightning.oversampling = 1;
}

Vector Shader::PhongShading(const Vector& position, const Vector& ray)
{
	MarcheResult result;
	Trace(position, ray, result);
	if (result.material != NULL)
	{
		Vector colAmbient = result.material->color * result.material->ambient;
		Vector colDiffuse(0, 0, 0);
		Vector colSpecular(0, 0, 0);
		Vector reflectedRay = ray - result.normal * 2 * result.normal.dot(ray);
		Vector hitPosOffset = result.position + result.normal * m_Epsilon;
		for (int i = 0; i < m_Lights.size(); i++)
		{
			Light light = m_Lights[i];
			Vector toLight = (light.position - result.position).normalized();
			double toLightDot = toLight.dot(result.normal);
			if (toLightDot > 0)
			{
				MarcheResult resultLigth;
				RayMarche(hitPosOffset, toLight, resultLigth);

				double diffFactor = toLightDot * result.material->diffuse * resultLigth.shadow_factor;
				colDiffuse += result.material->color * diffFactor;

				double specFactor = result.material->specular * 
					std::pow(reflectedRay.dot(toLight), result.material->specular_alpha) * 
					resultLigth.shadow_factor;
				if (specFactor > 0)
					colSpecular += light.color * specFactor;
			}
		}
		return colAmbient + colDiffuse + colSpecular;
	} else
	{
		return m_Lightning.background;
	}
}

double Shader::Trace(const Vector& position, const Vector& ray, MarcheResult& result)
{
	// Calculate distance and hit object
	double distance = RayMarche(position, ray, result);

	// Calculate normal at hit position
	if (result.material != NULL)
	{
		MarcheResult d;
		Vector dX(m_Epsilon, 0, 0), dY(0, m_Epsilon, 0), dZ(0, 0, m_Epsilon);
		Vector p = result.position;
		result.normal.x = GetDistance(p + dX, d) - GetDistance(p - dX, d);
		result.normal.y = GetDistance(p + dY, d) - GetDistance(p - dY, d);
		result.normal.z = GetDistance(p + dZ, d) - GetDistance(p - dZ, d);
		result.normal.normalize();
	}
	return distance;
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
			result.material = NULL;
			result.distance = distance;
			return distance;
		}
		if (d < m_MinDistance) {
			result.distance = distance;
			return distance;
		}
	}
	return distance;
}

double Shader::GetDistance(const Vector& position, MarcheResult& result)
{
	double minDist = m_MaxDistance;
	//std::cout << "get distance " << std::endl;
	for(auto p = m_Primitives.begin(); p != m_Primitives.end(); ++p)
	{		
		PrimitivePtr primitive = *p;
		double distance = primitive->SignedDistance(position);
		//std::cout << " dist is " << distance << std::endl;
		if (distance < minDist)
		{
			minDist = distance;
			result.material = primitive->GetMaterial();
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
		color += PhongShading(pos, ray);
	}
	color *= 255. / oversampling;
	int red = EnsureRange((int)color.x, 0, 255);
	int green = EnsureRange((int)color.y, 0, 255);
	int blue = EnsureRange((int)color.z, 0, 255);
	return 	(red << 16) |
			(green << 8) |
			(blue);
}