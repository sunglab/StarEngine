//
//  StarTimer.h
//
//  Created by sungwoo choi on 8/25/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef StarEngine_Timer
#define StarEngine_Timer

#ifdef __APPLE__
#include "TargetConditionals.h"
#include <mach/mach.h>
#include <mach/mach_time.h>
#include <CoreFoundation/CoreFoundation.h>

#elif ANDROID
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#endif
class StarTimerDelegate
{
public:
    virtual void CallbackFPS(int fps){};
    virtual void CallbackTICK(double tick){};
};
class StarTimer
{
private:
    uint64_t frame;
    StarTimerDelegate* delegate;
public:
    StarTimer(StarTimerDelegate* _delegate):frame(0){ delegate = _delegate; };
    uint64_t getMS() ;
    void  getFPS() ;
    uint64_t getFrame();
};


#endif
