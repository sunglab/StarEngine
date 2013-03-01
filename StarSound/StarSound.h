//
//  StarSound.h
//  StarEngine
//
//  Created by sungwoo choi on 9/5/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef StarEngine_StarSound_h
#define StarEngine_StarSound_h

#ifdef ANDROID

#include <AL/al.h>
#include <AL/alc.h>
#include <ivorbisfile.h>

#include <android/log.h>
#include <jni.h>

#include <stddef.h>
#include <assert.h>
#include <string.h>
#include <time.h>


#elif IOS

//#import <AVFoundation/AVFoundation.h>
//#import <OpenAL/al.h>
//#import <OpenAL/alc.h>

#endif

class StarSound
{
#ifdef ANDROID
private:
public:
    void Create_Sound(jarray data);
#elif IOS
#endif
};
#endif
