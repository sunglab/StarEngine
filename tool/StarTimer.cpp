

#include "StarTimer.h"

#include "../../Mac/GLSLTOY/ParticleArt/StarEngine.h" /* For Delegater */
Star *starDelegate;

#if IOS || MAC
unsigned long long StarTimer::getTime()
{
	static mach_timebase_info_data_t  sTimebaseInfo;
	uint64_t  time = mach_absolute_time();
	uint64_t  nanos;

	if (sTimebaseInfo.denom == 0) {
		(void)mach_timebase_info(&sTimebaseInfo);
	}

	nanos = time * sTimebaseInfo.numer / sTimebaseInfo.denom;

	return (unsigned long long)(nanos / 1000000);
}

#else  /* ANDROID or any others */
unsigned long long StarTimer::getTime()
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
	fTimer = (unsigned long long)current_msec;///1000.0f;

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

	if (current - lastTime > 1000) { // when higher than 1 SEC
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
    
	// Don't be over more than 1000
    starDelegate->CallbackTICK(current-frameTime);
	frameTime = current;

}

void StarTimer::startTick(char* name)
{
	timeForTesting = getTime();
    nameForTesting = name;
}

void StarTimer::endTick()
{
	// std::cout << "Total spend time :"<<(*this).time4Testing - getTime() << std::endl;

//#ifdef ANDROID
//	LOGE("---Total time---\n %llu\n %llu\n %llu\n",(*this).time4Testing, getTime(),(unsigned long long)getTime()-time4Testing) ;
//#elif IOS
//	printf("---Total time---\n %llu\n %llu\n %llu\n",(*this).time4Testing, getTime(),(unsigned long long)getTime()-time4Testing) ;
//#endif
    
#ifdef ANDROID
	LOGE("---%s takes ---\n%llu\n",nameForTesting,(unsigned long long)getTime()-timeForTesting) ;
#elif IOS
	printf("---%s takes ---\n%llu\n",nameForTesting,(unsigned long long)getTime()-timeForTesting) ;
#endif
}
