#include "vector.h"
#include <cmath>
#include <algorithm>

using namespace LibRayMarching;

Vector::Vector()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector::Vector(const Vector& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
}

Vector::Vector(const double& x, const double& y, const double& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector Vector::operator+(const Vector& vec) const
{
	return Vector(x+vec.x, y+vec.y, z+vec.z);
}

Vector Vector::operator+(const double& val) const
{
	return Vector(x+val, y+val, z+val);
}

Vector Vector::operator-(const Vector& vec) const
{
	return Vector(x-vec.x, y-vec.y, z-vec.z);
}

Vector Vector::operator-(const double& val) const
{
	return Vector(x-val, y-val, z-val);
}

Vector Vector::operator*(const Vector& vec) const
{
	return Vector(x*vec.x, y*vec.y, z*vec.z);
}

Vector Vector::operator*(const double& val) const
{
	return Vector(x*val, y*val, z*val);
}

Vector Vector::operator/(const Vector& vec) const
{
	return Vector(x/vec.x, y/vec.y, z/vec.z);
}

Vector Vector::operator/(const double& val) const
{
	return Vector(x/val, y/val, z/val);
}

Vector Vector::operator+=(const Vector& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return *this;
}

Vector Vector::operator+=(const double& val)
{
	x += val;
	y += val;
	z += val;
	return *this;
}

Vector Vector::operator-=(const Vector& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}

Vector Vector::operator-=(const double& val)
{
	x -= val;
	y -= val;
	z -= val;
	return *this;
}

Vector Vector::operator*=(const Vector& vec)
{
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
	return *this;
}

Vector Vector::operator*=(const double& val)
{
	x *= val;
	y *= val;
	z *= val;
	return *this;
}

Vector Vector::operator/=(const Vector& vec)
{
	x /= vec.x;
	y /= vec.y;
	z /= vec.z;
	return *this;
}

Vector Vector::operator/=(const double& val)
{
	x /= val;
	y /= val;
	z /= val;
	return *this;
}

double Vector::length() const
{
	return sqrt(x*x + y*y + z*z);
}

double Vector::lengthSquare() const
{
	return x*x + y*y + z*z;
}

double Vector::dot(const Vector& vec) const
{
	return x*vec.x + y*vec.y + z*vec.z;
}

Vector Vector::cross(const Vector& vec) const
{
	return Vector(
		(y * vec.z) - (vec.y * z),
		(z * vec.x) - (vec.z * x),
		(x * vec.y) - (vec.x * y)
	);
}

double Vector::min() const
{
	return std::min(std::min(x, y), z);
}

double Vector::max() const
{
	return std::max(std::max(x, y), z);
}

void Vector::normalize()
{
	double l = length();
	if (l != 0)
	{
		x /= l;
		y /= l;
		z /= l;
	}
}

Vector Vector::normalized() const
{
	double l = length();
	if (l != 0)
	{
		return Vector(x/l, y/l, z/l);
	} else
	{
		return Vector(*this);
	}
}

std::ostream& LibRayMarching::operator<<(std::ostream& stream, const Vector& vector)
{
	return stream << "(x=" << vector.x << ", y=" << vector.y << ", z=" << vector.z << ")";
}