//
//  StarFBO.cpp
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

    fbo = std::unique_ptr<unsigned int[]>(new unsigned int[0]);
    rboColor = std::unique_ptr<unsigned int[]>(new unsigned int[0]);
    rboDepth = std::unique_ptr<unsigned int[]>(new unsigned int[0]);
    vbo = std::unique_ptr<unsigned int[]>(new unsigned int[0]);
    vao = std::unique_ptr<unsigned int[]>(new unsigned int[0]);

#ifdef IOS
	glGenRenderbuffers(1, &rboColor[0]);
	glBindRenderbuffer(GL_RENDERBUFFER, rboColor[0]);
#elif MAC
#elif ANDROID
#elif _WIN32

	glGenRenderbuffers(1, &rboColor[0]);
	glBindRenderbuffer(GL_RENDERBUFFER, rboColor[0]);

#endif
}

StarFBO::StarFBO(unsigned int fbo_number, unsigned int vbo_number, unsigned int vao_number)
{
    
    fbo = std::unique_ptr<unsigned int[]>(new unsigned int[fbo_number]);
    rboColor = std::unique_ptr<unsigned int[]>(new unsigned int[fbo_number]);
    rboDepth = std::unique_ptr<unsigned int[]>(new unsigned int[fbo_number]);
    vbo = std::unique_ptr<unsigned int[]>(new unsigned int[vbo_number]);
    vao = std::unique_ptr<unsigned int[]>(new unsigned int[vao_number]);
    
    for(int i=0;i<fbo_number;i++)
    {
        fbo[i] = 0;
        rboColor[i] = 0;
        rboDepth[i] = 0;
    }
    
    for(int i=0;i<vbo_number;i++)
    {
        vbo[i] = 0;
    }
    
    for(int i=0;i<vao_number;i++)
    {
        vao[i] = 0;
    }
    
#ifdef IOS
	glGenRenderbuffers(1, &rboColor[0]);
	glBindRenderbuffer(GL_RENDERBUFFER, rboColor[0]);
#elif ANDROID
	glGenRenderbuffers(1, &rboColor[0]);
	glBindRenderbuffer(GL_RENDERBUFFER, rboColor[0]);
#elif MAC
	glGenRenderbuffers(1, &rboColor[0]);
	glBindRenderbuffer(GL_RENDERBUFFER, rboColor[0]);
#elif _WIN32
	glGenRenderbuffers(1, &rboColor[0]);
	glBindRenderbuffer(GL_RENDERBUFFER, rboColor[0]);
#endif
	// After that, It must be called [context renderbufferstorage]  // IOS

}

StarFBO::~StarFBO()
{
}

void StarFBO::createFBO(bool depth, bool stencil, unsigned int width, unsigned int height, unsigned int object_id, GLenum colorInternalFormat)
{
    stencil = false; // TODO : no stencil
    int err;
	if (object_id) // if it >= 0, it means 'main'
	{
		glGenFramebuffers(1, &fbo[object_id]);
		glBindFramebuffer(GL_FRAMEBUFFER, fbo[object_id]);

		glGenRenderbuffers(1, &rboColor[object_id]);
		glBindRenderbuffer(GL_RENDERBUFFER, rboColor[object_id]);

#ifdef ANDROID
		glRenderbufferStorage(GL_RENDERBUFFER, colorInternalFormat, width, height);
#elif IOS
		glRenderbufferStorage(GL_RENDERBUFFER, colorInternalFormat, width, height);
#else // Windows & OSX
		glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA8, width, height);
#endif

		if (depth)
		{ // Create the depth buffer.
			glGenRenderbuffers(1, &rboDepth[object_id]);
			glBindRenderbuffer(GL_RENDERBUFFER, rboDepth[object_id]);
#ifdef ANDROID
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8_OES, width, height);
#elif IOS
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8_OES, width, height);
#else
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
#endif
		}
        
		glBindFramebuffer(GL_FRAMEBUFFER, fbo[object_id]);
		// Attach ColorRenderbuffers
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, rboColor[object_id]);
        
		if (depth)
			// Attach DepthRenderbuffers
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rboDepth[object_id]);
        if (stencil)
            // Attach Stencil Renderbuffers
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rboDepth[object_id]);

	}
	else  // MAIN FBO
	{
#ifdef IOS
		if (depth)
		{ // Create the depth buffer.
			glGenRenderbuffers(1, &rboDepth[object_id]);
			glBindRenderbuffer(GL_RENDERBUFFER, rboDepth[object_id]);
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8_OES, width, height);
		}
		if (stencil)
		{
			//Create the stencil buffer)
			//                glGenRenderbuffers(1, &rboStencil[object_id]);
			//                glBindRenderbuffer(GL_RENDERBUFFER, rboStencil[object_id]);
			//                glRenderbufferStorage(GL_RENDERBUFFER, GL_STENCIL_INDEX8,width, height);
		}
		glGenFramebuffers(1, &fbo[object_id]);
		//glBindRenderbuffer(GL_RENDERBUFFER, rboColor[object_id]);
#else // if not IOS
		fbo[object_id] = 0;
#endif

#ifdef IOS
		glBindFramebuffer(GL_FRAMEBUFFER, fbo[object_id]);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, rboColor[object_id]);
		if (depth)
			// Attach DepthRenderbuffers
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rboDepth[object_id]);
        if (stencil)
            // Attach Stencil Renderbuffers
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rboDepth[object_id]);
#endif
	}
//	glBindRenderbuffer(GL_RENDERBUFFER, rboColor[object_id]);
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

#if defined(MAC) || defined(_WIN32)
void StarFBO::createFBO_MS(bool depth, bool stencil, unsigned int width, unsigned int height, unsigned int fbo_idx, unsigned int numOfMS)
{
	if (fbo_idx) // if it >= 0, it means 'main'
	{
		glGenFramebuffers(1, &fbo[fbo_idx]);
		glBindFramebuffer(GL_FRAMEBUFFER, fbo[fbo_idx]);

	//	glGenRenderbuffers(1, &rboColor[fbo_idx]);
	//	glBindRenderbuffer(GL_RENDERBUFFER, rboColor[fbo_idx]);

//		glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA8, width, height);
//		glRenderbufferStorage(GL_)

		if (depth)
		{ // Create the depth buffer.
			glGenRenderbuffers(1, &rboDepth[fbo_idx]);
			glBindRenderbuffer(GL_RENDERBUFFER, rboDepth[fbo_idx]);
//			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
			glRenderbufferStorageMultisample(GL_RENDERBUFFER, numOfMS, GL_DEPTH_COMPONENT, width, height);

		}

		glBindFramebuffer(GL_FRAMEBUFFER, fbo[fbo_idx]);

		if (depth)
			// Attach DepthRenderbuffers
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rboDepth[fbo_idx]);

	}
	else  // MAIN FBO
	{
		fbo[fbo_idx] = 0;

	}
//	glBindRenderbuffer(GL_RENDERBUFFER, rboColor[object_id]);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo[fbo_idx]);
}

void StarFBO::blit(Vec4 src, Vec4 dst, int mask, int filter)

{
	glBlitFramebuffer(
		src[0], src[1], src[2], src[3],
		dst[0], dst[1], dst[2], dst[3],
		mask, filter
	);
}

void StarFBO::unbindFBO_Blit()
{
	glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
}

void StarFBO::bindFBO_Blit(unsigned int from_fbo_idx, unsigned int to_fbo_idx)
{
	glBindFramebuffer(GL_READ_FRAMEBUFFER, fbo[from_fbo_idx]);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbo[to_fbo_idx]);
}
#endif

/*
 RBO
 */
void StarFBO::bindRBO(unsigned int object_id, bool depth, bool stencil)
{
	if (object_id)
	{
		glBindRenderbuffer(GL_RENDERBUFFER, rboColor[object_id]);
		if (depth)
			glBindRenderbuffer(GL_RENDERBUFFER, rboDepth[object_id]);
	}
	else
	{
		glBindRenderbuffer(GL_RENDERBUFFER, rboColor[object_id]);
#ifndef IOS //|ANDROID)
		if (depth)
			glBindRenderbuffer(GL_RENDERBUFFER, rboDepth[object_id]);
#endif

	}
}

void StarFBO::unbindRBO()
{
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
}


void StarFBO::resizeRBO(unsigned int width, unsigned int height)
{
#ifdef ANDROID
	glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA8_OES, width, height);
#elif IOS
	glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA8_OES, width, height);
#else
	glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA8, width, height);
#endif

	// maybe an error if has not depth
#ifdef ANDROID
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8_OES, width, height);
#elif IOS
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8_OES, width, height);
#else
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
#endif
}

/*
 VAO
 */
void StarFBO::createVAO(unsigned int object_id)
{
	// 'cuase it doesn't support opengl es 2.0
#ifdef MAC
	glGenVertexArrays(1, &vao[object_id]);
	glBindVertexArray(vao[object_id]);
#elif _WIN32
	glGenVertexArrays(1, &vao[object_id]);
	glBindVertexArray(vao[object_id]);
#else
	glGenVertexArraysOES(1, &vao[object_id]);
	glBindVertexArrayOES(vao[object_id]);
#endif
}

void StarFBO::bindVAO(unsigned int object_id)
{
#ifdef MAC
	glBindVertexArray(vao[object_id]);
#elif _WIN32
	glBindVertexArray(vao[object_id]);
#else
	glBindVertexArrayOES(vao[object_id]);
#endif
}
void StarFBO::unbindVAO()
{
#ifdef MAC
	glBindVertexArray(0);
#elif _WIN32
	glBindVertexArray(0);
#else
	glBindVertexArrayOES(0);
#endif
}

/*
 VBO
 */
void StarFBO::createVBO(unsigned int target, unsigned int size, void* data, unsigned int dataType, unsigned int object_id)
{
	glGenBuffers(1, &vbo[object_id]);
	glBindBuffer(target, vbo[object_id]);
	glBufferData(target, size, data, dataType);
}
void StarFBO::createVBOsub(unsigned int target, unsigned int offset, unsigned int size, void* data, unsigned int dataType, unsigned int object_id)
{
	glGenBuffers(1, &vbo[object_id]);
	glBindBuffer(target, vbo[object_id]);
	glBufferData(target, size, (void*)0, dataType);
	glBufferSubData(target, offset, size, data);
}
void StarFBO::createVAO_INDI(unsigned int* object_id)
{
	// 'cuase it doesn't support opengl es 2.0
#ifdef MAC
	glGenVertexArrays(1, object_id);
	glBindVertexArray(*object_id);
#elif _WIN32
	glGenVertexArrays(1, object_id);
	glBindVertexArray(*object_id);
#else
	glGenVertexArraysOES(1, object_id);
	glBindVertexArrayOES(*object_id);
#endif
}

void StarFBO::createVBOsub_INDI(unsigned int target, unsigned int offset, unsigned int size, void* data, unsigned int dataType, unsigned int* object_id)
{
	glGenBuffers(1, object_id);
	glBindBuffer(target, *object_id);
	glBufferData(target, size, (void*)0, dataType);
	glBufferSubData(target, offset, size, data);
}
void StarFBO::createVBO_INDI(unsigned int target, unsigned int size, void* data, unsigned int dataType, unsigned int* object_id)
{
	glGenBuffers(1, object_id);
	glBindBuffer(target, *object_id);
	glBufferData(target, size, data, dataType);
}
void StarFBO::bindVAO_INDI(unsigned int* object_id)
{
#ifdef MAC
	glBindVertexArray(*object_id);
#elif _WIN32
	glBindVertexArray(*object_id);
#else
	glBindVertexArrayOES(*object_id);
#endif
}
void StarFBO::bindVBO_INDI(unsigned int target, unsigned int* object_id)
{
	glBindBuffer(target, *object_id);
}

void StarFBO::bindVBO(unsigned int target, unsigned int object_id)
{
	glBindBuffer(target, vbo[object_id]);
}
void StarFBO::unbindVBO(unsigned int target)
{
	glBindBuffer(target, 0);
}

