//
//  StarView.hpp
//  MusicArtButton
//
//  Created by Sungwoo Choi on 5/25/16.
//  Copyright © 2016 SungLab. All rights reserved.
//

#ifndef StarView_hpp
#define StarView_hpp

#include <stdio.h>
#include "../StarMain.h"

//#include "StarString.h" // connect with
class StarTexture;
class StarFBO;
class StarShader;
class StarView
{
protected:
    
    int fbo_id[3]; // for rtt, prepared
    int vao_id;
    int vbo_id[10]; // position, uv, index, normal
    int err; // for opengl errors
    
    GLuint shader_program;
    GLuint fs_id;
    GLuint vs_id;
    
    GLuint attribute_id[10]; // position & uv
    GLuint uniform_id[10]; // matrix
    GLuint texture_id[4]; // 0 : normal, 1: click
    
    GLuint texture_number[4];
    
    StarFBO* starfbo;
    StarTexture* startexture;
    StarShader* starshader;
    
    StarTouch* startouch;
    
    Matrix final_matrix; // at least one
    
    bool initialed;
    bool offscreen; // for rtt
    
    Vec2 center;
    Vec4 rect;
    
    unsigned int height;
    unsigned int width;
    
    unsigned int fbo_height;
    unsigned int fbo_width;
    
    double now_tick;
    
public:
    
    void setStars(StarFBO* _starfbo, StarShader* _starshader, StarTouch* _startouch = 0)
    {
        offscreen = false;

        starfbo = _starfbo;
        starshader = _starshader;
        startouch = _startouch;
    }
    
    void setFBOsize(float _fbo_width,float _fbo_height) //??
    {
        fbo_width=_fbo_width; fbo_height=_fbo_height;
    };
    
    void setPosition(float x,float y,float width, float height)
    {
        rect = Vec4(x,y,width,height);
    };
    
    void setTextureID(StarTexture* _startexture, unsigned int _texture_id, unsigned int _texture_number=0)
    {
        startexture =_startexture;
        texture_id[_texture_number] = _texture_id;
    };

    virtual void init()=0;
    virtual void update()=0;
    virtual void render()=0;
    virtual void done()=0;
    
    void CallbackFPS(){};
    void CallbackTouchBegin(){};
    void CallbackTouchMove(){};
    void CallbackTouchEnd(){};
    void CallbackTouchCancel(){};
    
//    virtual void CallbackFPS(float t)=0;
//    virtual void CallbackTICK(float dt)=0;
//    virtual void CallbackTouchBegin()=0;
//    virtual void CallbackTouchMove()=0;
//    virtual void CallbackTouchEnd()=0;
//    virtual void CallbackTouchCancel()=0;
    
};


#endif /* StarView_hpp */
