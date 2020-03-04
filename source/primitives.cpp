#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>

#include "primitives.h"

using namespace LibRayMarching;

Primitive::Primitive()
{
	m_Distortion = pdNone;
	m_DistSinSize = 0;
	m_DistSinFactor = 0;
	m_Glow.intensity = 0;
}

void Primitive::IdentityPosition ()
{
	m_ModelToWorld = Matrix();
	m_Inverse = Matrix();
}

void Primitive::Translate (const Vector& vTranslation)
{
	m_ModelToWorld *= MatrixTranslate(vTranslation);
	m_Inverse = MatrixTranslate(vTranslation * -1) * m_Inverse;
}

void Primitive::Rotate (const Vector& vAxis, const float dRadian)
{
	m_ModelToWorld *= MatrixRotate(vAxis, dRadian);
	m_Inverse = MatrixRotate(vAxis, -dRadian) * m_Inverse;
}

void Primitive::Scale (const Vector& vScale)
{
	m_ModelToWorld *= MatrixScale(vScale);
	m_Inverse = MatrixScale(Vector(1, 1, 1) / vScale) * m_Inverse;
}

void Primitive::SetMaterial (const Material& Material)
{
	m_Material = Material;
}

void Primitive::SetGlow (const Glow& Glow)
{
	m_Glow = Glow;
}

void Primitive::SetDistortionSinus(float factor, float size)
{
	m_Distortion = pdSinus;
	m_DistSinSize = size;
	m_DistSinFactor = factor;
}

float Primitive::SignedDistance (const Vector& vPoint) const
{
	Vector p = m_Inverse * vPoint;
	float sd = InternSignedDistance(p);
	switch(m_Distortion){
		case pdSinus:
			//std::cout << " has sin distortion " << sd << std::endl;
			Vector d = p * (2 * M_PI / m_DistSinSize);
			sd += (sin(d.x) + sin(d.y) + sin(d.z)) * m_DistSinFactor;
			//std::cout << " result " << sd << std::endl;
			break;
	}
	return sd;
}

void Sphere::Initialize()
{
	
}

float Sphere::InternSignedDistance (const Vector& vPoint) const
{
	return vPoint.length() - m_Radius;
}

void Capsule::Initialize()
{
	m_P1P2 = m_Point2 - m_Point1;
	m_Length = m_P1P2.length();
}

float Capsule::InternSignedDistance (const Vector& vPoint) const
{	
	Vector p = vPoint - m_Point1;
	if (m_Length > 0)
	{
		float dot = EnsureRange(p.dot(m_P1P2) / (m_Length * m_Length), 0.f, 1.f);
		Vector onLine = m_P1P2 * dot;
		return (p - onLine).length() - m_Radius;
	}
	return p.length() - m_Radius;
}

void Box::Initialize()
{

}

float Box::InternSignedDistance (const Vector& vPoint) const
{
	Vector d = vPoint;
	d.x = std::abs(d.x);
	d.y = std::abs(d.y);
	d.z = std::abs(d.z);
	d -= m_Dimensions;
	d.x = std::max(0.f, d.x);
	d.y = std::max(0.f, d.y);
	d.z = std::max(0.f, d.z);
	return d.length();
}

void Plane::Initialize()
{

}

float Plane::InternSignedDistance (const Vector& vPoint) const
{
	return vPoint.dot(m_Normal);
}

void Cylinder::Initialize()
{

}

float Cylinder::InternSignedDistance (const Vector& vPoint) const
{
	float distCircle = sqrt(vPoint.x * vPoint.x + vPoint.y * vPoint.y) - m_Radius;
	float distHeight = std::abs(vPoint.z) - m_Height / 2;
	if (distCircle < 0 && distHeight < 0)
	{
		return std::max(distCircle, distHeight);
	} else 
	{
		distCircle = std::max(distCircle, 0.f);
		distHeight = std::max(distHeight, 0.f);
		return sqrt(distCircle * distCircle + distHeight * distHeight);
	}
}

void Torus::Initialize()
{

}

float Torus::InternSignedDistance (const Vector& vPoint) const
{
	float distBig = sqrt(vPoint.x * vPoint.x + vPoint.y * vPoint.y) - m_RadiusBig;
	float dist = sqrt(distBig * distBig  + vPoint.z * vPoint.z);
	return dist - m_RadiusSmall;
}

void MengerSponge::Initialize()
{

}

float MengerSponge::InternSignedDistance (const Vector& vPoint) const
{
	// SDF box
	Vector box(
		std::max(0.f, std::abs(vPoint.x) - 1),
		std::max(0.f, std::abs(vPoint.y) - 1),
		std::max(0.f, std::abs(vPoint.z) - 1));
	float sdBox = box.length();

	// SDF inside crosses
	float sdMS = sdBox;
	float size = 1;
	for (int i=0; i < m_SetpCount; i++)
	{
		Vector a = ((vPoint.abs() * size + size) % 2 - 1).abs();
		Vector d(std::max(a.x, a.y), std::max(a.y, a.z), std::max(a.z, a.x));
		size *= 3;
		float sdCross = (d.min() - 1.f/3.f) / size;
		sdMS = std::max(sdMS, -sdCross);		
	}
	return sdMS;
}

void QuaternionFractal::Initialize()
{

}

float QuaternionFractal::InternSignedDistance (const Vector& vPoint) const
{
	Quaternion z(vPoint.x, vPoint.y, vPoint.z, 0);
	Quaternion dz(1, 0, 0, 0);
	float m2;
	float sign = -1;
	for (int i = 0; i < m_Iterations; i++) {
		dz = z * dz * 2.f;
		z = z.squared() + m_Quaternion;
		m2 = z.dot(z);
		if (m2 > 10.0) {
			sign = 1;
			break;
		}
	}
	return 0.25f * sqrt(m2 / dz.dot(dz)) * std::abs(log(m2)) * sign;
}

void PrimitiveGroup::Initialize()
{
	
}

float PrimitiveGroup::InternSignedDistance (const Vector& vPoint) const
{
	float sd;
	switch(m_CombineAction){
		case caUnify:
			sd = (float) 10e10;
			for(auto p = m_Primitives.begin(); p != m_Primitives.end(); ++p)
			{		
				PrimitivePtr primitive = *p;
				float distance = primitive->SignedDistance(vPoint);
				sd = std::min(sd, distance);
			}
			return sd;
		case caIntersect:
			sd = (float) -10e10;
			for(auto p = m_Primitives.begin(); p != m_Primitives.end(); ++p)
			{		
				PrimitivePtr primitive = *p;
				float distance = primitive->SignedDistance(vPoint);
				sd = std::max(sd, distance);
			}
			return sd;
		case caSubtract:
			sd = 0;
			for(auto p = m_Primitives.begin(); p != m_Primitives.end(); ++p)
			{		
				PrimitivePtr primitive = *p;
				float distance = primitive->SignedDistance(vPoint);
				if (p == m_Primitives.begin())
				{
					sd = distance;
				} else
				{
					sd = std::max(sd, -distance);
				}				
			}
			return sd;
	}
}