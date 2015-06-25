//
//  StarBuffer.cpp
//  StarEngine
//
//  Created by sungwoo choi on 8/22/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#include "StarFBO.h"

/*
 FBO
 */
StarFBO::StarFBO()
{
    
    fbo = new unsigned int[0];
    rboColor = new unsigned int[0];
    rboDepth = new unsigned int[0];
    //    rboStencil = new unsigned int[0]; //it was combined with Depth buffer Object
    vbo = new unsigned int[0];
    vao = new unsigned int[0];
    
#ifdef IOS
    glGenRenderbuffers(1, &rboColor[0]);
    glBindRenderbuffer(GL_RENDERBUFFER, rboColor[0]);
#elif MAC
#elif ANDROID
#endif
}

StarFBO::StarFBO(unsigned int fbo_number,unsigned int vbo_number,unsigned int vao_number)
{
    
    fbo = new unsigned int[fbo_number];
    rboColor = new unsigned int[fbo_number];
    rboDepth = new unsigned int[fbo_number];
    //    rboStencil = new unsigned int[fbo_number];
    vbo = new unsigned int[vbo_number];
    vao = new unsigned int[vao_number];
    
    
#ifdef IOS
    glGenRenderbuffers(1, &rboColor[0]);
    glBindRenderbuffer(GL_RENDERBUFFER, rboColor[0]);
#elif MAC
    glGenRenderbuffers(1, &rboColor[0]);
    glBindRenderbuffer(GL_RENDERBUFFER, rboColor[0]);
#elif ANDROID
    glGenRenderbuffers(1, &rboColor[0]);
    glBindRenderbuffer(GL_RENDERBUFFER, rboColor[0]);
#endif
    // After that, It might be called [context renderbufferstorage]  // IOS
    
}

StarFBO::~StarFBO()
{
    delete[] vbo;
    delete[] vao;
    delete[] fbo;
    delete[] rboColor;
    delete[] rboDepth;
}

void StarFBO::createFBO(bool depth, bool stencil,unsigned int width, unsigned int height,unsigned int object_id )
{
    
    if (object_id) // Not a main on buffer
    {
        glGenFramebuffers(1, &fbo[object_id]);
        glBindFramebuffer(GL_FRAMEBUFFER, fbo[object_id]);
        
        glGenRenderbuffers(1, &rboColor[object_id]);
        glBindRenderbuffer(GL_RENDERBUFFER, rboColor[object_id]);
        
#ifdef ANDROID
        glRenderbufferStorage(GL_RENDERBUFFER,GL_RGBA8_OES, width, height);
#elif IOS
        glRenderbufferStorage(GL_RENDERBUFFER,GL_RGBA8_OES, width, height);
#else
        glRenderbufferStorage(GL_RENDERBUFFER,GL_RGBA8, width, height);
#endif
        
        if(depth)
        { // Create the depth buffer.
            glGenRenderbuffers(1, &rboDepth[object_id]);
            glBindRenderbuffer(GL_RENDERBUFFER, rboDepth[object_id]);
#ifdef ANDROID
            glRenderbufferStorage(GL_RENDERBUFFER,GL_DEPTH24_STENCIL8_OES, width, height);
#elif IOS
            glRenderbufferStorage(GL_RENDERBUFFER,GL_DEPTH24_STENCIL8_OES, width, height);
#else
            glRenderbufferStorage(GL_RENDERBUFFER,GL_DEPTH24_STENCIL8, width, height);
#endif
        }
        if(stencil)
        {
            //            //Create the stencil buffer.
            //            glGenRenderbuffers(1, &rboStencil[object_id]);
            //            glBindRenderbuffer(GL_RENDERBUFFER, rboStencil[object_id]);
            //            glRenderbufferStorage(GL_RENDERBUFFER, GL_STENCIL_IN, width, height);
        }
        
        glBindFramebuffer(GL_FRAMEBUFFER, fbo[object_id]);
        
        // Attach ColorRenderbuffers
        glFramebufferRenderbuffer(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_RENDERBUFFER,rboColor[object_id]);
        
        if(depth)
            // Attach DepthRenderbuffers
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER,rboDepth[object_id]);
        if(stencil)
            // Attach Stencil Renderbuffers
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rboDepth[object_id]);
        
        
    }
    else  // MAIN FBO
    {
#ifdef IOS
        if(depth)
        { // Create the depth buffer.
            glGenRenderbuffers(1, &rboDepth[object_id]);
            glBindRenderbuffer(GL_RENDERBUFFER, rboDepth[object_id]);
            glRenderbufferStorage(GL_RENDERBUFFER,GL_DEPTH24_STENCIL8_OES, width, height);
        }
        if(stencil)
        {
            //Create the stencil buffer)
            //                glGenRenderbuffers(1, &rboStencil[object_id]);
            //                glBindRenderbuffer(GL_RENDERBUFFER, rboStencil[object_id]);
            //                glRenderbufferStorage(GL_RENDERBUFFER, GL_STENCIL_INDEX8,width, height);
        }
        glGenFramebuffers(1, &fbo[object_id]);
        //    glBindRenderbuffer(GL_RENDERBUFFER, rboColor[object_id]);
#elif MAC
        fbo[object_id] = 0;
#elif ANDROID
        fbo[object_id] = 0;
#endif
#ifdef IOS
        glBindFramebuffer(GL_FRAMEBUFFER, fbo[object_id]);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_RENDERBUFFER,rboColor[object_id]);
        if(depth)
            // Attach DepthRenderbuffers
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER,rboDepth[object_id]);
        if(stencil)
            // Attach Stencil Renderbuffers
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rboDepth[object_id]);
#endif
    }
    //    glBindRenderbuffer(GL_RENDERBUFFER, rboColor[object_id]);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo[object_id]);
    
}

void StarFBO::bindFBO(unsigned int object_id)
{
    glBindFramebuffer(GL_FRAMEBUFFER, fbo[object_id]);
    
    
}
void StarFBO::unbindFBO()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}


/*
 RBO
 */
void StarFBO::bindRBO(unsigned int object_id)
{
    glBindRenderbuffer(GL_RENDERBUFFER, rboColor[object_id]);
    glBindRenderbuffer(GL_RENDERBUFFER, rboDepth[object_id]);
}
void StarFBO::unbindRBO()
{
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

void StarFBO::resizeRBO(unsigned int width, unsigned int height)
{
#ifdef ANDROID
    glRenderbufferStorage(GL_RENDERBUFFER,GL_RGBA8_OES, width, height);
#elif IOS
    glRenderbufferStorage(GL_RENDERBUFFER,GL_RGBA8_OES, width, height);
#else
    glRenderbufferStorage(GL_RENDERBUFFER,GL_RGBA8, width, height);
#endif
    
#ifdef ANDROID
    glRenderbufferStorage(GL_RENDERBUFFER,GL_DEPTH24_STENCIL8_OES, width, height);
#elif IOS
    glRenderbufferStorage(GL_RENDERBUFFER,GL_DEPTH24_STENCIL8_OES, width, height);
#else
    glRenderbufferStorage(GL_RENDERBUFFER,GL_DEPTH24_STENCIL8, width, height);
#endif
}

/*
 VAO
 */
void StarFBO::createVAO(unsigned int object_id)
{
    // 'cuase it doesn't support opengl es 2.0
#ifdef MAC
    glGenVertexArrays(1,&vao[object_id]);
    glBindVertexArray(vao[object_id]);
#elif IOS
    glGenVertexArraysOES(1,&vao[object_id]);
    glBindVertexArrayOES(vao[object_id]);
#elif ANDROID
    //    glGenVertexArraysOES(1,&vao[object_id]);
    //	glBindVertexArrayOES(vao[object_id]);
#endif
}
void StarFBO::bindVAO(unsigned int object_id)
{
#ifdef MAC
    glBindVertexArray(vao[object_id]);
#elif IOS
    glBindVertexArrayOES(vao[object_id]);
#elif ANDROID
    //    glBindVertexArrayOES(vao[object_id]);
#endif
}
void StarFBO::unbindVAO()
{
#ifdef MAC
    glBindVertexArray(0);
#elif IOS
    glBindVertexArrayOES(0);
#elif ANDROID
    //    glBindVertexArrayOES(0);
#endif
}

/*
 VBO
 */
void StarFBO::createVBO(unsigned int target,unsigned int size, void* data, unsigned int dataType, unsigned int object_id)
{
    glGenBuffers( 1, &vbo[object_id]);
    glBindBuffer( target, vbo[object_id]);
    glBufferData( target, size, data, dataType);
}
void StarFBO::createVBOsub(unsigned int target, unsigned int offset, unsigned int size, void* data, unsigned int dataType,unsigned int object_id)
{
    glGenBuffers( 1, &vbo[object_id]);
    glBindBuffer( target, vbo[object_id]);
    glBufferData( target, size, (void*)0, dataType);
    glBufferSubData(target, offset, size, data);
}
void StarFBO::bindVBO(unsigned int target, unsigned int object_id)
{
    glBindBuffer( target, vbo[object_id]);
}
void StarFBO::unbindVBO(unsigned int target)
{
    glBindBuffer(target,0);
}

