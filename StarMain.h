//
//  StarMain.h
//
//  Created by sungwoo choi on 8/25/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef StarEngine_Main_Header
#define StarEngine_Main_Header

#ifdef __cplusplus
#include <algorithm>
#include <vector>
#endif

// IOS
#if defined(IOS)
#ifndef METAL
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#import <UIKit/UIKit.h>
#include <iostream>
#import "GLView.h"
#endif
#endif

// ANDROID
#ifdef ANDROID

#include <android/log.h>
#include <jni.h>

#define GL_GLEXT_PROTOTYPES
#include <GLES3/gl3.h>
#include <GLES2/gl2ext.h>
#include <GLES3/gl31.h>

/*
// GLES 2.0
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
*/

#include <stdlib.h>
#include <string.h>
#include <iostream>
#define LOG_TAG "StarEngine"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#endif

#if (StarQt)
#include <QOpenGLBuffer>
#include <QOpenGLFramebufferObject>
#include <QOpenGLFunctions>

#endif
// MAC
#if (MAC && !StarQt)
#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>
#import <OpenGL/glext.h>
#elif _WIN32  //Windows

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <gl/glu.h>

#include <stdio.h>
#include <cstdlib>
#include <string>

void winprintf(const char* fmt, ...);
#endif

//OS Free
#include "./math/StarMath.h"
#include "./tool/StarTimer.h"
#include "./tool/StarTouch.h"
#include "./tool/StarUtil.h"

#ifndef METAL
#include "./renderer/StarFBO.h"
#include "./renderer/StarShader.h"
#include "./renderer/StarTexture.h"

#include "./ai/StarAnt.h"
#include "./geometry/StarGeo.h"
#include "./geometry/StarMesh.h"
#include "./geometry/StarOBJ.h"
#include "./geometry/StarStructure.h"

#include "./ui/StarScene.h"
#include "./ui/StarView.h"
#include "./effect/StarEffect.h"
#endif


#define ToInt(x) static_cast<int>(x)
#define ToUInt(x) static_cast<unsigned int>(x)
#define ToLong(x) static_cast<long>(x)
#define ToFloat(x) static_cast<float>(x)
#define ToDouble(x) static_cast<double>(x)

#define STRINGIFY(A) #A
#define XSTRINGIFY(A) STRINGIFY(A)

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
