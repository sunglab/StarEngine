//
//  StarOBJ.h
//  GeoArt
//
//  Created by Sungwoo Choi on 7/30/15.
//  Copyright (c) 2015 SungLab. All rights reserved.
//


#ifndef STARGEO_H
#define STARGEO_H
#include "../StarMain.h"



class StarGeo
{
public:
    virtual Vec3 generate(const Vec2& pos,float r) const;
//    virtual ~StarGeo();
};

class StarSphere
{
   // generate pos 0.0 to 1.0
public:
    virtual Vec3 generate(const Vec2& pos, float r) const
    {
        float u = pos.x, v = pos.y;
        float x = r * sin(u) * cos(v);
        float y = r * cos(u);
        float z = r * -sin(u) * sin(v);
        return Vec3(x,y,z);
    }
    ~StarSphere(){};
    
};
class StarStar
{
//    virtual Vec2 generate(unsigned int num, unsigned int ofNum float scale) const
//    {
//        
//    }
};
//class StarCube:StarGeo
//{
//public:
//    
//    unsigned short index;
//    
////    Vec3 generate(const Vec2& pos,Vec3& ratio) const
////    {
////        
////    }
//    
//};
#endif
