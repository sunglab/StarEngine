#include "Matrix.h"
#include <stdio.h>
#include <math.h>
#include "../StarMain.h"


Matrix Matrix::operator*(const Matrix& in_M)const
{
	Matrix out_M;
	Matrix_MxM(out_M,*this,in_M);
	return out_M;
}

Vec4 operator*(const Vec4& in_V,const Matrix& in_M)
{
	Vec4 out_V;
	Matrix_MxV(out_V,in_V,in_M);
	return out_V;
}

Vec3 operator*(const Vec3& in_V,const Matrix& in_M)
{ Vec3 out_V;
	Matrix_MxV(out_V,in_V,in_M);
	return out_V;
//	Vec4 temp_V;
//	Vec3 out_V;
//	Vec4 in_V2 = Vec4((in_V),0.0);
//	Matrix_MxV(temp_V,in_V2,in_M);
//	return out_V= Vec3(temp_V.x,temp_V.y,temp_V.z);
}

Vec2 operator*(const Vec2& in_V,const Matrix& in_M)
{ Vec2 out_V;
	Matrix_MxV(out_V,in_V,in_M);
	return out_V;
//	Vec4 temp_V;
//	Vec2 out_V;
//	Vec4 in_V2 = Vec4((in_V),0.0,0.0);
//	Matrix_MxV(temp_V,in_V2,in_M);
//	return out_V= Vec2(temp_V.x,temp_V.y);
}

void Matrix_MxM( Matrix& out_M, const Matrix& in_M1, const Matrix& in_M2)
{
    Matrix temp_M;
//    printf("works well MAT\n");
	temp_M.s[_0x0_] = in_M1.s[_0x0_]*in_M2.s[_0x0_] + in_M1.s[_0x1_]*in_M2.s[_1x0_] + in_M1.s[_0x2_]*in_M2.s[_2x0_] + in_M1.s[_0x3_]*in_M2.s[_3x0_];
	temp_M.s[_0x1_] = in_M1.s[_0x0_]*in_M2.s[_0x1_] + in_M1.s[_0x1_]*in_M2.s[_1x1_] + in_M1.s[_0x2_]*in_M2.s[_2x1_] + in_M1.s[_0x3_]*in_M2.s[_3x1_];
	temp_M.s[_0x2_] = in_M1.s[_0x0_]*in_M2.s[_0x2_] + in_M1.s[_0x1_]*in_M2.s[_1x2_] + in_M1.s[_0x2_]*in_M2.s[_2x2_] + in_M1.s[_0x3_]*in_M2.s[_3x2_];
	temp_M.s[_0x3_] = in_M1.s[_0x0_]*in_M2.s[_0x3_] + in_M1.s[_0x1_]*in_M2.s[_1x3_] + in_M1.s[_0x2_]*in_M2.s[_2x3_] + in_M1.s[_0x3_]*in_M2.s[_3x3_];

	temp_M.s[_1x0_] = in_M1.s[_1x0_]*in_M2.s[_0x0_] + in_M1.s[_1x1_]*in_M2.s[_1x0_] + in_M1.s[_1x2_]*in_M2.s[_2x0_] + in_M1.s[_1x3_]*in_M2.s[_3x0_];
	temp_M.s[_1x1_] = in_M1.s[_1x0_]*in_M2.s[_0x1_] + in_M1.s[_1x1_]*in_M2.s[_1x1_] + in_M1.s[_1x2_]*in_M2.s[_2x1_] + in_M1.s[_1x3_]*in_M2.s[_3x1_];
	temp_M.s[_1x2_] = in_M1.s[_1x0_]*in_M2.s[_0x2_] + in_M1.s[_1x1_]*in_M2.s[_1x2_] + in_M1.s[_1x2_]*in_M2.s[_2x2_] + in_M1.s[_1x3_]*in_M2.s[_3x2_];
	temp_M.s[_1x3_] = in_M1.s[_1x0_]*in_M2.s[_0x3_] + in_M1.s[_1x1_]*in_M2.s[_1x3_] + in_M1.s[_1x2_]*in_M2.s[_2x3_] + in_M1.s[_1x3_]*in_M2.s[_3x3_];

	temp_M.s[_2x0_] = in_M1.s[_2x0_]*in_M2.s[_0x0_] + in_M1.s[_2x1_]*in_M2.s[_1x0_] + in_M1.s[_2x2_]*in_M2.s[_2x0_] + in_M1.s[_2x3_]*in_M2.s[_3x0_];
	temp_M.s[_2x1_] = in_M1.s[_2x0_]*in_M2.s[_0x1_] + in_M1.s[_2x1_]*in_M2.s[_1x1_] + in_M1.s[_2x2_]*in_M2.s[_2x1_] + in_M1.s[_2x3_]*in_M2.s[_3x1_];
	temp_M.s[_2x2_] = in_M1.s[_2x0_]*in_M2.s[_0x2_] + in_M1.s[_2x1_]*in_M2.s[_1x2_] + in_M1.s[_2x2_]*in_M2.s[_2x2_] + in_M1.s[_2x3_]*in_M2.s[_3x2_];
	temp_M.s[_2x3_] = in_M1.s[_2x0_]*in_M2.s[_0x3_] + in_M1.s[_2x1_]*in_M2.s[_1x3_] + in_M1.s[_2x2_]*in_M2.s[_2x3_] + in_M1.s[_2x3_]*in_M2.s[_3x3_];

	temp_M.s[_3x0_] = in_M1.s[_3x0_]*in_M2.s[_0x0_] + in_M1.s[_3x1_]*in_M2.s[_1x0_] + in_M1.s[_3x2_]*in_M2.s[_2x0_] + in_M1.s[_3x3_]*in_M2.s[_3x0_];
	temp_M.s[_3x1_] = in_M1.s[_3x0_]*in_M2.s[_0x1_] + in_M1.s[_3x1_]*in_M2.s[_1x1_] + in_M1.s[_3x2_]*in_M2.s[_2x1_] + in_M1.s[_3x3_]*in_M2.s[_3x1_];
	temp_M.s[_3x2_] = in_M1.s[_3x0_]*in_M2.s[_0x2_] + in_M1.s[_3x1_]*in_M2.s[_1x2_] + in_M1.s[_3x2_]*in_M2.s[_2x2_] + in_M1.s[_3x3_]*in_M2.s[_3x2_];
	temp_M.s[_3x3_] = in_M1.s[_3x0_]*in_M2.s[_0x3_] + in_M1.s[_3x1_]*in_M2.s[_1x3_] + in_M1.s[_3x2_]*in_M2.s[_2x3_] + in_M1.s[_3x3_]*in_M2.s[_3x3_];
	
    out_M = temp_M;
    // because of android stupid cpus above
    
//#if defined(YES_NEON)
//
//Matrix_MxM_NEON(out_M.s, in_M1.s, in_M2.s);
//
//	#if defined(IOS)
//	    printf("YES NEON\n");
//	#elif defined(ANDROID)
//	    LOGE("YES NEON\n");
//	#endif
//
//#else
//
//out_M.s[_0x0_] = in_M1.s[_0x0_]*in_M2.s[_0x0_] + in_M1.s[_0x1_]*in_M2.s[_1x0_] + in_M1.s[_0x2_]*in_M2.s[_2x0_] + in_M1.s[_0x3_]*in_M2.s[_3x0_];
//out_M.s[_0x1_] = in_M1.s[_0x0_]*in_M2.s[_0x1_] + in_M1.s[_0x1_]*in_M2.s[_1x1_] + in_M1.s[_0x2_]*in_M2.s[_2x1_] + in_M1.s[_0x3_]*in_M2.s[_3x1_];
//out_M.s[_0x2_] = in_M1.s[_0x0_]*in_M2.s[_0x2_] + in_M1.s[_0x1_]*in_M2.s[_1x2_] + in_M1.s[_0x2_]*in_M2.s[_2x2_] + in_M1.s[_0x3_]*in_M2.s[_3x2_];
//out_M.s[_0x3_] = in_M1.s[_0x0_]*in_M2.s[_0x3_] + in_M1.s[_0x1_]*in_M2.s[_1x3_] + in_M1.s[_0x2_]*in_M2.s[_2x3_] + in_M1.s[_0x3_]*in_M2.s[_3x3_];
//
//out_M.s[_1x0_] = in_M1.s[_1x0_]*in_M2.s[_0x0_] + in_M1.s[_1x1_]*in_M2.s[_1x0_] + in_M1.s[_1x2_]*in_M2.s[_2x0_] + in_M1.s[_1x3_]*in_M2.s[_3x0_];
//out_M.s[_1x1_] = in_M1.s[_1x0_]*in_M2.s[_0x1_] + in_M1.s[_1x1_]*in_M2.s[_1x1_] + in_M1.s[_1x2_]*in_M2.s[_2x1_] + in_M1.s[_1x3_]*in_M2.s[_3x1_];
//out_M.s[_1x2_] = in_M1.s[_1x0_]*in_M2.s[_0x2_] + in_M1.s[_1x1_]*in_M2.s[_1x2_] + in_M1.s[_1x2_]*in_M2.s[_2x2_] + in_M1.s[_1x3_]*in_M2.s[_3x2_];
//out_M.s[_1x3_] = in_M1.s[_1x0_]*in_M2.s[_0x3_] + in_M1.s[_1x1_]*in_M2.s[_1x3_] + in_M1.s[_1x2_]*in_M2.s[_2x3_] + in_M1.s[_1x3_]*in_M2.s[_3x3_];
//
//out_M.s[_2x0_] = in_M1.s[_2x0_]*in_M2.s[_0x0_] + in_M1.s[_2x1_]*in_M2.s[_1x0_] + in_M1.s[_2x2_]*in_M2.s[_2x0_] + in_M1.s[_2x3_]*in_M2.s[_3x0_];
//out_M.s[_2x1_] = in_M1.s[_2x0_]*in_M2.s[_0x1_] + in_M1.s[_2x1_]*in_M2.s[_1x1_] + in_M1.s[_2x2_]*in_M2.s[_2x1_] + in_M1.s[_2x3_]*in_M2.s[_3x1_];
//out_M.s[_2x2_] = in_M1.s[_2x0_]*in_M2.s[_0x2_] + in_M1.s[_2x1_]*in_M2.s[_1x2_] + in_M1.s[_2x2_]*in_M2.s[_2x2_] + in_M1.s[_2x3_]*in_M2.s[_3x2_];
//out_M.s[_2x3_] = in_M1.s[_2x0_]*in_M2.s[_0x3_] + in_M1.s[_2x1_]*in_M2.s[_1x3_] + in_M1.s[_2x2_]*in_M2.s[_2x3_] + in_M1.s[_2x3_]*in_M2.s[_3x3_];
//
//out_M.s[_3x0_] = in_M1.s[_3x0_]*in_M2.s[_0x0_] + in_M1.s[_3x1_]*in_M2.s[_1x0_] + in_M1.s[_3x2_]*in_M2.s[_2x0_] + in_M1.s[_3x3_]*in_M2.s[_3x0_];
//out_M.s[_3x1_] = in_M1.s[_3x0_]*in_M2.s[_0x1_] + in_M1.s[_3x1_]*in_M2.s[_1x1_] + in_M1.s[_3x2_]*in_M2.s[_2x1_] + in_M1.s[_3x3_]*in_M2.s[_3x1_];
//out_M.s[_3x2_] = in_M1.s[_3x0_]*in_M2.s[_0x2_] + in_M1.s[_3x1_]*in_M2.s[_1x2_] + in_M1.s[_3x2_]*in_M2.s[_2x2_] + in_M1.s[_3x3_]*in_M2.s[_3x2_];
//out_M.s[_3x3_] = in_M1.s[_3x0_]*in_M2.s[_0x3_] + in_M1.s[_3x1_]*in_M2.s[_1x3_] + in_M1.s[_3x2_]*in_M2.s[_2x3_] + in_M1.s[_3x3_]*in_M2.s[_3x3_];
//
//#endif
}

//void Matrix_MxM_NEON(__MATRIX__TYPE__ * out_M, const __MATRIX__TYPE__* in_M1, const __MATRIX__TYPE__* in_M2)
//{
//#ifdef YES_NEON
//    
//asm volatile
//(
//	//Save
//	"VLDMIA %1, { q8  - q11 }\n\t" // M1
//	"VLDMIA %2, { q0  -  q3 } \n\t" // M2
// 
//	//out_M = 	in_M1 first row x in_M2 first col
//	"VMUL.f32		q12,		q8,		d0[0]\n\t"
//	"VMUL.f32		q13,		q8,		d2[0]\n\t"
//	"VMUL.f32		q14,		q8,		d4[0]\n\t"
//	"VMUL.f32		q15,		q8,		d6[0]\n\t"
// 
//	//out_M = 	in_M1 seond row x in_M2 second col
//	"VMLA.f32		q12,		q9,		d0[1]\n\t"
//	"VMLA.f32		q13,		q9,		d2[1]\n\t"
//	"VMLA.f32		q14,		q9,		d4[1]\n\t"
//	"VMLA.f32		q15,		q9,		d6[1]\n\t"
// 
//	//out_M = 	in_M1 third row x in_M2 third col
//	"VMLA.f32		q12,		q10,        d1[0]\n\t"
//	"VMLA.f32		q13,		q10,        d3[0]\n\t"
//	"VMLA.f32		q14,		q10,        d5[0]\n\t"
//	"VMLA.f32		q15,		q10,        d7[0]\n\t"
// 
//	//out_M = 	in_M1 last row x in_M2 last col
//	"VMLA.f32		q12,		q11,        d1[1]\n\t"
//	"VMLA.f32		q13,		q11,        d3[1]\n\t"
//	"VMLA.f32		q14,		q11,        d5[1]\n\t"
//	"VMLA.f32		q15,		q11,        d7[1]\n\t"
//
//	//Store
//	"VSTMIA %0, { q12	-	q15 }"
//
//	// output : input : lobber
//	:
//	: "r" (out_M),"r" (in_M1), "r" (in_M2)
//	: "memory", "q0", "q1", "q2", "q3", "q8", "q9", "q10", "q11", "q12", "q13", "q14", "q15"
//	);
//#endif
//}

void Matrix_MxV( Vec4& out_V, const Vec4& in_V, const Matrix& in_M)
{
    Vec4 temp_V;
    
	temp_V.x = in_V.x * in_M.s[_0x0_] + in_V.y * in_M.s[_1x0_] + in_V.z * in_M.s[_2x0_] + in_V.w * in_M.s[_3x0_];
	temp_V.y = in_V.x * in_M.s[_0x1_] + in_V.y * in_M.s[_1x1_] + in_V.z * in_M.s[_2x1_] + in_V.w * in_M.s[_3x1_];
	temp_V.z = in_V.x * in_M.s[_0x2_] + in_V.y * in_M.s[_1x2_] + in_V.z * in_M.s[_2x2_] + in_V.w * in_M.s[_3x2_];
	temp_V.w = in_V.x * in_M.s[_0x3_] + in_V.y * in_M.s[_1x3_] + in_V.z * in_M.s[_2x3_] + in_V.w * in_M.s[_3x3_];
    
    out_V = temp_V;
//#ifdef YES_NEON
//Matrix_MxV_NEON(&out_V.x, &in_V.x, in_M.s);
//#else
//out_V.x = in_V.x * in_M.s[_0x0_] + in_V.y * in_M.s[_1x0_] + in_V.z * in_M.s[_2x0_] + in_V.w * in_M.s[_3x0_];
//out_V.y = in_V.x * in_M.s[_0x1_] + in_V.y * in_M.s[_1x1_] + in_V.z * in_M.s[_2x1_] + in_V.w * in_M.s[_3x1_];
//out_V.z = in_V.x * in_M.s[_0x2_] + in_V.y * in_M.s[_1x2_] + in_V.z * in_M.s[_2x2_] + in_V.w * in_M.s[_3x2_];
//out_V.w = in_V.x * in_M.s[_0x3_] + in_V.y * in_M.s[_1x3_] + in_V.z * in_M.s[_2x3_] + in_V.w * in_M.s[_3x3_];
//#endif
}

// Added w value to be used with the Traslate function
void Matrix_MxV( Vec3& out_V, const Vec3& in_V, const Matrix& in_M)
{
    Vec3 temp_V;
    
    temp_V.x = in_V.x * in_M.s[_0x0_] + in_V.y * in_M.s[_1x0_] + in_V.z * in_M.s[_2x0_];
    temp_V.y = in_V.x * in_M.s[_0x1_] + in_V.y * in_M.s[_1x1_] + in_V.z * in_M.s[_2x1_];
    temp_V.z = in_V.x * in_M.s[_0x2_] + in_V.y * in_M.s[_1x2_] + in_V.z * in_M.s[_2x2_];
    
    out_V = temp_V;
}

void Matrix_MxV( Vec2& out_V, const Vec2& in_V, const Matrix& in_M)
{
    Vec2 temp_V;
	temp_V.x = in_V.x * in_M.s[_0x0_] + in_V.y * in_M.s[_1x0_]+in_M.s[_3x0_];
	temp_V.y = in_V.x * in_M.s[_0x1_] + in_V.y * in_M.s[_1x1_]+in_M.s[_3x1_];
    out_V = temp_V;
}
void Matrix_MxV_NEON(__VERTEX__TYPE__* out_V, const __VERTEX__TYPE__* in_V, const __MATRIX__TYPE__* in_M)
{
	/*
#ifdef YES_NEON
asm volatile
(
	// Store m & v - avoiding q4-q7 which need to be preserved - q0 = result
	"vldmia %1, { q8-q11 }	\n\t"	// q8-q11 = m
	"vldmia %2, { q1 }		\n\t"	// q1     = v

	// result = first column of A x V.x
	"vmul.f32 q0, q8, d2[0]\n\t"

	// result += second column of A x V.y
	"vmla.f32 q0, q9, d2[1]\n\t"

	// result += third column of A x V.z
	"vmla.f32 q0, q10, d3[0]\n\t"

	// result += last column of A x V.w
	"vmla.f32 q0, q11, d3[1]\n\t"

	// output = result registers
	"vstmia %0, { q0 }"

	: // no output
	: "r" (out_V), "r" (in_V), "r" (in_M) 	// input - note *value* of pointer doesn't change
	: "memory", "q0", "q1", "q8", "q9", "q10", "q11" //clobber
	);

#endif
*/
}

void Matrix_Translation( Matrix& out_M, const float x, const float y, const float z)
{
	out_M.s[_0x0_] = 1.f; out_M.s[_0x1_] = 0.f; out_M.s[_0x2_] = 0.f; out_M.s[_0x3_] = 0.f;
	out_M.s[_1x0_] = 0.f; out_M.s[_1x1_] = 1.f; out_M.s[_1x2_] = 0.f; out_M.s[_1x3_] = 0.f;
	out_M.s[_2x0_] = 0.f; out_M.s[_2x1_] = 0.f; out_M.s[_2x2_] = 1.f; out_M.s[_2x3_] = 0.f;
	out_M.s[_3x0_] =   x; out_M.s[_3x1_] =   y; out_M.s[_3x2_] =   z; out_M.s[_3x3_] = 1.f;
}

void Matrix_Scaling( Matrix& out_M, const float x, const float y, const float z)
{
	out_M.s[_0x0_] =   x; out_M.s[_0x1_] = 0.f; out_M.s[_0x2_] = 0.f; out_M.s[_0x3_] = 0.f;
	out_M.s[_1x0_] = 0.f; out_M.s[_1x1_] =   y; out_M.s[_1x2_] = 0.f; out_M.s[_1x3_] = 0.f;
	out_M.s[_2x0_] = 0.f; out_M.s[_2x1_] = 0.f; out_M.s[_2x2_] =   z; out_M.s[_2x3_] = 0.f;
	out_M.s[_3x0_] = 0.f; out_M.s[_3x1_] = 0.f; out_M.s[_3x2_] = 0.f; out_M.s[_3x3_] = 1.f;
}

void Matrix_Identity( Matrix& out_M)
{
	out_M.s[_0x0_] = 1.f; out_M.s[_0x1_] = 0.f; out_M.s[_0x2_] = 0.f; out_M.s[_0x3_] = 0.f;
	out_M.s[_1x0_] = 0.f; out_M.s[_1x1_] = 1.f; out_M.s[_1x2_] = 0.f; out_M.s[_1x3_] = 0.f;
	out_M.s[_2x0_] = 0.f; out_M.s[_2x1_] = 0.f; out_M.s[_2x2_] = 1.f; out_M.s[_2x3_] = 0.f;
	out_M.s[_3x0_] = 0.f; out_M.s[_3x1_] = 0.f; out_M.s[_3x2_] = 0.f; out_M.s[_3x3_] = 1.f;
}

void Matrix_Look_At( Matrix& out_M, const Vec3& in_EYE, const Vec3& in_AT,const Vec3& in_UP)
{
    Vec3 zAxis, yAxis, xAxis;
    Matrix 	t;

//    zAxis = Vec3(in_AT.x - in_EYE.x,in_AT.y - in_EYE.y, in_AT.z - in_EYE.z);

    zAxis = (in_AT-in_EYE).normalize();
    yAxis = in_UP;
    yAxis.normalize();
    
    xAxis = zAxis.cross(yAxis) ;
    yAxis = xAxis.cross(zAxis); // because temporary y-axis could be not right-angled(90)

    out_M.s[_0x0_] = xAxis.x; out_M.s[_0x1_] = yAxis.x; out_M.s[_0x2_] = -zAxis.x; out_M.s[_0x3_] = 0;//-in_EYE.x;//-(xAxis.dot(in_EYE));
    out_M.s[_1x0_] = xAxis.y; out_M.s[_1x1_] = yAxis.y; out_M.s[_1x2_] = -zAxis.y; out_M.s[_1x3_] = 0;//-in_EYE.y;//-(yAxis.dot(in_EYE));
    out_M.s[_2x0_] = xAxis.z; out_M.s[_2x1_] = yAxis.z;  out_M.s[_2x2_] = -zAxis.z; out_M.s[_2x3_] = 0;//-in_EYE.z;//-(zAxis.dot(in_EYE));
    out_M.s[_3x0_] = 0;           out_M.s[_3x1_] =  0;            out_M.s[_3x2_] =  0;            out_M.s[_3x3_] = 1;
//    out_M.s[_3x0_] = -in_EYE.x;           out_M.s[_3x1_] =  -in_EYE.y;            out_M.s[_3x2_] =  -in_EYE.z;            out_M.s[_3x3_] = 1;
//    out_M.s[_3x0_] = -xAxis.dot(in_EYE);           out_M.s[_3x1_] =  -yAxis.dot(in_EYE);            out_M.s[_3x2_] =  -zAxis.dot(in_EYE);            out_M.s[_3x3_] = 1;

    Matrix_Identity(t);
	Matrix_Translation(t, -in_EYE.x, -in_EYE.y, -in_EYE.z);
	Matrix_MxM(out_M, t, out_M);
}

void Matrix_Rotation_X(Matrix	&out_M,const float angle)
{
	float COS =	(float)cos(angle);
	float SIN =	(float)sin(angle);
	out_M.s[_0x0_]=  1.f;		out_M.s[_0x1_]= 0.f;	out_M.s[_0x2_]= 0.f;	out_M.s[_0x3_]= 0.f;
	out_M.s[_1x0_]=	 0.f;		out_M.s[_1x1_]= COS;	out_M.s[_1x2_]= SIN;	out_M.s[_1x3_]= 0.f;
	out_M.s[_2x0_]=  0.f;		out_M.s[_2x1_]=-SIN;	out_M.s[_2x2_]= COS;	out_M.s[_2x3_]=	0.f;
	out_M.s[_3x0_]=	 0.f;		out_M.s[_3x1_]= 0.f;	out_M.s[_3x2_]= 0.f;	out_M.s[_3x3_]= 1.f;
    
}

void Matrix_Rotation_Y(Matrix	&out_M, const float angle)
{
	float COS =	(float)cos(angle);
	float SIN =	(float)sin(angle);
	out_M.s[_0x0_]=  COS;		out_M.s[_0x1_]= 0.f;	out_M.s[_0x2_]=-SIN;	out_M.s[_0x3_]= 0.f;
	out_M.s[_1x0_]=	 0.f;		out_M.s[_1x1_]= 1.f;	out_M.s[_1x2_]= 0.f;	out_M.s[_1x3_]= 0.f;
    out_M.s[_2x0_]=  SIN;		out_M.s[_2x1_]=	0.f;	out_M.s[_2x2_]= COS;	out_M.s[_2x3_]=	0.f;
	out_M.s[_3x0_]=	 0.f;		out_M.s[_3x1_]= 0.f;	out_M.s[_3x2_]= 0.f;	out_M.s[_3x3_]= 1.f;
}

void Matrix_Rotation_Z( Matrix	&out_M, const float angle)
{
	float COS =	(float)cos(angle);
	float SIN =	(float)sin(angle);
	out_M.s[_0x0_]=  COS;		out_M.s[_0x1_]= SIN;	out_M.s[_0x2_]= 0.f;	out_M.s[_0x3_]= 0.f;
	out_M.s[_1x0_]=  -SIN;	out_M.s[_1x1_]= COS;	out_M.s[_1x2_]= 0.f;	out_M.s[_1x3_]= 0.f;
	out_M.s[_2x0_]=  0.f;		out_M.s[_2x1_]=	0.f;	out_M.s[_2x2_]= 1.f;	out_M.s[_2x3_]=	0.f;
	out_M.s[_3x0_]=	 0.f;		out_M.s[_3x1_]= 0.f;     out_M.s[_3x2_]= 0.f;out_M.s[_3x3_]= 1.f;
}

void Matrix_Transpose(Matrix& out_M,const Matrix& in_M)
{
    Matrix t;
    t.s[_0x0_] = in_M.s[_0x0_]; t.s[_1x0_] = in_M.s[_0x1_]; t.s[_2x0_] = in_M.s[_0x2_]; t.s[_3x0_] = in_M.s[_0x3_];
    t.s[_0x1_] = in_M.s[_1x0_]; t.s[_1x1_] = in_M.s[_1x1_]; t.s[_2x1_] = in_M.s[_1x2_]; t.s[_3x1_] = in_M.s[_1x3_];
    t.s[_0x2_] = in_M.s[_2x0_]; t.s[_1x2_] = in_M.s[_2x1_]; t.s[_2x2_] = in_M.s[_2x2_]; t.s[_3x2_] = in_M.s[_2x3_];
    t.s[_0x3_] = in_M.s[_3x0_]; t.s[_1x3_] = in_M.s[_3x1_]; t.s[_2x3_] = in_M.s[_3x2_]; t.s[_3x3_] = in_M.s[_3x3_];
    out_M = t;
}

void Matrix_Inverse(Matrix& out_M, const Matrix& in_M)
{
    Matrix	mDummyMatrix;
    double		det_1;
    double		pos, neg, temp;
    
    /* Calculate the determinant of submatrix A and determine if the
     the matrix is singular as limited by the double precision
     floating-point data representation. */
    pos = neg = 0.0;
    temp =  in_M.s[ 0] * in_M.s[ 5] * in_M.s[10];
    if (temp >= 0.0) pos += temp; else neg += temp;
    temp =  in_M.s[ 4] * in_M.s[ 9] * in_M.s[ 2];
    if (temp >= 0.0) pos += temp; else neg += temp;
    temp =  in_M.s[ 8] * in_M.s[ 1] * in_M.s[ 6];
    if (temp >= 0.0) pos += temp; else neg += temp;
    temp = -in_M.s[ 8] * in_M.s[ 5] * in_M.s[ 2];
    if (temp >= 0.0) pos += temp; else neg += temp;
    temp = -in_M.s[ 4] * in_M.s[ 1] * in_M.s[10];
    if (temp >= 0.0) pos += temp; else neg += temp;
    temp = -in_M.s[ 0] * in_M.s[ 9] * in_M.s[ 6];
    if (temp >= 0.0) pos += temp; else neg += temp;
    det_1 = pos + neg;
    
    /* Is the submatrix A singular? */
    if ((det_1 == 0.0) || (abs(det_1 / (pos - neg)) < 1.0e-15))
    {
        /* Matrix M has no inverse */
        printf("Matrix has no inverse : singular matrix\n");
        return;
    }
    else
    {
        /* Calculate inverse(A) = adj(A) / det(A) */
        det_1 = 1.0 / det_1;
        mDummyMatrix.s[ 0] =   ( in_M.s[ 5] * in_M.s[10] - in_M.s[ 9] * in_M.s[ 6] ) * (float)det_1;
        mDummyMatrix.s[ 1] = - ( in_M.s[ 1] * in_M.s[10] - in_M.s[ 9] * in_M.s[ 2] ) * (float)det_1;
        mDummyMatrix.s[ 2] =   ( in_M.s[ 1] * in_M.s[ 6] - in_M.s[ 5] * in_M.s[ 2] ) * (float)det_1;
        mDummyMatrix.s[ 4] = - ( in_M.s[ 4] * in_M.s[10] - in_M.s[ 8] * in_M.s[ 6] ) * (float)det_1;
        mDummyMatrix.s[ 5] =   ( in_M.s[ 0] * in_M.s[10] - in_M.s[ 8] * in_M.s[ 2] ) * (float)det_1;
        mDummyMatrix.s[ 6] = - ( in_M.s[ 0] * in_M.s[ 6] - in_M.s[ 4] * in_M.s[ 2] ) * (float)det_1;
        mDummyMatrix.s[ 8] =   ( in_M.s[ 4] * in_M.s[ 9] - in_M.s[ 8] * in_M.s[ 5] ) * (float)det_1;
        mDummyMatrix.s[ 9] = - ( in_M.s[ 0] * in_M.s[ 9] - in_M.s[ 8] * in_M.s[ 1] ) * (float)det_1;
        mDummyMatrix.s[10] =   ( in_M.s[ 0] * in_M.s[ 5] - in_M.s[ 4] * in_M.s[ 1] ) * (float)det_1;
        
        /* Calculate -C * inverse(A) */
        mDummyMatrix.s[12] = - ( in_M.s[12] * mDummyMatrix.s[ 0] + in_M.s[13] * mDummyMatrix.s[ 4] + in_M.s[14] * mDummyMatrix.s[ 8] );
        mDummyMatrix.s[13] = - ( in_M.s[12] * mDummyMatrix.s[ 1] + in_M.s[13] * mDummyMatrix.s[ 5] + in_M.s[14] * mDummyMatrix.s[ 9] );
        mDummyMatrix.s[14] = - ( in_M.s[12] * mDummyMatrix.s[ 2] + in_M.s[13] * mDummyMatrix.s[ 6] + in_M.s[14] * mDummyMatrix.s[10] );
        
        /* Fill in last row */
        mDummyMatrix.s[ 3] = 0.0f;
        mDummyMatrix.s[ 7] = 0.0f;
        mDummyMatrix.s[11] = 0.0f;
        mDummyMatrix.s[15] = 1.0f;
    }
    
   	/* Copy contents of dummy matrix in pfMatrix */
    out_M = mDummyMatrix;
  
}

void Matrix_PerspectiveProjection
(Matrix& out_M,
  const __VERTEX__TYPE__ FOV,
  const __VERTEX__TYPE__ ASPECT,
  const __VERTEX__TYPE__ NEAR,
  const __VERTEX__TYPE__ FAR)
{
    float f, n;
    
    f = 1.0f / (float)tan(FOV * 0.5f); // 1/tan(theta/2)
    n = 1.0f / (NEAR - FAR);
    
    out_M.s[_0x0_] = f/ASPECT;    out_M.s[_0x1_] = 0.0;                       out_M.s[_0x2_] = 0.0;                           out_M.s[_0x3_] = 0.0;
    out_M.s[_1x0_] = 0;                         out_M.s[_1x1_] =     f;                          out_M.s[_1x2_] = 0.0;                           out_M.s[_1x3_] = 0.0;
    out_M.s[_2x0_] = 0;                     out_M.s[_2x1_] = 0.0;                        out_M.s[_2x2_] = (FAR+NEAR)*n;             out_M.s[_2x3_] = -1.0;
    out_M.s[_3x0_] = 0;                     out_M.s[_3x1_] = 0.0;                        out_M.s[_3x2_] =  2*(FAR*NEAR)*n;         out_M.s[_3x3_] = 0.0;

}

void Matrix_OrthoProjection( Matrix& out_M, const float width, const float height, const float nZ, const float fZ)
{
    out_M.s[_0x0_] = 2 / width; out_M.s[_0x1_] = 0;                 	out_M.s[_0x2_] = 0;                                 out_M.s[_0x3_] = 0;
	out_M.s[_1x0_] = 0;             out_M.s[_1x1_] = 2 / height;     out_M.s[_1x2_] = 0;                                out_M.s[_1x3_] = 0;
    out_M.s[_2x0_] = 0;             	out_M.s[_2x1_] = 0;                     out_M.s[_2x2_] =-2.0 / (fZ - nZ);      out_M.s[_2x3_] =0;
	out_M.s[_3x0_] = -1;             	out_M.s[_3x1_] = -1;                     out_M.s[_3x2_] = - (fZ+nZ)/(fZ-nZ);                         	out_M.s[_3x3_] = 1.;
}

/*
 * Quaternion
 */
void Matrix_Quarternion_Indentity(Quaternion& out_Q)
{
    out_Q.x = 0.0;
    out_Q.y = 0.0;
    out_Q.z = 0.0;
    out_Q.w = 1.0;
}

void Matrix_Quaternion_Normalize(Quaternion& out_Q)
{
    double t_BigMag =  out_Q.x*out_Q.x + out_Q.y*out_Q.y + out_Q.z*out_Q.z + out_Q.w*out_Q.w;
    float t_Mag = (float)sqrt(t_BigMag);
    
    if(t_Mag!=0.0f)
    {
        t_Mag = 1.0f / t_Mag;
        out_Q.x *= t_Mag;
        out_Q.y *= t_Mag;
        out_Q.z *= t_Mag;
        out_Q.w *= t_Mag;
    }
}
void Matrix_Quaternion_Rotation_Axis(Quaternion& out_Q,Vec3& axis, float angle)
{
    float  t_Sin = (float)sin(angle*0.5f);
    float  t_Cos = (float)cos(angle*0.5f);
    out_Q.x = axis.x*t_Sin;
    out_Q.y = axis.y*t_Sin;
    out_Q.z = axis.z*t_Sin;
    out_Q.w = t_Cos;
}

