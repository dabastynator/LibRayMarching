#include "matrix.h"
#include "vector.h"
#include <cmath>

using namespace LibRayMarching;

Matrix::Matrix()
{
	field[0]  = 1; field[1]  = 0; field[2]  = 0; field[3]  = 0;
	field[4]  = 0; field[5]  = 1; field[6]  = 0; field[7]  = 0;
	field[8]  = 0; field[9]  = 0; field[10] = 1; field[11] = 0;
	field[12] = 0; field[13] = 0; field[14] = 0; field[15] = 1;
}

Matrix::Matrix(const Matrix& mx)
{
	field[0]  = mx.field[0];  field[1]  = mx.field[1];  field[2]  = mx.field[2];  field[3]  = mx.field[3];
	field[4]  = mx.field[4];  field[5]  = mx.field[5];  field[6]  = mx.field[6];  field[7]  = mx.field[7];
	field[8]  = mx.field[8];  field[9]  = mx.field[9];  field[10] = mx.field[10]; field[11] = mx.field[11];
	field[12] = mx.field[12]; field[13] = mx.field[13]; field[14] = mx.field[14]; field[15] = mx.field[15];
}

Matrix Matrix::operator+(const Matrix& mx) const
{
	Matrix res;
	for(int i = 0; i < 16; i++)
	{
		res.field[i] = field[i] + mx.field[i];
	}
	return res;
}

Matrix Matrix::operator-(const Matrix& mx) const
{
	Matrix res;
	for(int i = 0; i < 16; i++)
	{
		res.field[i] = field[i] - mx.field[i];
	}
	return res;
}
Matrix Matrix::operator*(const Matrix& mx) const
{
	Matrix res;
	res.field[0]  = field[0]  * mx.field[0] + field[1]  * mx.field[4] + field[2]  * mx.field[8]  + field[3]  * mx.field[12];
	res.field[1]  = field[0]  * mx.field[1] + field[1]  * mx.field[5] + field[2]  * mx.field[9]  + field[3]  * mx.field[13];
	res.field[2]  = field[0]  * mx.field[2] + field[1]  * mx.field[6] + field[2]  * mx.field[10] + field[3]  * mx.field[14];
	res.field[3]  = field[0]  * mx.field[3] + field[1]  * mx.field[7] + field[2]  * mx.field[11] + field[3]  * mx.field[15];
	res.field[4]  = field[4]  * mx.field[0] + field[5]  * mx.field[4] + field[6]  * mx.field[8]  + field[7]  * mx.field[12];
	res.field[5]  = field[4]  * mx.field[1] + field[5]  * mx.field[5] + field[6]  * mx.field[9]  + field[7]  * mx.field[13];
	res.field[6]  = field[4]  * mx.field[2] + field[5]  * mx.field[6] + field[6]  * mx.field[10] + field[7]  * mx.field[14];
	res.field[7]  = field[4]  * mx.field[3] + field[5]  * mx.field[7] + field[6]  * mx.field[11] + field[7]  * mx.field[15];
	res.field[8]  = field[8]  * mx.field[0] + field[9]  * mx.field[4] + field[10] * mx.field[8]  + field[11] * mx.field[12];
	res.field[9]  = field[8]  * mx.field[1] + field[9]  * mx.field[5] + field[10] * mx.field[9]  + field[11] * mx.field[13];
	res.field[10] = field[8]  * mx.field[2] + field[9]  * mx.field[6] + field[10] * mx.field[10] + field[11] * mx.field[14];
	res.field[11] = field[8]  * mx.field[3] + field[9]  * mx.field[7] + field[10] * mx.field[11] + field[11] * mx.field[15];
	res.field[12] = field[12] * mx.field[0] + field[13] * mx.field[4] + field[14] * mx.field[8]  + field[15] * mx.field[12];
	res.field[13] = field[12] * mx.field[1] + field[13] * mx.field[5] + field[14] * mx.field[9]  + field[15] * mx.field[13];
	res.field[14] = field[12] * mx.field[2] + field[13] * mx.field[6] + field[14] * mx.field[10] + field[15] * mx.field[14];
	res.field[15] = field[12] * mx.field[3] + field[13] * mx.field[7] + field[14] * mx.field[11] + field[15] * mx.field[15];
	return res;
}

Matrix Matrix::operator+=(const Matrix& mx)
{
	for (int i = 0; i < 16; i++)
	{
		field[i] += mx.field[i];
	}
	return *this;
}

Matrix Matrix::operator-=(const Matrix& mx)
{
	for (int i = 0; i < 16; i++)
	{
		field[i] -= mx.field[i];
	}
	return *this;
}
Matrix Matrix::operator*=(const Matrix& mx)
{
	Matrix result = (*this) * mx;
	field[0] = result.field[0];
	field[1] = result.field[1];
	field[2] = result.field[2];
	field[3] = result.field[3];
	field[4] = result.field[4];
	field[5] = result.field[5];
	field[6] = result.field[6];
	field[7] = result.field[7];
	field[8] = result.field[8];
	field[9] = result.field[9];
	field[10] = result.field[10];
	field[11] = result.field[11];
	field[12] = result.field[12];
	field[13] = result.field[13];
	field[14] = result.field[14];
	field[15] = result.field[15];
	return *this;
}

Vector Matrix::operator*(const Vector& vec) const
{
	return Vector(
		vec.x * field[0] + vec.y * field[4] + vec.z * field[8]  + field[12],
		vec.x * field[1] + vec.y * field[5] + vec.z * field[9]  + field[13],
		vec.x * field[2] + vec.y * field[6] + vec.z * field[10] + field[14]
	);
}

Matrix LibRayMarching::MatrixRotate(const Vector& axis, const float& angle_radian)
{
	float s = std::sin(angle_radian);
	float c = std::cos(angle_radian);

	Matrix mx;
	mx.field[0]  = c + axis.x * axis.x * (1 - c);
	mx.field[1]  = axis.x * axis.y * (1 - c) - axis.z * s;
	mx.field[2]  = axis.x * axis.z * (1 - c) + axis.y * s;
	mx.field[3]  = 0;
	mx.field[4]  = axis.y * axis.x * (1 - c) + axis.z * s;
	mx.field[5]  = c + axis.y * axis.y * (1 - c);
	mx.field[6]  = axis.y * axis.z * (1 - c) - axis.x * s;
	mx.field[7]  = 0;
	mx.field[8]  = axis.z * axis.x * (1 - c) - axis.y * s;
	mx.field[9]  = axis.z * axis.y * (1 - c) + axis.x * s;
	mx.field[10] = c + axis.z * axis.z * (1 - c);
	mx.field[11]  = 0;
	mx.field[12]  = 0;
	mx.field[13]  = 0;
	mx.field[14]  = 0;
	mx.field[15]  = 1;
	return mx;
}

Matrix LibRayMarching::MatrixTranslate(const Vector& translation)
{
	Matrix result;
	result.field[12] = translation.x;
	result.field[13] = translation.y;
	result.field[14] = translation.z;
	return result;
}

Matrix LibRayMarching::MatrixScale(const Vector& scale)
{
	Matrix result;
	result.field[0]  = scale.x;
	result.field[5]  = scale.y;
	result.field[10] = scale.z;
	return result;
}

Matrix LibRayMarching::MatrixScale(const float& scale)
{
	Matrix result;
	result.field[0]  = scale;
	result.field[5]  = scale;
	result.field[10] = scale;
	return result;
}

Matrix LibRayMarching::MatrixInverse(const Matrix& matrix)
{
	Matrix result;
	// TODO
	return result;
}

std::ostream& LibRayMarching::operator<<(std::ostream& stream, const Matrix& matrix)
{
	for (int i=0; i < 4; i++)
	{
		stream << "(" << matrix.field[0 + 4*i] << ", " << matrix.field[1 + 4*i] << ", "
			 << matrix.field[2 + 4*i] << ", " << matrix.field[3 + 4*i] << ")" << std::endl;
	}
	return stream;
}