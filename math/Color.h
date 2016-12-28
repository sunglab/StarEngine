//
//  Color.h
//
//  Created by sungwoo choi on 8/22/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef COLOR_H
#define COLOR_H
#include "../star.h"
#include "../tool/StarUtil.h"
#include <time.h>
#include <stdlib.h>

class HSV
{
public:
    __COLOR__TYPE__ h;
    __COLOR__TYPE__ s;
    __COLOR__TYPE__ v;
    HSV(__COLOR__TYPE__ _h, __COLOR__TYPE__ _s, __COLOR__TYPE__ _v)
    {
        h = _h;
        s = _s;
        v = _v;
    }
};
//typedef struct
//{
//	double r;
//	double g;
//	double b;
//} RGB;

class Color3
{
public:
    __COLOR__TYPE__ r;
    __COLOR__TYPE__ g;
    __COLOR__TYPE__ b;
    
    Color3()
    {
        r = 0.f;
        g = 0.f;
        b = 0.f;
    }
    
    Color3(__COLOR__TYPE__ rgb)
    {
        r = rgb;
        g = rgb;
        b = rgb;
    }
    
    Color3(const __COLOR__TYPE__ _r,const __COLOR__TYPE__ _g,const __COLOR__TYPE__ _b)
    {
        r = _r;
        g = _g;
        b = _b;
    }
    
    Color3(const Color3& newColor)
    {
        r = newColor.r;
        g = newColor.g;
        b = newColor.b;
    }
    Color3(const __COLOR__TYPE__* pColor)
    {
        r = *pColor++;
        g = *pColor++;
        b = *pColor++;
    }
    
    Color3 operator+(const Color3& in_Color)const;
    Color3 operator-(const Color3& in_Color)const;
    void operator+=(const Color3& in_Color);
    void operator-=(const Color3& in_Color);
    
    Color3 operator+(__COLOR__TYPE__ in_Scalar)const;
    Color3 operator-(__COLOR__TYPE__ in_Scalar)const;
    Color3 operator*(__COLOR__TYPE__ in_Scalar)const;
    Color3 operator/(__COLOR__TYPE__ in_Scalar)const;
    
    void operator+=(__COLOR__TYPE__ in_Scalar);
    void operator-=(__COLOR__TYPE__ in_Scalar);
    void operator*=(__COLOR__TYPE__ in_Scalar);
    void operator/=(__COLOR__TYPE__ in_Scalar);
    
    const Color3& operator[](int index)const;
    Color3& operator[](int index);
    Color3& operator=(const __COLOR__TYPE__& in_Scalar);
    
    void zero()
    {
        (*this) = (float)0.0f;
    }
    void lerp(float, Color3&);
    void genColor();
    void setHSV(HSV in);
    
};

class Color4
{
public:
    __COLOR__TYPE__ r;
    __COLOR__TYPE__ g;
    __COLOR__TYPE__ b;
    __COLOR__TYPE__ a;
    
    Color4()
    {
        r = 0.f;
        g = 0.f;
        b = 0.f;
        a = 0.f;
    }
    
    Color4(float rgb)
    {
        r = rgb;
        g = rgb;
        b = rgb;
        a = rgb;
        
    }
    Color4(const __COLOR__TYPE__ _r,const __COLOR__TYPE__ _g,const __COLOR__TYPE__ _b,const __COLOR__TYPE__ _a)
    {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    }
    
    Color4(const Color4& newColor)
    {
        r = newColor.r;
        g = newColor.g;
        b = newColor.b;
        a = newColor.a;
    }
    Color4(const Color3& newColor, float alpha)
    {
        r = newColor.r;
        g = newColor.g;
        b = newColor.b;
        a = alpha;
    }
    
    Color4 operator+(const Color4& inColor)const;
    Color4 operator-(const Color4& inColor)const;
    void operator+=(const Color4& inColor);
    void operator-=(const Color4& inColor);
    
    Color4 operator+(__COLOR__TYPE__ in_Scalar)const;
    Color4 operator-(__COLOR__TYPE__ in_Scalar)const;
    Color4 operator*(__COLOR__TYPE__ in_Scalar)const;
    Color4 operator/(__COLOR__TYPE__ in_Scalar)const;
    
    void operator+=(__COLOR__TYPE__ in_Scalar);
    void operator-=(__COLOR__TYPE__ in_Scalar);
    void operator*=(__COLOR__TYPE__ in_Scalar);
    void operator/=(__COLOR__TYPE__ in_Scalar);
    
    const Color4& operator[](int index)const;
    Color4& operator[](int index);
    Color4& operator=(const __COLOR__TYPE__& in_Scalar);
    
    Color3 rgb()
    {
        return Color3(r,g,b);
    }
    void zero()
    {
        (*this) = 0;
    }
    void lerp(float, Color4&);
    void lerp(float, Color3&);
    void genColor();
    void setHSV(HSV in);
};


#endif
