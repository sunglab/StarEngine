//
//  StarOBJ.cpp
//  GeoArt
//
//  Created by Sungwoo Choi on 7/30/15.
//  Copyright (c) 2015 SungLab. All rights reserved.
//

#include "StarOBJ.h"

#include <boost/tokenizer.hpp>
using namespace std;
using namespace boost;

StarOBJ::StarOBJ(const string& path, vector<Vec3>& position, vector<Vec2>& texcoord,vector<Vec3>& normal,  vector<unsigned short>& index):filepath(path)
{
    string line;
    unsigned int v=0, vt=0, vn=0, lines=0;
    unsigned short offset = 0;
    ifstream objfile(path.c_str());
    
    if(!objfile)
        starLOG("file not open\n");
    else
        while (std::getline(objfile,line))
        {
            istringstream lineSS(line);
            string lineType;
            lineSS >> lineType;
            
            // vertex
            if( lineType == "v" )
            {
                v++;
                float x = 0 ,y = 0,z = 0;
                lineSS >> x >> y >> z ;
                temp_position.push_back( Vec3( x, y, z));
            }
            
            // texture
            else if( lineType == "vt" )
            {
                vt++;
                float u = 0, v = 0;
                lineSS >> u >> v ;
                temp_texcoord.push_back(Vec2( u, v ));
            }
            
            // normal
            else if( lineType == "vn" )
            {
                vn++;
                float x = 0, y = 0, z = 0;
                lineSS >> x >> y >> z;
                temp_normal.push_back(Vec3( x, y, z ).normalize());
            }
            
            else if( lineType == "f" )
            {
                string i,j,k;
                //            string m,n,o;
                lineSS >> i >> j >> k;
                parseFace(i,index);
                parseFace(j,index);
                parseFace(k,index);
                
                //           if((!vn) && (!vt))
                //           {
                //            lineSS >> i >> j >> k;
                //            idx.push_back(i-1);
                //            idx.push_back(j-1);
                //            idx.push_back(k-1);
                //           }
                //           else if((vn) && (!vt))
                //           {
                //               
                //           }
                //           else if((!vn) && (vt))
                //           {
                //               
                //           }
                //           else if((vn) && (vt))
                //           {
                //               
                //           
                //           }
                //           else
                //           {
                //               starLOG("doesn't make sense\n");
                //               starLOG("doesn't make sense\n");
                //               starLOG("doesn't make sense\n");
                //               starLOG("doesn't make sense\n");
                //           }
            }
        }
    
    if(vn)
        offset++;
    if(vt)
        offset++;
    
    for(vector<unsigned short>::iterator itr=index.begin(); itr!=index.end();itr++)
        position.push_back(temp_position[*itr]);
    
    if((offset==1) && vt)
    {
        for(vector<unsigned short>::iterator itr=temp_index.begin(); itr!=temp_index.end();itr++)
            texcoord.push_back(temp_texcoord[*itr]);
    }
    else if((offset==1) && vn)
    {
        for(vector<unsigned short>::iterator itr=temp_index.begin(); itr!=temp_index.end();itr++)
            normal.push_back(temp_normal[*itr]);
    }
    else if(offset==2)
    {
        int i = 0;
        for(vector<unsigned short>::iterator itr=temp_index.begin(); itr!=temp_index.end();itr++,i++)
        {
            if((i%2))
                normal.push_back(temp_normal[*itr]);
            else
                texcoord.push_back(temp_texcoord[*itr]);
        }
    }
    else
    {
        
    }
    
    starLOG("\nv = %d vn = %d vt = %d f = %d offset = %d lines = %d\n", position.size(), normal.size(), texcoord.size(), index.size(),offset, lines);
    starLOG("v = %d vn = %d vt = %d f = %d offset = %d lines = %d\n", position.size(), temp_normal.size(), temp_texcoord.size(), temp_index.size(),offset, lines);
    
}

void StarOBJ::parseFace(const string& faces, vector<unsigned short>& idx)
{
    boost::char_separator<char> sep("/");
    boost::tokenizer<boost::char_separator<char> > tokens(faces, sep);
    for(tokenizer<boost::char_separator<char> >::iterator itridx=tokens.begin(); itridx!=tokens.end();itridx++)
    {
        if(itridx==tokens.begin())
            idx.push_back(std::stoi((*itridx))-1);
        else
            temp_index.push_back(std::stoi(*itridx)-1);
    }
    
}

unsigned int StarOBJ::getVertexCount() const
{
    return vertexCount;
}

unsigned int StarOBJ::getNormalCount() const
{
    return normalCount;
}
