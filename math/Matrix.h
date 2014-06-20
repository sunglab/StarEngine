#ifndef MATRIX_H
#define MATRIX_H

#include "../star.h"
#include "./Vector.h"
#include "./Quaternion.h"
class Matrix
{
	public:
		__MATRIX__TYPE__* operator[] (const unsigned int row)
		{ return &s[row<<2]; }

		__MATRIX__TYPE__ s[16];

		Matrix operator*(const Matrix& in_M)const;
    friend Vec4 operator*(const Vec4& in_V, const Matrix& in_M);
    friend Vec3 operator*(const Vec3& in_V, const Matrix& in_M);
    friend Vec2 operator*(const Vec2& in_V, const Matrix& in_M);
//    (*this) inverse(void)
//    {
//        Matrix out_M;
//        out_M = *this;
//    }
};

void Matrix_MxM( Matrix& out_M, const Matrix& in_M1, const Matrix& in_M2);

void Matrix_MxV( Vec4& out_V, const Vec4& in_V, const Matrix& in_M);
void Matrix_MxV( Vec3& out_V, const Vec3& in_V, const Matrix& in_M);
void Matrix_MxV( Vec2& out_V, const Vec2& in_V, const Matrix& in_M);

void Matrix_Translation( Matrix& out_M, const float x, const float y, const float z);

void Matrix_Scaling( Matrix& out_M, const float x, const float y, const float z);

void Matrix_Rotation_X( Matrix& out_M, const float angle);

void Matrix_Rotation_Y( Matrix& out_M, const float angle);

void Matrix_Rotation_Z( Matrix& out_M, const float angle);

void Matrix_Identity( Matrix& out_M);

void Matrix_Look_At( Matrix& out_M, const Vec3& in_EYE, const Vec3& in_AT, const Vec3& in_UP);

void Matrix_Ortho( Matrix& out_M, const float width, const float height, const float nZ, const float fZ, const bool ROT);


// NEON SIMD
void Matrix_MxM_NEON(__MATRIX__TYPE__ * out_M, const __MATRIX__TYPE__* in_M1, const __MATRIX__TYPE__* in_M2);

void Matrix_MxV_NEON(__VERTEX__TYPE__* out_V, const __VERTEX__TYPE__* in_V1, const __MATRIX__TYPE__* in_M);

// Quaternion
void Matrix_Quaternion_Identity(Quaternion& out_Q);
void Matrix_Quaternion_RotationAxis(Quaternion& out_Q,const Vec3& in_Axis, const float angle);
void Matrix_Quaternion_ToAxisAngle(Quaternion&	in_Q,Vec3& in_Axis, float& angle);
void Matrix_Quaternion_Slerp(Quaternion& out_Q, const Quaternion& in_Q1, const Quaternion& in_Q2, const float t);
void Matrix_Quaternion_Normalize(Quaternion& in_Q);
void Matrix_Rotation_Quaternion(Matrix& out_M,const Quaternion& in_Q);
void Matrix_Quaternion_Multiply(Quaternion& out_Q,const Quaternion& in_Q1,const Quaternion& in_Q2);

#endif // MATRIX

