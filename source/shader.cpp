#include <iostream>
#include <cmath>
#include "shader.h"
#include "primitives.h"

using namespace LibRayMarching;

Shader::Shader()
{
	m_MaxIteration = 300;
	m_MaxDistance = 100;
	m_MinDistance = 0.00001;
	m_Epsilon = 0.005;
	m_Bouncing = 10;
	m_Lightning.background = Vector(0, 0, 0);
	m_Lightning.min_dist_background = m_MaxDistance;
	m_Lightning.max_dist_background = m_MaxDistance;
	m_Lightning.soft_shadow = 50;
	m_Lightning.minimal_shadow = 0.1;
	m_Lightning.oversampling = 1;
	m_Lightning.normal_by_environment = false;
	m_Bouncing = 8;
}

Vector Shader::RefractRay(const Vector& ray, const Vector& normal, float refraction)
{
	float dot = -ray.dot(normal);
	float alpha = acos(EnsureRange(dot, -1.f, 1.f));
	float beta = alpha / refraction;
	Vector cross = normal.cross(ray);
	Vector comp = cross.cross(normal);
	return normal * -cos(beta) + comp * (sin(beta) / comp.length());
}

Vector Shader::PhongShading(const Vector& position, const Vector& ray, int bouncing)
{
	MarcheResult result;
	RayMarche(position, ray, result);
	if (result.primitive != NULL)
	{
		if (result.distance > m_Lightning.max_dist_background)
		{
			return m_Lightning.background;
		}
		CalcNormal(position, ray, result);
		Material* material = result.primitive->GetMaterial();
		Vector colAmbient = material->color * material->ambient;
		Vector colDiffuse(0, 0, 0);
		Vector colSpecular(0, 0, 0);
		Vector reflectedRay = ray - result.normal * 2 * result.normal.dot(ray);
		Vector hitPosOffset = result.position + result.normal * m_Epsilon;
		for (int i = 0; i < m_Lights.size(); i++)
		{
			Light light = m_Lights[i];
			Vector toLight = (light.position - result.position).normalized();
			float toLightDot = toLight.dot(result.normal);
			if (toLightDot > 0)
			{
				MarcheResult resultLigth;
				RayMarche(hitPosOffset, toLight, resultLigth);

				float diffFactor = toLightDot * material->diffuse * resultLigth.shadow_factor;
				colDiffuse += material->color * diffFactor;

				float specFactor = material->specular * 
					std::pow(reflectedRay.dot(toLight), material->specular_alpha) * 
					resultLigth.shadow_factor;
				if (specFactor > 0)
					colSpecular += light.color * specFactor;
			}
		}
		Vector colReflected(0, 0, 0), colTransparent(0, 0, 0);
		if (material->reflection > 0 && bouncing > 0)
		{
			colReflected = PhongShading(hitPosOffset, reflectedRay, bouncing - 1) * material->reflection;
		}
		if (material->transparency > 0 && bouncing > 0)
		{			
			Vector refractedIn = RefractRay(ray, result.normal, material->refraction);
			Vector hitPosInside = result.position - result.normal * m_Epsilon;
			MarcheResult resultInside;
			resultInside.primitive = result.primitive;
			RayMarcheInside(result.primitive, hitPosInside, refractedIn, resultInside);
			CalcNormal(hitPosInside, refractedIn, resultInside);
			Vector refractedOut = RefractRay(refractedIn * -1, resultInside.normal, 1 / material->refraction) * -1;
			Vector hitPosOut = resultInside.position + resultInside.normal * m_Epsilon;
			colTransparent = PhongShading(hitPosOut, refractedOut, bouncing - 1) * material->transparency;
		}
		Vector colFinal = colAmbient + colDiffuse + colSpecular + colReflected + colTransparent;
		if (result.distance > m_Lightning.min_dist_background)
		{
			float ratio = (result.distance - m_Lightning.max_dist_background) / 
				(m_Lightning.min_dist_background - m_Lightning.max_dist_background);
			colFinal = colFinal * ratio + m_Lightning.background * (1 - ratio);
		}
		return colFinal;
	} else
	{
		return m_Lightning.background;
	}
}

float Shader::CalcNormal(Vector pos, Vector ray, MarcheResult& result)
{
	if (result.primitive != NULL)
	{
		Primitive* primitive = result.primitive;
		if (m_Lightning.normal_by_environment)
		{
			Vector dX(m_Epsilon, 0, 0), dY(0, m_Epsilon, 0), dZ(0, 0, m_Epsilon);
			Vector p = result.position;			
			result.normal.x = primitive->SignedDistance(p + dX) - primitive->SignedDistance(p - dX);
			result.normal.y = primitive->SignedDistance(p + dY) - primitive->SignedDistance(p - dY);
			result.normal.z = primitive->SignedDistance(p + dZ) - primitive->SignedDistance(p - dZ);
			result.normal.normalize();
		}
		else{
			// Additional ray marche to get right normal
			MarcheResult e1, e2;
			Vector r1 = ray.cross(VectorX);
			if (r1.length() < m_Epsilon) {
				r1 = ray.cross(VectorY);
			}
			r1.normalize();
			Vector r2 = ray.cross(r1).normalized();
			Vector p1 = pos + r1 * m_Epsilon;
			Vector p2 = pos + r2 * m_Epsilon;
			RayMarchePrimitive(primitive, p1, ray, e1);
			RayMarchePrimitive(primitive, p2, ray, e2);

			// Calculate normal
			Vector v1 = e1.position - result.position;
			Vector v2 = e2.position - result.position;
			result.normal = v2.cross(v1).normalized();
			if (result.normal.dot(ray) > 0) {
				result.normal = result.normal * -1;
			}
		}
	}
}

float Shader::RayMarche(const Vector& position, const Vector& ray, MarcheResult& result)
{
	float distance = 0;
	result.shadow_factor = 1;
	result.position = position + ray * distance;	
	for (int i = 0; i < m_MaxIteration; i++) {
		float d = GetDistance(result.position, result);
		if (distance > 0) {
			result.shadow_factor = std::min(result.shadow_factor, m_Lightning.soft_shadow * d / distance);
			result.shadow_factor = std::max(result.shadow_factor, m_Lightning.minimal_shadow);
		}
		distance += d;
		result.position = position + ray * distance;		
		if (distance > m_MaxDistance) {
			result.primitive = NULL;
			result.distance = distance;
			return distance;
		}
		if (d < m_MinDistance) {
			result.distance = distance;
			return distance;
		}
	}
	result.distance = distance;
	return distance;
}

void Shader::RayMarcheInside(const Primitive* primitive, const Vector& position, const Vector& ray, MarcheResult& result)
{
	float distance = 0;
	result.position = position + ray * distance;	
	for (int i = 0; i < m_MaxIteration; i++) {
		float d = -primitive->SignedDistance(result.position);
		distance += d;
		result.position = position + ray * distance;		
		if (distance > m_MaxDistance) {
			result.primitive = NULL;
			result.distance = distance;
			return;
		}
		if (d < m_MinDistance) {
			result.distance = distance;
			return;
		}
	}
	result.distance = distance;
}

void Shader::RayMarchePrimitive(const Primitive* primitive, const Vector& position, const Vector& ray, MarcheResult& result)
{
	float distance = 0;
	result.shadow_factor = 1;
	result.position = position + ray * distance;	
	for (int i = 0; i < m_MaxIteration; i++) {
		float d = primitive->SignedDistance(result.position);
		distance += d;
		result.position = position + ray * distance;		
		if (distance > m_MaxDistance) {
			result.primitive = NULL;
			result.distance = distance;
		}
		if (d < m_MinDistance) {
			result.distance = distance;
		}
	}
	result.distance = distance;
}

float Shader::GetDistance(const Vector& position, MarcheResult& result)
{
	float minDist = m_MaxDistance;
	for(auto p = m_Primitives.begin(); p != m_Primitives.end(); ++p)
	{		
		PrimitivePtr primitive = *p;
		float distance = primitive->SignedDistance(position);
		if (distance < minDist)
		{
			minDist = distance;
			result.primitive = primitive.get();
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
		float offset = i / oversampling;
		m_Camera.CalculateRay(x + offset, y + offset, pos, ray);		
		color += PhongShading(pos, ray, m_Bouncing);
	}
	color *= 255. / oversampling;
	int red = EnsureRange((int)color.x, 0, 255);
	int green = EnsureRange((int)color.y, 0, 255);
	int blue = EnsureRange((int)color.z, 0, 255);
	return 	(red << 16) |
			(green << 8) |
			(blue);
}