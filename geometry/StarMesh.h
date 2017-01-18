//
//  StarGeo.h
//
//  Created by Sungwoo Choi on 7/30/15.
//  Copyright (c) 2015 SungLab. All rights reserved.
//


#ifndef STARMESH_H
#define STARMESH_H
#include "../StarMain.h"

class StarMesh
{
private:
protected:
    Vec3* pos_vert;
    Vec2* tex_vert;
    Vec3* norm_vert;
public:
    virtual void generatePV()=0;
    virtual void generateTV()=0;
};

//class StarGird
//{
//public:
//    Vec3* generateVERT(const Vec2& size) //size = number of rectangles
//    {
//
//        int width = (int)size.x;
//        int height= (int)size.y;
//
//        float stepX = 2.0/width;
//        float stepY = 2.0/height;
//
//        Vec3* ret= new Vec3[width*height*6];
//
//        for(int i=0; i<width; i++)
//        {
//            for(int j=0; j<height; j++)
//            {
//                ret[(i*height+j)*6+0] = Vec3(-1. + stepX*i, -1.+ stepY*j, 0.0);
//                ret[(i*height+j)*6+1] = Vec3(-1. + stepX*(i+1), -1. + stepY*j, 0.0);
//                ret[(i*height+j)*6+2] = Vec3(-1. + stepX*i, -1. + stepY*(j+1), 0.0);
//
//                ret[(i*height+j)*6+2] = Vec3(-1. + stepX*i, -1. + stepY*(j+1), 0.0);
//                ret[(i*height+j)*6+1] = Vec3(-1. + stepX*(i+1), -1. + stepY*j, 0.0);
//                ret[(i*height+j)*6+1] = Vec3(-1. + stepX*(i+1), -1. + stepY*(j+1), 0.0);
//            }
//        }
//
//        return ret;
//    }
//
//    Vec3* generateTEX(const Vec2& size) //size = number of rectangles
//    {
//
//        int width = (int)size.x;
//        int height= (int)size.y;
//
//        float stepX = 1.0/width;
//        float stepY = 1.0/height;
//        Vec3* ret= new Vec3[width*height*6];
//
//        for(int i=0; i<width; i++)
//        {
//            for(int j=0; j<height; j++)
//            {
//                ret[(i*height+j)*6+0] = Vec3(0.0 + stepX*i, 0.0+ stepY*j, 0.0);
//                ret[(i*height+j)*6+1] = Vec3(0.0 + stepX*(i+1), 0.0 + stepY*j, 0.0);
//                ret[(i*height+j)*6+2] = Vec3(0.0 + stepX*i, 0.0 + stepY*(j+1), 0.0);
//
//                ret[(i*height+j)*6+2] = Vec3(0.0 + stepX*i, 0.0 + stepY*(j+1), 0.0);
//                ret[(i*height+j)*6+1] = Vec3(0.0 + stepX*(i+1), 0.0 + stepY*j, 0.0);
//                ret[(i*height+j)*6+1] = Vec3(0.0 + stepX*(i+1), 0.0 + stepY*(j+1), 0.0);
//            }
//        }
//
//        return ret;
//    }
//};

class StarGrid:public StarMesh
{
    
private:
    Vec2 grid;
    int width;
    int height;
    
public:
    StarGrid(Vec2 _grid):grid(_grid)
    {
        width = (int)grid.x;
        height = (int)grid.y;
        
        int total = width * height * 6;//two triangles
        pos_vert = new Vec3[total];
        tex_vert = new Vec2[total];
        norm_vert = new Vec3[total];
    }
    
    Vec3* getPV()
    {
        return pos_vert;
    }
    Vec2* getTV()
    {
        return tex_vert;
    }
    
    void generateTV()
    {

        float stepX = 1.0/width;
        float stepY = 1.0/height;
//        Vec3* ret= new Vec3[width*height*6];
        
        for(int i=0; i<width; i++)
        {
            for(int j=0; j<height; j++)
            {
                tex_vert[(i*height+j)*6+0] = Vec2(0.0 + stepX*i, 0.0+ stepY*j);
                tex_vert[(i*height+j)*6+1] = Vec2(0.0 + stepX*(i+1), 0.0 + stepY*j);
                tex_vert[(i*height+j)*6+2] = Vec2(0.0 + stepX*i, 0.0 + stepY*(j+1));
                
                tex_vert[(i*height+j)*6+3] = Vec2(0.0 + stepX*i, 0.0 + stepY*(j+1));
                tex_vert[(i*height+j)*6+4] = Vec2(0.0 + stepX*(i+1), 0.0 + stepY*j);
                tex_vert[(i*height+j)*6+5] = Vec2(0.0 + stepX*(i+1), 0.0 + stepY*(j+1));
            }
        }
    }
    
    void generatePV()
    {
        
        float stepX = 2.0/width;
        float stepY = 2.0/height;
        
//        Vec3* ret= new Vec3[width*height*6];
        
        for(int i=0; i<width; i++)
        {
            for(int j=0; j<height; j++)
            {
                pos_vert[(i*height+j)*6+0] = Vec3(-1. + stepX*i, -1.+ stepY*j,0.0);
                pos_vert[(i*height+j)*6+1] = Vec3(-1. + stepX*(i+1), -1. + stepY*j,0.0);
                pos_vert[(i*height+j)*6+2] = Vec3(-1. + stepX*i, -1. + stepY*(j+1),0.0);
                
                pos_vert[(i*height+j)*6+3] = Vec3(-1. + stepX*i, -1. + stepY*(j+1),0.0);
                pos_vert[(i*height+j)*6+4] = Vec3(-1. + stepX*(i+1), -1. + stepY*j,0.0);
                pos_vert[(i*height+j)*6+5] = Vec3(-1. + stepX*(i+1), -1. + stepY*(j+1),0.0);
            }
        }
    }
    void generateNV()
    {
        
        for(int i=0; i<width; i++)
        {
            for(int j=0; j<height; j++)
            {
                norm_vert[(i*height+j)*6+0] = pos_vert[(i*height+j)*6+1].cross(pos_vert[(i*height+j)*6+2]);
                norm_vert[(i*height+j)*6+1] = pos_vert[(i*height+j)*6+2].cross(pos_vert[(i*height+j)*6+0]);
                norm_vert[(i*height+j)*6+2] = pos_vert[(i*height+j)*6+0].cross(pos_vert[(i*height+j)*6+2]);
                
                norm_vert[(i*height+j)*6+3] = pos_vert[(i*height+j)*6+4].cross(pos_vert[(i*height+j)*6+5]);
                norm_vert[(i*height+j)*6+4] = pos_vert[(i*height+j)*6+5].cross(pos_vert[(i*height+j)*6+3]);
                norm_vert[(i*height+j)*6+5] = pos_vert[(i*height+j)*6+3].cross(pos_vert[(i*height+j)*6+4]);
                
                norm_vert[(i*height+j)*6+0].normalize();
                norm_vert[(i*height+j)*6+1].normalize();
                norm_vert[(i*height+j)*6+2].normalize();
                norm_vert[(i*height+j)*6+3].normalize();
                norm_vert[(i*height+j)*6+4].normalize();
                norm_vert[(i*height+j)*6+5].normalize();
            }
        }
    }
};
#endif
