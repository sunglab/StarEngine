//
//  StarBuffer.h
//  StarEngine
//
//  Created by sungwoo choi on 8/22/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef StarEngine_StarFBO_h
#define StarEngine_StarFBO_h

#include "../StarMain.h"

class StarFBO
{
    // IDs
    private:
    GLuint s_FrameBuffer;
    GLuint s_ColorRenderBuffer;
    GLuint s_DepthRenderBuffer;
    
    GLuint b1_FrameBuffer;
    GLuint b1_ColorRenderBuffer;
    GLuint b1_DepthRenderBuffer;
    
    GLuint b2_FrameBuffer;
    GLuint b2_ColorRenderBuffer;
    GLuint b2_DepthRenderBuffer;
   
    GLuint b3_FrameBuffer;
    GLuint b3_ColorRenderBuffer;
    GLuint b3_DepthRenderBuffer;
    
    public:
    //ColorRenderbuffer Setting
    StarFBO();
    //ETC Renderbuffers and Framebuffer Setting
    void  createFBO(bool depth=0, bool stencil=0,int width=0,int height=0);
    void  createFBObyBackFirst(bool depth=0, bool stencil=0,int width=0,int height=0);
    void  createFBObyBackSecond(bool depth=0, bool stencil=0,int width=0,int height=0);
    void  createFBObyBackThird(bool depth=0, bool stencil=0,int width=0,int height=0);

    //Binding to  Onscreen Buffers
    void  bindingColorbuffer();
    void  bindingFramebuffer();
    
    //Release to Onscreen Buffers
    void  bindingColorbufferRelease();
    void  bindingFramebufferRelease();
    
    //Binding to Offscreen buffers
    void  bindingColorBackbufferFirst();
    void  bindingFrameBackbufferFirst();
        
    //Binding to Offscreen buffers
    void  bindingColorBackbufferSecond();
    void  bindingFrameBackbufferSecond();
    
    //Binding to Offscreen buffers
    void  bindingColorBackbufferThird();
    void  bindingFrameBackbufferThird();
    
    //Release to Offscreen buffers
    void  bindingColorBackbufferRelease();
    void  bindingFrameBackbufferRelease();

};
#endif
