//
//  StarMain.h
//
//  Created by sungwoo choi on 8/25/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef StarEngine_Main_Header
#define StarEngine_Main_Header

class starengine;

#ifdef __cplusplus
//#include <memory>
#include <algorithm>
#endif


// IOS
 #ifdef IOS
#import "GLView.h"
#import <UIKit/UIKit.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#include <iostream>
 #endif

// ANDROID
#ifdef ANDROID

#include <jni.h>
#include <android/log.h>

#define GL_GLEXT_PROTOTYPES
#include <GLES3/gl3.h>
#include <GLES2/gl2ext.h>
#include <GLES3/gl31.h>

//#endif

/*
// GLES 2.0
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
*/

#include <stdlib.h>
#include <iostream>
#include <string.h>
#define  LOG_TAG    "StarEngine"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__) 
#endif

#if (StarQt)
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLFramebufferObject>

#endif
// MAC
#if (MAC && !StarQt)
#import <OpenGL/gl3.h>
#import <OpenGL/glext.h>
#import <Cocoa/Cocoa.h>
#elif _WIN32 //Windows

#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <gl/glu.h>

#include <stdio.h>
#include <string>
#include <cstdlib>

void winprintf(const char *fmt, ...);
#endif

// OS FREE
#include "./renderer/StarShader.h"
#include "./renderer/StarFBO.h"
#include "./renderer/StarTexture.h"
#include "./math/StarMath.h"
#include "./tool/StarTimer.h"
#include "./tool/StarTouch.h"
#include "./tool/StarUtil.h"

#include "./effect/StarEffect.h"
#include "./effect/StarParticle.h"
#include "./geometry/StarStructure.h"
#include "./geometry/StarOBJ.h"
#include "./geometry/StarGeo.h"
#include "./geometry/StarMesh.h"
#include "./ai/StarAnt.h"

#include "./ui/StarView.h"
#include "./cv/StarCV.h"
#include "./ui/StarScene.h"


#define ToInt(x) static_cast<int>(x)
#define ToUInt(x) static_cast<unsigned int>(x)
#define ToLong(x) static_cast<long>(x)
#define ToFloat(x) static_cast<float>(x)
#define ToDouble(x) static_cast<double>(x)

#define STRINGIFY(A)  #A

#if StarQt
#define starLOG qDebug
#elif IOS
#define starLOG printf
#elif MAC
#define starLOG printf
#elif ANDROID
#define starLOG LOGE
#elif _WIN32
#define starLOG winprintf
#endif

#endif
