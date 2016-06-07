
#include "Vector.h"
//#include "StarTouch.h"
//#include "StarEngine.h"

Vec2 Normalize(Vec2 vec2)
{return vec2/vec2.length();}
Vec3 Normalize(Vec3 vec3)
{return vec3/vec3.length();}
Vec4 Normalize(Vec4 vec4)
{return vec4/vec4.length();}

/*
 *      Vec2
 */
Vec2 Vec2::operator+(const Vec2& in_Vec)const
{
	Vec2 out_Vector;
	out_Vector.x = x + in_Vec.x;
	out_Vector.y = y + in_Vec.y;
	return out_Vector;
}

Vec2 Vec2::operator-(const Vec2& in_Vec)const
{
	Vec2 out_Vector;
	out_Vector.x = x - in_Vec.x;
	out_Vector.y = y - in_Vec.y;
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

Vec2 Vec2::operator*(const Vec2& in_Vector)const
{
    Vec2 out_Vector;
    out_Vector.x = x * in_Vector.x;
    out_Vector.y = y * in_Vector.y;
    return out_Vector;
}


Vec2 Vec2::operator/(const __VERTEX__TYPE__& in_Scalar)const
{
	Vec2 out_Vector;
	out_Vector.x = x / in_Scalar;
	out_Vector.y = y / in_Scalar;
	return out_Vector;
}

Vec2& Vec2::operator+=(const Vec2& in_Vec)
{
	x += in_Vec.x;
	y += in_Vec.y;
	return *this;
}

Vec2& Vec2::operator-=(const Vec2& in_Vec)
{
	x -= in_Vec.x;
	y -= in_Vec.y;
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

__VERTEX__TYPE__& Vec2::operator[](int index)
{
	if(index==0)
    return (*this).x;
	else
    return (*this).y;
}

const __VERTEX__TYPE__& Vec2::operator[](int index) const
{
//    return (*this)[index];
	if(index==0)
    return (*this).x;
	else
    return (*this).y;

}

Vec2& Vec2::operator=(const __VERTEX__TYPE__& in_Scalar)
{
    x = in_Scalar; y = in_Scalar;
    return (*this);
}


__VERTEX__TYPE__ Vec2::length() const
{
 return sqrtf((x*x)+(y*y));
}

__VERTEX__TYPE__ Vec2::lengthSquared() const
{
	return (x*x)+(y*y);
}

__VERTEX__TYPE__ Vec2::dot(const Vec2& in_Vec) const
{
	return (x*in_Vec.x)+(y*in_Vec.y);
}

void Vec2::normalize()
{
	(*this) /= length();
}

void Vec2::lerp(float t, Vec2& in_Vec)
{
	this->x = (1.-t)*(this->x) + (t)*(in_Vec.x);
	this->y = (1.-t)*(this->y) + (t)*(in_Vec.y);
}
//Vec2 Vec2::lerp(float t, Vec2& in_Vec)
//{
//    return Vec2((1.-t)*(this->x) + (t)*(in_Vec.x), (1.-t)*(this->y) + (t)*(in_Vec.y));
//}

/*
 *      Vec3
 */
Vec3 Vec3::operator+(const Vec3& in_Vec)const
{
    Vec3 out_Vector;
    out_Vector.x = x + in_Vec.x;
    out_Vector.y = y + in_Vec.y;
    out_Vector.z = z + in_Vec.z;
	return out_Vector;
}

Vec3 Vec3::operator-(const Vec3& in_Vec)const
{
    Vec3 out_Vector;
    out_Vector.x = x - in_Vec.x;
    out_Vector.y = y - in_Vec.y;
    out_Vector.z = z - in_Vec.z;
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

Vec3& Vec3::operator+=(const Vec3& in_Vec)
{ 
	x += in_Vec.x;
	y += in_Vec.y;
	z += in_Vec.z;
	return *this;
}

Vec3& Vec3::operator-=(const Vec3& in_Vec)
{
	x -= in_Vec.x;
	y -= in_Vec.y;
	z -= in_Vec.z;
	return *this;
}
Vec3& Vec3::operator+=(const Vec2& in_Vec)
{
    x += in_Vec.x;
    y += in_Vec.y;
    return *this;
}

Vec3& Vec3::operator-=(const Vec2& in_Vec)
{
    x -= in_Vec.x;
    y -= in_Vec.y;
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

__VERTEX__TYPE__&  Vec3::operator[](int index)
{
//    return (this)[index];
	if (index == 0)
		return (*this).x;
	else if (index == 1)
		return (*this).y;
	else if (index == 2)
		return (*this).z;

}

const __VERTEX__TYPE__&  Vec3::operator[](int index) const
{
//    return (this)[index];
	if (index == 0)
		return (*this).x;
	else if (index == 1)
		return (*this).y;
	else if (index == 2)
		return (*this).z;
}
Vec3& Vec3::operator=(const __VERTEX__TYPE__& in_Scalar)
{
    x = in_Scalar; y = in_Scalar; z = in_Scalar;
    return (*this);
}


__VERTEX__TYPE__ Vec3::length() const
{
 return sqrtf((x*x)+(y*y)+(z*z));
}

__VERTEX__TYPE__ Vec3::lengthSquared() const
{
	return (x*x)+(y*y)+(z*z);
} 

__VERTEX__TYPE__ Vec3::dot(const Vec3& in_Vec) const
{
	return (x*in_Vec.x)+(y*in_Vec.y)+(z*in_Vec.z);
}

void Vec3::normalize()
{
    (*this) /= length();
}

Vec3 Vec3::cross(const Vec3& in_Vec)const
{
	return Vec3((y * in_Vec.z - z * in_Vec.y), (z * in_Vec.x - x * in_Vec.z), (x * in_Vec.y - y * in_Vec.x));
}

void Vec3::lerp(float t, Vec3& in_Vec)
{
	this->x = (1.-t)*(this->x) + (t)*(in_Vec.x);
	this->y = (1.-t)*(this->y) + (t)*(in_Vec.y);
	this->z = (1.-t)*(this->z) + (t)*(in_Vec.z);
}

/*
 *      Vec4
 */
Vec4 Vec4::operator+(const Vec4& in_Vec)const
{
	Vec4 out_Vector;
	out_Vector.x = x + in_Vec.x;
	out_Vector.y = y + in_Vec.y;
	out_Vector.z = z + in_Vec.z;
	out_Vector.w = w + in_Vec.w;
	return out_Vector;
}

Vec4 Vec4::operator-(const Vec4& in_Vec)const
{
	Vec4 out_Vector;
	out_Vector.x = x - in_Vec.x;
	out_Vector.y = y - in_Vec.y;
	out_Vector.z = z - in_Vec.z;
	out_Vector.w = w - in_Vec.w;
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

Vec4& Vec4::operator+=(const Vec2& in_Vec)
{
    x += in_Vec.x;
    y += in_Vec.y;
    return *this;
}

Vec4& Vec4::operator+=(const Vec3& in_Vec)
{
    x += in_Vec.x;
    y += in_Vec.y;
    z += in_Vec.z;
    return *this;
}

Vec4& Vec4::operator+=(const Vec4& in_Vec)
{ 
	x += in_Vec.x;
	y += in_Vec.y;
	z += in_Vec.z;
	w += in_Vec.w;
	return *this;
}

Vec4& Vec4::operator-=(const Vec2& in_Vec)
{
    x -= in_Vec.x;
    y -= in_Vec.y;
    return *this;
}

Vec4& Vec4::operator-=(const Vec3& in_Vec)
{
    x -= in_Vec.x;
    y -= in_Vec.y;
    z -= in_Vec.z;
    return *this;
}

Vec4& Vec4::operator-=(const Vec4& in_Vec)
{
	x -= in_Vec.x;
	y -= in_Vec.y;
	z -= in_Vec.z;
	w -= in_Vec.w;
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

__VERTEX__TYPE__& Vec4::operator[](int index)
{
//    return (this)[index];
	if (index == 0)
		return (*this).x;
	else if (index == 1)
		return (*this).y;
	else if (index == 2)
		return (*this).z;
	else if (index == 3)
		return (*this).w;


}

const __VERTEX__TYPE__& Vec4::operator[](int index) const
{
//    return (this)[index];
	if (index == 0)
		return (*this).x;
	else if (index == 1)
		return (*this).y;
	else if (index == 2)
		return (*this).z;
	else if (index == 3)
		return (*this).w;
}

Vec4& Vec4::operator=(const __VERTEX__TYPE__& in_Scalar)
{
    x = in_Scalar; y = in_Scalar; z = in_Scalar; w = in_Scalar;
    return (*this);
}

__VERTEX__TYPE__ Vec4::length() const
{
 return sqrtf((x*x)+(y*y)+(z*z)+(w*w));
}

__VERTEX__TYPE__ Vec4::lengthSquared() const
{
	return (x*x)+(y*y)+(z*z)+(w*w);
}

__VERTEX__TYPE__ Vec4::dot(const Vec4& in_Vec) const
{
	return (x*in_Vec.x)+(y*in_Vec.y)+(z*in_Vec.z)+(w*in_Vec.w);
}

void Vec4::normalize()
{
	(*this) /= length();
}

void Vec4::lerp(float t, Vec3& in_Vec)
{
	this->x = (1.-t)*(this->x) + (t)*(in_Vec.x);
	this->y = (1.-t)*(this->y) + (t)*(in_Vec.y);
	this->z = (1.-t)*(this->z) + (t)*(in_Vec.z);
}

void Vec4::lerp(float t, Vec4& in_Vec)
{
	this->x = (1.-t)*(this->x) + (t)*(in_Vec.x);
	this->y = (1.-t)*(this->y) + (t)*(in_Vec.y);
	this->z = (1.-t)*(this->z) + (t)*(in_Vec.z);
	this->w = (1.-t)*(this->w) + (t)*(in_Vec.w);
}


/*
 *      Support
 */

void trackBall( Vec3& out_V, Vec2& in_V_Center_Touch,  float trackball_R)
{
    Vec2 point = in_V_Center_Touch;
//    point.y = -point.y;
    
    const float radius = trackball_R;
    const float safeRadius = radius - 1.f; // to avoid z = non;
//    const float safeRadius = radius;
    
    if (point.length() > safeRadius)
    {
        float angle = atan2(point.y, point.x);
        point.x = safeRadius * cos(angle);
        point.y = safeRadius * sin(angle);
    }
    
    float z = sqrt(radius*radius - point.lengthSquared()); // may be not correct
//    printf("x y z = %f,  %f %f %f\n",,point.x/radius, point.y/radius, z/radius);
//    float z = radius - point.length();
    out_V = Vec3(point.x, point.y, z) / radius; //normalize
//    out_V = Vec3(point.x, point.y, z);
//    printf("x y z = %f, %f %f %f\n",out_V.length(),point.x/radius, point.y/radius, z/radius);
}

//void trackBall_Power(StarTouch* startouch,
//                     Star* star,
//                     Vec3& touch_start3D_out,
//                     Vec3& touch_end3D_out,
//                     
//                     Vec2& vec_center_to_start,
//                     Vec2& vec_center_to_end,
//                     Vec2& vec_center_power_out,
//                     
//                     Vec2* savedTouchPos,
//                     
//                     float& sideOfRect,
//                     Vec2& centerOfRect,
//                     
//                     float& scale,
//                     float& old_scale)
//{
//    
//
//    
//    if(savedTouchPos[1].length()==0.0)
//    {
//        old_scale = scale;
//        prev_Quat = now_Quat; // change the value that was used at the last cycle
//        savedTouchPos= startouch->nowPos[0];
//        temp2= startouch->nowPos[1];
//        //            NSLog(@"gg");
//    }
//    
//    int num = startouch->fingers;
//    if (num)
//    {
//       // must be used based on num
//    }
//    
//    scale = old_scale * (float)(startouch->nowPos[1]-startouch->nowPos[0]).length()/(float)((savedTouchPos[0]-savedTouchPos[1]).length());
//    vec_center_to_start = (startouch->prePos[0]+startouch->prePos[1])*0.5 - centerOfRect;//from center
//    vec_center_to_end = (startouch->nowPos[0]+startouch->nowPos[1])*0.5- centerOfRect;
//    
//    trackBall(touch_start3D_out, vec_center_to_start,sideOfRect);
//    trackBall(touch_end3D_out, vec_center_to_end, sideOfRect);//
//    vec_center_power_out += (vec_center_to_end - vec_center_to_start)*1.5;//long += okay???
//}
