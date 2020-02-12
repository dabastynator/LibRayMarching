#include <iostream>
#include <cmath>
#include <algorithm>

#include "shader.h"
#include "primitives.h"

using namespace LibRayMarching;

Shader::Shader()
{
	m_MaxIteration = 300;
	m_MaxDistance = 100;
	m_MinDistance = 0.00001f;
	m_Epsilon = 0.005f;
	m_Bouncing = 10;
	m_Lightning.background = Vector(0, 0, 0);
	m_Lightning.min_dist_background = m_MaxDistance;
	m_Lightning.max_dist_background = m_MaxDistance;
	m_Lightning.soft_shadow = 50.f;
	m_Lightning.minimal_shadow = 0.1f;
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
	RayMarche(position, ray, result, m_MaxDistance);
	Vector colBackground = m_Lightning.background;
	if (result.glow_factor > 0)
	{
		result.glow *= 1 / result.glow_factor;
		result.glow_factor = std::min(1.f, result.glow_factor);
		colBackground = colBackground * (1 - result.glow_factor) + result.glow * result.glow_factor;
	}
	if (result.primitive != NULL)
	{
		if (result.distance > m_Lightning.max_dist_background)
		{
			return colBackground;
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
			Vector toLightReal = light.position - result.position;
			Vector toLight = toLightReal.normalized();
			float toLightDot = toLight.dot(result.normal);
			if (toLightDot > 0)
			{
				MarcheResult resultLigth;
				RayMarche(hitPosOffset, toLight, resultLigth, toLightReal.length());

				float diffFactor = toLightDot * material->diffuse * resultLigth.shadow_factor;
				colDiffuse += material->color * light.color * diffFactor;

				float specFactor = material->specular * 
					std::pow(reflectedRay.dot(toLight), material->specular_alpha) * 
					resultLigth.shadow_factor;
				if (specFactor > 0)
				{
					colSpecular += light.color * specFactor;
				}
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
		colFinal = colFinal * (1 - result.glow_factor) + result.glow * result.glow_factor;
		return colFinal;
	} else
	{
		return colBackground;
	}
}

void Shader::CalcNormal(Vector pos, Vector ray, MarcheResult& result)
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

float Shader::RayMarche(const Vector& position, const Vector& ray, MarcheResult& result, double max_distance)
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
		if (distance > max_distance) {
			result.primitive = NULL;
			result.distance = distance;
			return distance;
		}
		if (d < m_MinDistance) {
			result.distance = distance;
			result.shadow_factor = m_Lightning.minimal_shadow;
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
	result.glow_factor = 0;
	result.glow = VectorNull;
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
		Glow *glow = primitive->GetGlow();
		float glow_factor = glow->intensity * (1.f / (1.f + distance));
		result.glow_factor += glow_factor;
		result.glow += glow->color * glow_factor;
		if (distance < minDist)
		{
			minDist = distance;
			result.primitive = primitive.get();
		}
	}
	return minDist;
} 

Vector Shader::RenderPixel(float x, float y)
{
	Vector pos;
	Vector ray;
	Vector color;
	float oversampling = std::max(1, m_Lightning.oversampling);
	float oversqrt = sqrt(oversampling);
	for (float i = 0; i < oversampling; i++) {
		float offset_x = fmod(i / oversqrt, 1.f);
		float offset_y = floor(i / oversqrt) / oversqrt;
		m_Camera.CalculateRay(x + offset_x, y + offset_y, pos, ray);		
		color += PhongShading(pos, ray, m_Bouncing);
	}
	return color;
	color.x = EnsureRange(color.x / oversampling, 0.f, 1.f);
	color.y = EnsureRange(color.y / oversampling, 0.f, 1.f);
	color.z = EnsureRange(color.z / oversampling, 0.f, 1.f);
	return color;
}