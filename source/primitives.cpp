#include "primitives.h"

using namespace LibRayMarching;

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

void Sphere::Initialize()
{
	
}

double Sphere::SignedDistance (const Vector& vPoint)
{
	Vector p = m_Inverse * vPoint;
	return p.length() - m_Radius;
}

void Capsule::Initialize()
{
	m_P1P2 = m_Point2 - m_Point1;
	m_Length = m_P1P2.length();
}

double Capsule::SignedDistance (const Vector& vPoint)
{	
	Vector p = m_Inverse * vPoint - m_Point1;
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

double Box::SignedDistance (const Vector& vPoint)
{
	Vector d = m_Inverse * vPoint;
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

double Plane::SignedDistance (const Vector& vPoint)
{
	Vector p = vPoint - m_Origin;
	return std::abs(p.dot(m_TransformedNormal));
}