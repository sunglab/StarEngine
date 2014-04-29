#include "Math.h"

//float op_Sin(float angle)
//{
//#ifdef YES_NEON
//
//#else
//    
//#endif
//}
//float op_SQRT(float angle)
//{
//#ifdef YES_NEON
//    printf("ok?");
//    asm volatile ("vmov.f32 s0, r0 		\n\t");
//	 op_SQRT_NEON(angle);
//	asm volatile ("vmov.f32 r0, s0 		\n\t");
//    
//#else
////     printf("no?");
//    float b, c;
//	int m;
//	union {
//		float 	f;
//		int 	i;
//	} a;
//
//	//fast invsqrt approangle
//	a.f = angle;
//	a.i = 0x5F3759DF - (a.i >> 1);		//VRSQRTE
//	c = angle * a.f;
//	b = (3.0f - c * a.f) * 0.5;		//VRSQRTS
//	a.f = a.f * b;		
//	c = angle * a.f;
//	b = (3.0f - c * a.f) * 0.5;
//	a.f = a.f * b;	
//
//	//fast inverse approangle
//	angle = a.f;
//	m = 0x3F800000 - (a.i & 0x7F800000);
//	a.i = a.i + m;
//	a.f = 1.41176471f - 0.47058824f * a.f;
//	a.i = a.i + m;
//	b = 2.0 - a.f * angle;
//	a.f = a.f * b;
//	b = 2.0 - a.f * angle;
//	a.f = a.f * b;
//    return a.f;
//#endif
//}

//float op_SQRT_NEON(float angle)
//{
//	
//	asm volatile (
//			//fast invsqrt approx
//			"vmov.f32 		d1, d0					\n\t"	//d1 = d0
//			"vrsqrte.f32 	d0, d0					\n\t"	//d0 = ~ 1.0 / sqrt(d0)
//			"vmul.f32 		d2, d0, d1				\n\t"	//d2 = d0 * d1
//			"vrsqrts.f32 	d3, d2, d0				\n\t"	//d3 = (3 - d0 * d2) / 2 	
//			"vmul.f32 		d0, d0, d3				\n\t"	//d0 = d0 * d3
//			"vmul.f32 		d2, d0, d1				\n\t"	//d2 = d0 * d1	
//			"vrsqrts.f32 	d3, d2, d0				\n\t"	//d4 = (3 - d0 * d3) / 2	
//			"vmul.f32 		d0, d0, d3				\n\t"	//d0 = d0 * d3	
//			//fast reciporical approximation
//			"vrecpe.f32		d1, d0					\n\t"	//d1 = ~ 1 / d0; 
//			"vrecps.f32		d2, d1, d0				\n\t"	//d2 = 2.0 - d1 * d0; 
//			"vmul.f32		d1, d1, d2				\n\t"	//d1 = d1 * d2; 
//			"vrecps.f32		d2, d1, d0				\n\t"	//d2 = 2.0 - d1 * d0; 
//			"vmul.f32		d0, d1, d2				\n\t"	//d0 = d1 * d2; 
//
//			::: "d0", "d1", "d2", "d3"
//			);
//}
