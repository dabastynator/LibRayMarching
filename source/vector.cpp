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

Vector::Vector(const float& val)
{
	x = val;
	y = val;
	z = val;
}

Vector::Vector(const float& x, const float& y, const float& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector Vector::operator+(const Vector& vec) const
{
	return Vector(x+vec.x, y+vec.y, z+vec.z);
}

Vector Vector::operator+(const float& val) const
{
	return Vector(x+val, y+val, z+val);
}

Vector Vector::operator-(const Vector& vec) const
{
	return Vector(x-vec.x, y-vec.y, z-vec.z);
}

Vector Vector::operator-(const float& val) const
{
	return Vector(x-val, y-val, z-val);
}

Vector Vector::operator*(const Vector& vec) const
{
	return Vector(x*vec.x, y*vec.y, z*vec.z);
}

Vector Vector::operator*(const float& val) const
{
	return Vector(x*val, y*val, z*val);
}

Vector Vector::operator/(const Vector& vec) const
{
	return Vector(x/vec.x, y/vec.y, z/vec.z);
}

Vector Vector::operator/(const float& val) const
{
	return Vector(x/val, y/val, z/val);
}

Vector Vector::operator%(const Vector& vec) const
{
	return Vector(std::fmod(x, vec.x), std::fmod(y, vec.y), std::fmod(z, vec.z));
}

Vector Vector::operator%(const float& val) const
{
	return Vector(std::fmod(x, val), std::fmod(y, val), std::fmod(z, val));
}

Vector Vector::operator+=(const Vector& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return *this;
}

Vector Vector::operator+=(const float& val)
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

Vector Vector::operator-=(const float& val)
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

Vector Vector::operator*=(const float& val)
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

Vector Vector::operator/=(const float& val)
{
	x /= val;
	y /= val;
	z /= val;
	return *this;
}

Vector Vector::operator%=(const Vector& vec)
{
	x = std::fmod(x, vec.x);
	y = std::fmod(y, vec.y);
	z = std::fmod(z, vec.z);
	return *this;
}

Vector Vector::operator%=(const float& val)
{
	x = std::fmod(x, val);
	y = std::fmod(y, val);
	z = std::fmod(z, val);
	return *this;
}

float Vector::length() const
{
	return sqrt(x*x + y*y + z*z);
}

float Vector::lengthSquare() const
{
	return x*x + y*y + z*z;
}

float Vector::dot(const Vector& vec) const
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

float Vector::min() const
{
	return std::min(std::min(x, y), z);
}

float Vector::max() const
{
	return std::max(std::max(x, y), z);
}

Vector Vector::abs() const
{
	return Vector(std::abs(x), std::abs(y), std::abs(z));
}

void Vector::normalize()
{
	float l = length();
	if (l != 0)
	{
		x /= l;
		y /= l;
		z /= l;
	}
}

Vector Vector::normalized() const
{
	float l = length();
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