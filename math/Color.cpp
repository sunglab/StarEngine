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

Color3 Color3::operator+(__COLOR__TYPE__ in_Scalar)const
{
	Color3 out_Color;
	out_Color.r = r + in_Scalar; 
	out_Color.g = g + in_Scalar;
	out_Color.b = b + in_Scalar;
	return (out_Color);
}
Color3 Color3::operator-(__COLOR__TYPE__ in_Scalar)const
{
	Color3 out_Color;
	out_Color.r = r - in_Scalar;
	out_Color.g = g - in_Scalar;
	out_Color.b = b - in_Scalar;
	return (out_Color);
}
Color3 Color3::operator*(__COLOR__TYPE__ in_Scalar)const
{
	Color3 out_Color;
	out_Color.r = r * in_Scalar;
	out_Color.g = g * in_Scalar;
	out_Color.b = b * in_Scalar;
	return (out_Color);
}
Color3 Color3::operator/(__COLOR__TYPE__ in_Scalar)const
{
	Color3 out_Color;
	out_Color.r = r / in_Scalar;
	out_Color.g = g / in_Scalar;
	out_Color.b = b / in_Scalar;
	return (out_Color);
}

void Color3::operator+=(const Color3& in_Color)
{
	r += in_Color.r;
	g += in_Color.g;
	b += in_Color.b;
}
void Color3::operator-=(const Color3& in_Color)
{
	r -= in_Color.r;
	g -= in_Color.g;
	b -= in_Color.b;
}

void Color3::operator+=(__COLOR__TYPE__ in_Scalar)
{
	r += in_Scalar;
	g += in_Scalar;
	b += in_Scalar;
}

void Color3::operator-=(__COLOR__TYPE__ in_Scalar)
{
	r -= in_Scalar;
	g -= in_Scalar;
	b -= in_Scalar;
}

void Color3::operator*=(__COLOR__TYPE__ in_Scalar)
{
	r *= in_Scalar;
	g *= in_Scalar;
	b *= in_Scalar;
}

void Color3::operator/=(__COLOR__TYPE__ in_Scalar)
{
	r /= in_Scalar;
	g /= in_Scalar;
	b /= in_Scalar;
}

Color3& Color3::operator=(const __COLOR__TYPE__& in_Scalar)
{
	r = in_Scalar;
	g = in_Scalar;
	b = in_Scalar;
	return (*this);
}

const Color3& Color3::operator[](int index)const
{
	return (this)[index];
}

Color3& Color3::operator[](int index)
{
	return (this)[index];
}

void Color3::lerp(float t,Color3& newColor)
{
	(this->r) = (1.f-t)*(this->r) + newColor.r * t;
	(this->g) = (1.f-t)*(this->g) + newColor.g * t;
	(this->b) = (1.f-t)*(this->b) + newColor.b * t;
}

void Color3::genColor()
{
	srand((unsigned)time(NULL));
	this->r = rand()%100*0.01;
	this->g = rand()%100*0.01;
	this->b = rand()%100*0.01;
}

void Color3::setHSV(HSV in)
    {
        double      hh, p, q, t, ff;
        long        i;
        Color3         out;
        
        if(in.s <= 0.0) {       // < is bogus, just shuts up warnings
            out.r = in.v;
            out.g = in.v;
            out.b = in.v;
            *this =  out;
        }
        hh = in.h;
        if(hh >= 360.0) hh = 0.0;
        hh /= 60.0;
        i = (long)hh;
        ff = hh - i;
        p = in.v * (1.0 - in.s);
        q = in.v * (1.0 - (in.s * ff));
        t = in.v * (1.0 - (in.s * (1.0 - ff)));
        
        switch(i) {
            case 0:
                out.r = in.v;
                out.g = t;
                out.b = p;
                break;
            case 1:
                out.r = q;
                out.g = in.v;
                out.b = p;
                break;
            case 2:
                out.r = p;
                out.g = in.v;
                out.b = t;
                break;
                
            case 3:
                out.r = p;
                out.g = q;
                out.b = in.v;
                break;
            case 4:
                out.r = t;
                out.g = p;
                out.b = in.v;
                break;
            case 5:
            default:
                out.r = in.v;
                out.g = p;
                out.b = q;
                break;
        }
        *this = out;
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

Color4 Color4::operator+(__COLOR__TYPE__ in_Scalar)const
{
	Color4 out_Color;
	out_Color.r = r + in_Scalar; 
	out_Color.g = g + in_Scalar;
	out_Color.b = b + in_Scalar;
	out_Color.a = a + in_Scalar;
	return (out_Color);
}
Color4 Color4::operator-(__COLOR__TYPE__ in_Scalar)const
{
	Color4 out_Color;
	out_Color.r = r - in_Scalar;
	out_Color.g = g - in_Scalar;
	out_Color.b = b - in_Scalar;
	out_Color.a = a - in_Scalar;
	return (out_Color);
}
Color4 Color4::operator*(__COLOR__TYPE__ in_Scalar)const
{
	Color4 out_Color;
	out_Color.r = r * in_Scalar;
	out_Color.g = g * in_Scalar;
	out_Color.b = b * in_Scalar;
	out_Color.a = a * in_Scalar;
	return (out_Color);
}
Color4 Color4::operator/(__COLOR__TYPE__ in_Scalar)const
{
	Color4 out_Color;
	out_Color.r = r / in_Scalar;
	out_Color.g = g / in_Scalar;
	out_Color.b = b / in_Scalar;
	out_Color.a = a / in_Scalar;
	return (out_Color);
}

void Color4::operator+=(const Color4& in_Color)
{
	r += in_Color.r;
	g += in_Color.g;
	b += in_Color.b;
	a += in_Color.a;
}
void Color4::operator-=(const Color4& in_Color)
{
	r -= in_Color.r;
	g -= in_Color.g;
	b -= in_Color.b;
	a -= in_Color.a;
}

void Color4::operator+=(__COLOR__TYPE__ in_Scalar)
{
	r += in_Scalar;
	g += in_Scalar;
	b += in_Scalar;
	//a += in_Scalar;
}

void Color4::operator-=(__COLOR__TYPE__ in_Scalar)
{
	r -= in_Scalar;
	g -= in_Scalar;
	b -= in_Scalar;
	//a -= in_Scalar;
}

void Color4::operator*=(__COLOR__TYPE__ in_Scalar)
{
	r *= in_Scalar;
	g *= in_Scalar;
	b *= in_Scalar;
	//a *= in_Scalar;
}

void Color4::operator/=(__COLOR__TYPE__ in_Scalar)
{
	r /= in_Scalar;
	g /= in_Scalar;
	b /= in_Scalar;
	//a /= in_Scalar;
}
Color4& Color4::operator=(const __COLOR__TYPE__& in_Scalar)
{
	r = in_Scalar;
	g = in_Scalar;
	b = in_Scalar;
	a = in_Scalar;
	return (*this);	
}
const Color4& Color4::operator[](int index)const
{
	return (this)[index];
}
Color4& Color4::operator[](int index)
{
	return (this)[index];
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
void Color4::genColor()
{
    srand((unsigned)time(NULL));
	this->r = rand()%100*0.01;
	this->g = rand()%100*0.01;
	this->b = rand()%100*0.01;
    this->a = 1.0f;
}

void Color4::setHSV(HSV in)
{
    double      hh, p, q, t, ff;
    long        i;
    Color4         out;
    out.a = 1.0;
    if(in.s <= 0.0) {       // < is bogus, just shuts up warnings
        out.r = in.v;
        out.g = in.v;
        out.b = in.v;
        *this =  out;
    }
    hh = in.h;
    if(hh >= 360.0) hh = 0.0;
    hh /= 60.0;
    i = (long)hh;
    ff = hh - i;
    p = in.v * (1.0 - in.s);
    q = in.v * (1.0 - (in.s * ff));
    t = in.v * (1.0 - (in.s * (1.0 - ff)));
    
    switch(i) {
        case 0:
            out.r = in.v;
            out.g = t;
            out.b = p;
            break;
        case 1:
            out.r = q;
            out.g = in.v;
            out.b = p;
            break;
        case 2:
            out.r = p;
            out.g = in.v;
            out.b = t;
            break;
            
        case 3:
            out.r = p;
            out.g = q;
            out.b = in.v;
            break;
        case 4:
            out.r = t;
            out.g = p;
            out.b = in.v;
            break;
        case 5:
        default:
            out.r = in.v;
            out.g = p;
            out.b = q;
            break;
    }
    *this = out;
    }