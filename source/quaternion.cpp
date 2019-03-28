#include "quaternion.h"
#include <cmath>
#include <algorithm>

using namespace LibRayMarching;

Quaternion::Quaternion()
{
	r = 0;
	i = 0;
	j = 0;
	k = 0;
}

Quaternion::Quaternion(const Quaternion& quat)
{
	r = quat.r;
	i = quat.i;
	j = quat.j;
	k = quat.k;
}

Quaternion::Quaternion(const double& r, const double& i, const double& j, const double& k)
{
	this->r = r;
	this->i = i;
	this->j = j;
	this->k = k;
}

Quaternion Quaternion::operator+(const Quaternion& quat) const
{
	return Quaternion(r+quat.r, i+quat.i, j+quat.j, k+quat.k);
}

Quaternion Quaternion::operator-(const Quaternion& quat) const
{
	return Quaternion(r-quat.r, i-quat.i, j-quat.j, k-quat.k);
}

Quaternion Quaternion::operator*(const Quaternion& quat) const
{
	return Quaternion(
		r * quat.r - i * quat.i - j * quat.j - k * quat.k,
		r * quat.i + i * quat.r + j * quat.k - k * quat.j,
		r * quat.j - i * quat.k + j * quat.r + k * quat.i,
		r * quat.k + i * quat.j - j * quat.i + k * quat.r);
}

Quaternion Quaternion::operator*(const double& val) const
{
	return Quaternion(r*val, i*val, j*val, k*val);
}

Quaternion Quaternion::operator/(const double& val) const
{
	return Quaternion(r/val, i/val, j/val, k/val);
}

Quaternion Quaternion::operator+=(const Quaternion& quat)
{
	r += quat.r;
	i += quat.i;
	j += quat.j;
	k += quat.k;
	return *this;
}

Quaternion Quaternion::operator-=(const Quaternion& quat)
{
	r -= quat.r;
	i -= quat.i;
	j -= quat.j;
	k -= quat.k;
	return *this;
}

Quaternion Quaternion::operator*=(const Quaternion& quat)
{
	double r_new = r * quat.r - i * quat.i - j * quat.j - k * quat.k;
	double i_new = r * quat.i + i * quat.r + j * quat.k - k * quat.j;
	double j_new = r * quat.j - i * quat.k + j * quat.r + k * quat.i;
	double k_new = r * quat.k + i * quat.j - j * quat.i + k * quat.r;
	r = r_new;
	i = i_new;
	j = j_new;
	k = k_new;
	return *this;
}

Quaternion Quaternion::operator*=(const double& val)
{
	r *= val;
	i *= val;
	j *= val;
	k *= val;
	return *this;
}

Quaternion Quaternion::operator/=(const double& val)
{
	r /= val;
	i /= val;
	j /= val;
	k /= val;
	return *this;
}

double Quaternion::length() const
{
	return sqrt(r*r + i*i + j*j + k*k);
}

double Quaternion::norm() const
{
	return r*r + i*i + j*j + k*k;
}

double Quaternion::dot(const Quaternion& quat) const
{
	return r * quat.r + i * quat.i + j * quat.j + k * quat.k;
}

Quaternion Quaternion::cross(const Quaternion& quat) const
{
	return Quaternion(0,
		j * quat.k - k * quat.j,
		k * quat.i - i * quat.k,
		i * quat.j - j * quat.i
	);
}

void Quaternion::normalize()
{
	double l = length();
	if (l != 0)
	{
		r /= l;
		i /= l;
		j /= l;
		k /= l;
	}
}

Quaternion Quaternion::normalized() const
{
	double l = length();
	if (l != 0)
	{
		return Quaternion(r/l, i/l, j/l, k/l);
	} else
	{
		return Quaternion(*this);
	}
}

Quaternion Quaternion::squared() const
{
	return Quaternion(
		r * r - i * i - j * j - k * k,
		2 * r * i,
		2 * r * j,
		2 * r * k);
}

std::ostream& LibRayMarching::operator<<(std::ostream& stream, const Quaternion& quat)
{
	return stream << "(r=" << quat.r << ", i=" << quat.i << ", j=" << quat.j << ", k=" << quat.k << ")";
}