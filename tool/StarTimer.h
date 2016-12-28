//
//  StarTimer.h
//
//  Created by sungwoo choi on 8/25/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef StarEngine_Timer
#define StarEngine_Timer

#include "../StarMain.h"
//#include "iostream"
#ifdef __APPLE__
#include "TargetConditionals.h"
#include <mach/mach.h>
#include <mach/mach_time.h>
#include <CoreFoundation/CoreFoundation.h>
//#include <iostream>
//using namespace std;

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
    int frame;
    StarTimerDelegate* delegate;
public:
    //StarTimer():frame(0){}
    StarTimer(StarTimerDelegate* _delegate):frame(0){delegate = _delegate;};
    unsigned long long getTime() ;
    void  getFPS() ;
    int getFrame();
};


#endif
