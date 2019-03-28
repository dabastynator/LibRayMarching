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
		double x;
		double y;
		double z;

		Vector();
		Vector(const Vector& vector);
		Vector(const double& val);
		Vector(const double& x, const double& y, const double& z);

		Vector operator+(const Vector& vec) const;
		Vector operator+(const double& val) const;
		Vector operator-(const Vector& vec) const;
		Vector operator-(const double& val) const;
		Vector operator*(const Vector& vec) const;
		Vector operator*(const double& val) const;
		Vector operator/(const Vector& vec) const;
		Vector operator/(const double& val) const;
		Vector operator%(const Vector& vec) const;
		Vector operator%(const double& val) const;

		Vector operator+=(const Vector& vec);
		Vector operator+=(const double& val);
		Vector operator-=(const Vector& vec);
		Vector operator-=(const double& val);
		Vector operator*=(const Vector& vec);
		Vector operator*=(const double& val);
		Vector operator/=(const Vector& vec);
		Vector operator/=(const double& val);
		Vector operator%=(const Vector& vec);
		Vector operator%=(const double& val);

		double length() const;
		double lengthSquare() const;
		double dot(const Vector& vec) const;
		Vector cross(const Vector& vec) const;
		double min() const;
		double max() const;
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
