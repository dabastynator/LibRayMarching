#pragma once

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
		Vector(const double& x, const double& y, const double& z);

		Vector operator+(const Vector& vec) const;
		Vector operator+(const double& val) const;
		Vector operator-(const Vector& vec) const;
		Vector operator-(const double& val) const;
		Vector operator*(const Vector& vec) const;
		Vector operator*(const double& val) const;

		Vector operator+=(const Vector& vec);
		Vector operator+=(const double& val);
		Vector operator-=(const Vector& vec);
		Vector operator-=(const double& val);
		Vector operator*=(const Vector& vec);
		Vector operator*=(const double& val);

		double length() const;
		double lengthSquare() const;
		double dot(const Vector& vec) const;
		Vector cross(const Vector& vec) const;
		double min() const;
		double max() const;
	};
}
