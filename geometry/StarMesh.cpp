//
//  StarGeo.cpp
//
//  Created by Sungwoo Choi on 7/30/15.
//  Copyright (c) 2015 SungLab. All rights reserved.
//

#include "StarMesh.h"


//void StarGrid::update()
//{
//    unsigned int idx_grid = 0;
//    
//    for(int i=1; i<(height); i++)
//    {
//        for(int j=1; j<width; j++)
//        {
//            idx_grid = i*(width+1)+j;
//            
//            float randAngle = rand()%628*0.01;
//            float randAlpha = rand()%628*0.01;
//            grid_power[idx_grid] -= Vec3(sinf(randAngle)*cosf(randAlpha),sinf(randAngle)*sinf(randAlpha),cosf(randAngle))*0.1;
//            
//            grid_position[idx_grid].z += grid_power[idx_grid].z;
//            grid_position[idx_grid].x = 0.0;
//            grid_position[idx_grid].y = 0.0;
//            
//            if((grid_position[idx_grid].z)<0.0||(grid_position[idx_grid].z)>100)
//                grid_position[idx_grid].z = 0.0;
//            
//        }
//    }
//    
////    starLOG("grid[0]:%f\n", grid_position[0].z);
////    starLOG("grid[1]:%f\n", grid_position[1].z);
//    float stepX = 2.0/width;
//    float stepY = 2.0/height;
//    unsigned int idx = 0;
//    
//    for(int i=0; i<height; i++)
//    {
//        for(int j=0; j<width; j++)
//        {
//            
//            idx_grid = i*(width+1)+j;
//            idx = i*width+j;
//            
//            pos_vert[(idx)*6+0] = Vec3(-1. + stepX*j, -1.+ stepY*i,0.0);
//            pos_vert[(idx)*6+1] = Vec3(-1. + stepX*(j+1), -1. + stepY*i,0.0);
//            pos_vert[(idx)*6+2] = Vec3(-1. + stepX*j, -1. + stepY*(i+1),0.0);
//            
//            pos_vert[(idx)*6+3] = Vec3(-1. + stepX*j, -1. + stepY*(i+1),0.0);
//            pos_vert[(idx)*6+4] = Vec3(-1. + stepX*(j+1), -1. + stepY*i,0.0);
//            pos_vert[(idx)*6+5] = Vec3(-1. + stepX*(j+1), -1. + stepY*(i+1),0.0);
//            
//            for(int z=0;z<6;z++)
//            {
//                pos_vert[(idx)*6+z].x *= screen.x;
//                pos_vert[(idx)*6+z].y *= screen.y;
//            }
//            
////            starLOG("grid[0]:%d  %f\n",idx_grid, grid_position[idx_grid].z);
////            starLOG("grid[1]:%d  %f\n",idx_grid+width+1, grid_position[idx_grid+width+1].z);
////       if(j!=0)
////       {
//            pos_vert[(idx)*6+0] += grid_position[idx_grid];
//            pos_vert[(idx)*6+1] += grid_position[idx_grid+1];
//            pos_vert[(idx)*6+2] += grid_position[idx_grid+width+1];
//            pos_vert[(idx)*6+3] += grid_position[idx_grid+width+1];
//            pos_vert[(idx)*6+4] += grid_position[idx_grid+1];
//            pos_vert[(idx)*6+5] += grid_position[idx_grid+width+2];
////            pos_vert[(idx)*6+0] += grid_position[idx_grid+width+2];
////            pos_vert[(idx)*6+1] += grid_position[idx_grid];
////            pos_vert[(idx)*6+2] += grid_position[idx_grid+1];
////            pos_vert[(idx)*6+3] += grid_position[idx_grid+1];
////            pos_vert[(idx)*6+4] += grid_position[idx_grid+width+2];
////            pos_vert[(idx)*6+5] += grid_position[idx_grid+width+3];
////       }
////       else
////       {
//////           pos_vert[(idx)*6+0] += 0;
//////           pos_vert[(idx)*6+1] += 0;
//////           pos_vert[(idx)*6+2] += 0;
//////           pos_vert[(idx)*6+3] += grid_position[idx_grid+width+2];
//////           pos_vert[(idx)*6+4] += grid_position[idx_grid+1];
//////           pos_vert[(idx)*6+5] += grid_position[idx_grid+width+3];
////       }
////            if(j==0)
////            {
////                pos_vert[(idx)*6+0].zero();// += grid_position[idx_grid];
////                pos_vert[(idx)*6+1].zero();// += grid_position[idx_grid+1];
////                pos_vert[(idx)*6+2].zero(); //+= grid_position[idx_grid+width+2];
////                pos_vert[(idx)*6+3].zero();// += grid_position[idx_grid+width+2];
////                pos_vert[(idx)*6+4].zero();// += grid_position[idx_grid+1];
////                pos_vert[(idx)*6+5].zero();// += grid_position[idx_grid+width+3];
////            }
////            starLOG("hi\n");
////            norm_vert[(idx)*6+0] = (pos_vert[(idx)*6+1]).cross(pos_vert[(idx)*6+2]);
////            norm_vert[(idx)*6+1] = pos_vert[(idx)*6+2].cross(pos_vert[(idx)*6+0]);
////            norm_vert[(idx)*6+2] = pos_vert[(idx)*6+0].cross(pos_vert[(idx)*6+1]);
////            norm_vert[(idx)*6+3] = pos_vert[(idx)*6+4].cross(pos_vert[(idx)*6+5]);
////            norm_vert[(idx)*6+4] = pos_vert[(idx)*6+5].cross(pos_vert[(idx)*6+3]);
////            norm_vert[(idx)*6+5] = pos_vert[(idx)*6+3].cross(pos_vert[(idx)*6+4]);
//            
//            norm_vert[(idx)*6+0] = (pos_vert[(idx)*6+1]-pos_vert[(idx)*6+0]).cross((pos_vert[(idx)*6+2]-pos_vert[(idx)*6+0]));//*-1.0;
//            norm_vert[(idx)*6+1] = (pos_vert[(idx)*6+2]-pos_vert[(idx)*6+1]).cross((pos_vert[(idx)*6+0]-pos_vert[(idx)*6+1]));//*-1.0;
//            norm_vert[(idx)*6+2] = (pos_vert[(idx)*6+0]-pos_vert[(idx)*6+2]).cross((pos_vert[(idx)*6+1]-pos_vert[(idx)*6+2]));//*-1.0;
//            norm_vert[(idx)*6+3] = (pos_vert[(idx)*6+4]-pos_vert[(idx)*6+3]).cross((pos_vert[(idx)*6+5]-pos_vert[(idx)*6+3]));//*-1.0;
//            norm_vert[(idx)*6+4] = (pos_vert[(idx)*6+5]-pos_vert[(idx)*6+4]).cross((pos_vert[(idx)*6+3]-pos_vert[(idx)*6+4]));//*-1.0;
//            norm_vert[(idx)*6+5] = (pos_vert[(idx)*6+3]-pos_vert[(idx)*6+5]).cross((pos_vert[(idx)*6+4]-pos_vert[(idx)*6+5]));//*-1.0;
//            
//            //                norm_vert[(idx)*6+0].normalize();
//            //                norm_vert[(idx)*6+1].normalize();
//            //                norm_vert[(idx)*6+2].normalize();
//            //                norm_vert[(idx)*6+3].normalize();
//            //                norm_vert[(idx)*6+4].normalize();
//            //                norm_vert[(idx)*6+5].normalize();
//            
//            //                norm_vert[(idx)*6+0]/=(norm_vert[(idx)*6+0]).length();
//            //                norm_vert[(idx)*6+1]/=(norm_vert[(idx)*6+1]).length();
//            //                norm_vert[(idx)*6+2]/=(norm_vert[(idx)*6+2]).length();
//            //                norm_vert[(idx)*6+3]/=(norm_vert[(idx)*6+3]).length();
//            //                norm_vert[(idx)*6+4]/=(norm_vert[(idx)*6+4]).length();
//            //                norm_vert[(idx)*6+5]/=(norm_vert[(idx)*6+5]).length();
//            
////            norm_vert[(idx)*6+0]= Vec3(0,0,1.*(float)idx/(width*height));
////            norm_vert[(idx)*6+1]= Vec3(0,0,1.*(float)idx/(width*height));
////            norm_vert[(idx)*6+2]= Vec3(0,0,1.*(float)idx/(width*height));
////            norm_vert[(idx)*6+3]= Vec3(0,0,1.*(float)idx/(width*height));
////            norm_vert[(idx)*6+4]= Vec3(0,0,1.*(float)idx/(width*height));
////            norm_vert[(idx)*6+5]= Vec3(0,0,1.*(float)idx/(width*height));
//            
//            norm_vert[(idx)*6+0].normalize();
//            norm_vert[(idx)*6+1].normalize();
//            norm_vert[(idx)*6+2].normalize();
//            norm_vert[(idx)*6+3].normalize();
//            norm_vert[(idx)*6+4].normalize();
//            norm_vert[(idx)*6+5].normalize();
//            
//            
//        }
//    }
//}

void StarGrid::update()
{
    unsigned int idx_grid = 0;
    
    for(int i=1; i<(height); i++)
    {
        for(int j=1; j<width; j++)
        {
            idx_grid = i*(width)+j;
            
            float randAngle = rand()%628*0.01;
            float randAlpha = rand()%628*0.01;
            
//            grid_power[idx_grid] -= Vec3(sinf(randAngle)*cosf(randAlpha),sinf(randAngle)*sinf(randAlpha),cosf(randAngle))*0.0001;
            
            if((grid_position[idx_grid]-grid_destination[idx_grid]).length()<0.01)
            {
                grid_position[idx_grid] = grid_destination[idx_grid];
            }
            else
            {
           float angle =  atan2(grid_position[idx_grid].y-grid_destination[idx_grid].y,
                  grid_position[idx_grid].x - grid_destination[idx_grid].x);
            
            grid_power[idx_grid] -= Vec2(cos(angle),sin(angle))*0.0001;
            grid_position[idx_grid].z = 0.0;
            grid_position[idx_grid].x += grid_power[idx_grid].x;
            grid_position[idx_grid].y += grid_power[idx_grid].y;
            
            
            if((grid_position[idx_grid].z)<0.0||(grid_position[idx_grid].z)>100)
                grid_position[idx_grid].z = 0.0;
            }
            
        }
    }
    
    float stepX = 2.0/width;
    float stepY = 2.0/height;
    unsigned int idx = 0;
    
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            
            idx_grid = i*(width)+j;
            idx = i*width+j;
            
            
            //i=0;
            //j=0;
            pos_vert[(idx)*6+0] = Vec3(-1. + stepX*0, -1.+ stepY*0,0.0);
            pos_vert[(idx)*6+1] = Vec3(-1. + stepX*(0+1), -1. + stepY*0,0.0);
            pos_vert[(idx)*6+2] = Vec3(-1. + stepX*0, -1. + stepY*(0+1),0.0);
            pos_vert[(idx)*6+3] = Vec3(-1. + stepX*0, -1. + stepY*(0+1),0.0);
            pos_vert[(idx)*6+4] = Vec3(-1. + stepX*(0+1), -1. + stepY*0,0.0);
            pos_vert[(idx)*6+5] = Vec3(-1. + stepX*(0+1), -1. + stepY*(0+1),0.0);
            
//            pos_vert[(idx)*6+0] = Vec3(-1. + stepX*j, -1.+ stepY*i,0.0);
//            pos_vert[(idx)*6+1] = Vec3(-1. + stepX*(j+1), -1. + stepY*i,0.0);
//            pos_vert[(idx)*6+2] = Vec3(-1. + stepX*j, -1. + stepY*(i+1),0.0);
//            pos_vert[(idx)*6+3] = Vec3(-1. + stepX*j, -1. + stepY*(i+1),0.0);
//            pos_vert[(idx)*6+4] = Vec3(-1. + stepX*(j+1), -1. + stepY*i,0.0);
//            pos_vert[(idx)*6+5] = Vec3(-1. + stepX*(j+1), -1. + stepY*(i+1),0.0);
            
            pos_vert[(idx)*6+0] += grid_position[idx_grid];
            pos_vert[(idx)*6+1] += grid_position[idx_grid];
            pos_vert[(idx)*6+2] += grid_position[idx_grid];
            pos_vert[(idx)*6+3] += grid_position[idx_grid];
            pos_vert[(idx)*6+4] += grid_position[idx_grid];
            pos_vert[(idx)*6+5] += grid_position[idx_grid];
        }
    }
}
void StarGrid::swap(int idx1, int idx2)
{
    float stepX = 2.0/width;
    float stepY = 2.0/height;
    
    grid_power[idx1].zero();
    grid_power[idx2].zero();
    Vec2 temp = grid_destination[idx1].xy();
    grid_destination[idx1] = grid_destination[idx2];
    grid_destination[idx2] = temp;
                     
//        Vec3* ret= new Vec3[width*height*6];
//    for(int i=0; i<height; i++)
//    {
//        for(int j=0; j<width; j++)
//        {
//    for(int i=0;i<6;i++)
//    {
//        int idx = idx1;
//        grid_position[(idx1)] = pos_vert[(idx2)*6+0];
////        pos_vert[(idx)*6+1] = pos_vert[(idx2)*6+1];
////        pos_vert[(idx)*6+2] = pos_vert[(idx2)*6+2];
////        pos_vert[(idx)*6+3] = pos_vert[(idx2)*6+3];
////        pos_vert[(idx)*6+4] = pos_vert[(idx2)*6+4];
////        pos_vert[(idx)*6+5] = pos_vert[(idx2)*6+5];
//    }
//        }
//    }
}
void StarGrid::generateTV()
{
    
    float stepX = 1.0/width;
    float stepY = 1.0/height;
    
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            tex_vert[(i*width+j)*6+0] = Vec2(0.0 + stepX*j, 0.0+ stepY*i);
            tex_vert[(i*width+j)*6+1] = Vec2(0.0 + stepX*(j+1), 0.0 + stepY*i);
            tex_vert[(i*width+j)*6+2] = Vec2(0.0 + stepX*j, 0.0 + stepY*(i+1));
            
            tex_vert[(i*width+j)*6+3] = Vec2(0.0 + stepX*j, 0.0 + stepY*(i+1));
            tex_vert[(i*width+j)*6+4] = Vec2(0.0 + stepX*(j+1), 0.0 + stepY*i);
            tex_vert[(i*width+j)*6+5] = Vec2(0.0 + stepX*(j+1), 0.0 + stepY*(i+1));
        }
    }
}

void StarGrid::generatePV()
{
    
    float stepX = 2.0/width;
    float stepY = 2.0/height;
    
    //        Vec3* ret= new Vec3[width*height*6];
    
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int idx = i*width+j;
            
            pos_vert[(idx)*6+0] = Vec3(-1. + stepX*j, -1.+ stepY*i,0.0);
            pos_vert[(idx)*6+1] = Vec3(-1. + stepX*(j+1), -1. + stepY*i,0.0);
            pos_vert[(idx)*6+2] = Vec3(-1. + stepX*j, -1. + stepY*(i+1),0.0);
            
            pos_vert[(idx)*6+3] = Vec3(-1. + stepX*j, -1. + stepY*(i+1),0.0);
            pos_vert[(idx)*6+4] = Vec3(-1. + stepX*(j+1), -1. + stepY*i,0.0);
            pos_vert[(idx)*6+5] = Vec3(-1. + stepX*(j+1), -1. + stepY*(i+1),0.0);
        }
    }
}
void StarGrid::generateCV()
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
             int idx = i*width+j;
//            float color = ((idx)*((int)(idx/6)))%4;
            Color4 color;
            int random = rand()%4+1;
            if(random ==1)
                color = Color4(1.0,0.0,0.0,1.0);
            if(random ==2)
                color = Color4(0.0,1.0,0.0,1.0);
            if(random ==3)
                color = Color4(0.0,0.0,1.0,1.0);
            if(random ==4)
                color = Color4(1.0,1.0,0.0,1.0);
            
//            float color = (idx) / total_vert_tri;
            
//            color_vert[(i*width+j)*6+0] = Color4(color*0.25);
//            color_vert[(i*width+j)*6+1] = Color4(color*0.25);
//            color_vert[(i*width+j)*6+2] = Color4(color*0.25);
//            color_vert[(i*width+j)*6+3] = Color4(color*0.25);
//            color_vert[(i*width+j)*6+4] = Color4(color*0.25);
//            color_vert[(i*width+j)*6+5] = Color4(color*0.25);
            
//            int idx = i*width+j;
            
            color_vert[(i*width+j)*6+0] = color;
            color_vert[(i*width+j)*6+1] = color;
            color_vert[(i*width+j)*6+2] = color;
            color_vert[(i*width+j)*6+3] = color;
            color_vert[(i*width+j)*6+4] = color;
            color_vert[(i*width+j)*6+5] = color;
            
        }
    }
}
void StarGrid::generateNV()
{
    
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            //                norm_vert[(idx)*6+0] = pos_vert[(idx)*6+1].cross(pos_vert[(idx)*6+2]);
            //                norm_vert[(idx)*6+1] = pos_vert[(idx)*6+2].cross(pos_vert[(idx)*6+0]);
            //                norm_vert[(idx)*6+2] = pos_vert[(idx)*6+0].cross(pos_vert[(idx)*6+1]);
            //
            //                norm_vert[(idx)*6+3] = pos_vert[(idx)*6+4].cross(pos_vert[(idx)*6+5]);
            //                norm_vert[(idx)*6+4] = pos_vert[(idx)*6+5].cross(pos_vert[(idx)*6+3]);
            //                norm_vert[(idx)*6+5] = pos_vert[(idx)*6+3].cross(pos_vert[(idx)*6+4]);
            int idx = i*width+j;
            
            norm_vert[(idx)*6+0] = pos_vert[(idx)*6+1].cross(pos_vert[(idx)*6+2]);
            norm_vert[(idx)*6+1] = pos_vert[(idx)*6+2].cross(pos_vert[(idx)*6+0]);
            norm_vert[(idx)*6+2] = pos_vert[(idx)*6+0].cross(pos_vert[(idx)*6+1]);
            
            norm_vert[(idx)*6+3] = pos_vert[(idx)*6+4].cross(pos_vert[(idx)*6+5]);
            norm_vert[(idx)*6+4] = pos_vert[(idx)*6+5].cross(pos_vert[(idx)*6+3]);
            norm_vert[(idx)*6+5] = pos_vert[(idx)*6+3].cross(pos_vert[(idx)*6+4]);
            
            norm_vert[(idx)*6+0].normalize();
            norm_vert[(idx)*6+1].normalize();
            norm_vert[(idx)*6+2].normalize();
            norm_vert[(idx)*6+3].normalize();
            norm_vert[(idx)*6+4].normalize();
            norm_vert[(idx)*6+5].normalize();
        }
    }
}
void StarGrid::generateWire(Vec3* line)
{
    int idx = 0;
    for(int h=0;h<height;h++)
        for(int w=0;w<width;w++)
        {
            int idx_rect = h*width+w;
            
            
//            int idx_grid = h*(width+1)+w;
            int TAIL = 2;
            
            line[idx * TAIL] = pos_vert[(idx_rect)*6+0];
            line[((idx++) * TAIL)+1] =  pos_vert[(idx_rect)*6+1];
            line[idx * TAIL] =  pos_vert[(idx_rect)*6+0];
            line[((idx++) * TAIL)+1] =  pos_vert[(idx_rect)*6+2];
            
            if(h==height-1)
            {
                line[(idx) * TAIL]  =  pos_vert[(idx_rect)*6+2];
                line[((idx++) * TAIL)+1]  = pos_vert[(idx_rect)*6+3];
            }
            if(w==width-1)
            {
                line[(idx) * TAIL]  = pos_vert[(idx_rect)*6+3];
                line[((idx++) * TAIL)+1]  =  pos_vert[(idx_rect)*6+1];
            }
            
//            line[idx * TAIL] = grid_position[idx_grid] + pos_vert[(idx_rect)*6+0];
//            line[((idx++) * TAIL)+1] = grid_position[idx_grid+1] + pos_vert[(idx_rect)*6+1];
//            line[idx * TAIL] = grid_position[idx_grid] + pos_vert[(idx_rect)*6+0];
//            line[((idx++) * TAIL)+1] = grid_position[idx_grid+width+1] + pos_vert[(idx_rect)*6+2];
//            
//            if(h==height-1)
//            {
//                line[(idx) * TAIL]  = grid_position[idx_grid+width+1] + pos_vert[(idx_rect)*6+2];
//                line[((idx++) * TAIL)+1]  = grid_position[idx_grid+width+2] + pos_vert[(idx_rect)*6+3];
//            }
//            if(w==width-1)
//            {
//                line[(idx) * TAIL]  = grid_position[idx_grid+width+2] + pos_vert[(idx_rect)*6+3];
//                line[((idx++) * TAIL)+1]  = grid_position[idx_grid+1] + pos_vert[(idx_rect)*6+1];
//            }

         //   starLOG("%f\n",line[(idx) * TAIL].z);
//            if(h==height-1&&w==width-1)
//                starLOG("width : %d height %d last index %d %d\n", width, height, idx, total_wire_rect);
        }
}
