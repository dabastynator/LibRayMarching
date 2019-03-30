#include <cmath>

#include "primitives.h"

using namespace LibRayMarching;

Primitive::Primitive()
{
	m_Distortion = pdNone;
	m_DistSinSize = 0;
	m_DistSinFactor = 0;
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

void Primitive::Rotate (const Vector& vAxis, const double dRadian)
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

void Primitive::SetDistortionSinus(double factor, double size)
{
	m_Distortion = pdSinus;
	m_DistSinSize = size;
	m_DistSinFactor = factor;
}

double Primitive::SignedDistance (const Vector& vPoint) const
{
	Vector p = m_Inverse * vPoint;
	double sd = InternSignedDistance(p);
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

double Sphere::InternSignedDistance (const Vector& vPoint) const
{
	return vPoint.length() - m_Radius;
}

void Capsule::Initialize()
{
	m_P1P2 = m_Point2 - m_Point1;
	m_Length = m_P1P2.length();
}

double Capsule::InternSignedDistance (const Vector& vPoint) const
{	
	Vector p = vPoint - m_Point1;
	if (m_Length > 0)
	{
		double dot = EnsureRange(p.dot(m_P1P2) / (m_Length * m_Length), 0., 1.);
		Vector onLine = m_P1P2 * dot;
		return (p - onLine).length() - m_Radius;
	}
	return p.length() - m_Radius;
}

void Box::Initialize()
{

}

double Box::InternSignedDistance (const Vector& vPoint) const
{
	Vector d = vPoint;
	d.x = std::abs(d.x);
	d.y = std::abs(d.y);
	d.z = std::abs(d.z);
	d -= m_Dimensions;
	d.x = std::max(0., d.x);
	d.y = std::max(0., d.y);
	d.z = std::max(0., d.z);
	return d.length();
}

void Plane::Initialize()
{
	m_Origin = m_ModelToWorld * VectorNull;
	m_TransformedNormal = m_ModelToWorld * m_Normal;
}

double Plane::InternSignedDistance (const Vector& vPoint) const
{
	Vector p = vPoint - m_Origin;
	return std::abs(p.dot(m_TransformedNormal));
}

void Cylinder::Initialize()
{

}

double Cylinder::InternSignedDistance (const Vector& vPoint) const
{
	double distCircle = sqrt(vPoint.x * vPoint.x + vPoint.y * vPoint.y) - m_Radius;
	double distHeight = std::abs(vPoint.z) - m_Height / 2;
	if (distCircle < 0 && distHeight < 0)
	{
		return std::max(distCircle, distHeight);
	} else 
	{
		distCircle = std::max(distCircle, 0.);
		distHeight = std::max(distHeight, 0.);
		return sqrt(distCircle * distCircle + distHeight * distHeight);
	}
}

void Torus::Initialize()
{

}

double Torus::InternSignedDistance (const Vector& vPoint) const
{
	double distBig = sqrt(vPoint.x * vPoint.x + vPoint.y * vPoint.y) - m_RadiusBig;
	double dist = sqrt(distBig * distBig  + vPoint.z * vPoint.z);
	return dist - m_RadiusSmall;
}

void MengerSponge::Initialize()
{

}

double MengerSponge::InternSignedDistance (const Vector& vPoint) const
{
	// SDF box
	Vector box(
		std::max(0., std::abs(vPoint.x) - 1),
		std::max(0., std::abs(vPoint.y) - 1),
		std::max(0., std::abs(vPoint.z) - 1));
	float sdBox = box.length();

	// SDF inside crosses
	float sdMS = sdBox;
	float size = 1;
	for (int i=0; i < m_SetpCount; i++)
	{
		Vector a = ((vPoint.abs() * size + size) % 2 - 1).abs();
		Vector d(std::max(a.x, a.y), std::max(a.y, a.z), std::max(a.z, a.x));
		size *= 3;
		float sdCross = (d.min() - 1./3.) / size;
		sdMS = std::max(sdMS, -sdCross);		
	}
	return sdMS;
}

void QuaternionFractal::Initialize()
{

}

double QuaternionFractal::InternSignedDistance (const Vector& vPoint) const
{
	Quaternion z(vPoint.x, vPoint.y, vPoint.z, 0);
	double md2 = 1.0;
	double mz2 = z.dot(z);
	for (int i = 0; i < m_Iterations; i++) {
		md2 *= 4.0 * mz2;
		z = z.squared() + m_Quaternion;
		mz2 = z.dot(z);
		if (mz2 > 10.0)
			break;
	}
	return 0.25 * sqrt(mz2 / md2) * log(mz2);
}

void PrimitiveGroup::Initialize()
{
	
}

double PrimitiveGroup::InternSignedDistance (const Vector& vPoint) const
{
	double sd;
	switch(m_CombineAction){
		case caUnify:
			sd = 10e10;
			for(auto p = m_Primitives.begin(); p != m_Primitives.end(); ++p)
			{		
				PrimitivePtr primitive = *p;
				double distance = primitive->SignedDistance(vPoint);
				sd = std::min(sd, distance);
			}
			return sd;
		case caIntersect:
			sd = -10e10;
			for(auto p = m_Primitives.begin(); p != m_Primitives.end(); ++p)
			{		
				PrimitivePtr primitive = *p;
				double distance = primitive->SignedDistance(vPoint);
				sd = std::max(sd, distance);
			}
			return sd;
		case caSubtract:
			sd = 0;
			for(auto p = m_Primitives.begin(); p != m_Primitives.end(); ++p)
			{		
				PrimitivePtr primitive = *p;
				double distance = primitive->SignedDistance(vPoint);
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