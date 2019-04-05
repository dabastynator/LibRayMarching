#pragma once

#include <iostream>

namespace LibRayMarching
{
	template <typename T>
	T EnsureRange(const T& value, const T& low, const T& high)
	{
		return value < low ? low : (value > high ? high : value);
	}

	struct Vector
	{
		float x;
		float y;
		float z;

		Vector();
		Vector(const Vector& vector);
		Vector(const float& val);
		Vector(const float& x, const float& y, const float& z);

		Vector operator+(const Vector& vec) const;
		Vector operator+(const float& val) const;
		Vector operator-(const Vector& vec) const;
		Vector operator-(const float& val) const;
		Vector operator*(const Vector& vec) const;
		Vector operator*(const float& val) const;
		Vector operator/(const Vector& vec) const;
		Vector operator/(const float& val) const;
		Vector operator%(const Vector& vec) const;
		Vector operator%(const float& val) const;

		Vector operator+=(const Vector& vec);
		Vector operator+=(const float& val);
		Vector operator-=(const Vector& vec);
		Vector operator-=(const float& val);
		Vector operator*=(const Vector& vec);
		Vector operator*=(const float& val);
		Vector operator/=(const Vector& vec);
		Vector operator/=(const float& val);
		Vector operator%=(const Vector& vec);
		Vector operator%=(const float& val);

		float length() const;
		float lengthSquare() const;
		float dot(const Vector& vec) const;
		Vector cross(const Vector& vec) const;
		float min() const;
		float max() const;
		Vector abs() const;
		void normalize();
		Vector normalized() const;		
	};

	const Vector VectorNull(0, 0, 0);
	const Vector VectorX(1, 0, 0);
	const Vector VectorY(0, 1, 0);
	const Vector VectorZ(1, 0, 1);

	std::ostream& operator<< (std::ostream& stream, const Vector& vector);
}
