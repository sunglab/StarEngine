
#include "Vector.h"

Vec2 Vec2::operator+(const Vec2& in_Vector)const
{
	Vec2 out_Vector;
	out_Vector.x = x + in_Vector.x;
	out_Vector.y = y + in_Vector.y;
	return out_Vector;
}

Vec2 Vec2::operator-(const Vec2& in_Vector)const
{
	Vec2 out_Vector;
	out_Vector.x = x - in_Vector.x;
	out_Vector.y = y - in_Vector.y;
	return out_Vector;
}

Vec2 Vec2::operator+(const __VERTEX__TYPE__& in_Scalar)const
{
	Vec2 out_Vector;
	out_Vector.x = x + in_Scalar;
	out_Vector.y = y + in_Scalar;
	return out_Vector;
}

Vec2 Vec2::operator-(const __VERTEX__TYPE__& in_Scalar)const
{
	Vec2 out_Vector;
	out_Vector.x = x - in_Scalar;
	out_Vector.y = y - in_Scalar;
	return out_Vector;
}


Vec2 Vec2::operator*(const __VERTEX__TYPE__& in_Scalar)const
{
	Vec2 out_Vector;
	out_Vector.x = x * in_Scalar;
	out_Vector.y = y * in_Scalar;
	return out_Vector;
}

Vec2 Vec2::operator/(const __VERTEX__TYPE__& in_Scalar)const
{
	Vec2 out_Vector;
	out_Vector.x = x / in_Scalar;
	out_Vector.y = y / in_Scalar;
	return out_Vector;
}

Vec2& Vec2::operator+=(const Vec2& in_Vector)
{
	x += in_Vector.x;
	y += in_Vector.y;
	return *this;
}

Vec2& Vec2::operator-=(const Vec2& in_Vector)
{
	x -= in_Vector.x;
	y -= in_Vector.y;
	return *this;
}

Vec2& Vec2::operator+=(const __VERTEX__TYPE__& in_Scalar)
{
	x += in_Scalar;
	y += in_Scalar;
	return *this;
}

Vec2& Vec2::operator-=(const __VERTEX__TYPE__& in_Scalar)
{
	x -= in_Scalar;
	y -= in_Scalar;
	return *this;
}

Vec2& Vec2::operator*=(const __VERTEX__TYPE__& in_Scalar)
{

	x *= in_Scalar;
	y *= in_Scalar;
	return *this;
}

Vec2& Vec2::operator/=(const __VERTEX__TYPE__& in_Scalar)
{
	x /= in_Scalar;
	y /= in_Scalar;
	return *this;
}

Vec2& Vec2::operator[](int index)
{
    return (this)[index];
}

const Vec2& Vec2::operator[](int index) const
{
    return (this)[index];
}

Vec2& Vec2::operator=(const __VERTEX__TYPE__& in_Scalar)
{
    x = in_Scalar; y = in_Scalar;
    return (*this);
}

//FUNCs
__VERTEX__TYPE__ Vec2::length() const
{
 return sqrtf((x*x)+(y*y));
}

__VERTEX__TYPE__ Vec2::lengthSquared() const
{
	return (x*x)+(y*y);
}

__VERTEX__TYPE__ Vec2::dot(const Vec2& in_V) const
{
	return (x*in_V.x)+(y*in_V.y);
}

Vec2& Vec2::normalize() 
{
	return (*this) /= length();
}

//////////////////////////////////////////////
/////////////////VEC3/////////////////////////
//////////////////////////////////////////////
Vec3 Vec3::operator+(const Vec3& in_Vector)const
{
    Vec3 out_Vector;
    out_Vector.x = x + in_Vector.x;
    out_Vector.y = y + in_Vector.y;
    out_Vector.z = z + in_Vector.z;
	return out_Vector;
}

Vec3 Vec3::operator-(const Vec3& in_Vector)const
{
    Vec3 out_Vector;
    out_Vector.x = x - in_Vector.x;
    out_Vector.y = y - in_Vector.y;
    out_Vector.z = z - in_Vector.z;
	return out_Vector;
}

Vec3 Vec3::operator+(const __VERTEX__TYPE__& in_Scalar)const
{ 
    Vec3 out_Vector;
    out_Vector.x = x + in_Scalar;
    out_Vector.y = y + in_Scalar;
    out_Vector.z = z + in_Scalar;
	return out_Vector;
}

Vec3 Vec3::operator-(const __VERTEX__TYPE__& in_Scalar)const
{
    Vec3 out_Vector;
    out_Vector.x = x - in_Scalar;
    out_Vector.y = y - in_Scalar;
    out_Vector.z = z - in_Scalar;
	return out_Vector;
}

Vec3 Vec3::operator*(const __VERTEX__TYPE__& in_Scalar)const
{
    Vec3 out_Vector;
    out_Vector.x = x * in_Scalar;
    out_Vector.y = y * in_Scalar;
    out_Vector.z = z * in_Scalar;
	return out_Vector;
}

Vec3 Vec3::operator/(const __VERTEX__TYPE__& in_Scalar)const
{
    Vec3 out_Vector;
    out_Vector.x = x / in_Scalar;
    out_Vector.y = y / in_Scalar;
    out_Vector.z = z / in_Scalar;
	return out_Vector;
}

Vec3& Vec3::operator+=(const Vec3& in_Vector)
{ 
	x += in_Vector.x;
	y += in_Vector.y;
	z += in_Vector.z;
	return *this;
}

Vec3& Vec3::operator-=(const Vec3& in_Vector)
{
	x -= in_Vector.x;
	y -= in_Vector.y;
	z -= in_Vector.z;
	return *this;
}

Vec3& Vec3::operator+=(const __VERTEX__TYPE__& in_Scalar)
{ 
	x += in_Scalar;
	y += in_Scalar;
	z += in_Scalar;
	return *this;
}

Vec3& Vec3::operator-=(const __VERTEX__TYPE__& in_Scalar)
{
	x -= in_Scalar;
	y -= in_Scalar;
	z -= in_Scalar;
	return *this;
}

Vec3& Vec3::operator*=(const __VERTEX__TYPE__& in_Scalar)
{
	x *= in_Scalar;
	y *= in_Scalar;
	z *= in_Scalar;
	return *this;
}

Vec3& Vec3::operator/=(const __VERTEX__TYPE__& in_Scalar)
{
	x /= in_Scalar;
	y /= in_Scalar;
	z /= in_Scalar;
	return *this;
}

Vec3& Vec3::operator[](int index)
{
    return (this)[index];
}

Vec3& Vec3::operator=(const __VERTEX__TYPE__& in_Scalar)
{
    x = in_Scalar; y = in_Scalar; z = in_Scalar;
    return (*this);
}
const Vec3& Vec3::operator[](int index) const
{
    return (this)[index];
}

//FUNCs
__VERTEX__TYPE__ Vec3::length() const
{
 return sqrtf((x*x)+(y*y));
}

__VERTEX__TYPE__ Vec3::lengthSquared() const
{
	return (x*x)+(y*y);
} 

__VERTEX__TYPE__ Vec3::dot(const Vec3& in_V) const
{
	return (x*in_V.x)+(y*in_V.y)+(z*in_V.z);
}

Vec3& Vec3::normalize() 
{
	return (*this) /= length();
}

Vec3 Vec3::cross(const Vec3& in_V)const
{
	return Vec3(y * in_V.z - z * in_V.y, (z * in_V.x) - (x * in_V.z), x * in_V.y - y * in_V.x);
}
////////////////////////////////////////////
///////////////////VEC4/////////////////////
////////////////////////////////////////////
Vec4 Vec4::operator+(const Vec4& in_Vector)const
{
	Vec4 out_Vector;
	out_Vector.x = x + in_Vector.x;
	out_Vector.y = y+ in_Vector.y;
	out_Vector.z = z + in_Vector.z;
	out_Vector.w = w + in_Vector.w;
	return out_Vector;
}

Vec4 Vec4::operator-(const Vec4& in_Vector)const
{
	Vec4 out_Vector;
	out_Vector.x = x - in_Vector.x;
	out_Vector.y = y - in_Vector.y;
	out_Vector.z = z - in_Vector.z;
	out_Vector.w = w - in_Vector.w;
	return out_Vector;
}

Vec4 Vec4::operator+(const __VERTEX__TYPE__& in_Scalar)const
{ 
	Vec4 out_Vector;
	out_Vector.x = x + in_Scalar;
	out_Vector.y = y + in_Scalar;
	out_Vector.z = z + in_Scalar;
	out_Vector.w = w + in_Scalar;
	return out_Vector;
}

Vec4 Vec4::operator-(const __VERTEX__TYPE__& in_Scalar)const
{
	Vec4 out_Vector;
	out_Vector.x = x - in_Scalar;
	out_Vector.y = y - in_Scalar;
	out_Vector.z = z - in_Scalar;
	out_Vector.w = w - in_Scalar;
	return out_Vector;
}

Vec4 Vec4::operator*(const __VERTEX__TYPE__& in_Scalar)const
{
	Vec4 out_Vector;
	out_Vector.x = x * in_Scalar;
	out_Vector.y = y * in_Scalar;
	out_Vector.z = z * in_Scalar;
	out_Vector.w = w * in_Scalar;
	return out_Vector;
}

Vec4 Vec4::operator/(const __VERTEX__TYPE__& in_Scalar)const
{
	Vec4 out_Vector;
	out_Vector.x = x / in_Scalar;
	out_Vector.y = y / in_Scalar;
	out_Vector.z = z / in_Scalar;
	out_Vector.w = w / in_Scalar;
	return out_Vector;
}

Vec4& Vec4::operator+=(const Vec4& in_Vector)
{ 
	x += in_Vector.x;
	y += in_Vector.y;
	z += in_Vector.z;
	w += in_Vector.w;
	return *this;
}

Vec4& Vec4::operator-=(const Vec4& in_Vector)
{
	x -= in_Vector.x;
	y -= in_Vector.y;
	z -= in_Vector.z;
	w -= in_Vector.z;
	return *this;
}

Vec4& Vec4::operator+=(const __VERTEX__TYPE__& in_Scalar)
{ 
	x += in_Scalar;
	y += in_Scalar;
	z += in_Scalar;
	w += in_Scalar;
	return *this;
}

Vec4& Vec4::operator-=(const __VERTEX__TYPE__& in_Scalar)
{
	x -= in_Scalar;
	y -= in_Scalar;
	z -= in_Scalar;
	w -= in_Scalar;
	return *this;
}

Vec4& Vec4::operator*=(const __VERTEX__TYPE__& in_Scalar)
{
	x *= in_Scalar;
	y *= in_Scalar;
	z *= in_Scalar;
	w -= in_Scalar;
	return *this;
}

Vec4& Vec4::operator/=(const __VERTEX__TYPE__& in_Scalar)
{
	x /= in_Scalar;
	y /= in_Scalar;
	z /= in_Scalar;
	w /= in_Scalar;
	return *this;
}

Vec4& Vec4::operator=(const __VERTEX__TYPE__& in_Scalar)
{
    x = in_Scalar; y = in_Scalar; z = in_Scalar; w = in_Scalar;
    return (*this);
}

//FUNCs
__VERTEX__TYPE__ Vec4::length() const
{
 return sqrtf((x*x)+(y*y)+(z*z)+(w*w));
}
__VERTEX__TYPE__ Vec4::lengthSquared() const
{
	return (x*x)+(y*y)+(z*z)+(w*w);
} 
__VERTEX__TYPE__ Vec4::dot(const Vec4& in_V) const
{
	return (x*in_V.x)+(y*in_V.y)+(z*in_V.z)+(w*in_V.w);
}
Vec4& Vec4::normalize() 
{
	return (*this) /= length();
}
