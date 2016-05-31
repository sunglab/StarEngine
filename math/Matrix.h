#ifndef MATRIX_H
#define MATRIX_H

#include "../star.h"
#include "./Vector.h"
//#include "./Quaternion.h"
class Quaternion
{
public:
    float w;
    float x;
    float y;
    float z;
    Quaternion():w(1),x(0),y(0),z(0)
    {}
    Quaternion(float _w,float _x, float _y, float _z)
    {w = _w; x = _x; y = _y; z = _z;}
    
    Quaternion operator+(const float& in_Scalar) const;
    Quaternion operator-(const float& in_Scalar) const;
    Quaternion operator*(const float& in_Scalar) const;
    Quaternion operator/(const float& in_Scalar) const;
    
    
    Quaternion operator+(const Quaternion& in_Q) const;
    Quaternion operator-(const Quaternion& in_Q) const;
    
    float dot(const Quaternion& in_Q);
    void lerp(float t,const Quaternion& in_Q);
    
    
};
class Matrix3
{
public:
    __MATRIX__TYPE__* operator[] (const unsigned int row)
    { return &s[row*3]; }
    
		__MATRIX__TYPE__ s[9];
    
    Matrix3 operator*(const Matrix3& in_M)const;
    friend Vec3 operator*(const Vec3& in_V, const Matrix3& in_M);
};
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
void Matrix_to_Matrix3( Matrix3& out_M, const Matrix& in_M);
void Matrix_MxM( Matrix& out_M, const Matrix& in_M1, const Matrix& in_M2);

void Matrix_MxV( Vec4& out_V, const Vec4& in_V, const Matrix& in_M);
void Matrix_MxV( Vec3& out_V, const Vec3& in_V, const Matrix& in_M);
void Matrix_MxV( Vec2& out_V, const Vec2& in_V, const Matrix& in_M);

void Matrix_Translation( Matrix& out_M, const float x, const float y, const float z);

void Matrix_Viewport(Matrix& out_M, const Vec2& in_Rect, const Matrix& in_M);
void Matrix_Scaling( Matrix& out_M, const float x, const float y, const float z);

void Matrix_Scaling_By_Perspective(Matrix& out_M, const float FOV, const float ASPECT);

void Matrix_Rotation_X( Matrix& out_M, const float angle);

void Matrix_Rotation_Y( Matrix& out_M, const float angle);

void Matrix_Rotation_Z( Matrix& out_M, const float angle);

void Matrix_Identity( Matrix& out_M);

void Matrix_Look_At( Matrix& out_M, const Vec3& in_EYE, const Vec3& in_AT, const Vec3& in_UP);

void Matrix_PerspectiveProjection(Matrix& out_M, const __VERTEX__TYPE__ FOV, const __VERTEX__TYPE__ ASPECT, const __VERTEX__TYPE__ NEAR, const __VERTEX__TYPE__ FAR);
void Matrix_OrthoProjection( Matrix& out_M, const float width, const float height, const float nZ, const float fZ);

void Matrix_Transpose( Matrix& out_M, const Matrix& in_M);
void Matrix_Inverse( Matrix& out_M, const Matrix& in_M);

/*
 * 3X3
 */
void Matrix3_Identity(Matrix3& out_M);
void Matrix3_Inverse( Matrix3& out_M, const Matrix3& in_M);
void Matrix3_Transpose(Matrix3& out_M, const Matrix3& in_M);
void Matrix3_Scaling( Matrix3& out_M, const float x, const float y, const float z);
void Matrix_MxV( Vec3& out_V, const Vec3& in_V, const Matrix3& in_M);
// NEON SIMD
void Matrix_MxM_NEON(__MATRIX__TYPE__ * out_M, const __MATRIX__TYPE__* in_M1, const __MATRIX__TYPE__* in_M2);

void Matrix_MxV_NEON(__VERTEX__TYPE__* out_V, const __VERTEX__TYPE__* in_V1, const __MATRIX__TYPE__* in_M);

// Quaternion
void Quaternion_Identity(Quaternion& out_Q);
void Quaternion_Normalize(Quaternion& out_Q);
void Quaternion_Rotation_Axis(Quaternion &out_Q, const Vec3 &axis, float angle);
void Quaternion_Rotation_Vector(Quaternion& out_Q, const  Vec3& in_V1,const  Vec3& in_V2);
void Quaternion_Rotation_Quaternion(Quaternion& out_Q, const Quaternion& in_Q1,const Quaternion& in_Q2);
void Quaternion_to_Matrix(Matrix& out_M, const Quaternion& in_Q);
//void Matrix_Quaternion_Identity(Quaternion& out_Q);
//void Matrix_Quaternion_RotationAxis(Quaternion& out_Q,const Vec3& in_Axis, const float angle);
//void Matrix_Quaternion_ToAxisAngle(Quaternion&	in_Q,Vec3& in_Axis, float& angle);
//void Matrix_Quaternion_Slerp(Quaternion& out_Q, const Quaternion& in_Q1, const Quaternion& in_Q2, const float t);
//void Matrix_Rotation_Quaternion(Matrix& out_M,const Quaternion& in_Q);
//void Matrix_Quaternion_Multiply(Quaternion& out_Q,const Quaternion& in_Q1,const Quaternion& in_Q2);

#endif // MATRIX

