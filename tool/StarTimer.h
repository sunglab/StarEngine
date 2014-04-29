
#ifndef StarEngine_Timer
#define StarEngine_Timer

#include "../StarMain.h"
#ifdef __APPLE__
#include "TargetConditionals.h"
#include <mach/mach.h>
#include <mach/mach_time.h>
#include <CoreFoundation/CoreFoundation.h>
#include <iostream>

#elif ANDROID
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#endif

class StarTimer
{
private:
    unsigned long  long time4Testing;
    
    
public:
    StarTimer():time4Testing(0.f)
    {
        
    }
    unsigned long long getTime() ;
    void  getFPS() ;
//    float getTick();
    void startTick();
    void endTick();
};


#endif