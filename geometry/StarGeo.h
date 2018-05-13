//
//  StarGeo.h
//
//  Created by Sungwoo Choi on 7/30/15.
//  Copyright (c) 2015 SungLab. All rights reserved.
//


#ifndef STARGEO_H
#define STARGEO_H
#include "../StarMain.h"
#include <vector>


class StarGeo
{
public:
   // virtual Vec3 generate(const Vec2& pos,float r) const {};
//    virtual ~StarGeo();
// Utils
    
    void extendTwoPoint(std::vector<Vec2>& pair_vertices, size_t size)
    {
        for(int i=0; i<pair_vertices.size()/2; i++) {
            float angle = atan2f(pair_vertices[i*2].y - pair_vertices[i*2+1].y,
                                  pair_vertices[i*2].x - pair_vertices[i*2+1].x);
           pair_vertices[i*2] += Vec2(cos(angle), sin(angle)) * size;
           pair_vertices[i*2+1] -= Vec2(cos(angle), sin(angle)) * size;
        }
    }
    void extendTwoPoint(std::vector<Vec3>& pair_vertices, size_t size)
    {
        for(int i=0; i<pair_vertices.size()/2; i++) {
            float angle = atan2f(pair_vertices[i*2].y - pair_vertices[i*2+1].y,
                                 pair_vertices[i*2].x - pair_vertices[i*2+1].x);
            pair_vertices[i*2] += Vec2(cos(angle), sin(angle)) * size;
            pair_vertices[i*2+1] -= Vec2(cos(angle), sin(angle)) * size;
        }
    }
    
    Vec2 intersection(Vec2 p1, Vec2 p2, Vec2 p3, Vec2 p4) {
        
        float x1 = p1.x, x2 = p2.x, x3 = p3.x, x4 = p4.x;
        float y1 = p1.y, y2 = p2.y, y3 = p3.y, y4 = p4.y;
        
        float d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
        if (d == 0) return Vec2(0.0);
        
        float pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
        float x = ( pre * (x3 - x4) - (x1 - x2) * post ) / d;
        float y = ( pre * (y3 - y4) - (y1 - y2) * post ) / d;
        
        if ( x < min(x1, x2) || x > max(x1, x2) ||
            x < min(x3, x4) || x > max(x3, x4) ) Vec2(0.0);
        if ( y < min(y1, y2) || y > max(y1, y2) ||
            y < min(y3, y4) || y > max(y3, y4) )Vec2(0.0);
        
        Vec2 ret;
        ret.x = x;
        ret.y = y;
        return ret;
    }
    Vec2 compute2DPolygonCentroid(vector<Vec2> vertices)
    {
        Vec2 centroid = {0, 0};
        double signedArea = 0.0;
        double x0 = 0.0; // Current vertex X
        double y0 = 0.0; // Current vertex Y
        double x1 = 0.0; // Next vertex X
        double y1 = 0.0; // Next vertex Y
        double a = 0.0;  // Partial signed area
        
        // For all vertices except last
        int i=0;
        for (i=0; i< vertices.size()-1 ; ++i)
        {
            x0 = vertices[i].x;
            y0 = vertices[i].y;
            x1 = vertices[i+1].x;
            y1 = vertices[i+1].y;
            a = x0*y1 - x1*y0;
            signedArea += a;
            centroid.x += (x0 + x1)*a;
            centroid.y += (y0 + y1)*a;
        }
        
        // Do last vertex separately to avoid performing an expensive
        // modulus operation in each iteration.
        x0 = vertices[i].x;
        y0 = vertices[i].y;
        x1 = vertices[0].x;
        y1 = vertices[0].y;
        a = x0*y1 - x1*y0;
        signedArea += a;
        centroid.x += (x0 + x1)*a;
        centroid.y += (y0 + y1)*a;
        
        signedArea *= 0.5;
        centroid.x /= (6.0*signedArea);
        centroid.y /= (6.0*signedArea);
        
        return centroid;
    }
};

class StarSphere//: public StarGeo
{
//	float M_PI = 3.1415f;
   // generate pos 0.0 to 1.0
public:
	Vec2 domain(float x, float y,float side)
	{
		//float pi_2 = 6.28318548;
		return Vec2(x*M_PI/(side - 1.), y*2.*M_PI/(side - 1.));
	//	return Vec2(x*2.*M_PI/(side - 1.), y*2.*M_PI/(side - 1.));
		//return Vec2(x*pi_2/(side - 1.), y*pi_2/(side - 1.));
	}
    virtual Vec3 generate(const Vec2& pos, float r = 1.0) const
    {
        float u = pos.x, v = pos.y;
        float x = r * sin(u) * cos(v);
        float y = r * cos(u);
        float z = r * -sin(u) * sin(v);
        return Vec3(x,y,z);
    }
    virtual
    ~StarSphere(){};
    
};

class StarCube
{
public:
    virtual Vec3 generate(const Vec2& pos, float r = 1.0) const
    {
        float u = pos.x, v = pos.y;
        float x = r * sin(u) * cos(v);
        float y = r * cos(u);
        float z = r * -sin(u) * sin(v);
        return Vec3(x,y,z);
    }
    ~StarCube(){};
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
