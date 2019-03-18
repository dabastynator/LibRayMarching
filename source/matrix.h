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

	Matrix MatrixRotate(const Vector& axis, const double& angle_radian);
	Matrix MatrixTranslate(const Vector& translation);
	Matrix MatrixScale(const Vector& scale);
	Matrix MatrixScale(const double& scale);
	Matrix MatrixInverse(const Matrix& matrix);
}
