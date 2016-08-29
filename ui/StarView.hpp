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
//#include "../geometry/StarStructure.h"
enum
{
	SETVIEW_ONE_RECT,
	SETVIEW_FEW_RECTS,

	SETVIEW_ONE_SPHERE,
	SETVIEW_FEW_SPHERE,

	SETVIEW_ONE_CUBE,
	SETVIEW_FEW_CUBES,

	TOTAL_SETVIEW,
};

//#include "StarString.h" // connect with
class StarTexture;
class StarFBO;
class StarShader;

class StarView
{
public:
    Matrix final_matrix; // at least one

protected:
 //   int vao_id;
 //   int vbo_id[10]; // position, uv, index, normal
    int err; // for opengl errors
    
    GLuint vs_id;
    GLuint fs_id;
    GLuint shader_program;

	std::vector<Vec3>	rect_pos;
	std::vector<Vec3>	rect_pos_save;
	std::vector<Vec2> rect_uv;
	std::vector <Vec3> rect_norm;
	std::vector <Color4> rect_color;
	std::vector<unsigned short> rect_idx;
	std::vector<float> rect_factor;
    std::vector<bool> rect_factor_inc;

	Matrix3 norm_matrix;

	/*
	* Handle from GLSL
	*/
    GLuint attribute_id[10]; // position & uv
    GLuint uniform_id[10]; // matrix
    GLuint texture_id[4]; //  from glsl
    
    GLuint texture_name[4]; // from my own name in enum
    
    StarFBO* starfbo;
    StarTexture* startexture;
    StarShader* starshader;
    
    StarTouch* startouch;

    bool initialed;

    Vec2 center;
    Vec4 rect;
    
    //unsigned int height;
    //unsigned int width;

    float height;
    float width;
    
	float animation_time;

	float heightOfnearPlane;
/*    unsigned int fbo_height;
    unsigned int fbo_width;
 */   
    
public:
    
    double now_tick; 

    StarView* setStars(StarFBO* _starfbo, StarShader* _starshader, StarTouch* _startouch = 0)
    {
        starfbo = _starfbo;
        starshader = _starshader;
        startouch = _startouch;
		now_tick = 0.0;
		animation_time = 0.0;
		heightOfnearPlane = 0.0;

		for (int i = 0; i < 10; i++)
		{
			attribute_id[i] = i;
			uniform_id[i] = 0;
		}

		return this;
	};

	StarView* setShaderID(unsigned int _id)
	{
		shader_program = _id;
		return this;
	};
   
	void setTime(float _time)
	{
		animation_time = _time;
	}
    
    void setView(unsigned int SETTING = 0, unsigned int NUMBER = 1)
    {
        switch (SETTING)
        {
            case SETVIEW_ONE_RECT:
            {
                rect_pos.clear();
                rect_uv.clear();
                rect_idx.clear();
                
                rect_pos.push_back(Vec3(rect_Pos_Vertex[0], rect_Pos_Vertex[1], rect_Pos_Vertex[2]));
                rect_pos.push_back(Vec3(rect_Pos_Vertex[3], rect_Pos_Vertex[4], rect_Pos_Vertex[5]));
                rect_pos.push_back(Vec3(rect_Pos_Vertex[6], rect_Pos_Vertex[7], rect_Pos_Vertex[8]));
                rect_pos.push_back(Vec3(rect_Pos_Vertex[9], rect_Pos_Vertex[10], rect_Pos_Vertex[11]));
                
                rect_uv.push_back(Vec2(rect_UV_Vertex[0], rect_UV_Vertex[1]));
                rect_uv.push_back(Vec2(rect_UV_Vertex[2], rect_UV_Vertex[3]));
                rect_uv.push_back(Vec2(rect_UV_Vertex[4], rect_UV_Vertex[5]));
                rect_uv.push_back(Vec2(rect_UV_Vertex[6], rect_UV_Vertex[7]));
                
                rect_idx.push_back(rect_Idx_Vertex[0]);
                rect_idx.push_back(rect_Idx_Vertex[1]);
                rect_idx.push_back(rect_Idx_Vertex[2]);
                rect_idx.push_back(rect_Idx_Vertex[3]);
                rect_idx.push_back(rect_Idx_Vertex[4]);
                rect_idx.push_back(rect_Idx_Vertex[5]);

				rect_color.push_back(Color4(1.0));
				rect_color.push_back(Color4(1.0));
				rect_color.push_back(Color4(1.0));
				rect_color.push_back(Color4(1.0));

				rect_factor.push_back(0.0);
				rect_factor.push_back(0.0);
				rect_factor.push_back(0.0);
				rect_factor.push_back(0.0);

                rect_factor.push_back(false);
                rect_factor.push_back(false);
                rect_factor.push_back(false);
                rect_factor.push_back(false);
                
                break;
                
            }
            case SETVIEW_FEW_RECTS:
            {
                rect_pos.clear();
                rect_uv.clear();
                rect_color.clear();
                rect_idx.clear();
                
                srand((unsigned)time(NULL));
                for (int i = 0; i < NUMBER; i++)
                {
                    rect_pos.push_back(Vec3(rect_Pos_Vertex[0], rect_Pos_Vertex[1], rect_Pos_Vertex[2]));
                    rect_pos.push_back(Vec3(rect_Pos_Vertex[3], rect_Pos_Vertex[4], rect_Pos_Vertex[5]));
                    rect_pos.push_back(Vec3(rect_Pos_Vertex[6], rect_Pos_Vertex[7], rect_Pos_Vertex[8]));
                    rect_pos.push_back(Vec3(rect_Pos_Vertex[9], rect_Pos_Vertex[10], rect_Pos_Vertex[11]));
                    
                    rect_color.push_back(Color4(1.0));
                    rect_color.push_back(Color4(1.0));
                    rect_color.push_back(Color4(1.0));
                    rect_color.push_back(Color4(1.0));
                    
                    float f = rand()%1000 *0.001;
                    
                    rect_factor.push_back(f);
                    rect_factor.push_back(f);
                    rect_factor.push_back(f);
                    rect_factor.push_back(f);
                    
                    rect_factor_inc.push_back(i%2);
                    rect_factor_inc.push_back(i%2);
                    rect_factor_inc.push_back(i%2);
                    rect_factor_inc.push_back(i%2);
                    
                    rect_uv.push_back(Vec2(rect_UV_Vertex[0], rect_UV_Vertex[1]));
                    rect_uv.push_back(Vec2(rect_UV_Vertex[2], rect_UV_Vertex[3]));
                    rect_uv.push_back(Vec2(rect_UV_Vertex[4], rect_UV_Vertex[5]));
                    rect_uv.push_back(Vec2(rect_UV_Vertex[6], rect_UV_Vertex[7]));
                    
                    rect_idx.push_back(4*i+rect_Idx_Vertex[0]);
                    rect_idx.push_back(4*i+rect_Idx_Vertex[1]);
                    rect_idx.push_back(4*i+rect_Idx_Vertex[2]);
                    rect_idx.push_back(4*i+rect_Idx_Vertex[3]);
                    rect_idx.push_back(4*i+rect_Idx_Vertex[4]);
                    rect_idx.push_back(4*i+rect_Idx_Vertex[5]);
                    
                }
                break;
            }//case done
                
        }

	}

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
	StarView* setMatrix(Matrix& m)
	{
//		final_matrix = Matrix{
//			m.s[0],m.s[1],m.s[2],m.s[3],
//			m.s[4],m.s[5],m.s[6],m.s[7],
//			m.s[8],m.s[9],m.s[10],m.s[11],
//			m.s[12],m.s[13],m.s[14],m.s[15] };
        final_matrix = m;

		return this;
	}
    //StarView* setTextureID(StarTexture* _startexture, unsigned int _texture_id,float width,float height unsigned int _texture_number=0)
    StarView* setTextureID(StarTexture* _startexture, unsigned int _texture_name=79,unsigned int _texture_number=0)
    {
	/*	texture_height = height;
		texture_width = width;*/
		
        startexture =_startexture;

		if (_texture_name == 79)
		{
			//starLOG("yes null\n");
			return this;
		}
		texture_name[_texture_number] = _texture_name;
		return this;
    };

	void setHeightOfNP(float honp)
	{
		heightOfnearPlane = honp;
	}
	/*
	* Overriding
	*/
    virtual void init()=0;
    virtual void update()=0;
    virtual void render()=0;
    virtual void done()=0;

    /*
    virtual void CallbackFPS(){};
    virtual void CallbackTouchBegin(){};
    virtual void CallbackTouchMove(){};
    virtual void CallbackTouchEnd(){};
    virtual void CallbackTouchCancel(){};
*/

	//virtual void CallbackFPS()=0;
	//virtual void CallbackTouchBegin()=0;
	//virtual void CallbackTouchMove()=0;
	//virtual void CallbackTouchEnd()=0;
	//virtual void CallbackTouchCancel()=0;

	
	void CallbackFPS(){};
	void CallbackTouchBegin(){};
	void CallbackTouchMove(){};
	void CallbackTouchEnd(){};
	void CallbackTouchCancel(){};
	



};

// TEMPLATE
//void CallbackFPS() {};
//void CallbackTouchBegin() {};
//void CallbackTouchMove() {};
//void CallbackTouchEnd() {};
//void CallbackTouchCancel() {};



//#if(_WIN32 | MAC)
//attribute_id[0] = 0;
//attribute_id[1] = 1;
//attribute_id[2] = 3;
//
//#else
//attribute_id[0] = glGetAttribLocation(shader_program, "position");
//attribute_id[1] = glGetAttribLocation(shader_program, "color");
////  attribute_id[2]= glGetAttribLocation(shader_program, "inputTextureCoordinate");
//attribute_id[2] = glGetAttribLocation(shader_program, "factor");
//#endif


//starfbo->createVAO(VAO_SMOKE);
//
//rect_pos.clear();
//rect_uv.clear();
//rect_idx.clear();
//
//rect_pos.push_back(Vec3(rect_Pos_Vertex[0], rect_Pos_Vertex[1], rect_Pos_Vertex[2]));
//rect_pos.push_back(Vec3(rect_Pos_Vertex[3], rect_Pos_Vertex[4], rect_Pos_Vertex[5]));
//rect_pos.push_back(Vec3(rect_Pos_Vertex[6], rect_Pos_Vertex[7], rect_Pos_Vertex[8]));
//rect_pos.push_back(Vec3(rect_Pos_Vertex[9], rect_Pos_Vertex[10], rect_Pos_Vertex[11]));
//
//rect_uv.push_back(Vec2(rect_UV_Vertex[0], rect_UV_Vertex[1]));
//rect_uv.push_back(Vec2(rect_UV_Vertex[2], rect_UV_Vertex[3]));
//rect_uv.push_back(Vec2(rect_UV_Vertex[4], rect_UV_Vertex[5]));
//rect_uv.push_back(Vec2(rect_UV_Vertex[6], rect_UV_Vertex[7]));
//
//rect_idx.push_back(rect_Idx_Vertex[0]);
//rect_idx.push_back(rect_Idx_Vertex[1]);
//rect_idx.push_back(rect_Idx_Vertex[2]);
//rect_idx.push_back(rect_Idx_Vertex[3]);
//rect_idx.push_back(rect_Idx_Vertex[4]);
//rect_idx.push_back(rect_Idx_Vertex[5]);
//
//starfbo->createVBOsub(GL_ARRAY_BUFFER, 0, sizeof(Vec3)*rect_pos.size(), (void*)&rect_pos[0], GL_DYNAMIC_DRAW, VBO_SMOKE_POSITION);
//glEnableVertexAttribArray(attribute_id[0]);
//glVertexAttribPointer(attribute_id[0], 3, GL_FLOAT, 0, 0, 0);
//
//starfbo->createVBO(GL_ARRAY_BUFFER, sizeof(Vec2)*rect_uv.size(), (void*)&rect_uv[0], GL_STATIC_DRAW, VBO_SMOKE_UV);
//glEnableVertexAttribArray(attribute_id[1]);
//glVertexAttribPointer(attribute_id[1], 2, GL_FLOAT, 0, 0, 0);
//
//starfbo->createVBOsub(GL_ARRAY_BUFFER, 0, sizeof(Vec3)*rect_pos.size(), (void*)&rect_pos[0], GL_DYNAMIC_DRAW, VBO_SMOKE_POSITION);
//glEnableVertexAttribArray(attribute_id[0]);
//glVertexAttribPointer(attribute_id[0], 3, GL_FLOAT, 0, 0, 0);
//
///*starfbo->createVBOsub(GL_ARRAY_BUFFER, 0, sizeof(Color4)*rect_uv.size(), (void*)&rect_color[0], GL_DYNAMIC_DRAW, VBO_SMOKE_UV);
//glEnableVertexAttribArray(attribute_id[1]);
//glVertexAttribPointer(attribute_id[1], 2, GL_FLOAT, 0, 0, 0);
//*/
//starfbo->createVBO(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned short)*rect_idx.size(), (void*)&rect_idx[0], GL_STATIC_DRAW, VBO_SMOKE_INDEX);

/*
* RENDER
*/
//starfbo->bindVAO();
//glViewport(0, 0, StarInfo::starRECT.x, StarInfo::starRECT.y);
//
//glUseProgram(shader_program);
//
//attribute_id[0] = 0;
//attribute_id[1] = 1;
//
////uniform_id[0] = glGetUniformLocation(shader_program, "finalM");
////glUniformMatrix4fv(uniform_id[0], 1, GL_FALSE, final_matrix.s);
//
//startexture->bindTEXTURE(GL_TEXTURE0 + , );
//texture_id[0] = glGetUniformLocation(shader_program, "texture0");
//glUniform1i(texture_id[0], );
//
//
//glEnable(GL_BLEND);
//glBlendFunc(GL_SRC_ALPHA, GL_ONE);
//
//glDrawElements(GL_TRIANGLES, rect_idx.size(), GL_UNSIGNED_SHORT, (void*)0); // right
//
//glDisable(GL_BLEND);


#endif /* StarView_hpp */
