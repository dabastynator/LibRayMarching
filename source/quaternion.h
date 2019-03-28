#pragma once

#include <iostream>

namespace LibRayMarching
{

	struct Quaternion
	{
		double r;
		double i;
		double j;
		double k;

		Quaternion();
		Quaternion(const Quaternion& Quaternion);
		Quaternion(const double& r, const double& i, const double& j, const double& k);

		Quaternion operator+(const Quaternion& quat) const;
		Quaternion operator-(const Quaternion& quat) const;
		Quaternion operator*(const Quaternion& quat) const;
		Quaternion operator*(const double& val) const;
		Quaternion operator/(const Quaternion& quat) const;
		Quaternion operator/(const double& val) const;

		Quaternion operator+=(const Quaternion& quat);
		Quaternion operator-=(const Quaternion& quat);
		Quaternion operator*=(const Quaternion& quat);
		Quaternion operator*=(const double& val);
		Quaternion operator/=(const double& val);

		double length() const;
		double norm() const;
		double dot(const Quaternion& quat) const;
		Quaternion cross(const Quaternion& quat) const;
		Quaternion squared() const;
		void normalize();
		Quaternion normalized() const;		
	};

	const Quaternion QuaternionIdentity(1, 0, 0, 0);

	std::ostream& operator<< (std::ostream& stream, const Quaternion& Quaternion);
}
