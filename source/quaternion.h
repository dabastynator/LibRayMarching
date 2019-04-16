#pragma once

#include <iostream>

namespace LibRayMarching
{

	struct Quaternion
	{
		float r;
		float i;
		float j;
		float k;

		Quaternion();
		Quaternion(const Quaternion& Quaternion);
		Quaternion(const float& r, const float& i, const float& j, const float& k);

		Quaternion operator+(const Quaternion& quat) const;
		Quaternion operator-(const Quaternion& quat) const;
		Quaternion operator*(const Quaternion& quat) const;
		Quaternion operator*(const float& val) const;
		Quaternion operator/(const Quaternion& quat) const;
		Quaternion operator/(const float& val) const;

		Quaternion operator+=(const Quaternion& quat);
		Quaternion operator-=(const Quaternion& quat);
		Quaternion operator*=(const Quaternion& quat);
		Quaternion operator*=(const float& val);
		Quaternion operator/=(const float& val);

		float length() const;
		float norm() const;
		float dot(const Quaternion& quat) const;
		Quaternion cross(const Quaternion& quat) const;
		Quaternion squared() const;
		void normalize();
		Quaternion normalized() const;		
	};

	const Quaternion QuaternionIdentity(1, 0, 0, 0);

	std::ostream& operator<< (std::ostream& stream, const Quaternion& Quaternion);
}
