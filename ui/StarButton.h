//
//  StarButton.h
//
//  Created by Sungwoo Choi on 7/30/15.
//  Copyright (c) 2015 SungLab. All rights reserved.
//


#ifndef STARBUTTON_H
#define STARBUTTON_H

//#include ""

//#include "./StarUI.h"
//#include "StarView.hpp"
#include <iostream> 

#include "StarMain.h"
#include "./StarView.hpp"

#include "../../../ConsoleApplication1/StarDefine.h"
//#include "../math/Matrix.h"
//#include "../renderer/StarTexture.h"

using namespace std;

class StarButton:public StarView
{
public:
	/*
	* Button Properties
	*/
	std::vector<Vec3> button_position;
//	std::vector<Vec4> button_normal;
//	std::vector<Vec2> button_size;
	std::vector<Vec2> button_uv;
	std::vector<unsigned short> button_index;

	StarButton()
	{
		button_position.clear();
		button_uv.clear();
		button_index.clear();
	};

    int texture_id;

	StarButton* addButton(Vec4 rect)
	{
		button_position.push_back(Vec3(rect.x,rect.y,-10.));
		button_position.push_back(Vec3(rect.x+rect.z,rect.y,-10.));
		button_position.push_back(Vec3(rect.x,rect.y+rect.w,-10.));
		button_position.push_back(Vec3(rect.x+rect.z,rect.y+rect.w,-10.));


		starLOG(" hmmm, %f %f", rect.w, rect.z);
		//starLOG
	//	button_index.push_back(size);
		return this;
	}
	StarButton* addUV(Vec4 rect)
	{

		starLOG(" hmmm, %f %f", rect.w, rect.z);
		button_uv.push_back(Vec2(rect.x,rect.y));
		button_uv.push_back(Vec2(rect.x+rect.z,rect.y));
		button_uv.push_back(Vec2(rect.x,rect.y+rect.w));
		button_uv.push_back(Vec2(rect.x+rect.z,rect.y+rect.w));


		return this;
	}


    
    //void initialize( int _vao_id, int _vbo_id)
	void init()
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
        

		int rect_num = button_position.size() / 4;
		if (!rect_num)
		{
			starLOG("Error, add buttton first\n");
			return;
		}

		starLOG("uuuuuuuuuuuuuuu");
        starfbo->createVAO(VAO_BT);
       
	
		attribute_id[0] = 0;// glGetAttribLocation(shader_program, "position");
		attribute_id[1] = 1;// glGetAttribLocation(shader_program, "inputTextureCoordinate");
        

	//	starLOG("wwwwwwwwwwwww");
        starfbo->createVBO(GL_ARRAY_BUFFER, sizeof(Vec3)*button_position.size(), (void*)&button_position[0], GL_STATIC_DRAW, VBO_BT_POSITION);
        glEnableVertexAttribArray(attribute_id[0]);
        glVertexAttribPointer(attribute_id[0], 3, GL_FLOAT, 0, 0, 0);
        
	//	starLOG("xxxxxxxxx");
        starfbo->createVBO(GL_ARRAY_BUFFER, sizeof(Vec2)*button_uv.size(), (void*)&button_uv[0], GL_STATIC_DRAW, VBO_BT_UV);
        glEnableVertexAttribArray(attribute_id[1]);
        glVertexAttribPointer(attribute_id[1], 2, GL_FLOAT, 0, 0, 0);
        
	//	starLOG("yyyyyy");
		for (int i = 0;i<rect_num; i++)
			for (int a = 0; a < 6; a++)
				button_index.push_back(rect_Index[a]+ 4*i);
		
        starfbo->createVBO(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned short)*button_index.size(), (void*)&button_index[0], GL_STATIC_DRAW, VBO_BT_INDEX);
		starLOG("zzzz");
        Matrix_Identity(final_matrix);
		Matrix_OrthoProjection(final_matrix, width, height, 0.1,1000.);
    }
    
    
	void update()
	{

	}
    void render()
    {
        
    //    starfbo->bindFBO(fbo_id[0]);
//        glEnable(GL_DEPTH_TEST);
        
//        glClearColor(0.0, 0.0, 0.0, 1.0);
//        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        
        starfbo->bindVAO(VAO_BT);
        
        glViewport(0,0, width,height);
        
        glUseProgram(shader_program);
        
        startexture->bindTEXTURE(GL_TEXTURE0+texture_name[0], texture_name[0]);
        texture_id = glGetUniformLocation(shader_program, "texture0");
        glUniform1i(texture_id,texture_name[0]);
        
//        unifrom_id = glGetUniformLocation(shader_program,"backColor");
        
//        Matrix_Identity(final_matrix);
       int a =  glGetUniformLocation(shader_program,"finalM");
//        glUniformMatrix4fv(shader_program, 1, GL_FALSE,final_matrix->s );
        glUniformMatrix4fv(a, 1, GL_FALSE, final_matrix.s);
        
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
        
		glDisable(GL_BLEND);
       // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
       // glEnable(GL_DEPTH_TEST);
    }

void done()
{

}

};
#endif
