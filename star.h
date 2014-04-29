#ifndef STAR_H
#define STAR_H
  
#if (defined(IOS) && defined(__ARM_NEON__))||(defined(ANDROID) && defined(_ARM_ARCH_7))
#define YES_NEON
#else
#define NO_NEON
#endif

/* MATH */
#define __S_C_A_L_A_R__ float

#define __COLOR__TYPE__ __S_C_A_L_A_R__
#define __VERTEX__TYPE__ __S_C_A_L_A_R__
#define __MATRIX__TYPE__ __S_C_A_L_A_R__

#define _0x0_  0 
#define _0x1_  1 
#define _0x2_  2
#define _0x3_  3
#define _1x0_  4
#define _1x1_  5
#define _1x2_  6
#define _1x3_  7
#define _2x0_  8
#define _2x1_  9 
#define _2x2_ 10 
#define _2x3_ 11 
#define _3x0_ 12 
#define _3x1_ 13 
#define _3x2_ 14 
#define _3x3_ 15

#endif // STAR_H
