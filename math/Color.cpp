#include "Color.h"

Color3 Color3::operator+(const Color3& in_Color)const
{
	Color3 out_Color;
	out_Color.r = r + in_Color.r;
	out_Color.g = g + in_Color.g;
	out_Color.b = b + in_Color.b;
	return (out_Color);
}
Color3 Color3::operator-(const Color3& in_Color)const
{
	Color3 out_Color;
	out_Color.r = r - in_Color.r;
	out_Color.g = g - in_Color.g;
	out_Color.b = b - in_Color.b;
	return (out_Color);
}
Color3 Color3::operator*(const Color3& in_Color)const
{
	Color3 out_Color;
	out_Color.r = r * in_Color.r;
	out_Color.g = g * in_Color.g;
	out_Color.b = b * in_Color.b;
	return (out_Color);
}
Color3 Color3::operator/(const Color3& in_Color)const
{
	Color3 out_Color;
	out_Color.r = r / in_Color.r;
	out_Color.g = g / in_Color.g;
	out_Color.b = b / in_Color.b;
	return (out_Color);
}

Color3 Color3::operator+(__COLOR__TYPE__ in_Float)const
{
	Color3 out_Color;
	out_Color.r = r + in_Float; 
	out_Color.g = g + in_Float;
	out_Color.b = b + in_Float;
	return (out_Color);
}
Color3 Color3::operator-(__COLOR__TYPE__ in_Float)const
{
	Color3 out_Color;
	out_Color.r = r - in_Float;
	out_Color.g = g - in_Float;
	out_Color.b = b - in_Float;
	return (out_Color);
}
Color3 Color3::operator*(__COLOR__TYPE__ in_Float)const
{
	Color3 out_Color;
	out_Color.r = r * in_Float;
	out_Color.g = g * in_Float;
	out_Color.b = b * in_Float;
	return (out_Color);
}
Color3 Color3::operator/(__COLOR__TYPE__ in_Float)const
{
	Color3 out_Color;
	out_Color.r = r / in_Float;
	out_Color.g = g / in_Float;
	out_Color.b = b / in_Float;
	return (out_Color);
}

void Color3::lerp(float t,Color3& newColor)
{
	(this->r) = (1.f-t)*(this->r) + newColor.r * t;
	(this->g) = (1.f-t)*(this->g) + newColor.g * t;
	(this->b) = (1.f-t)*(this->b) + newColor.b * t;
}



/* Color4 */
Color4 Color4::operator+(const Color4& in_Color)const
{
	Color4 out_Color;
	out_Color.r = r + in_Color.r;
	out_Color.g = g + in_Color.g;
	out_Color.b = b + in_Color.b;
	out_Color.a = a + in_Color.a;
	return (out_Color);
}

Color4 Color4::operator-(const Color4& in_Color)const
{
	Color4 out_Color;
	out_Color.r = r - in_Color.r;
	out_Color.g = g - in_Color.g;
	out_Color.b = b - in_Color.b;
	out_Color.a = a - in_Color.a;
	return (out_Color);
}
Color4 Color4::operator*(const Color4& in_Color)const
{
	Color4 out_Color;
	out_Color.r = r * in_Color.r;
	out_Color.g = g * in_Color.g;
	out_Color.b = b * in_Color.b;
	out_Color.a = a * in_Color.a;
	return (out_Color);
}
Color4 Color4::operator/(const Color4& in_Color)const
{
	Color4 out_Color;
	out_Color.r = r / in_Color.r;
	out_Color.g = g / in_Color.g;
	out_Color.b = b / in_Color.b;
	out_Color.a = a / in_Color.a;
	return (out_Color);
}

Color4 Color4::operator+(__COLOR__TYPE__ in_Float)const
{
	Color4 out_Color;
	out_Color.r = r + in_Float; 
	out_Color.g = g + in_Float;
	out_Color.b = b + in_Float;
	out_Color.a = a + in_Float;
	return (out_Color);
}
Color4 Color4::operator-(__COLOR__TYPE__ in_Float)const
{
	Color4 out_Color;
	out_Color.r = r - in_Float;
	out_Color.g = g - in_Float;
	out_Color.b = b - in_Float;
	out_Color.a = a - in_Float;
	return (out_Color);
}
Color4 Color4::operator*(__COLOR__TYPE__ in_Float)const
{
	Color4 out_Color;
	out_Color.r = r * in_Float;
	out_Color.g = g * in_Float;
	out_Color.b = b * in_Float;
	out_Color.a = a * in_Float;
	return (out_Color);
}
Color4 Color4::operator/(__COLOR__TYPE__ in_Float)const
{
	Color4 out_Color;
	out_Color.r = r / in_Float;
	out_Color.g = g / in_Float;
	out_Color.b = b / in_Float;
	out_Color.a = a / in_Float;
	return (out_Color);
}

void Color4::lerp(float t,Color4& newColor)
{
	(this->r) = (1.f-t)*(this->r) + newColor.r * t;
	(this->g) = (1.f-t)*(this->g) + newColor.g * t;
	(this->b) = (1.f-t)*(this->b) + newColor.b * t;
	(this->a) = (1.f-t)*(this->a) + newColor.a * t;
}

void Color4::lerp(float t,Color3& newColor)
{
	(this->r) = (1.f-t)*(this->r) + newColor.r * t;
	(this->g) = (1.f-t)*(this->g) + newColor.g * t;
	(this->b) = (1.f-t)*(this->b) + newColor.b * t;
}
