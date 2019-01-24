//
//  StarGeo.h
//
//  Created by Sungwoo Choi on 7/30/15.
//  Copyright (c) 2015 SungLab. All rights reserved.
//


#ifndef STARMESH_H
#define STARMESH_H
#include "../StarMain.h"
//#inlcude "../star
class StarMesh
{
private:
protected:
    Vec3* grid_position;
    Vec3* grid_destination;
    Vec3* grid_power;
    
    Vec3* pos_vert;
    Vec2* tex_vert;
    Vec3* norm_vert;
    Color4* color_vert;
    
public:
    virtual void generatePV()=0;
    virtual void generateTV()=0;
    virtual void generateNV()=0;
    virtual void generateCV()=0;
    virtual void generateWire(Vec3*)=0;
    
};


class StarGrid:public StarMesh
{
    
private:
    Vec2 screen;
    Vec2 grid;
    int width;
    int height;
    
public:
    
    int total_vert_tri;
    int total_vert_point;
    int total_wire_rect;
    
    StarGrid(Vec2 _grid, Vec2 _screen):grid(_grid), screen(_screen)
    {
        width = (int)grid.x;
        height = (int)grid.y;
        
        int total = width * height * 6;//two triangles
//        int total_grid = (width+1) * (height+1);
        int total_grid = width*height;
        
        total_vert_tri = total;
        total_vert_point = total_grid;
        total_wire_rect = height*(width+1)+width*(height+1);
        
        grid_position = new Vec3[total_grid];
        grid_destination= new Vec3[total_grid];
        grid_power= new Vec3[total_grid];
        
        pos_vert = new Vec3[total];
        tex_vert = new Vec2[total];
        norm_vert = new Vec3[total];
        color_vert = new Color4[total];
        
        for(int i=0;i<total;i++)
        {
            pos_vert[i].zero();
            tex_vert[i].zero();
            norm_vert[i].zero();
            color_vert[i].zero();
        }
        
        for(int i=0;i<total_grid;i++)
        {
            grid_position[i].zero();
//            grid_destination[i].zero();
            grid_destination[i] = Vec3(0.5,0.5,0.0);
            grid_power[i].zero();
        }
        float stepX = 2.0/width;
        float stepY = 2.0/height;
        unsigned int idx = 0;
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
               int  idx = i*width+j;
                grid_position[(idx)] = Vec3(stepX*j, stepY*i,rand()%10000*0.01);
                grid_destination[(idx)] = Vec3(stepX*j, stepY*i,0.0);
                
//                grid_position[(idx)*6+1] = Vec3(-1. + stepX*(0+1), -1. + stepY*0,0.0);
//                grid[(idx)*6+2] = Vec3(-1. + stepX*0, -1. + stepY*(0+1),0.0);
//                pos_vert[(idx)*6+3] = Vec3(-1. + stepX*0, -1. + stepY*(0+1),0.0);
//                pos_vert[(idx)*6+4] = Vec3(-1. + stepX*(0+1), -1. + stepY*0,0.0);
//                pos_vert[(idx)*6+5] = Vec3(-1. + stepX*(0+1), -1. + stepY*(0+1),0.0);
                
            }
        }
//        float stepX = 2.0/width;
//        float stepY = 2.0/height;
//        
//        for(int i=0; i<height; i++)
//        {
//            for(int j=0; j<width; j++)
//            {
//                int idx = i*width+j;
//                
//                grid_destination[(idx)] =  Vec3(stepX*(j), stepY*i,0.0);
////                pos_vert[(idx)*6+0] = Vec3(-1. + stepX*j, -1.+ stepY*i,0.0);
////                pos_vert[(idx)*6+1] = Vec3(-1. + stepX*(j+1), -1. + stepY*i,0.0);
////                pos_vert[(idx)*6+2] = Vec3(-1. + stepX*j, -1. + stepY*(i+1),0.0);
////                
////                pos_vert[(idx)*6+3] = Vec3(-1. + stepX*j, -1. + stepY*(i+1),0.0);
////                pos_vert[(idx)*6+4] = Vec3(-1. + stepX*(j+1), -1. + stepY*i,0.0);
////                pos_vert[(idx)*6+5] = Vec3(-1. + stepX*(j+1), -1. + stepY*(i+1),0.0);
//            }
//        }
       
    }
    
    void update();
    void generatePV();
    void generateTV();
    void generateNV();
    void generateCV();
    void generateWire(Vec3*);
   
    void swap(int,int);
    
    Vec3* getPV()
    {
        return pos_vert;
    }
    Vec2* getTV()
    {
        return tex_vert;
    }
    Vec3* getNV()
    {
        return norm_vert;
    }
    
    Color4* getCV()
    {
        return color_vert;
    }
    
    
};
#endif
