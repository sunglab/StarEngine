//
//  StarBuffer.cpp
//  StarEngine
//
//  Created by sungwoo choi on 8/22/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#include "StarFBO.h"

//////* For Logging *///////
#ifdef ANDROID
#include <android/log.h>
#define  LOG_TAG    "StarEngine"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#elif IOS
#include <iostream>
#endif

GLuint s_FrameBuffer;
GLuint s_ColorRenderBuffer;
GLuint _DepthRenderBuffer;

StarFBO::StarFBO()
{
#ifdef ANDROID
    LOGE("Created RederColorbuffer");
#elif IOS
    std::cout << "Created RederColorbuffer" <<std::endl;
#endif
    // Create the renderbuffer object.
    glGenRenderbuffers(1, &s_ColorRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, s_ColorRenderBuffer);
}

void StarFBO::createFBO(bool depth, bool stencil,int width, int height)
{   


    if(depth)
    { // Create the depth buffer.
    glGenRenderbuffers(1, &_DepthRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, _DepthRenderBuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, width, height);
    }
    if(stencil)
    {
      //Create the stencil buffer.
    }

    // Create the framebuffer object.
    glGenFramebuffers(1, &s_FrameBuffer);
#ifdef IOS
    glBindFramebuffer(GL_FRAMEBUFFER, s_FrameBuffer);
#elif ANDROID
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
#endif
    // Attach ColorRenderbuffers
    glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                              GL_COLOR_ATTACHMENT0,
                              GL_RENDERBUFFER,
                              s_ColorRenderBuffer);

    if(depth)
    {// Attach DepthRenderbuffers
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, 
                              GL_DEPTH_ATTACHMENT, 
                              GL_RENDERBUFFER, 
                              _DepthRenderBuffer);
    }
    // Bind the color buffer for rendering.
    glBindRenderbuffer(GL_RENDERBUFFER, s_ColorRenderBuffer);


}

void StarFBO::bindingColorbuffer()
{
    glBindRenderbuffer(GL_RENDERBUFFER, s_ColorRenderBuffer);
}
void StarFBO::bindingFramebuffer()
{
#ifdef IOS
    glBindFramebuffer(GL_FRAMEBUFFER, s_FrameBuffer);
#elif ANDROID
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
#endif
}
