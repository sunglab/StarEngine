//
//  StarBuffer.cpp
//  StarEngine
//
//  Created by sungwoo choi on 8/22/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#include "StarFBO.h"


StarFBO::StarFBO()
{
#ifdef ANDROID
    LOGE("Created RederColorbuffer");
#elif IOS
    printf("Created RederColorbuffer\n");
#endif

    // Create the renderbuffer object.
    glGenRenderbuffers(1, &s_ColorRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, s_ColorRenderBuffer);
    
    // after that, It might be called [context renderbufferstorage]
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
    //glBindRenderbuffer(GL_RENDERBUFFER, s_ColorRenderBuffer);


}

void StarFBO::createFBObyBackFirst(bool depth, bool stencil,int width, int height)
{
    // Create the framebuffer object.
    glGenFramebuffers(1, &b1_FrameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, b1_FrameBuffer);
    
//    // Create the renderbuffer object.
    glGenRenderbuffers(1, &b1_ColorRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, b1_ColorRenderBuffer);
    glRenderbufferStorage(GL_RENDERBUFFER,GL_RGBA8_OES, width, height);
    
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

    
    if(depth)
    {// Attach DepthRenderbuffers
        glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                                  GL_DEPTH_ATTACHMENT,
                                  GL_RENDERBUFFER,
                                  b1_DepthRenderBuffer);
    }
    
    // Attach ColorRenderbuffers
    glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                              GL_COLOR_ATTACHMENT0,
                              GL_RENDERBUFFER,
                              b1_ColorRenderBuffer);
}
void StarFBO::createFBObyBackSecond(bool depth, bool stencil,int width, int height)
{
    // Create the framebuffer object.
    glGenFramebuffers(1, &b2_FrameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, b2_FrameBuffer);
   
    // Create the renderbuffer object.
    glGenRenderbuffers(1, &b2_ColorRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, b2_ColorRenderBuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA8_OES, width, height);
    
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

    
    if(depth)
    {// Attach DepthRenderbuffers
        glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                                  GL_DEPTH_ATTACHMENT,
                                  GL_RENDERBUFFER,
                                  b2_DepthRenderBuffer);
    }
    // Attach ColorRenderbuffers
    glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                              GL_COLOR_ATTACHMENT0,
                              GL_RENDERBUFFER,
                              b2_ColorRenderBuffer);
}

void StarFBO::createFBObyBackThird(bool depth, bool stencil,int width, int height)
{
    // Create the framebuffer object.
    glGenFramebuffers(1, &b3_FrameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, b3_FrameBuffer);
    
    // Create the renderbuffer object.
    glGenRenderbuffers(1, &b3_ColorRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, b3_ColorRenderBuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA8_OES, width, height);
    
    if(depth)
    { // Create the depth buffer.
        glGenRenderbuffers(1, &b3_DepthRenderBuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, b3_DepthRenderBuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, width, height);
    }
    if(stencil)
    {
        //Create the stencil buffer.
    }

    
    if(depth)
    {// Attach DepthRenderbuffers
        glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                                  GL_DEPTH_ATTACHMENT,
                                  GL_RENDERBUFFER,
                                  b3_DepthRenderBuffer);
    }
    // Attach ColorRenderbuffers
    glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                              GL_COLOR_ATTACHMENT0,
                              GL_RENDERBUFFER,
                              b3_ColorRenderBuffer);
}
/* This is Off Frame & Render Buffers binding
 */
void StarFBO::bindingColorBackbufferFirst()
{
    glBindRenderbuffer(GL_RENDERBUFFER, b1_ColorRenderBuffer);
}
void StarFBO::bindingFrameBackbufferFirst()
{
    glBindFramebuffer(GL_FRAMEBUFFER, b1_FrameBuffer);
}
void StarFBO::bindingColorBackbufferSecond()
{
    glBindRenderbuffer(GL_RENDERBUFFER, b2_ColorRenderBuffer);
}
void StarFBO::bindingFrameBackbufferSecond()
{
    glBindFramebuffer(GL_FRAMEBUFFER, b2_FrameBuffer);
}
void StarFBO::bindingColorBackbufferThird()
{
    glBindFramebuffer(GL_RENDERBUFFER, b3_ColorRenderBuffer);
}
void StarFBO::bindingFrameBackbufferThird()
{
    glBindFramebuffer(GL_FRAMEBUFFER, b3_FrameBuffer);
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



