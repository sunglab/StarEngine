//
//  StarBuffer.h
//  StarEngine
//
//  Created by sungwoo choi on 8/22/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef StarEngine_StarFBO_h
#define StarEngine_StarFBO_h

#ifdef ANDROID
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#elif IOS
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#endif


class StarFBO
{
    public:
    //ColorRenderbuffer Setting
    StarFBO();
    //ETC Renderbuffers and Framebuffer Setting
    void  createFBO(bool depth=0, bool stencil=0,int width=0,int height=0);

    //Binding 2 buffers
    void  bindingColorbuffer();
    void  bindingFramebuffer();
    
    private:

};
#endif
