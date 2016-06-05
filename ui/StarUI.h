//
//  StarOBJ.h
//  GeoArt
//
//  Created by Sungwoo Choi on 7/30/15.
//  Copyright (c) 2015 SungLab. All rights reserved.

#ifndef STARUI_H
#define STARUI_H

//#include "../renderer/StarFBO.h"
#include "../StarMain.h"

/*
 * Because UI must look more like a fixed-base pipeline
 * Shader, attribute, uniform is fixed
 */
#define STRINGIFY(A)  #A

#ifdef MAC
static const char button_onVertexShader[] =
"#version 150\n"
"in vec3 position;\n"
"in vec2 inputTextureCoordinate;\n"
"out vec2 textureCoordinate;\n"
"uniform mat4 finalM;\n"
"void main(void)\n"
"{   \n"
"	gl_Position = vec4(position,1.0)*finalM;\n"
"textureCoordinate = inputTextureCoordinate.xy;\n"
"}\n";

static const char* button_onFragmentShader= STRINGIFY(
                                                      \n#version 150\n
                                                      precision highp float;
                                                      uniform sampler2D texture0;
                                                      in vec2 textureCoordinate;
                                                      out vec4 fragColor;
                                                      void main()
{
    vec4 tex0 = texture(texture0, textureCoordinate.st,0.0);
    fragColor=vec4(tex0);
});
#else
// FINAL SCREEN
static const char button_onVertexShader[] =
"attribute vec3 position;\n"
"attribute vec2 inputTextureCoordinate;\n"
"varying vec2 textureCoordinate;\n"
"uniform mat4 finalM;\n"
"void main(void)\n"
"{   \n"
"gl_Position = vec4(position,1.0)*finalM;\n"
"textureCoordinate = inputTextureCoordinate.xy;\n"
"}\n";

static const char* button_onFragmentShader= STRINGIFY(
                                                      //"#version 150\n"
                                                      precision highp float;
                                                      uniform sampler2D texture0;
                                                      varying vec2 textureCoordinate;
                                                      void main()
{
    vec4 tex0 = texture2D(texture0, textureCoordinate.st,0.0);
    gl_FragColor = tex0;
});
#endif

static const  float button_vertices[] = {
    -1.0,-1.0,0.0,
    1.0, -1.0,0.0,
    -1.0, 1.0,0.0,
    1.0, 1.0,0.0,
};
static const float button_texturevertices[] = {
    0.0, 0.0,
    1.0,0.0,
    0.0,1.0,
    1.0,1.0,
};

static const unsigned short button_indices[] =
{
    0,1,2,2,1,3
};

class StarFBO;
class StarTexture;
class StarShader;

class StarUI:public StarView
{
    
 public:
//    StarUI()
//    {
//        Matrix_Identity(&(*final_matrix).s);
//    }
    

    virtual ~StarUI(){}
};

#endif
