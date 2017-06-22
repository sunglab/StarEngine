
//
//  StarMain.h
//
//  Created by sungwoo choi on 8/25/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef STAR_H
#define STAR_H

class StarEngine
{
    
public:
    
    // List
    virtual bool TurnOn_StarEngine(int width=0,int height=0) = 0;
    virtual bool Update_StarEngine() = 0;
    virtual bool Render_StarEngine() = 0;
    virtual bool TurnOff_StarEngine() = 0;
    virtual bool ReStart_StarEngine(int width,int height) = 0;
    virtual bool ReRun_StarEngine() = 0;
    virtual bool Setting_Shader() = 0; // Build All Shaders
    virtual bool Setting_Texture(void* array, int width, int height, int textureid) = 0; // Textures
    
    // Callback
    virtual void CallbackFPS(int FPS) = 0;
    virtual void CallbackTICK(double TICK) = 0;
    virtual void CallbackTouchBegin() = 0;
    virtual void CallbackTouchMove() = 0;
    virtual void CallbackTouchEnd() = 0;
    virtual void CallbackTouchCancel() = 0;
//    virtual void Callback_Press(int idx) = 0;
    
};

#if (defined(IOS) && defined(__ARM_NEON__))||(defined(ANDROID) && defined(_ARM_ARCH_7))
#define YES_NEON
#else
#define NO_NEON
#endif

/* 
 MATH 
 */

#define __S_C_A_L_A_R__ float

#define __COLOR__TYPE__ __S_C_A_L_A_R__
#define __VERTEX__TYPE__ __S_C_A_L_A_R__
#define __MATRIX__TYPE__ __S_C_A_L_A_R__

/*

 row vector based like V x M  
 
 0 4  8 12
 1 5  9 13
 2 6 10 14
 3 7 11 15
 
 */
#define _0x0_  0
#define _1x0_  1
#define _2x0_  2
#define _3x0_  3

#define _0x1_  4
#define _1x1_  5
#define _2x1_  6
#define _3x1_  7

#define _0x2_  8
#define _1x2_  9
#define _2x2_ 10
#define _3x2_ 11

#define _0x3_  12
#define _1x3_  13
#define _2x3_  14
#define _3x3_  15


#endif // STAR_H
