
//
//  Vector.h
//
//  Created by sungwoo choi on 8/22/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include "../star.h"
#include <stdio.h>

// __VERTEX__TYPE__ing-point Operations
//#define __VERTEX__TYPE___MUL(a,b)		(	(VERTEX_TYPE)(	(a)*(b)	)	)
//#define __VERTEX__TYPE___DIV(a,b)		(	(VERTEX_TYPE)(	(a)/(b)	)	)
//#define __VERTEX__TYPE___ABS(a)			(	(VERTEX_TYPE)(	fabs(a)		)
//template <typename T>

class Vec3;
class Vec4;
class Vec2
{
public: 
    
    __VERTEX__TYPE__ x;
    __VERTEX__TYPE__ y;
    
    Vec2(){}
    Vec2(const __VERTEX__TYPE__& in_X,const __VERTEX__TYPE__& in_Y)
    {
        x = in_X;
        y = in_Y;
    }
    Vec2(const __VERTEX__TYPE__& in_XY)
    {
        x = in_XY;
        y = in_XY;
    }
    Vec2(const Vec3& vec3);
    Vec2 operator+(const Vec2& in_Vector)const;
    Vec2 operator-(const Vec2& in_Vector)const;
    Vec2& operator+=(const Vec2& in_Vector);
    Vec2& operator-=(const Vec2& in_Vector);
    Vec2 operator*(const Vec2& in_Vector)const;
    
    Vec2 operator+(const __VERTEX__TYPE__& in_Scalar)const;
    Vec2 operator-(const __VERTEX__TYPE__& in_Scalar)const;
    Vec2 operator*(const __VERTEX__TYPE__& in_Scalar)const;
    Vec2 operator/(const __VERTEX__TYPE__& in_Scalar)const;
    
    Vec2& operator+=(const __VERTEX__TYPE__& in_Scalar);
    Vec2& operator-=(const __VERTEX__TYPE__& in_Scalar);
    Vec2& operator*=(const __VERTEX__TYPE__& in_Scalar);
    Vec2& operator/=(const __VERTEX__TYPE__& in_Scalar);
    
	__VERTEX__TYPE__& operator[](int index);
	const __VERTEX__TYPE__& operator[](const int index) const;
    Vec2& operator=(const __VERTEX__TYPE__& in_Scalar);
    Vec2& operator=(const Vec3& in_Vec3);
    
    __VERTEX__TYPE__ length()const;
    __VERTEX__TYPE__ lengthSquared()const;
    __VERTEX__TYPE__ dot(const Vec2&)const;
    
    void normalize();
    
    void lerp(float, Vec2&);
//    Vec2 lerp(float, Vec2&);
    
    void zero()
    {(*this) = 0.f;}
};


class Vec3
{
public:
    __VERTEX__TYPE__ x;
    __VERTEX__TYPE__ y;
    __VERTEX__TYPE__ z;
    
    Vec3(){}
    Vec3(const __VERTEX__TYPE__& in_X,const __VERTEX__TYPE__& in_Y,const __VERTEX__TYPE__& in_Z)
    { 
        x = in_X; y = in_Y; z = in_Z;
    }
    
    Vec3(const __VERTEX__TYPE__& const_value)
    {
        x = const_value; y = const_value; z = const_value;
    }
    
    Vec3(const __VERTEX__TYPE__* pVector)
    {
        x = *pVector++;
        y = *pVector++;
        z = *pVector;
    }
    
    Vec3(const Vec2& in_V,const __VERTEX__TYPE__&  in_Scalar)
    {
        x = in_V.x;
        y = in_V.y;
        z = in_Scalar;
    }
    Vec3(const Vec2& in_V)
    {
        x = in_V.x;
        y = in_V.y;
		z = 0.0;
    }
    
    Vec3 operator+(const Vec3& in_Vector)const;
    Vec3 operator-(const Vec3& in_Vector)const;
    
    Vec3& operator+=(const Vec2& in_Vector);
    Vec3& operator-=(const Vec2& in_Vector);
    
    Vec3& operator+=(const Vec3& in_Vector);
    Vec3& operator-=(const Vec3& in_Vector);
    
    bool operator==(const Vec3& in_Vector);
    friend bool operator==(const Vec3& in_Vector1, const Vec3& in_Vector2) {
        Vec3 ret = in_Vector1 - in_Vector2;
        float threshold = 0.000001f;
        return fabs(ret.x) < threshold &&
        fabs(ret.y) < threshold &&
        fabs(ret.z) < threshold;
    }

    Vec3 operator+(const __VERTEX__TYPE__& in_Scalar)const;
    Vec3 operator-(const __VERTEX__TYPE__& in_Scalar)const;
    Vec3 operator*(const __VERTEX__TYPE__& in_Scalar)const;
    Vec3 operator/(const __VERTEX__TYPE__& in_Scalar)const;
    
    Vec3& operator+=(const __VERTEX__TYPE__& in_Scalar);
    Vec3& operator-=(const __VERTEX__TYPE__& in_Scalar);
    Vec3& operator*=(const __VERTEX__TYPE__& in_Scalar);
    Vec3& operator/=(const __VERTEX__TYPE__& in_Scalar);
    
	__VERTEX__TYPE__& operator[](int index);
	const __VERTEX__TYPE__& operator[](const int index) const;
    Vec3& operator=(const __VERTEX__TYPE__& in_Scalar);
    
    __VERTEX__TYPE__ length()const;
    __VERTEX__TYPE__ lengthSquared()const;
	__VERTEX__TYPE__ dot(const Vec3& in_V)const; 
	void normalize(); Vec3 cross(const Vec3& in_V)const;
    
    
    
	friend Vec3 operator*(const Vec3& in_V1, const Vec3& in_V2)
    {
        return Vec3(in_V1.x*in_V2.x,in_V1.y*in_V2.y, in_V1.z*in_V2.z);
    }
	Vec2 xy();
    void lerp(float, Vec3&);
    void cubic(float, Vec3&);
	void cos(float, Vec3&);
    
/*	Vec4 xyzw()
	{
		return Vec4(this->x, this->y, this->z, 1.0);
		}
	*/
    void zero()
    {(*this) = 0.f;}
    
};

//Vec3 operator*(const Vec3& in_V1, const Vec3& in_V2)
//{
//    return Vec3(in_V1.x*in_V2.x,in_V1.y*in_V2.y, in_V1.z*in_V2.z);
//}

class Vec4
{
public:
    __VERTEX__TYPE__ x;
    __VERTEX__TYPE__ y;
    __VERTEX__TYPE__ z;
    __VERTEX__TYPE__ w;
    
    Vec4(){}
    
    Vec4(const __VERTEX__TYPE__& in_X,const __VERTEX__TYPE__& in_Y,const __VERTEX__TYPE__& in_Z,const  __VERTEX__TYPE__& in_W)
    {
        x = in_X; y = in_Y; z = in_Z; w = in_W;
    }
    
    Vec4(const __VERTEX__TYPE__& in_XYZW)
    {
        x = in_XYZW; y = in_XYZW; z = in_XYZW; w = in_XYZW;
    }
    
    Vec4(const Vec3& in_V, const __VERTEX__TYPE__& s)
    {
        x = in_V.x; y = in_V.y; z = in_V.z; w = s;
    }
    
    Vec4(const Vec2& in_V, const __VERTEX__TYPE__& sz, const __VERTEX__TYPE__& sw)
    {
        x = in_V.x; y = in_V.y; z = sz; w = sw;
    }
    
    Vec4(const __VERTEX__TYPE__& s, const Vec3& in_V)
    {
        x = s, y = in_V.z, z = in_V.y; w = in_V.z;
    }
    
    Vec4(const __VERTEX__TYPE__* pVector)
    {
        x = *pVector++;
        y = *pVector++;
        z = *pVector++;
        w = *pVector;
    }
    
    Vec4 operator+(const Vec4& in_Vector)const;
    Vec4 operator-(const Vec4& in_Vector)const;
    
    Vec4& operator+=(const Vec4& in_Vector);
    Vec4& operator+=(const Vec3& in_Vector);
    Vec4& operator+=(const Vec2& in_Vector);
    
    Vec4& operator-=(const Vec4& in_Vector);
    Vec4& operator-=(const Vec3& in_Vector);
    Vec4& operator-=(const Vec2& in_Vector);
    
    Vec4 operator+(const __VERTEX__TYPE__& in_Scalar)const;
    Vec4 operator-(const __VERTEX__TYPE__& in_Scalar)const;
    Vec4 operator*(const __VERTEX__TYPE__& in_Scalar)const;
    Vec4 operator/(const __VERTEX__TYPE__& in_Scalar)const;
    
    Vec4& operator+=(const __VERTEX__TYPE__& in_Scalar);
    Vec4& operator-=(const __VERTEX__TYPE__& in_Scalar);
    Vec4& operator*=(const __VERTEX__TYPE__& in_Scalar);
    Vec4& operator/=(const __VERTEX__TYPE__& in_Scalar);
    
	__VERTEX__TYPE__& operator[](int index);
	const __VERTEX__TYPE__& operator[](const int index) const;

    Vec4& operator=(const __VERTEX__TYPE__& in_Scalar); // [] where ??? is it ?
    
    friend Vec4 operator*(const Vec4& in_V1, const Vec4& in_V2)
    {
        return Vec4(in_V1.x*in_V2.x,in_V1.y*in_V2.y, in_V1.z*in_V2.z,1.0);
    }
    __VERTEX__TYPE__ length()const;
    __VERTEX__TYPE__ lengthSquared()const;
    __VERTEX__TYPE__ dot(const Vec4&)const;
    void normalize();

//    Vec4 cross()const;

	Vec2 xy();
	Vec3 xyz();
    
    void lerp(float, Vec3&);
    void lerp(float, Vec4&);
    
    void zero()
    {(*this) = 0.f;}
};

void trackBall( Vec3& out_V, Vec2& in_V_Center_Touch,  float trackball_R);



Vec2 Normalize(Vec2 vec2);
Vec3 Normalize(Vec3 vec3);
Vec4 Normalize(Vec4 vec4);

#endif
