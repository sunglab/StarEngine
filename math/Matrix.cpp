//
//  Matrix.cpp
//
//  Created by sungwoo choi on 8/22/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#include "Matrix.h"
#include <stdio.h>
#include <math.h>
#include "../StarMain.h"

Vec3 operator*(const Vec3& in_V, const Matrix3& in_M)
{
    Vec3 out_V;
    Matrix_MxV(out_V,in_V,in_M);
    return out_V;
}

Vec4 Matrix::operator*(const Vec4& in_V) const
{
	 //row vector
	 return Vec4(  s[0]*in_V.x + s[4]*in_V.y + s[8]*in_V.z  + s[12]*in_V.w,
                   s[1]*in_V.x + s[5]*in_V.y + s[9]*in_V.z  + s[13]*in_V.w,
                   s[2]*in_V.x + s[6]*in_V.y + s[10]*in_V.z + s[14]*in_V.w,
                   s[3]*in_V.x + s[7]*in_V.y + s[11]*in_V.z + s[15]*in_V.w);
}

Matrix3 Matrix3::operator*(const Matrix3& in_M)const
{
	Matrix3 out_M;
	Matrix_MxM(out_M,*this,in_M);
	return out_M;
}

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
{   Vec3 out_V;
	Matrix_MxV(out_V,in_V,in_M);
	return out_V;
}

Vec2 operator*(const Vec2& in_V,const Matrix& in_M)
{ Vec2 out_V;
	Matrix_MxV(out_V,in_V,in_M);
	return out_V;
}

void Matrix_to_Matrix3( Matrix3& out_M, const Matrix& in_M)
{
    out_M.s[0] = in_M.s[_0x0_];
    out_M.s[1] = in_M.s[_1x0_];
    out_M.s[2] = in_M.s[_2x0_];
    out_M.s[3] = in_M.s[_0x1_];
    out_M.s[4] = in_M.s[_1x1_];
    out_M.s[5] = in_M.s[_2x1_];
    out_M.s[6] = in_M.s[_0x2_];
    out_M.s[7] = in_M.s[_1x2_];
    out_M.s[8] = in_M.s[_2x2_];
}

void Matrix_MxM( Matrix3& out_M, const Matrix3& in_M1, const Matrix3& in_M2)
{
    Matrix3 temp_M;
    temp_M.s[_0x0] = in_M1.s[_0x0]*in_M2.s[_0x0] + in_M1.s[_0x1]*in_M2.s[_1x0] + in_M1.s[_0x2]*in_M2.s[_2x0];
    temp_M.s[_0x1] = in_M1.s[_0x0]*in_M2.s[_0x1] + in_M1.s[_0x1]*in_M2.s[_1x1] + in_M1.s[_0x2]*in_M2.s[_2x1];
    temp_M.s[_0x2] = in_M1.s[_0x0]*in_M2.s[_0x2] + in_M1.s[_0x1]*in_M2.s[_1x2] + in_M1.s[_0x2]*in_M2.s[_2x2];

    temp_M.s[_1x0] = in_M1.s[_1x0]*in_M2.s[_0x0] + in_M1.s[_1x1]*in_M2.s[_1x0] + in_M1.s[_1x2]*in_M2.s[_2x0];
    temp_M.s[_1x1] = in_M1.s[_1x0]*in_M2.s[_0x1] + in_M1.s[_1x1]*in_M2.s[_1x1] + in_M1.s[_1x2]*in_M2.s[_2x1];
    temp_M.s[_1x2] = in_M1.s[_1x0]*in_M2.s[_0x2] + in_M1.s[_1x1]*in_M2.s[_1x2] + in_M1.s[_1x2]*in_M2.s[_2x2];

    temp_M.s[_2x0] = in_M1.s[_2x0]*in_M2.s[_0x0] + in_M1.s[_2x1]*in_M2.s[_1x0] + in_M1.s[_2x2]*in_M2.s[_2x0];
    temp_M.s[_2x1] = in_M1.s[_2x0]*in_M2.s[_0x1] + in_M1.s[_2x1]*in_M2.s[_1x1] + in_M1.s[_2x2]*in_M2.s[_2x1];
    temp_M.s[_2x2] = in_M1.s[_2x0]*in_M2.s[_0x2] + in_M1.s[_2x1]*in_M2.s[_1x2] + in_M1.s[_2x2]*in_M2.s[_2x2];

   /*
	temp_M[0][0] = in_M1[0][0]*in_M2[0][0] + in_M1[0][1]*in_M2[1][0] + in_M1[0][2]*in_M2[2][0];
    temp_M[0][1] = in_M1[0][0]*in_M2[0][1] + in_M1[0][1]*in_M2[1][1] + in_M1[0][2]*in_M2[2][1];
    temp_M[0][2] = in_M1[0][0]*in_M2[0][2] + in_M1[0][1]*in_M2[1][2] + in_M1[0][2]*in_M2[2][2];
    
    temp_M[1][0] = in_M1[1][0]*in_M2[0][0] + in_M1[1][1]*in_M2[1][0] + in_M1[1][2]*in_M2[2][0];
    temp_M[1][1] = in_M1[1][0]*in_M2[0][1] + in_M1[1][1]*in_M2[1][1] + in_M1[1][2]*in_M2[2][1];
    temp_M[1][2] = in_M1[1][0]*in_M2[0][2] + in_M1[1][1]*in_M2[1][2] + in_M1[1][2]*in_M2[2][2];
    
    temp_M[2][0] = in_M1[2][0]*in_M2[0][0] + in_M1[2][1]*in_M2[1][0] + in_M1[2][2]*in_M2[2][0];
    temp_M[2][1] = in_M1[2][0]*in_M2[0][1] + in_M1[2][1]*in_M2[1][1] + in_M1[2][2]*in_M2[2][1];
    temp_M[2][2] = in_M1[2][0]*in_M2[0][2] + in_M1[2][1]*in_M2[1][2] + in_M1[2][2]*in_M2[2][2];
    */
    
    out_M = temp_M;
}

void Matrix_MxM( Matrix& out_M, const Matrix& in_M1, const Matrix& in_M2)
{
    Matrix temp_M;
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
	temp_V.x = in_V.x * in_M.s[_0x0_] + in_V.y * in_M.s[_0x1_] + in_V.z * in_M.s[_0x2_] + in_V.w * in_M.s[_0x3_];
	temp_V.y = in_V.x * in_M.s[_1x0_] + in_V.y * in_M.s[_1x1_] + in_V.z * in_M.s[_1x2_] + in_V.w * in_M.s[_1x3_];
	temp_V.z = in_V.x * in_M.s[_2x0_] + in_V.y * in_M.s[_2x1_] + in_V.z * in_M.s[_2x2_] + in_V.w * in_M.s[_2x3_];
	temp_V.w = in_V.x * in_M.s[_3x0_] + in_V.y * in_M.s[_3x1_] + in_V.z * in_M.s[_3x2_] + in_V.w * in_M.s[_3x3_];
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
void Matrix_MxV( Vec3& out_V, const Vec3& in_V, const Matrix3& in_M)
{
    Vec3 temp_V;

    temp_V.x = in_V.x * in_M.s[0] + in_V.y * in_M.s[1] + in_V.z * in_M.s[2];
    temp_V.y = in_V.x * in_M.s[3] + in_V.y * in_M.s[4] + in_V.z * in_M.s[5];
    temp_V.z = in_V.x * in_M.s[6] + in_V.y * in_M.s[7] + in_V.z * in_M.s[8];
    
    out_V = temp_V;
}

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
//#ifdef YES_NEON
//asm volatile
//(
//    // Store m & v - avoiding q4-q7 which need to be preserved - q0 = result
//    "vldmia %1, { q8-q11 }    \n\t"    // q8-q11 = m
//    "vldmia %2, { q1 }        \n\t"    // q1     = v
//
//    // result = first column of A x V.x
//    "vmul.f32 q0, q8, d2[0]\n\t"
//
//    // result += second column of A x V.y
//    "vmla.f32 q0, q9, d2[1]\n\t"
//
//    // result += third column of A x V.z
//    "vmla.f32 q0, q10, d3[0]\n\t"
//
//    // result += last column of A x V.w
//    "vmla.f32 q0, q11, d3[1]\n\t"
//
//    // output = result registers
//    "vstmia %0, { q0 }"
//
//    : // no output
//    : "r" (out_V), "r" (in_V), "r" (in_M)     // input - note *value* of pointer doesn't change
//    : "memory", "q0", "q1", "q8", "q9", "q10", "q11" //clobber
//    );
//
//#endif
}

void Matrix_Viewport(Matrix& out_M, const Vec2& in_Rect, const Matrix& in_M)
{
    throw std::runtime_error("empty matrix");
//    out_M.s[_0x0_] = 1.f; out_M.s[_0x1_] = 0.f; out_M.s[_0x2_] = 0.f; out_M.s[_0x3_] = 0.f;
//    out_M.s[_1x0_] = 0.f; out_M.s[_1x1_] = 1.f; out_M.s[_1x2_] = 0.f; out_M.s[_1x3_] = 0.f;
//    out_M.s[_2x0_] = 0.f; out_M.s[_2x1_] = 0.f; out_M.s[_2x2_] = 1.f; out_M.s[_2x3_] = 0.f;
//    out_M.s[_3x0_] =   x; out_M.s[_3x1_] =   y; out_M.s[_3x2_] =   z; out_M.s[_3x3_] = 1.f;
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

void Matrix3_Scaling( Matrix3& out_M, const float x, const float y, const float z)
{
    out_M.s[0] =   x; out_M.s[3] = 0.f; out_M.s[6] = 0.f;
    out_M.s[1] = 0.f; out_M.s[4] =   y; out_M.s[7] = 0.f;
    out_M.s[2] = 0.f; out_M.s[5] = 0.f; out_M.s[8] =   z;
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

    zAxis = Normalize(in_EYE-in_AT); // a direction vector
    xAxis = Normalize(in_UP.cross(zAxis));
    yAxis = Normalize(zAxis.cross(xAxis));// because temporary y-axis could be not right-angled(90)

    out_M.s[_0x0_] = xAxis.x; out_M.s[_0x1_] = yAxis.x; out_M.s[_0x2_] = zAxis.x; out_M.s[_0x3_] = 0;//-(xAxis.dot(in_EYE));
    out_M.s[_1x0_] = xAxis.y; out_M.s[_1x1_] = yAxis.y; out_M.s[_1x2_] = zAxis.y; out_M.s[_1x3_] = 0;//-(yAxis.dot(in_EYE));
    out_M.s[_2x0_] = xAxis.z; out_M.s[_2x1_] = yAxis.z; out_M.s[_2x2_] = zAxis.z; out_M.s[_2x3_] = 0;//-(zAxis.dot(in_EYE));
    out_M.s[_3x0_] = -((xAxis).dot(in_EYE));
    out_M.s[_3x1_] = -((yAxis).dot(in_EYE));
    out_M.s[_3x2_] = -((zAxis).dot(in_EYE));
    out_M.s[_3x3_] = 1;
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
	out_M.s[_1x0_]=  -SIN;      out_M.s[_1x1_]= COS;	out_M.s[_1x2_]= 0.f;	out_M.s[_1x3_]= 0.f;
	out_M.s[_2x0_]=  0.f;		out_M.s[_2x1_]=	0.f;	out_M.s[_2x2_]= 1.f;	out_M.s[_2x3_]=	0.f;
	out_M.s[_3x0_]=	 0.f;		out_M.s[_3x1_]= 0.f;    out_M.s[_3x2_]= 0.f;    out_M.s[_3x3_]= 1.f;
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

void Matrix3_Identity(Matrix3& out_M)
{
    out_M.s[0]=1.;
    out_M.s[1]=0.;
    out_M.s[2]=0.;
    
    out_M.s[3]=0.;
    out_M.s[4]=1.;
    out_M.s[5]=0.;
    
    out_M.s[6]=0.;
    out_M.s[7]=0.;
    out_M.s[8]=1.;
}

void Matrix3_Inverse(Matrix3& out_M, const Matrix3& in_M)
{
    Matrix3 temp_M;
    
    double determinant = in_M.s[0]*(in_M.s[4]*in_M.s[8]-in_M.s[7]*in_M.s[5])
    -in_M.s[1]*(in_M.s[3]*in_M.s[8]-in_M.s[5]*in_M.s[6])
    +in_M.s[2]*(in_M.s[3]*in_M.s[7]-in_M.s[4]*in_M.s[6]);
    if(determinant==0)
    {
        starLOG("Inverse Determinant Zero\n");
        return;
    }
    
    double invdet = 1/determinant;
    temp_M.s[0] =  (in_M.s[4]*in_M.s[8]-in_M.s[7]*in_M.s[5])*invdet;
    temp_M.s[3] = -(in_M.s[1]*in_M.s[8]-in_M.s[2]*in_M.s[7])*invdet;
    temp_M.s[6] =  (in_M.s[1]*in_M.s[5]-in_M.s[2]*in_M.s[4])*invdet;
    temp_M.s[1] = -(in_M.s[3]*in_M.s[8]-in_M.s[5]*in_M.s[6])*invdet;
    temp_M.s[4] =  (in_M.s[0]*in_M.s[8]-in_M.s[2]*in_M.s[6])*invdet;
    temp_M.s[7] = -(in_M.s[0]*in_M.s[5]-in_M.s[3]*in_M.s[2])*invdet;
    temp_M.s[2] =  (in_M.s[3]*in_M.s[7]-in_M.s[6]*in_M.s[4])*invdet;
    temp_M.s[5] = -(in_M.s[0]*in_M.s[7]-in_M.s[6]*in_M.s[1])*invdet;
    temp_M.s[8] =  (in_M.s[0]*in_M.s[4]-in_M.s[3]*in_M.s[1])*invdet;
    
    out_M = temp_M;
}

void Matrix3_Transpose(Matrix3& out_M, const Matrix3& in_M)
{
    Matrix3 t;
    t.s[0] = in_M.s[0]; t.s[3] = in_M.s[1]; t.s[6] = in_M.s[2];
    t.s[1] = in_M.s[3]; t.s[4] = in_M.s[4]; t.s[7] = in_M.s[5];
    t.s[2] = in_M.s[6]; t.s[5] = in_M.s[7]; t.s[8] = in_M.s[8];
    out_M = t;
}


void Matrix_Inverse(Matrix& out_M, const Matrix& in_M)
{
    double inv[16], det;
    int i;
   
    inv[0] = in_M.s[5]  * in_M.s[10] * in_M.s[15] -
    in_M.s[5]  * in_M.s[11] * in_M.s[14] -
    in_M.s[9]  * in_M.s[6]  * in_M.s[15] +
    in_M.s[9]  * in_M.s[7]  * in_M.s[14] +
    in_M.s[13] * in_M.s[6]  * in_M.s[11] -
    in_M.s[13] * in_M.s[7]  * in_M.s[10];
    
    inv[4] = -in_M.s[4]  * in_M.s[10] * in_M.s[15] +
    in_M.s[4]  * in_M.s[11] * in_M.s[14] +
    in_M.s[8]  * in_M.s[6]  * in_M.s[15] -
    in_M.s[8]  * in_M.s[7]  * in_M.s[14] -
    in_M.s[12] * in_M.s[6]  * in_M.s[11] +
    in_M.s[12] * in_M.s[7]  * in_M.s[10];
    
    inv[8] = in_M.s[4]  * in_M.s[9] * in_M.s[15] -
    in_M.s[4]  * in_M.s[11] * in_M.s[13] -
    in_M.s[8]  * in_M.s[5] * in_M.s[15] +
    in_M.s[8]  * in_M.s[7] * in_M.s[13] +
    in_M.s[12] * in_M.s[5] * in_M.s[11] -
    in_M.s[12] * in_M.s[7] * in_M.s[9];
    
    inv[12] = -in_M.s[4]  * in_M.s[9] * in_M.s[14] +
    in_M.s[4]  * in_M.s[10] * in_M.s[13] +
    in_M.s[8]  * in_M.s[5] * in_M.s[14] -
    in_M.s[8]  * in_M.s[6] * in_M.s[13] -
    in_M.s[12] * in_M.s[5] * in_M.s[10] +
    in_M.s[12] * in_M.s[6] * in_M.s[9];
    
    inv[1] = -in_M.s[1]  * in_M.s[10] * in_M.s[15] +
    in_M.s[1]  * in_M.s[11] * in_M.s[14] +
    in_M.s[9]  * in_M.s[2] * in_M.s[15] -
    in_M.s[9]  * in_M.s[3] * in_M.s[14] -
    in_M.s[13] * in_M.s[2] * in_M.s[11] +
    in_M.s[13] * in_M.s[3] * in_M.s[10];
    
    inv[5] = in_M.s[0]  * in_M.s[10] * in_M.s[15] -
    in_M.s[0]  * in_M.s[11] * in_M.s[14] -
    in_M.s[8]  * in_M.s[2] * in_M.s[15] +
    in_M.s[8]  * in_M.s[3] * in_M.s[14] +
    in_M.s[12] * in_M.s[2] * in_M.s[11] -
    in_M.s[12] * in_M.s[3] * in_M.s[10];
    
    inv[9] = -in_M.s[0]  * in_M.s[9] * in_M.s[15] +
    in_M.s[0]  * in_M.s[11] * in_M.s[13] +
    in_M.s[8]  * in_M.s[1] * in_M.s[15] -
    in_M.s[8]  * in_M.s[3] * in_M.s[13] -
    in_M.s[12] * in_M.s[1] * in_M.s[11] +
    in_M.s[12] * in_M.s[3] * in_M.s[9];
    
    inv[13] = in_M.s[0]  * in_M.s[9] * in_M.s[14] -
    in_M.s[0]  * in_M.s[10] * in_M.s[13] -
    in_M.s[8]  * in_M.s[1] * in_M.s[14] +
    in_M.s[8]  * in_M.s[2] * in_M.s[13] +
    in_M.s[12] * in_M.s[1] * in_M.s[10] -
    in_M.s[12] * in_M.s[2] * in_M.s[9];
    
    inv[2] = in_M.s[1]  * in_M.s[6] * in_M.s[15] -
    in_M.s[1]  * in_M.s[7] * in_M.s[14] -
    in_M.s[5]  * in_M.s[2] * in_M.s[15] +
    in_M.s[5]  * in_M.s[3] * in_M.s[14] +
    in_M.s[13] * in_M.s[2] * in_M.s[7] -
    in_M.s[13] * in_M.s[3] * in_M.s[6];
    
    inv[6] = -in_M.s[0]  * in_M.s[6] * in_M.s[15] +
    in_M.s[0]  * in_M.s[7] * in_M.s[14] +
    in_M.s[4]  * in_M.s[2] * in_M.s[15] -
    in_M.s[4]  * in_M.s[3] * in_M.s[14] -
    in_M.s[12] * in_M.s[2] * in_M.s[7] +
    in_M.s[12] * in_M.s[3] * in_M.s[6];
    
    inv[10] = in_M.s[0]  * in_M.s[5] * in_M.s[15] -
    in_M.s[0]  * in_M.s[7] * in_M.s[13] -
    in_M.s[4]  * in_M.s[1] * in_M.s[15] +
    in_M.s[4]  * in_M.s[3] * in_M.s[13] +
    in_M.s[12] * in_M.s[1] * in_M.s[7] -
    in_M.s[12] * in_M.s[3] * in_M.s[5];
    
    inv[14] = -in_M.s[0]  * in_M.s[5] * in_M.s[14] +
    in_M.s[0]  * in_M.s[6] * in_M.s[13] +
    in_M.s[4]  * in_M.s[1] * in_M.s[14] -
    in_M.s[4]  * in_M.s[2] * in_M.s[13] -
    in_M.s[12] * in_M.s[1] * in_M.s[6] +
    in_M.s[12] * in_M.s[2] * in_M.s[5];
    
    inv[3] = -in_M.s[1] * in_M.s[6] * in_M.s[11] +
    in_M.s[1] * in_M.s[7] * in_M.s[10] +
    in_M.s[5] * in_M.s[2] * in_M.s[11] -
    in_M.s[5] * in_M.s[3] * in_M.s[10] -
    in_M.s[9] * in_M.s[2] * in_M.s[7] +
    in_M.s[9] * in_M.s[3] * in_M.s[6];
    
    inv[7] = in_M.s[0] * in_M.s[6] * in_M.s[11] -
    in_M.s[0] * in_M.s[7] * in_M.s[10] -
    in_M.s[4] * in_M.s[2] * in_M.s[11] +
    in_M.s[4] * in_M.s[3] * in_M.s[10] +
    in_M.s[8] * in_M.s[2] * in_M.s[7] -
    in_M.s[8] * in_M.s[3] * in_M.s[6];
    
    inv[11] = -in_M.s[0] * in_M.s[5] * in_M.s[11] +
    in_M.s[0] * in_M.s[7] * in_M.s[9] +
    in_M.s[4] * in_M.s[1] * in_M.s[11] -
    in_M.s[4] * in_M.s[3] * in_M.s[9] -
    in_M.s[8] * in_M.s[1] * in_M.s[7] +
    in_M.s[8] * in_M.s[3] * in_M.s[5];
    
    inv[15] = in_M.s[0] * in_M.s[5] * in_M.s[10] -
    in_M.s[0] * in_M.s[6] * in_M.s[9] -
    in_M.s[4] * in_M.s[1] * in_M.s[10] +
    in_M.s[4] * in_M.s[2] * in_M.s[9] +
    in_M.s[8] * in_M.s[1] * in_M.s[6] -
    in_M.s[8] * in_M.s[2] * in_M.s[5];
    
    det = in_M.s[0] * inv[0] + in_M.s[1] * inv[4] + in_M.s[2] * inv[8] + in_M.s[3] * inv[12];
    
    if (det == 0)
        return ;
    
    det = 1.0 / det;
    
    for (i = 0; i < 16; i++)
        out_M.s[i] = inv[i] * det;
  
}

void Matrix_PerspectiveProjection
(Matrix& out_M,
 const __VERTEX__TYPE__ FOV,
 const __VERTEX__TYPE__ ASPECT,
 const __VERTEX__TYPE__ N_EAR,
 const __VERTEX__TYPE__ F_AR)
{
    
    float fov = 1.0f / (float)tan(FOV * 0.5f); // 1/tan(theta/2)
    float nf = 1.0f / (N_EAR - F_AR);
    
    out_M.s[_0x0_] = fov/ASPECT;
    out_M.s[_1x0_] = 0;
    out_M.s[_2x0_] = 0;
    out_M.s[_3x0_] = 0;
    
    out_M.s[_0x1_] = 0.0;
    out_M.s[_1x1_] = fov;
    out_M.s[_2x1_] = 0.0;
    out_M.s[_3x1_] = 0.0;
    
    out_M.s[_0x2_] = 0.0;
    out_M.s[_1x2_] = 0.0;
    out_M.s[_2x2_] = (N_EAR+F_AR) * nf;
    out_M.s[_3x2_] = (2.f*N_EAR*F_AR) * nf;
    
    out_M.s[_0x3_] = 0.0;
    out_M.s[_1x3_] = 0.0;
    out_M.s[_2x3_] = -1.0;
    out_M.s[_3x3_] = 0.0;
    
}

void Matrix_OrthoProjection( Matrix& out_M, const float width, const float height, const float nZ, const float fZ)
{
    // asumed r-l = width , t-b = height
    out_M.s[_0x0_] = 2./width; out_M.s[_0x1_] = 0;              out_M.s[_0x2_] = 0;                    out_M.s[_0x3_] = 0;
	out_M.s[_1x0_] = 0;         out_M.s[_1x1_] = 2./height;     out_M.s[_1x2_] = 0;                    out_M.s[_1x3_] = 0;
    out_M.s[_2x0_] = 0;         out_M.s[_2x1_] = 0;              out_M.s[_2x2_] = -2./(fZ-nZ);         out_M.s[_2x3_] = 0;
	out_M.s[_3x0_] = 0;        out_M.s[_3x1_] = 0;            out_M.s[_3x2_] = -(fZ+nZ)/(fZ-nZ);      out_M.s[_3x3_] = 1.;
}


/*
 * Quaternion
 */

Quaternion Quaternion::operator+(const float& in_Scalar) const
{
    return Quaternion(this->w+in_Scalar, this->x+in_Scalar, this->y+in_Scalar, this->z+in_Scalar);
}
Quaternion Quaternion::operator-(const float& in_Scalar) const
{
    return Quaternion(this->w-in_Scalar, this->x-in_Scalar, this->y-in_Scalar, this->z-in_Scalar);
}
Quaternion Quaternion::operator*(const float& in_Scalar) const
{
    return Quaternion(this->w*in_Scalar, this->x*in_Scalar, this->y*in_Scalar, this->z*in_Scalar);
}
Quaternion Quaternion::operator/(const float& in_Scalar) const
{
    return Quaternion(this->w/in_Scalar, this->x/in_Scalar, this->y/in_Scalar, this->z/in_Scalar);
}


Quaternion Quaternion::operator+(const Quaternion& in_Q) const
{
    return Quaternion(this->w+in_Q.w, this->x+in_Q.x, this->y+in_Q.y, this->z+in_Q.z);
}
Quaternion Quaternion::operator-(const Quaternion& in_Q) const
{
    return Quaternion(this->w-in_Q.w, this->x-in_Q.x, this->y-in_Q.y, this->z-in_Q.z);
}



float Quaternion::dot(const Quaternion& in_Q)
{
    return w*in_Q.w + x*in_Q.x + y*in_Q.y + z*in_Q.z;
}

void Quaternion::lerp(const float t,const Quaternion& in_Q)
{
    const float epsilon = .0001f;
    float dot  = this->dot(in_Q);
    
    if (dot > 1.-epsilon)
    {
        Quaternion result = in_Q + (*this - in_Q)*t;
        Quaternion_Normalize(result);
        if((this->w)!=(this->w))
        {
        }
        (*this) = result;
    }
    dot = starConstrain((float)dot, (float)0.0, (float)1.0);
    float theta = acos(dot)*t;
    Quaternion temp_Q1 = in_Q - (*this) * (dot);
    Quaternion_Normalize(temp_Q1);
    
    Quaternion temp_Q2 = (*this) * cos(theta) + (temp_Q1) * sin(theta);
    Quaternion_Normalize(temp_Q2);
    
    (*this)  = temp_Q2;
}

void  Quaternion_Identity(Quaternion& out_Q)
{
    out_Q.x = 0.0;
    out_Q.y = 0.0;
    out_Q.z = 0.0;
    out_Q.w = 1.0;
}

void Quaternion_Normalize(Quaternion& out_Q)
{
    double t_BigMag =  out_Q.x*out_Q.x + out_Q.y*out_Q.y + out_Q.z*out_Q.z + out_Q.w*out_Q.w;
    double t_Mag = (float)sqrt(t_BigMag);
    
    if(t_Mag!=0.0f)
    {
        t_Mag = 1.0f / t_Mag;
        out_Q.x *= t_Mag;
        out_Q.y *= t_Mag;
        out_Q.z *= t_Mag;
        out_Q.w *= t_Mag;
    }
}

void Quaternion_Rotation_Axis(Quaternion& out_Q,const Vec3& axis, float angle)
{
    float  t_Sin = (float)sin(angle*0.5f);
    float  t_Cos = (float)cos(angle*0.5f);
    out_Q.x = axis.x*t_Sin;
    out_Q.y = axis.y*t_Sin;
    out_Q.z = axis.z*t_Sin;
    out_Q.w = t_Cos;
}

void Quaternion_Rotation_Vector(Quaternion& out_Q, const Vec3& in_V1, const Vec3& in_V2)
{
    Vec3 cross = in_V1.cross(in_V2);
    float dot = in_V1.dot(in_V2);
    float s = sqrt((1.0f + dot) * 2.0f);
    out_Q.x = cross.x / s;
    out_Q.y = cross.y / s;
    out_Q.z = cross.z / s;
    out_Q.w = s *   0.5f;
    
}
void Quaternion_Rotation_Quaternion(Quaternion& out_Q, const Quaternion& in_Q1,const Quaternion& in_Q2)
{
    Quaternion temp_Q;
    temp_Q.w = in_Q1.w * in_Q2.w - in_Q1.x * in_Q2.x - in_Q1.y * in_Q2.y - in_Q1.z * in_Q2.z;
    temp_Q.x = in_Q1.w * in_Q2.x + in_Q1.x * in_Q2.w + in_Q1.y * in_Q2.z - in_Q1.z * in_Q2.y;
    temp_Q.y = in_Q1.w * in_Q2.y + in_Q1.y * in_Q2.w + in_Q1.z * in_Q2.x - in_Q1.x * in_Q2.z;
    temp_Q.z = in_Q1.w * in_Q2.z + in_Q1.z * in_Q2.w + in_Q1.x * in_Q2.y - in_Q1.y * in_Q2.x;
    Quaternion_Normalize(temp_Q);
    out_Q = temp_Q;
}

void Quaternion_to_Matrix(Matrix& out_M, const Quaternion& in_Q)
{
    const float s = 2.f;
    
    float xs, ys, zs;
    float wx, wy, wz;
    float xx, xy, xz;
    float yy, yz, zz;
    
    xs = in_Q.x * s;    ys = in_Q.y * s;    zs = in_Q.z * s;
    wx = in_Q.w * xs;   wy = in_Q.w * ys;   wz = in_Q.w * zs;
    xx = in_Q.x * xs;   xy = in_Q.x * ys;   xz = in_Q.x * zs;
    yy = in_Q.y * ys;   yz = in_Q.y * zs;   zz = in_Q.z * zs;
    
    out_M.s[_0x0_] = 1.-(yy+zz);    out_M.s[_0x1_] = xy+wz;          out_M.s[_0x2_] = xz-wy;         out_M.s[_0x3_] = 0.;
    out_M.s[_1x0_] = xy-wz;         out_M.s[_1x1_] = 1.-(xx+zz);     out_M.s[_1x2_] = yz+wx;         out_M.s[_1x3_] = 0.;
    out_M.s[_2x0_] = xz+wy;         out_M.s[_2x1_] = yz-wx;          out_M.s[_2x2_] = 1.-(xx+yy);    out_M.s[_2x3_] = 0.;
    out_M.s[_3x0_] = 0.;           	out_M.s[_3x1_] = 0.;             out_M.s[_3x2_] = 0.;            out_M.s[_3x3_] = 1.;
}
