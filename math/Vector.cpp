
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

Vec2 Vec2::operator*(const Vec2& in_Vector)const
{	
	Vec2 out_Vector;
	out_Vector.x = x * in_Vector.x;
	out_Vector.y = y * in_Vector.y;
	return out_Vector;
}

Vec2 Vec2::operator/(const Vec2& in_Vector)const
{	
	Vec2 out_Vector;
	out_Vector.x = x / in_Vector.x;
	out_Vector.y = y / in_Vector.y;
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

Vec2& Vec2::operator*=(const Vec2& in_Vector)
{
	x *= in_Vector.x;
	y *= in_Vector.y;
	return *this;
}

Vec2& Vec2::operator/=(const Vec2& in_Vector)
{
	x /= in_Vector.x;
	y /= in_Vector.y;
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
//    assert((index>=0)&&(index<=1));
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
//__VERTEX__TYPE__ Vec2::distanceSqrt() const
//{
//	return (x*x) + (y*y);
//}
//
//__VERTEX__TYPE__ Vec2::distance() const
//{
////	return (sqrt (x*x + y*y) );
//}
//
//Vec2& Vec2::normalize()
//{
//	return (*this) /= distance(); // x/dis y/dis ??
//}
//
//__VERTEX__TYPE__ Vec2::dot(const Vec2& in_Vector)//RHS
//{
//	return (x * in_Vector.x) + (y * in_Vector.x);
//}

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

Vec3 Vec3::operator*(const Vec3& in_Vector)const
{
    Vec3 out_Vector;
    out_Vector.x = x * in_Vector.x;
    out_Vector.y = y * in_Vector.y;
    out_Vector.z = z * in_Vector.z;
	return out_Vector;
}

Vec3 Vec3::operator/(const Vec3& in_Vector)const
{
    Vec3 out_Vector;
    out_Vector.x = x / in_Vector.x;
    out_Vector.y = y / in_Vector.y;
    out_Vector.z = z / in_Vector.z;
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

Vec3& Vec3::operator*=(const Vec3& in_Vector)
{
	x *= in_Vector.x;
	y *= in_Vector.y;
	z *= in_Vector.z;
	return *this;
}

Vec3& Vec3::operator/=(const Vec3& in_Vector)
{
	x /= in_Vector.x;
	y /= in_Vector.y;
	z /= in_Vector.z;
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
//    assert((index>=0)&&(index<=1));
    return (this)[index];
}

Vec3& Vec3::operator=(const __VERTEX__TYPE__& in_Scalar)
{
    x = in_Scalar; y = in_Scalar; z = in_Scalar;
    return (*this);
}
const Vec3& Vec3::operator[](int index) const
{
//       assert((index>=0)&&(index<=1));
    return (this)[index];
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

Vec4 Vec4::operator*(const Vec4& in_Vector)const
{
  Vec4 out_Vector;
	out_Vector.x = x * in_Vector.x;
	out_Vector.y = y * in_Vector.y;
	out_Vector.z = z * in_Vector.z;
	out_Vector.w = w * in_Vector.w;
	return out_Vector;
}

Vec4 Vec4::operator/(const Vec4& in_Vector)const
{
	Vec4 out_Vector;
	out_Vector.x = x / in_Vector.x;
	out_Vector.y = y / in_Vector.y;
	out_Vector.z = w / in_Vector.z;
	out_Vector.w = z / in_Vector.w;
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

Vec4& Vec4::operator*=(const Vec4& in_Vector)
{
	x *= in_Vector.x;
	y *= in_Vector.y;
	z *= in_Vector.z;
	w *= in_Vector.w;
	return *this;
}

Vec4& Vec4::operator/=(const Vec4& in_Vector)
{
	x /= in_Vector.x;
	y /= in_Vector.y;
	z /= in_Vector.z;
	w /= in_Vector.w;
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
