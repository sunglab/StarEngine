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
    Vec2* uv_vert;
public:
    virtual void generatePV()=0;
    virtual void generateTV()=0;
};

class StarGrid:public StarMesh
{
    
private:
    Vec2 grid;
    
public:
    StarGrid(Vec2 _grid):grid(_grid)
    {
        long total = (long)grid.x * (long)grid.y;
        pos_vert = new Vec3[total];
        uv_vert = new Vec2[total];
    }
    
    void generatePV()
    {
        
    }
    
    void generateTV()
    {
        
    }
    
};
#endif
