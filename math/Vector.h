
#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include "../star.h"
#include <stdio.h>
// Floating-point Operations
//#define __VERTEX__TYPE___MUL(a,b)		(	(VERTEX_TYPE)(	(a)*(b)	)	)
//#define __VERTEX__TYPE___DIV(a,b)		(	(VERTEX_TYPE)(	(a)/(b)	)	)
//#define __VERTEX__TYPE___ABS(a)			(	(VERTEX_TYPE)(	fabs(a)		)
//template <typename T>
//
class Vec2
{
	public: 

		__VERTEX__TYPE__ x;
		__VERTEX__TYPE__ y;

		Vec2(){}
		Vec2(const __VERTEX__TYPE__ in_X,const __VERTEX__TYPE__ in_Y)
		{
			x = in_X;
			y = in_Y;
		}
		Vec2(const __VERTEX__TYPE__ in_XY)
		{
			x = in_XY;
			y = in_XY;
		}

		Vec2(const Vec2& in_Vector)
		{
			x = in_Vector.x;
			y = in_Vector.y;
		}

		Vec2 operator+(const Vec2& in_Vector)const;
		Vec2 operator-(const Vec2& in_Vector)const;
		Vec2 operator*(const Vec2& in_Vector)const;
		Vec2 operator/(const Vec2& in_Vector)const;

		Vec2 operator+(const __VERTEX__TYPE__& in_Scalar)const;
		Vec2 operator-(const __VERTEX__TYPE__& in_Scalar)const;
		Vec2 operator*(const __VERTEX__TYPE__& in_Scalar)const;
		Vec2 operator/(const __VERTEX__TYPE__& in_Scalar)const;

		Vec2& operator+=(const Vec2& in_Vector);
		Vec2& operator-=(const Vec2& in_Vector);
		Vec2& operator*=(const Vec2& in_Vector);
		Vec2& operator/=(const Vec2& in_Vector);

		Vec2& operator+=(const __VERTEX__TYPE__& in_Scalar);
		Vec2& operator-=(const __VERTEX__TYPE__& in_Scalar);
		Vec2& operator*=(const __VERTEX__TYPE__& in_Scalar);
		Vec2& operator/=(const __VERTEX__TYPE__& in_Scalar);

		Vec2& operator[](const int index);
		const Vec2& operator[](const int index) const;
		Vec2& operator=(const __VERTEX__TYPE__& in_Scalar);

		void zero()
		{
			(*this) = 0.f;
		}
		//    __VERTEX__TYPE__ distanceSqrt() const;
		//		__VERTEX__TYPE__ distance() const;
		//		Vec2& normalize();
		//		__VERTEX__TYPE__ dot(const Vec2& in_Vector);
};

class Vec3
{
	public:

		__VERTEX__TYPE__ x;
		__VERTEX__TYPE__ y;
		__VERTEX__TYPE__ z;

		Vec3(){}

		Vec3(__VERTEX__TYPE__ in_X, __VERTEX__TYPE__ in_Y, __VERTEX__TYPE__ in_Z)
		{ 
			x = in_X; y = in_Y; z = in_Z;
		}

		Vec3(const __VERTEX__TYPE__ const_value)
		{
			x = const_value; y = const_value; z = const_value;
		}

		Vec3(const __VERTEX__TYPE__* pVector)
		{
			x = *pVector++;
			y = *pVector++;
			z = *pVector;
		}

		Vec3 operator+(const Vec3& in_Vector)const;
		Vec3 operator-(const Vec3& in_Vector)const;
		Vec3 operator*(const Vec3& in_Vector)const;
		Vec3 operator/(const Vec3& in_Vector)const;

		Vec3 operator+(const __VERTEX__TYPE__& in_Scalar)const;
		Vec3 operator-(const __VERTEX__TYPE__& in_Scalar)const;
		Vec3 operator*(const __VERTEX__TYPE__& in_Scalar)const;
		Vec3 operator/(const __VERTEX__TYPE__& in_Scalar)const;

		Vec3& operator+=(const Vec3& in_Vector);
		Vec3& operator-=(const Vec3& in_Vector);
		Vec3& operator*=(const Vec3& in_Vector);
		Vec3& operator/=(const Vec3& in_Vector);

		Vec3& operator+=(const __VERTEX__TYPE__& in_Scalar);
		Vec3& operator-=(const __VERTEX__TYPE__& in_Scalar);
		Vec3& operator*=(const __VERTEX__TYPE__& in_Scalar);
		Vec3& operator/=(const __VERTEX__TYPE__& in_Scalar);

		Vec3& operator[](const int index);
		const Vec3& operator[](const int index) const;
		Vec3& operator=(const __VERTEX__TYPE__& in_Scalar);
    
		void zero()
		{(*this) = 0.f;}

};

class Vec4
{
	public:
		__VERTEX__TYPE__ x;
		__VERTEX__TYPE__ y;
		__VERTEX__TYPE__ z;
		__VERTEX__TYPE__ w;

		Vec4(){}

		Vec4(const __VERTEX__TYPE__ in_X,const  __VERTEX__TYPE__ in_Y,const __VERTEX__TYPE__ in_Z,const  __VERTEX__TYPE__ in_W)
		{
			x = in_X; y = in_Y; z = in_Z; w = in_W;
		}

		Vec4(const __VERTEX__TYPE__ in_XYZW)
		{
			x = in_XYZW; y = in_XYZW; z = in_XYZW; w = in_XYZW;
		}

		Vec4(const Vec3& in_V, const __VERTEX__TYPE__ s)
		{
			x= in_V.x; y = in_V.y; z = in_V.z; w = s;
		}

		Vec4(const __VERTEX__TYPE__ s, const Vec3& in_V)
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
		Vec4 operator*(const Vec4& in_Vector)const;
		Vec4 operator/(const Vec4& in_Vector)const;

		Vec4 operator+(const __VERTEX__TYPE__& in_Scalar)const;
		Vec4 operator-(const __VERTEX__TYPE__& in_Scalar)const;
		Vec4 operator*(const __VERTEX__TYPE__& in_Scalar)const;
		Vec4 operator/(const __VERTEX__TYPE__& in_Scalar)const;

		Vec4& operator+=(const Vec4& in_Vector);
		Vec4& operator-=(const Vec4& in_Vector);
		Vec4& operator*=(const Vec4& in_Vector);
		Vec4& operator/=(const Vec4& in_Vector);

		Vec4& operator+=(const __VERTEX__TYPE__& in_Scalar);
		Vec4& operator-=(const __VERTEX__TYPE__& in_Scalar);
		Vec4& operator*=(const __VERTEX__TYPE__& in_Scalar);
		Vec4& operator/=(const __VERTEX__TYPE__& in_Scalar);

		Vec4& operator=(const __VERTEX__TYPE__& in_Scalar);

		void zero()
		{
			(*this) = 0.f;
		}
};

#endif
