#pragma once

#include "vector.h"

namespace LibRayMarching
{
	struct Matrix
	{
		double field[16];

		Matrix();
		Matrix(const Matrix& Matrix);

		Matrix operator+(const Matrix& mx) const;
		Matrix operator-(const Matrix& mx) const;
		Matrix operator*(const Matrix& mx) const;

		Matrix operator+=(const Matrix& mx);
		Matrix operator-=(const Matrix& mx);
		Matrix operator*=(const Matrix& mx);

		Vector operator*(const Vector& vec) const;
	};

	Matrix Rotate(const Vector& axis, const double& angle_radian);
	Matrix Translate(const Vector& translation);
	Matrix Scale(const Vector& scale);
	Matrix Scale(const double& scale);
}
