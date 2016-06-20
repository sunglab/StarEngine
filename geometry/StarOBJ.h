//
//  StarOBJ.h
//  GeoArt
//
//  Created by Sungwoo Choi on 7/30/15.
//  Copyright (c) 2015 SungLab. All rights reserved.
//


#ifndef STAROBJ_H
#define STAROBJ_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "./StarStructure.h"
#include "../StarMain.h"


using namespace std;

class StarOBJ
{
public:
    StarOBJ(const string& , vector<Vec3>&, vector<Vec2>&, vector<Vec3>&, vector<unsigned short>&);
    
    void parseFace(const string& face,vector<unsigned short>& );
    
    unsigned int getVertexCount() const;
    unsigned int getIndexCount() const;
    unsigned int getNormalCount() const;
    
    mutable unsigned int vertexCount;
    mutable unsigned int indexCount;
    mutable unsigned int faceCount;
    mutable unsigned int normalCount;
    
    std::vector<unsigned short> temp_index;
    std::vector<Vec3> temp_normal;
    std::vector<Vec3> temp_position;
    std::vector<Vec2> temp_texcoord;
   
    string filepath;
    
const static int MAX_LINE= 128;
    
};
#endif /* defined(__GeoArt__StarOBJ__) */
