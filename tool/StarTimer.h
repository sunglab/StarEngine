
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

class StarTimer
{
private:
    unsigned long  long timeForTesting;
    char* nameForTesting;
    
public:
    StarTimer():timeForTesting(0.f)
    {
        
    }
    unsigned long long getTime() ;
    void  getFPS() ;

    
    void startTick(char *name=(char*)"None");
    void endTick();
};


#endif