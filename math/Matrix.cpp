#include "Matrix.h"
#include <stdio.h>
#include <math.h>
#include "../StarMain.h"



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

//void MatrixVec3CrossProduct(
//		Vec3		&vOut,
//		const Vec3	&v1,
//		const Vec3	&v2)
//{
//	Vec3 result;
//
//	/* Perform alculation on a dummy VECTOR (result) */
//	result.x = v1.y * v2.z - v1.z * v2.y;
//	result.y = v1.z * v2.x - v1.x * v2.z;
//	result.z = v1.x * v2.y - v1.y * v2.x;
//
//	/* opy result in pOut */
//	vOut = result;
//}
//
//
//void MatrixVec3Normalize(
//		Vec3		&vOut,
//		const Vec3	&vIn)
//{
//	float f;
//	double temp;
//
//	temp = (double)(vIn.x * vIn.x + vIn.y * vIn.y + vIn.z * vIn.z);
//	temp = 1.0 / sqrt(temp);
//	f = (float)temp;
//
//	vOut.x = vIn.x * f;
//	vOut.y = vIn.y * f;
//	vOut.z = vIn.z * f;
//	//    printf(":)");
//}
//
//void Matrix_Look_At( Matrix& out_M, const Vec3& in_EYE, const Vec3& in_AT,const Vec3& in_UP)
//{
//	Vec3 f, vUpActual, s, u;
//	Matrix	t;
//
//	f.x = in_AT.x - in_EYE.x;
//	f.y = in_AT.y - in_EYE.y;
//	f.z = in_AT.z - in_EYE.z;
//
//	MatrixVec3Normalize(f, f);
//	MatrixVec3Normalize(vUpActual, in_UP);
//	MatrixVec3CrossProduct(s, f, vUpActual);
//	MatrixVec3CrossProduct(u, s, f);
//
//	out_M.s[ 0] = s.x;
//	out_M.s[ 1] = u.x;
//	out_M.s[ 2] = -f.x;
//	out_M.s[ 3] = 0;
//
//	out_M.s[ 4] = s.y;
//	out_M.s[ 5] = u.y;
//	out_M.s[ 6] = -f.y;
//	out_M.s[ 7] = 0;
//
//	out_M.s[ 8] = s.z;
//	out_M.s[ 9] = u.z;
//	out_M.s[10] = -f.z;
//	out_M.s[11] = 0;
//
//	out_M.s[12] = 0;
//	out_M.s[13] = 0;
//	out_M.s[14] = 0;
//	out_M.s[15] = 1;
//
//	Matrix_Translation(t, -in_EYE.x, -in_EYE.y, -in_EYE.z);
//	Matrix_MxM(out_M, t, out_M);
//
//}

void Matrix_RotationX(Matrix	&out_M,const float angle)
{
	float COS =	(float)cos(angle);
	float SIN =	(float)sin(angle);
	out_M.s[_0x0_]=  1.f;		out_M.s[_0x1_]= 0.f;	out_M.s[_0x2_]= 0.f;	out_M.s[_0x3_]= 0.f;
	out_M.s[_1x0_]=	 0.f;		out_M.s[_1x1_]= COS;	out_M.s[_1x2_]= SIN;	out_M.s[_1x3_]= 0.f;
	out_M.s[_2x0_]=  0.f;		out_M.s[_2x1_]=-SIN;	out_M.s[_2x2_]= COS;	out_M.s[_2x3_]=	0.f;
	out_M.s[_3x0_]=	 0.f;		out_M.s[_3x1_]= 0.f;	out_M.s[_3x2_]= 0.f;	out_M.s[_3x3_]= 1.f;

}


void Matrix_RotationY(Matrix	&out_M, const float angle)
{
	float COS =	(float)cos(angle);
	float SIN =	(float)sin(angle);
	out_M.s[_0x0_]=  COS;		out_M.s[_0x1_]= 0.f;	out_M.s[_0x2_]=-SIN;	out_M.s[_0x3_]= 0.f;
	out_M.s[_1x0_]=	 0.f;		out_M.s[_1x1_]= 1.f;	out_M.s[_1x2_]= 0.f;	out_M.s[_1x3_]= 0.f;
	out_M.s[_2x0_]=  SIN;		out_M.s[_2x1_]=	0.f;	out_M.s[_2x2_]= COS;	out_M.s[_2x3_]=	0.f;
	out_M.s[_3x0_]=	 0.f;		out_M.s[_3x1_]= 0.f;	out_M.s[_3x2_]= 0.f;	out_M.s[_3x3_]= 1.f;
}


void Matrix_RotationZ( Matrix	&out_M, const float angle)
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
		Matrix_RotationZ(mRotation, -90.0f*(3.1415926535f)/180.0f);
		Matrix_MxM(out_M, mRotation, mTemp);
	}
}
