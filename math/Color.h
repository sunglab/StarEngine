#ifndef COLOR_H
#define COLOR_H
#include "../star.h"

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

		Color3 operator+(const Color3& in_Color)const;
		Color3 operator-(const Color3& in_Color)const;
		Color3 operator*(const Color3& in_Color)const;
		Color3 operator/(const Color3& in_Color)const;

		Color3 operator+(__COLOR__TYPE__ in_Float)const;
		Color3 operator-(__COLOR__TYPE__ in_Float)const;
		Color3 operator*(__COLOR__TYPE__ in_Float)const;
		Color3 operator/(__COLOR__TYPE__ in_Float)const;

		void lerp(float, Color3&);
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

		Color4 operator+(const Color4& inColor)const;
		Color4 operator-(const Color4& inColor)const;
		Color4 operator*(const Color4& inColor)const;
		Color4 operator/(const Color4& inColor)const;

		Color4 operator+(__COLOR__TYPE__ in_Float)const;
		Color4 operator-(__COLOR__TYPE__ in_Float)const;
		Color4 operator*(__COLOR__TYPE__ in_Float)const;
		Color4 operator/(__COLOR__TYPE__ in_Float)const;

		void lerp(float, Color4&);
		void lerp(float, Color3&);
};


#endif
