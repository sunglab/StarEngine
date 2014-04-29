#ifndef MATRIX_H
#define MATRIX_H

#include "../star.h"
#include "./Vector.h"

class Matrix
{
	public:
		__MATRIX__TYPE__* operator[] (const unsigned int row)
		{ return &s[row<<2]; }

		__MATRIX__TYPE__ s[16];
};

void Matrix_MxM( Matrix& out_M, const Matrix& in_M1, const Matrix& in_M2);

void Matrix_MxV( Vec4& out_V, const Vec4& in_V, const Matrix& in_M);

void Matrix_Translation( Matrix& out_M, const float x, const float y, const float z);

void Matrix_Scaling( Matrix& out_M, const float x, const float y, const float z);

void Matrix_RotationX( Matrix& out_M, const float angle);

void Matrix_RotationY( Matrix& out_M, const float angle);

void Matrix_RotationZ( Matrix& out_M, const float angle);

void Matrix_Identity( Matrix& out_M);

void Matrix_Look_At( Matrix& out_M, const Vec3& in_EYE, const Vec3& in_AT, const Vec3& in_UP);

void Matrix_Ortho( Matrix& out_M, const float width, const float height, const float nZ, const float fZ, const bool ROT);


// NEON SIMD
void Matrix_MxM_NEON(__MATRIX__TYPE__ * out_M, const __MATRIX__TYPE__* in_M1, const __MATRIX__TYPE__* in_M2);

void Matrix_MxV_NEON(__VERTEX__TYPE__* out_V, const __VERTEX__TYPE__* in_V1, const __MATRIX__TYPE__* in_M);
#endif // MATRIX
