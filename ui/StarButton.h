//
//  StarButton.h
//
//  Created by Sungwoo Choi on 7/30/15.
//  Copyright (c) 2015 SungLab. All rights reserved.
//


#ifndef STARBUTTON_H
#define STARBUTTON_H

#include "../StarMain.h"
#include "./StarUI.h"
//#include "../math/Matrix.h"

//#include "../renderer/StarTexture.h"
//#include "StarDefine.h"
//#include "StarString.h"

static const char* star_attribute_vname_button_list[] = { "position","inputTextureCoordinate" };

using namespace std;

class Starbutton:public StarUI
{
public:
    
    int texture_id;
   
//    void setPosition(float x,float y,float width, float height);
    void setFBOsize(float _fbo_width,float _fbo_height)
    {
        fbo_width = _fbo_width;
        fbo_height = _fbo_height;
    }
    void setPosition(float _x,float _y,float _width,float _height)
    {
        center.x = _x;
        center.y = _y;
        width = _width;
        height = _height;
    }
    
    void setTextureID(StarTexture* _startexture, unsigned int _texture_number)
    {
        startexture = _startexture;
        texture_number = _texture_number;
    }
    
    void initialize(StarFBO* _starfbo, StarShader* _starshader, int _fbo_id, int _vao_id, int _vbo_id)
    {
        
       /*
        * this part is defined right before it is called
        */
        
//        starfbo->createFBO(true,true,fbo_width,fbo_height,_fbo_id);
//        
//        int err;
//        while ((err = glGetError()) != GL_NO_ERROR) {
//            printf("\n\nOpenGL error TURNON 1: %x\n\n",err);
//        }
//        GLenum status1 = glCheckFramebufferStatus(GL_FRAMEBUFFER);
//        if (status1 != GL_FRAMEBUFFER_COMPLETE) {
//            starLOG("ERROR FBO %x\n",status1);
//        }
        
        starfbo = _starfbo;
        starshader = _starshader;
        
        fbo_id = _fbo_id;
        vao_id = _vao_id;
        
        vbo_id[0] = _vbo_id+0;
        vbo_id[1] = _vbo_id+1;
        vbo_id[2] = _vbo_id+2;
       
        starfbo->bindFBO(fbo_id);
        starfbo->createVAO(vao_id);
        
        // NORMAL
        if( !starshader->ShaderLoadSourceFromMemory(button_onVertexShader, GL_VERTEX_SHADER,  &vert_shader_id))
            starLOG("hi1");
        if(!starshader->ShaderLoadSourceFromMemory(button_onFragmentShader, GL_FRAGMENT_SHADER, &frag_shader_id))
            starLOG("hi2");
        if(!starshader->CreateProgram(&shader_program,vert_shader_id,frag_shader_id, star_attribute_vname_button_list,  (sizeof(star_attribute_vname_button_list))/sizeof(star_attribute_vname_button_list[0])))
            starLOG("hi3");
//            starLOG("ERROR PROGRAM : %d",10);
        
        attribute_id[0] = glGetAttribLocation(shader_program,"position" );
        attribute_id[1] = glGetAttribLocation(shader_program,"inputTextureCoordinate" );
        
        starfbo->createVBO(GL_ARRAY_BUFFER, sizeof(button_vertices), (void*)&button_vertices[0], GL_STATIC_DRAW, vbo_id[0]);
        glEnableVertexAttribArray(attribute_id[0]);
        glVertexAttribPointer(attribute_id[0], 3, GL_FLOAT, 0, 0, 0);
        
        starfbo->createVBO(GL_ARRAY_BUFFER, sizeof(button_texturevertices), (void*)&button_texturevertices[0], GL_STATIC_DRAW, vbo_id[1]);
        glEnableVertexAttribArray(attribute_id[1]);
        glVertexAttribPointer(attribute_id[1], 2, GL_FLOAT, 0, 0, 0);
        
        starfbo->createVBO(GL_ELEMENT_ARRAY_BUFFER, sizeof(button_indices), (void*)&button_indices[0], GL_STATIC_DRAW, vbo_id[2]);
        
        
//        Matrix_Identity(*final_matrix);
//        Matrix_Identity(final_matrix);
    }
    
        Matrix aa;
    
    void render()
    {
        
        starfbo->bindFBO(fbo_id);
//        glEnable(GL_DEPTH_TEST);
        
//        glClearColor(0.0, 0.0, 0.0, 1.0);
//        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        
        starfbo->bindVAO(vao_id);
        
        glViewport(0,0,fbo_width, fbo_height);
        
        glUseProgram(shader_program);
        
        startexture->bindTEXTURE(GL_TEXTURE0+texture_number, texture_number);
        texture_id = glGetUniformLocation(shader_program, "texture0");
        glUniform1i(texture_id,texture_number);
        
//        unifrom_id = glGetUniformLocation(shader_program,"backColor");
        
  
        
        
        Matrix_Identity(aa);
       int a =  glGetUniformLocation(shader_program,"finalM");
//        glUniformMatrix4fv(shader_program, 1, GL_FALSE,final_matrix->s );
       
        
        glUniformMatrix4fv(a, 1, GL_FALSE, aa.s);
        
        int err;
        while ((err = glGetError()) != GL_NO_ERROR)
            printf("\n\nOpenGL error button: %x\n\n",err);
        
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE,GL_ZERO);
        
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
#ifdef ANDROID
        starfbo->bindVBO(GL_ARRAY_BUFFER,vbo_id[0]);
        glVertexAttribPointer(attribute_id[0], 3, GL_FLOAT, 0, 0, 0);
        glEnableVertexAttribArray(attribute_id[0]);
        
        starfbo->bindVBO(GL_ARRAY_BUFFER,vbo_id[1]);
        glVertexAttribPointer(attribute_id[1],2, GL_FLOAT, 0, 0, 0);
        glEnableVertexAttribArray(attribute_id[1]);
        
        starfbo->bindVBO(GL_ELEMENT_ARRAY_BUFFER, vbo_id[2]);
#endif
        
       
        
        glDrawElements(GL_TRIANGLES,6, GL_UNSIGNED_SHORT ,(void*)0);
        
     
        
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_DEPTH_TEST);
    }
};


#endif
