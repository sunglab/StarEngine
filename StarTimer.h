
#ifndef StarEngine_Timer
#define StarEngine_Timer

#ifdef IOS
//#include "Types.h"
#include <CoreFoundation/CoreFoundation.h>

#include <mach/mach.h>
#include <mach/mach_time.h>
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