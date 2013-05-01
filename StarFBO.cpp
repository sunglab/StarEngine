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



StarFBO::StarFBO()
{
#ifdef ANDROID
    LOGE("Created RederColorbuffer");
#elif IOS
    std::cout << "Created RederColorbuffer\n" <<std::endl;
    
#endif

    // Create the renderbuffer object.
    glGenRenderbuffers(1, &s_ColorRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, s_ColorRenderBuffer);
}

void StarFBO::createFBO(bool depth, bool stencil,int width, int height)
{   

    if(depth)
    { // Create the depth buffer.
    glGenRenderbuffers(1, &s_DepthRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, s_DepthRenderBuffer);
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
                              s_DepthRenderBuffer);
    }
    // Bind the color buffer for rendering.
    glBindRenderbuffer(GL_RENDERBUFFER, s_ColorRenderBuffer);


}

void StarFBO::createFBObyBack(bool depth, bool stencil,int width, int height)
{
    // Create the renderbuffer object.
    glGenRenderbuffers(1, &b1_ColorRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, b1_ColorRenderBuffer);
    
    if(depth)
    { // Create the depth buffer.
        glGenRenderbuffers(1, &b1_DepthRenderBuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, b1_DepthRenderBuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, width, height);
    }
    if(stencil)
    {
        //Create the stencil buffer.
    }
    
    // Create the framebuffer object.
    glGenFramebuffers(1, &b1_FrameBuffer);
#ifdef IOS
    glBindFramebuffer(GL_FRAMEBUFFER, b1_FrameBuffer);
#elif ANDROID
    glBindFramebuffer(GL_FRAMEBUFFER, b1_FrameBuffer);
#endif
    // Attach ColorRenderbuffers
    glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                              GL_COLOR_ATTACHMENT0,
                              GL_RENDERBUFFER,
                              b1_ColorRenderBuffer);
    
    if(depth)
    {// Attach DepthRenderbuffers
        glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                                  GL_DEPTH_ATTACHMENT,
                                  GL_RENDERBUFFER,
                                  b1_DepthRenderBuffer);
    }
}
void StarFBO::createFBObyBackSecond(bool depth, bool stencil,int width, int height)
{
    // Create the renderbuffer object.
    glGenRenderbuffers(1, &b2_ColorRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, b2_ColorRenderBuffer);
    
    if(depth)
    { // Create the depth buffer.
        glGenRenderbuffers(1, &b2_DepthRenderBuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, b2_DepthRenderBuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, width, height);
    }
    if(stencil)
    {
        //Create the stencil buffer.
    }
    
    // Create the framebuffer object.
    glGenFramebuffers(1, &b2_FrameBuffer);
#ifdef IOS
    glBindFramebuffer(GL_FRAMEBUFFER, b2_FrameBuffer);
#elif ANDROID
    glBindFramebuffer(GL_FRAMEBUFFER, b2_FrameBuffer);
#endif
    // Attach ColorRenderbuffers
    glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                              GL_COLOR_ATTACHMENT0,
                              GL_RENDERBUFFER,
                              b2_ColorRenderBuffer);
    
    if(depth)
    {// Attach DepthRenderbuffers
        glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                                  GL_DEPTH_ATTACHMENT,
                                  GL_RENDERBUFFER,
                                  b2_DepthRenderBuffer);
    }
}

/* This is Off Frame & Render Buffers binding
 */
void StarFBO::bindingColorBackbuffer()
{
    glBindRenderbuffer(GL_RENDERBUFFER, b1_ColorRenderBuffer);
}
void StarFBO::bindingFrameBackbuffer()
{
#ifdef IOS
    glBindFramebuffer(GL_FRAMEBUFFER, b1_FrameBuffer);
#elif ANDROID
    glBindFramebuffer(GL_FRAMEBUFFER, b1_FrameBuffer);
#endif
}

void StarFBO::bindingColorBackbufferSecond()
{
    glBindRenderbuffer(GL_RENDERBUFFER, b2_ColorRenderBuffer);
}
void StarFBO::bindingFrameBackbufferSecond()
{
#ifdef IOS
    glBindFramebuffer(GL_FRAMEBUFFER, b2_FrameBuffer);
#elif ANDROID
    glBindFramebuffer(GL_FRAMEBUFFER, b2_FrameBuffer);
#endif
}

void StarFBO::bindingColorBackbufferRelease()
{
    glBindRenderbuffer(GL_RENDERBUFFER,0);
}
void StarFBO::bindingFrameBackbufferRelease()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}



/* This is On Frame & Render Buffers binding
 */
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
void StarFBO::bindingColorbufferRelease()
{
    glBindRenderbuffer(GL_RENDERBUFFER,0);
}
void StarFBO::bindingFramebufferRelease()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}



