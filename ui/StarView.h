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
#include "../star.h"
#include <unordered_map>

enum class SETVIEW
{
    
    POINTS,
    
    LINES,
    
	RECT,

	CUBE,

	TOTAL
};

class StarTexture;
class StarFBO;
class StarShader;

class StarView//:public StarEngine
{
    
public:
    Matrix final_matrix; // at least one
    Matrix translation_matrix;
    Matrix scale_matrix;
    Matrix rotation_matrix;

protected:
    
    //unsigned int ObjectType;
    SETVIEW ObjectType;
    unsigned int ObjectNumber;
    
    std::vector<Vec3> rect_scale;
//    float rect_scale[i];
    
 //   int vao_id;
 //   int vbo_id[10]; // position, uv, index, normal
    int err; // for opengl errors
    
    GLuint vs_id;
    GLuint fs_id;
    GLuint shader_program;

    std::unordered_map<Vec3*,int> connection;
    
	std::vector<Vec3>	rect_pos;
	std::vector<Vec3>	rect_pos_save;
    std::vector<Vec3> rect_power;
    std::vector<Vec3> rect_power_cross;
	std::vector<Vec2> rect_uv;
	std::vector <Vec3> rect_norm;
	std::vector <Color4> rect_color;
	std::vector<unsigned short> rect_idx;
    
    // under the consideration
	std::vector<float> rect_factor;
    std::vector<bool> rect_factor_inc;
    std::vector<Vec3> rect_center;
    std::vector<Vec3> rect_center_prev;

	Matrix3 norm_matrix;

	/*
	* Handle from GLSL
	*/
    GLuint attribute_id[10]; // position & uv
    GLuint uniform_id[10]; // matrix
    
    GLuint texture_id[10]; //  from glsl  // sampler
    GLuint texture_name[10]; // from my own name in enum 
    
    StarFBO* starfbo;
    StarTexture* startexture;
    StarShader* starshader;
    
    StarTouch* startouch;

    bool initialed;

    Vec2 center;
    Vec4 rect;
    

    float height;
    float width;
    float hypo;
    
	float animation_time;

	float heightOfnearPlane;
    
    
public:
    
    double now_tick; 

    virtual bool isCollision(Vec3* pos){ return false;};
    
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
    
    StarView* setRect(float x=0., float y=0.)
    {
        if((x == 0.) || (y == 0.))
            return NULL;
        
        width = x;
        height = y;
        
        hypo = sqrtf(width*width + height*height);
        return this;
    }
    
	StarView* setShaderID(unsigned int _id)
	{
		shader_program = _id;
		return this;
	};
   
	void setTime(float _time)
	{
		animation_time = _time;
	}
    
    void sync()
    {
        
        switch(ObjectType)
        {
		case SETVIEW::RECT:
                for(int i=0; i< ObjectNumber; i++)
                {
                    rect_pos[i*4+0] = (rect_center[i]+ Vec3(rect_Pos_Vertex[0], rect_Pos_Vertex[1], rect_Pos_Vertex[2])*rect_scale[i]);
                    rect_pos[i*4+1] = (rect_center[i]+ Vec3(rect_Pos_Vertex[3], rect_Pos_Vertex[4], rect_Pos_Vertex[5])*rect_scale[i]);
                    rect_pos[i*4+2] = (rect_center[i]+ Vec3(rect_Pos_Vertex[6], rect_Pos_Vertex[7], rect_Pos_Vertex[8])*rect_scale[i]);
                    rect_pos[i*4+3] = (rect_center[i]+ Vec3(rect_Pos_Vertex[9], rect_Pos_Vertex[10], rect_Pos_Vertex[11])*rect_scale[i]);
                }
                break;
		case SETVIEW::LINES:
                for(int i=0; i< ObjectNumber; i++)
                {
                    rect_pos[i*2+1] = rect_pos[i*2+0];
                    rect_pos[i*2+0] = rect_center[i];
                }
                break;
		case  SETVIEW::POINTS:
                for(int i=0; i< ObjectNumber; i++)
                {
                    rect_pos[i] = rect_center[i];
                }
                break;
        }
    }
    
    Vec3* getPower(int idx)
    {
        return &rect_power[idx];
    }
    
    Vec3* getCenter(int idx)
    {
        return &rect_center[idx];
    }
    
    int getConnection(Vec3* pos)
    {
        return connection[pos];
    }
    
    void setView(SETVIEW SETTING = (SETVIEW::RECT), unsigned int NUMBER = 1, Vec3 SCALE = Vec3(1.0))

    {
        
        ObjectType = SETTING;
        ObjectNumber = NUMBER;
        
        rect_scale.resize(NUMBER, SCALE);
        rect_center.resize(NUMBER);
        rect_power.resize(NUMBER, Vec3(0.0));
        rect_factor.resize(NUMBER, 1.0);
        
        
        switch (SETTING)
        {
		case SETVIEW::RECT:
            {
                rect_pos.resize(NUMBER*4, Vec3(0.0));
                rect_color.resize(NUMBER*4, Color4(0.0));
                rect_uv.resize(NUMBER*4, Vec2(0.0));
                rect_factor.resize(NUMBER*4, 1.0);
                rect_factor_inc.resize(NUMBER*4, false);
                rect_idx.resize(NUMBER*6, 0);
                
                srand((unsigned)time(NULL));
                for (int i = 0; i < NUMBER; i++)
                {
                    rect_pos[i*4+0] = (Vec3(rect_Pos_Vertex[0], rect_Pos_Vertex[1], -1.)*rect_scale[i]);
                    rect_pos[i*4+1] = (Vec3(rect_Pos_Vertex[3], rect_Pos_Vertex[4], -1.)*rect_scale[i]);
                    rect_pos[i*4+2] = (Vec3(rect_Pos_Vertex[6], rect_Pos_Vertex[7], -1.)*rect_scale[i]);
                    rect_pos[i*4+3] = (Vec3(rect_Pos_Vertex[9], rect_Pos_Vertex[10],-1.)*rect_scale[i]);
                    
                    rect_color[i*4+0] = (Color4(1.0));
                    rect_color[i*4+1] = (Color4(1.0));
                    rect_color[i*4+2] = (Color4(1.0));
                    rect_color[i*4+3] = (Color4(1.0));
                    
                    float f = rand()%1000 *0.001;
                    
                    rect_factor[i*4+0] = (f);
                    rect_factor[i*4+1] = (f);
                    rect_factor[i*4+2] = (f);
                    rect_factor[i*4+3] = (f);
                    
                    rect_uv[i*4+0] = (Vec2(rect_UV_Vertex[0], rect_UV_Vertex[1]));
                    rect_uv[i*4+1] = (Vec2(rect_UV_Vertex[2], rect_UV_Vertex[3]));
                    rect_uv[i*4+2] = (Vec2(rect_UV_Vertex[4], rect_UV_Vertex[5]));
                    rect_uv[i*4+3] = (Vec2(rect_UV_Vertex[6], rect_UV_Vertex[7]));
                    
                    rect_idx[i*6+0] =(4*i+rect_Idx_Vertex[0]);
                    rect_idx[i*6+1] =(4*i+rect_Idx_Vertex[1]);
                    rect_idx[i*6+2] =(4*i+rect_Idx_Vertex[2]);
                    rect_idx[i*6+3] =(4*i+rect_Idx_Vertex[3]);
                    rect_idx[i*6+4] =(4*i+rect_Idx_Vertex[4]);
                    rect_idx[i*6+5] =(4*i+rect_Idx_Vertex[5]);
                    
                    rect_factor_inc[i*4+0] = (false);
                    rect_factor_inc[i*4+1] = (false);
                    rect_factor_inc[i*4+2] = (false);
                    rect_factor_inc[i*4+3] = (false);
                }
                break;
                
            }
		case SETVIEW::POINTS:
            {
                rect_pos.resize(NUMBER, Vec3(0.0));
                rect_color.resize(NUMBER, Color4(1.0));
                rect_idx.resize(NUMBER);
                
                for (unsigned int i = 0; i < NUMBER; i++)
                {
                    rect_pos[i] = (Vec3(0.0,0.0,0.));
                    rect_color[i] = (Color4(1.0));
                    rect_idx[i] = (i);
                }
                
                break;
            }
		case SETVIEW::LINES:
            {
                
                rect_pos.resize(NUMBER*2, Vec3(0.0));
                rect_color.resize(NUMBER*2, Color4(0.0));
                rect_idx.resize(NUMBER*2);
                
                for (int i = 0; i < NUMBER; i++)
                {
                    rect_pos[i*2+0] = (Vec3(0.0, 0.0, 0.0));
                    rect_pos[i*2+1] = (Vec3(0.0, 0.0, 0.0));
                    
                    rect_color[i*2+0] = (Color4(1.0));
                    rect_color[i*2+1] = (Color4(1.0));
                    
                    rect_idx[i*2+0] = (i*2+0);
                    rect_idx[i*2+1] = (i*2+1);
                }
                
                break;
            }
            default:
                break;
                
        }
        
    }
    
    void setColor(Color4& color,int i)
    {
        rect_color[i] = color;
    }
    
    void addPower(Vec3& power)
    {
        for(int i=0; i<rect_power.size(); i++)
        rect_power[i] += power;
    }
    
    void setPower(Vec3& power, int i)
    {
        rect_power[i] = power;
    }
    void setPosition(Vec3& position, int i)
    {
        rect_pos[i] = position;
    }
    
    void setUV(Vec2& uv, int i)
    {
        rect_uv[i] = uv;
    }
    
    void reset(){};

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
    
    StarView* setTextureID(StarTexture* _startexture, unsigned int _texture_name=79,unsigned int _texture_number=0)
    {
        
        startexture =_startexture;
        
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

//    void init(){};
//    void update(){};
//    void render(){};
//    void done(){};
    
	
    //optional
	virtual void CallbackFPS(){};
	virtual void CallbackTouchBegin(){};
	virtual void CallbackTouchMove(){};
	virtual void CallbackTouchEnd(){};
	virtual void CallbackTouchCancel(){};

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
