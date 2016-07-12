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
//    int fbo_id[3]; // for rtt, prepared
 //   int vao_id;
 //   int vbo_id[10]; // position, uv, index, normal
    int err; // for opengl errors
    
    GLuint shader_program;
    //GLuint fs_id;
    //GLuint vs_id;
    
    GLuint attribute_id[10]; // position & uv
    GLuint uniform_id[10]; // matrix
    GLuint texture_id[4]; //  from glsl
//	GLfloat texture_width;
//	GLfloat texture_height;
    
    GLuint texture_name[4]; // from my own name in enum
    
    StarFBO* starfbo;
    StarTexture* startexture;
    StarShader* starshader;
    
    StarTouch* startouch;
    
    Matrix final_matrix; // at least one
    
    bool initialed;

    Vec2 center;
    Vec4 rect;
    
    //unsigned int height;
    //unsigned int width;

    float height;
    float width;
    

/*    unsigned int fbo_height;
    unsigned int fbo_width;
 */   
    double now_tick;
    
public:
    
    StarView* setStars(StarFBO* _starfbo, StarShader* _starshader, StarTouch* _startouch = 0)
    {
        starfbo = _starfbo;
        starshader = _starshader;
        startouch = _startouch;

		return this;
	};

	StarView* setShaderID(unsigned int _id)
	{
		shader_program = _id;
		return this;
	};
    
  //  StarView* setFBOsize(float _fbo_width,float _fbo_height) // in need ?
  //  {
  //      fbo_width=_fbo_width; fbo_height=_fbo_height;
		//return this;
  //  };
    
    StarView* setPosition(float x,float y,float width, float height)
    {
        rect = Vec4(x,y,width,height);
		return this;
    };
	StarView* setScreen(float w, float h)
	{
		width = w;
		height = h;
		return this;
	}
    
    //StarView* setTextureID(StarTexture* _startexture, unsigned int _texture_id,float width,float height unsigned int _texture_number=0)
    StarView* setTextureID(StarTexture* _startexture, unsigned int _texture_id,unsigned int _texture_number=0)
    {
	/*	texture_height = height;
		texture_width = width;*/
		
        startexture =_startexture;
        texture_id[_texture_number] = 0;
		texture_name[_texture_number] = _texture_id;
		return this;
    };

	/*
	* Overriding
	*/
    virtual void init()=0;
    virtual void update()=0;
    virtual void render()=0;
    virtual void done()=0;
    

    virtual void CallbackFPS(){};
    virtual void CallbackTouchBegin(){};
    virtual void CallbackTouchMove(){};
    virtual void CallbackTouchEnd(){};
    virtual void CallbackTouchCancel(){};
};


#endif /* StarView_hpp */
