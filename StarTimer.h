
#ifndef StarEngine_Timer
#define StarEngine_Timer


#ifdef __APPLE__
#include "TargetConditionals.h"
#include <mach/mach.h>
#include <mach/mach_time.h>
#include <CoreFoundation/CoreFoundation.h>
#if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#elif TARGET_OS_IPHONE
// iOS device
#elif TARGET_OS_MAC
// Other kinds of Mac OS
#else
// Unsupported platform
#endif

#elif ANDROID
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#endif

class StarTimer
{

   private:
float getTime() ; 
    
    public:
void  getFPS() ;
float getTick();
};


#endif