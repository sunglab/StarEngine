

#include "StarTimer.h"


#ifdef ANDROID

#include <android/log.h>
#define  LOG_TAG    "StarEngine"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)      
#endif

#include "../Android/StarEngine/jni/StarEngine.h" /* For Delegater */


Star *starDelegate;

#ifdef IOS

float StarTimer::getTime()
{
    static mach_timebase_info_data_t  sTimebaseInfo;
    uint64_t  time = mach_absolute_time();
    uint64_t  nanos;
    
    if (sTimebaseInfo.denom == 0) {
        (void)mach_timebase_info(&sTimebaseInfo);
    }
    
    nanos = time * sTimebaseInfo.numer / sTimebaseInfo.denom;
    
    return ((float)nanos / 1000000.0);
}

#else  /* ANDROID or OTHERS */
float StarTimer::getTime()
{ 
    float fTimer = 0.0f; 
    
    long long current_msec; 
#ifdef ANDROID
    timespec current; 
    const int result = clock_gettime(CLOCK_MONOTONIC, &current); 
    current_msec = (current.tv_sec * 1000) + (current.tv_nsec / 1000000); 

#else  // windows ... something like that
    clock_t current = clock(); 
    current_msec = (current / 1000000); // in msec 

#endif 
    fTimer = (float)current_msec;///1000.0f; 
    
    return fTimer; 
}
#endif

void StarTimer::getFPS() 
{ 
    static unsigned long framePerSecond = 0; 
    static unsigned long lastTime = 0;
    static unsigned long frameTime = 0;
//    static char strFrameRate[50] = {0};  //IF I need to put Font with FPS
    
    unsigned long current = getTime();//GetTickCount(); 
//    LOGE("%lu\n",current);
    ++framePerSecond; 
     //if the time is bigger than 1.0 sec
   
    if (current - lastTime > 1000) {
        lastTime = current; // init 
//        sprintf(strFrameRate, "FPS :%d", int(framePerSecond)); 
            #ifdef ANDROID
//        LOGE(strFrameRate); 
            #elif IOS
//        printf("%s\n",strFrameRate);
            #endif
        starDelegate->CallbackFPS(framePerSecond);
           
        framePerSecond = 0; 
    } 
    if(current-frameTime<1000)
    starDelegate->CallbackTICK(current-frameTime);
    frameTime = current;
    
} 

