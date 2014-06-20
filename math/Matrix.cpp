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

	out_M.s[_0x0_] = in_M1.s[_0x0_]*in_M2.s[_0x0_] + in_M1.s[_0x1_]*in_M2.s[_1x0_] + in_M1.s[_0x2_]*in_M2.s[_2x0_] + in_M1.s[_0x3_]*in_M2.s[_3x0_];
	out_M.s[_0x1_] = in_M1.s[_0x0_]*in_M2.s[_0x1_] + in_M1.s[_0x1_]*in_M2.s[_1x1_] + in_M1.s[_0x2_]*in_M2.s[_2x1_] + in_M1.s[_0x3_]*in_M2.s[_3x1_];
	out_M.s[_0x2_] = in_M1.s[_0x0_]*in_M2.s[_0x2_] + in_M1.s[_0x1_]*in_M2.s[_1x2_] + in_M1.s[_0x2_]*in_M2.s[_2x2_] + in_M1.s[_0x3_]*in_M2.s[_3x2_];
	out_M.s[_0x3_] = in_M1.s[_0x0_]*in_M2.s[_0x3_] + in_M1.s[_0x1_]*in_M2.s[_1x3_] + in_M1.s[_0x2_]*in_M2.s[_2x3_] + in_M1.s[_0x3_]*in_M2.s[_3x3_];

	out_M.s[_1x0_] = in_M1.s[_1x0_]*in_M2.s[_0x0_] + in_M1.s[_1x1_]*in_M2.s[_1x0_] + in_M1.s[_1x2_]*in_M2.s[_2x0_] + in_M1.s[_1x3_]*in_M2.s[_3x0_];
	out_M.s[_1x1_] = in_M1.s[_1x0_]*in_M2.s[_0x1_] + in_M1.s[_1x1_]*in_M2.s[_1x1_] + in_M1.s[_1x2_]*in_M2.s[_2x1_] + in_M1.s[_1x3_]*in_M2.s[_3x1_];
	out_M.s[_1x2_] = in_M1.s[_1x0_]*in_M2.s[_0x2_] + in_M1.s[_1x1_]*in_M2.s[_1x2_] + in_M1.s[_1x2_]*in_M2.s[_2x2_] + in_M1.s[_1x3_]*in_M2.s[_3x2_];
	out_M.s[_1x3_] = in_M1.s[_1x0_]*in_M2.s[_0x3_] + in_M1.s[_1x1_]*in_M2.s[_1x3_] + in_M1.s[_1x2_]*in_M2.s[_2x3_] + in_M1.s[_1x3_]*in_M2.s[_3x3_];

	out_M.s[_2x0_] = in_M1.s[_2x0_]*in_M2.s[_0x0_] + in_M1.s[_2x1_]*in_M2.s[_1x0_] + in_M1.s[_2x2_]*in_M2.s[_2x0_] + in_M1.s[_2x3_]*in_M2.s[_3x0_];
	out_M.s[_2x1_] = in_M1.s[_2x0_]*in_M2.s[_0x1_] + in_M1.s[_2x1_]*in_M2.s[_1x1_] + in_M1.s[_2x2_]*in_M2.s[_2x1_] + in_M1.s[_2x3_]*in_M2.s[_3x1_];
	out_M.s[_2x2_] = in_M1.s[_2x0_]*in_M2.s[_0x2_] + in_M1.s[_2x1_]*in_M2.s[_1x2_] + in_M1.s[_2x2_]*in_M2.s[_2x2_] + in_M1.s[_2x3_]*in_M2.s[_3x2_];
	out_M.s[_2x3_] = in_M1.s[_2x0_]*in_M2.s[_0x3_] + in_M1.s[_2x1_]*in_M2.s[_1x3_] + in_M1.s[_2x2_]*in_M2.s[_2x3_] + in_M1.s[_2x3_]*in_M2.s[_3x3_];

	out_M.s[_3x0_] = in_M1.s[_3x0_]*in_M2.s[_0x0_] + in_M1.s[_3x1_]*in_M2.s[_1x0_] + in_M1.s[_3x2_]*in_M2.s[_2x0_] + in_M1.s[_3x3_]*in_M2.s[_3x0_];
	out_M.s[_3x1_] = in_M1.s[_3x0_]*in_M2.s[_0x1_] + in_M1.s[_3x1_]*in_M2.s[_1x1_] + in_M1.s[_3x2_]*in_M2.s[_2x1_] + in_M1.s[_3x3_]*in_M2.s[_3x1_];
	out_M.s[_3x2_] = in_M1.s[_3x0_]*in_M2.s[_0x2_] + in_M1.s[_3x1_]*in_M2.s[_1x2_] + in_M1.s[_3x2_]*in_M2.s[_2x2_] + in_M1.s[_3x3_]*in_M2.s[_3x2_];
	out_M.s[_3x3_] = in_M1.s[_3x0_]*in_M2.s[_0x3_] + in_M1.s[_3x1_]*in_M2.s[_1x3_] + in_M1.s[_3x2_]*in_M2.s[_2x3_] + in_M1.s[_3x3_]*in_M2.s[_3x3_];
	/*
#if defined(YES_NEON)

Matrix_MxM_NEON(out_M.s, in_M1.s, in_M2.s);

	//#if defined(IOS)
	//    printf("YES NEON\n");
	//#elif defined(ANDROID)
	//    LOGE("YES NEON\n");
	//#endif

#else
out_M.s[_0x0_] = in_M1.s[_0x0_]*in_M2.s[_0x0_] + in_M1.s[_0x1_]*in_M2.s[_1x0_] + in_M1.s[_0x2_]*in_M2.s[_2x0_] + in_M1.s[_0x3_]*in_M2.s[_3x0_];
out_M.s[_0x1_] = in_M1.s[_0x0_]*in_M2.s[_0x1_] + in_M1.s[_0x1_]*in_M2.s[_1x1_] + in_M1.s[_0x2_]*in_M2.s[_2x1_] + in_M1.s[_0x3_]*in_M2.s[_3x1_];
out_M.s[_0x2_] = in_M1.s[_0x0_]*in_M2.s[_0x2_] + in_M1.s[_0x1_]*in_M2.s[_1x2_] + in_M1.s[_0x2_]*in_M2.s[_2x2_] + in_M1.s[_0x3_]*in_M2.s[_3x2_];
out_M.s[_0x3_] = in_M1.s[_0x0_]*in_M2.s[_0x3_] + in_M1.s[_0x1_]*in_M2.s[_1x3_] + in_M1.s[_0x2_]*in_M2.s[_2x3_] + in_M1.s[_0x3_]*in_M2.s[_3x3_];

out_M.s[_1x0_] = in_M1.s[_1x0_]*in_M2.s[_0x0_] + in_M1.s[_1x1_]*in_M2.s[_1x0_] + in_M1.s[_1x2_]*in_M2.s[_2x0_] + in_M1.s[_1x3_]*in_M2.s[_3x0_];
out_M.s[_1x1_] = in_M1.s[_1x0_]*in_M2.s[_0x1_] + in_M1.s[_1x1_]*in_M2.s[_1x1_] + in_M1.s[_1x2_]*in_M2.s[_2x1_] + in_M1.s[_1x3_]*in_M2.s[_3x1_];
out_M.s[_1x2_] = in_M1.s[_1x0_]*in_M2.s[_0x2_] + in_M1.s[_1x1_]*in_M2.s[_1x2_] + in_M1.s[_1x2_]*in_M2.s[_2x2_] + in_M1.s[_1x3_]*in_M2.s[_3x2_];
out_M.s[_1x3_] = in_M1.s[_1x0_]*in_M2.s[_0x3_] + in_M1.s[_1x1_]*in_M2.s[_1x3_] + in_M1.s[_1x2_]*in_M2.s[_2x3_] + in_M1.s[_1x3_]*in_M2.s[_3x3_];

out_M.s[_2x0_] = in_M1.s[_2x0_]*in_M2.s[_0x0_] + in_M1.s[_2x1_]*in_M2.s[_1x0_] + in_M1.s[_2x2_]*in_M2.s[_2x0_] + in_M1.s[_2x3_]*in_M2.s[_3x0_];
out_M.s[_2x1_] = in_M1.s[_2x0_]*in_M2.s[_0x1_] + in_M1.s[_2x1_]*in_M2.s[_1x1_] + in_M1.s[_2x2_]*in_M2.s[_2x1_] + in_M1.s[_2x3_]*in_M2.s[_3x1_];
out_M.s[_2x2_] = in_M1.s[_2x0_]*in_M2.s[_0x2_] + in_M1.s[_2x1_]*in_M2.s[_1x2_] + in_M1.s[_2x2_]*in_M2.s[_2x2_] + in_M1.s[_2x3_]*in_M2.s[_3x2_];
out_M.s[_2x3_] = in_M1.s[_2x0_]*in_M2.s[_0x3_] + in_M1.s[_2x1_]*in_M2.s[_1x3_] + in_M1.s[_2x2_]*in_M2.s[_2x3_] + in_M1.s[_2x3_]*in_M2.s[_3x3_];

out_M.s[_3x0_] = in_M1.s[_3x0_]*in_M2.s[_0x0_] + in_M1.s[_3x1_]*in_M2.s[_1x0_] + in_M1.s[_3x2_]*in_M2.s[_2x0_] + in_M1.s[_3x3_]*in_M2.s[_3x0_];
out_M.s[_3x1_] = in_M1.s[_3x0_]*in_M2.s[_0x1_] + in_M1.s[_3x1_]*in_M2.s[_1x1_] + in_M1.s[_3x2_]*in_M2.s[_2x1_] + in_M1.s[_3x3_]*in_M2.s[_3x1_];
out_M.s[_3x2_] = in_M1.s[_3x0_]*in_M2.s[_0x2_] + in_M1.s[_3x1_]*in_M2.s[_1x2_] + in_M1.s[_3x2_]*in_M2.s[_2x2_] + in_M1.s[_3x3_]*in_M2.s[_3x2_];
out_M.s[_3x3_] = in_M1.s[_3x0_]*in_M2.s[_0x3_] + in_M1.s[_3x1_]*in_M2.s[_1x3_] + in_M1.s[_3x2_]*in_M2.s[_2x3_] + in_M1.s[_3x3_]*in_M2.s[_3x3_];

#endif
*/
}

void Matrix_MxM_NEON(__MATRIX__TYPE__ * out_M, const __MATRIX__TYPE__* in_M1, const __MATRIX__TYPE__* in_M2)
{
	/*
		 LOGE("HAHA2");
#ifdef YES_NEON
asm volatile
(
	//Save 
	"VLDMIA %1, { q0  -  q3 } \n\t" // M1
	"VLDMIA %2, { q8  - q11 }\n\t" // M2

	//out_M = 	in_M2 x *(in_M1[row1])
	"VMUL.f32		q12,		q8,		d0[0]\n\t"
	"VMUL.f32		q13,		q8,		d2[0]\n\t"
	"VMUL.f32		q14,		q8,		d4[0]\n\t"
	"VMUL.f32		q15,		q8,		d6[0]\n\t"
	//out_M += in_M2 x *(in_M1[row2])
	"VMLA.f32		q12,		q9,		d0[1]\n\t"
	"VMLA.f32		q13,		q9,		d2[1]\n\t"
	"VMLA.f32		q14,		q9,		d4[1]\n\t"
	"VMLA.f32		q15,		q9,		d6[1]\n\t"
	//out_M += in_M2 x *(in_M1[row3])
	"VMLA.f32		q12,		q10,	d1[0]\n\t"
	"VMLA.f32		q13,		q10,	d3[0]\n\t"
	"VMLA.f32		q14,		q10,	d5[0]\n\t"
	"VMLA.f32		q15,		q10,	d7[0]\n\t"
	//out_M += in_M2 x *(in_M1[row4])
	"VMLA.f32		q12,		q11,	d1[1]\n\t"
	"VMLA.f32		q13,		q11,	d3[1]\n\t"
	"VMLA.f32		q14,		q11,	d5[1]\n\t"
	"VMLA.f32		q15,		q11, 	d7[1]\n\t"

	//Store
	"VSTMIA %0, { q12	-	q15 }"

	// output : input : lobber
	:
	: "r" (out_M),"r" (in_M1), "r" (in_M2)
	: "memory", "q0", "q1", "q2", "q3", "q8", "q9", "q10", "q11", "q12", "q13", "q14", "q15"
	);
#endif
*/
}

void Matrix_MxV( Vec4& out_V, const Vec4& in_V, const Matrix& in_M)
{
	out_V.x = in_V.x * in_M.s[_0x0_] + in_V.y * in_M.s[_1x0_] + in_V.z * in_M.s[_2x0_] + in_V.w * in_M.s[_3x0_];
	out_V.y = in_V.x * in_M.s[_0x1_] + in_V.y * in_M.s[_1x1_] + in_V.z * in_M.s[_2x1_] + in_V.w * in_M.s[_3x1_];
	out_V.z = in_V.x * in_M.s[_0x2_] + in_V.y * in_M.s[_1x2_] + in_V.z * in_M.s[_2x2_] + in_V.w * in_M.s[_3x2_];
	out_V.w = in_V.x * in_M.s[_0x3_] + in_V.y * in_M.s[_1x3_] + in_V.z * in_M.s[_2x3_] + in_V.w * in_M.s[_3x3_];
	/*
#ifdef YES_NEON
Matrix_MxV_NEON(&out_V.x, &in_V.x, in_M.s);
#else
out_V.x = in_V.x * in_M.s[_0x0_] + in_V.y * in_M.s[_1x0_] + in_V.z * in_M.s[_2x0_] + in_V.w * in_M.s[_3x0_];
out_V.y = in_V.x * in_M.s[_0x1_] + in_V.y * in_M.s[_1x1_] + in_V.z * in_M.s[_2x1_] + in_V.w * in_M.s[_3x1_];
out_V.z = in_V.x * in_M.s[_0x2_] + in_V.y * in_M.s[_1x2_] + in_V.z * in_M.s[_2x2_] + in_V.w * in_M.s[_3x2_];
out_V.w = in_V.x * in_M.s[_0x3_] + in_V.y * in_M.s[_1x3_] + in_V.z * in_M.s[_2x3_] + in_V.w * in_M.s[_3x3_];
#endif
*/
}

// Added w value to be used with the Traslate function
void Matrix_MxV( Vec3& out_V, const Vec3& in_V, const Matrix& in_M)
{
	out_V.x = in_V.x * in_M.s[_0x0_] + in_V.y * in_M.s[_1x0_] + in_V.z * in_M.s[_2x0_] + in_M.s[_3x0_];
	out_V.y = in_V.x * in_M.s[_0x1_] + in_V.y * in_M.s[_1x1_] + in_V.z * in_M.s[_2x1_] + in_M.s[_3x1_];
	out_V.z = in_V.x * in_M.s[_0x2_] + in_V.y * in_M.s[_1x2_] + in_V.z * in_M.s[_2x2_] + in_M.s[_3x2_];
}

void Matrix_MxV( Vec2& out_V, const Vec2& in_V, const Matrix& in_M)
{
	out_V.x = in_V.x * in_M.s[_0x0_] + in_V.y * in_M.s[_1x0_]+in_M.s[_3x0_];
	out_V.y = in_V.x * in_M.s[_0x1_] + in_V.y * in_M.s[_1x1_]+in_M.s[_3x1_];
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
///----------------------------------------------------------------------------------- unsafe------//
void MatrixVec3CrossProduct(Vec3& out_V,const Vec3& in_V1,const Vec3&	in_V2)
{
	Vec3 result;
	/* Perform alculation on a dummy VECTOR (result) */
	result.x = in_V1.y * in_V2.z - in_V1.z * in_V2.y;
	result.y = in_V1.z * in_V2.x - in_V1.x * in_V2.z;
	result.z = in_V1.x * in_V2.y - in_V1.y * in_V2.x;
	/* opy result in pOut */
	out_V = result;
}


void MatrixVec3Normalize(Vec3& out_V,const Vec3& in_V)
{
	float f; double tmp;
	tmp = (double)(in_V.x * in_V.x + in_V.y * in_V.y + in_V.z * in_V.z);
	tmp = 1.0 / sqrt(tmp);
	f = (float)tmp;
	out_V.x = in_V.x * f;
	out_V.y = in_V.y * f;
	out_V.z = in_V.z * f;
}

void Matrix_Look_At( Matrix& out_M, const Vec3& in_EYE, const Vec3& in_AT,const Vec3& in_UP)
{
	Vec3 f, vUpActual, s, u;
	Matrix	t;

	f.x = in_AT.x - in_EYE.x;
	f.y = in_AT.y - in_EYE.y;
	f.z = in_AT.z - in_EYE.z;

	MatrixVec3Normalize(f, f);
	MatrixVec3Normalize(vUpActual, in_UP);
	MatrixVec3CrossProduct(s, f, vUpActual);
	MatrixVec3CrossProduct(u, s, f);

	out_M.s[ 0] = s.x;
	out_M.s[ 1] = u.x;
	out_M.s[ 2] = -f.x;
	out_M.s[ 3] = 0;

	out_M.s[ 4] = s.y;
	out_M.s[ 5] = u.y;
	out_M.s[ 6] = -f.y;
	out_M.s[ 7] = 0;

	out_M.s[ 8] = s.z;
	out_M.s[ 9] = u.z;
	out_M.s[10] = -f.z;
	out_M.s[11] = 0;

	out_M.s[12] = 0;
	out_M.s[13] = 0;
	out_M.s[14] = 0;
	out_M.s[15] = 1;

	Matrix_Translation(t, -in_EYE.x, -in_EYE.y, -in_EYE.z);
	Matrix_MxM(out_M, t, out_M);

}
///----------------------------------------------------------------------------------- unsafe------//
//void Matrix_Rotation_X(Matrix	&out_M,const float angle)
//{
//	float COS =	(float)cos(angle);
//	float SIN =	(float)sin(angle);
//	out_M.s[_0x0_]=  1.f;		out_M.s[_0x1_]= 0.f;	out_M.s[_0x2_]= 0.f;	out_M.s[_0x3_]= 0.f;
//	out_M.s[_1x0_]=	 0.f;		out_M.s[_1x1_]= COS;	out_M.s[_1x2_]= SIN;	out_M.s[_1x3_]= 0.f;
//	out_M.s[_2x0_]=  0.f;		out_M.s[_2x1_]=-SIN;	out_M.s[_2x2_]= COS;	out_M.s[_2x3_]=	0.f;
//	out_M.s[_3x0_]=	 0.f;		out_M.s[_3x1_]= 0.f;	out_M.s[_3x2_]= 0.f;	out_M.s[_3x3_]= 1.f;
//
//}
//void Matrix_Rotation_Y(Matrix	&out_M, const float angle)
//{
//	float COS =	(float)cos(angle);
//	float SIN =	(float)sin(angle);
//	out_M.s[_0x0_]=  COS;		out_M.s[_0x1_]= 0.f;	out_M.s[_0x2_]=-SIN;	out_M.s[_0x3_]= 0.f;
//	out_M.s[_1x0_]=	 0.f;		out_M.s[_1x1_]= 1.f;	out_M.s[_1x2_]= 0.f;	out_M.s[_1x3_]= 0.f;
//	out_M.s[_2x0_]=  SIN;		out_M.s[_2x1_]=	0.f;	out_M.s[_2x2_]= COS;	out_M.s[_2x3_]=	0.f;
//	out_M.s[_3x0_]=	 0.f;		out_M.s[_3x1_]= 0.f;	out_M.s[_3x2_]= 0.f;	out_M.s[_3x3_]= 1.f;
//}

void Matrix_Rotation_X(Matrix	&out_M,const float angle)
{
	float COS =	(float)cos(angle);
	float SIN =	(float)sin(angle);
	out_M.s[_0x0_]=  1.f;		out_M.s[_0x1_]= 0.f;	out_M.s[_0x2_]= 0.f;	out_M.s[_0x3_]= 0.f;
	out_M.s[_1x0_]=	 0.f;		out_M.s[_1x1_]= COS;	out_M.s[_1x2_]= 0.f;	out_M.s[_1x3_]= 0.f;
	out_M.s[_2x0_]=  0.f;		out_M.s[_2x1_]=-SIN;	out_M.s[_2x2_]= 1.0;	out_M.s[_2x3_]=	0.f;
	out_M.s[_3x0_]=	 0.f;		out_M.s[_3x1_]= 0.f;	out_M.s[_3x2_]= 0.f;	out_M.s[_3x3_]= 1.f;
    
}


void Matrix_Rotation_Y(Matrix	&out_M, const float angle)
{
	float COS =	(float)cos(angle);
	float SIN =	(float)sin(angle);
	out_M.s[_0x0_]=  COS;		out_M.s[_0x1_]= 0.f;	out_M.s[_0x2_]=0.f;	out_M.s[_0x3_]= 0.f;
	out_M.s[_1x0_]=	 0.f;		out_M.s[_1x1_]= 1.f;	out_M.s[_1x2_]= 0.f;	out_M.s[_1x3_]= 0.f;
	out_M.s[_2x0_]=  SIN;		out_M.s[_2x1_]=	0.f;	out_M.s[_2x2_]= 1.f;	out_M.s[_2x3_]=	0.f;
	out_M.s[_3x0_]=	 0.f;		out_M.s[_3x1_]= 0.f;	out_M.s[_3x2_]= 0.f;	out_M.s[_3x3_]= 1.f;
}

void Matrix_Rotation_Z( Matrix	&out_M, const float angle)
{
	float COS =	(float)cos(angle);
	float SIN =	(float)sin(angle);
	out_M.s[_0x0_]=  COS;		out_M.s[_0x1_]= SIN;	out_M.s[_0x2_]= 0.f;	out_M.s[_0x3_]= 0.f;
	out_M.s[_1x0_]=	-SIN;		out_M.s[_1x1_]= COS;	out_M.s[_1x2_]= 0.f;	out_M.s[_1x3_]= 0.f;
	out_M.s[_2x0_]=  0.f;		out_M.s[_2x1_]=	0.f;	out_M.s[_2x2_]= 1.f;	out_M.s[_2x3_]=	0.f;
	out_M.s[_3x0_]=	 0.f;		out_M.s[_3x1_]= 0.f;	out_M.s[_3x2_]= 0.f;	out_M.s[_3x3_]= 1.f;
}

void Matrix_Ortho( Matrix& out_M, const float width, const float height, const float nZ, const float fZ, const bool ROT)
{
	out_M.s[ 0] = 2 / width;
	out_M.s[ 1] = 0;
	out_M.s[ 2] = 0;
	out_M.s[ 3] = 0;

	out_M.s[ 4] = 0;
	out_M.s[ 5] = 2 / height;
	out_M.s[ 6] = 0;
	out_M.s[ 7] = 0;

	out_M.s[ 8] = 0;
	out_M.s[ 9] = 0;
	out_M.s[10] = 1 / (nZ - fZ);
	out_M.s[11] = nZ / (nZ - fZ);

	out_M.s[12] = 0;
	out_M.s[13] = 0;
	out_M.s[14] = 0;
	out_M.s[15] = 1;

	if (ROT)
	{
		Matrix mRotation, mTemp = out_M;
		Matrix_Rotation_Z(mRotation, -90.0f*(3.1415926535f)/180.0f);
		Matrix_MxM(out_M, mRotation, mTemp);
	}
}

////////////////
/* Quaternion */
////////////////

void Matrix_Quaternion_Identity(Quaternion& out_Q)
{
	out_Q.x = 0.f;
	out_Q.y = 0.f;
	out_Q.z = 0.f;
	out_Q.w = 1.f;
}
void Matrix_Quaternion_RotationAxis(Quaternion& out_Q,const Vec3& in_Axis, const float angle)
{
	float sin, cos;
	sin = (float)sinf(angle*0.5f);
	cos = (float)cosf(angle*0.5f);
	/* create a quaternion */
	out_Q.x = in_Axis.x * sin;
	out_Q.y = in_Axis.y * sin;
	out_Q.z = in_Axis.z * sin;
	out_Q.w = cos;
	/* normalize it */
	Matrix_Quaternion_Normalize(out_Q);
}

void Matrix_Quaternion_ToAxisAngle(Quaternion&	in_Q,Vec3& in_Axis, float& angle)
{
	float cosAngle, sinAngle;
	double temp;

	/* compute some values */
	cosAngle = in_Q.w;
	temp = 1.0f - (cosAngle*cosAngle);
	angle = (float)acosf(cosAngle)*2.0f;
	sinAngle = (float)sqrtf(temp);

	/* to void a division by zero */
	if((float)abs(sinAngle)<0.0005f)
		sinAngle = 1.0f;

	/* get axis vector */
	in_Axis.x = in_Q.x / sinAngle;		
	in_Axis.y = in_Q.y / sinAngle; 
	in_Axis.z = in_Q.z / sinAngle;

}

void Matrix_Quaternion_Slerp(Quaternion& out_Q, const Quaternion& in_Q1, const Quaternion& in_Q2, const float t)
{
	float cos, angle, a, b;

	if(t<0.0f||t>1.0f)
	{
		out_Q.x = 0;
		out_Q.y = 0;	
		out_Q.z = 0;
		out_Q.w = 1;
		return;
	}

	cos = (in_Q1.w * in_Q2.w) + (in_Q1.x * in_Q2.x) + (in_Q1.y * in_Q2.y) + (in_Q1.z * in_Q2.z);
	if(cos < 0)
	{
		Quaternion tmp_Q;
		tmp_Q.x = -in_Q2.x;
		tmp_Q.y = -in_Q2.y;
		tmp_Q.z = -in_Q2.z;
		tmp_Q.w = -in_Q2.w;

		Matrix_Quaternion_Slerp(out_Q,in_Q1,tmp_Q, t);
		return;
	}
	cos = _min(cos,1.0f);
	angle = cosf(cos);
	if(angle==0.f)// to void a division by zero
	{ 
		out_Q = in_Q1;
		return;
	}

	/* precompute some values */
	a = (sinf((1.0f-t)*angle) / sin(angle));
	b = (sinf(t*angle) / sinf(angle));
	/* compute resulting quaternion */
	out_Q.x = (a * in_Q1.x) + (b * in_Q2.x);
	out_Q.y = (a * in_Q1.y) + (b * in_Q2.y);
	out_Q.z = (a * in_Q1.z) + (b * in_Q2.z);
	out_Q.w = (a * in_Q1.w) + (b * in_Q2.w);
	/* normalize result */
	Matrix_Quaternion_Normalize(out_Q);
}
void Matrix_Quaternion_Normalize(Quaternion& in_Q)
{
	float magnitude;;
	double tmp;
	/* compute quaternion magnitude */
	tmp = (in_Q.w*in_Q.w)+(in_Q.x*in_Q.x)+(in_Q.y*in_Q.y)+(in_Q.z*in_Q.z);
	magnitude = sqrt(tmp);

	if(magnitude != 0.0f)
	{
		magnitude = 1.0f / magnitude;
		in_Q.x *= magnitude;
		in_Q.y *= magnitude;
		in_Q.z *= magnitude;
		in_Q.w *= magnitude;
	}
}

void Matrix_Rotation_Quaternion(Matrix& out_M,const Quaternion& in_Q)
{
	const Quaternion* p_Q;
	p_Q = &in_Q;
	out_M.s[0] = 1.0f - 2.0f * (p_Q->y)*(p_Q->y) - 2.0f * (p_Q->z)*(p_Q->z);
	out_M.s[1] = 2.0f * (p_Q->x) * (p_Q->y) - 2.0f * (p_Q->z)*(p_Q->w);
	out_M.s[2] = 2.0f * (p_Q->x) * (p_Q->z) + 2.0f * (p_Q->y)*(p_Q->w);
	out_M.s[3] = 0.0f;

	out_M.s[4] = 2.0f * (p_Q->x)*(p_Q->y) + 2.0f *(p_Q->z)*(p_Q->w);
	out_M.s[5] = 1.0f - 2.0f*(p_Q->x)*(p_Q->x) - 2.0f*(p_Q->z)*(p_Q->z);
	out_M.s[6] = 2.0f * (p_Q->y)*(p_Q->z) - 2.0f * (p_Q->x)*(p_Q->w);
	out_M.s[7] = 0.0f;

	out_M.s[8] = 2.0f * (p_Q->x)*(p_Q->z) - 2.0f*(p_Q->y)*(p_Q->w);
	out_M.s[9] = 2.0f * (p_Q->y)*(p_Q->z) + 2.0f*(p_Q->x)*(p_Q->w);
	out_M.s[10] = 1.0f - 2.0f*(p_Q->x)*(p_Q->x) - 2.0f*(p_Q->y)*(p_Q->y);
	out_M.s[11] = 0.0f;

	out_M.s[12] = 0.0f;
	out_M.s[13] = 0.0f;
	out_M.s[14] = 0.0f;
	out_M.s[15] = 1.0f;
}

void Matrix_Quaternion_Multiply(Quaternion& out_Q,const Quaternion& in_Q1,const Quaternion& in_Q2)
{
	Vec3 crossProduct;

	/* compute scalr component */
	out_Q.w = (in_Q1.w*in_Q2.w) - (in_Q1.x*in_Q2.x + in_Q1.y*in_Q2.y + in_Q1.z*in_Q2.z);
	/* compute corss product */
	crossProduct.x = in_Q1.y*in_Q2.z - in_Q1.z*in_Q2.y;
	crossProduct.y = in_Q1.z*in_Q2.x - in_Q1.x*in_Q2.z;
	crossProduct.z = in_Q1.x*in_Q2.y - in_Q1.y*in_Q2.x;
	/* compute result vector */
	out_Q.x = (in_Q1.w * in_Q2.x) +(in_Q2.w * in_Q1.x) + crossProduct.x;
	out_Q.y = (in_Q1.w * in_Q2.y) +(in_Q2.w * in_Q1.y) + crossProduct.y;
	out_Q.x = (in_Q1.w * in_Q2.z) +(in_Q2.w * in_Q1.z) + crossProduct.z;

	Matrix_Quaternion_Normalize(out_Q);
}


