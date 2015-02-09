#ifndef PARTICLE_H
#define PARTICLE_H
#include "../StarMain.h"

class Points
{
public:
    Vec3 pos;
    Color4 color;
};

class Lines
{
public:
    Points head;
    Points tail;
};

class Particle
{
	public:
	Points point;

//	Vec3 angle;
//	Vec3 tranlation;
//	Vec3 scale;

	Particle();
	
};

class ParticleLine
{
public:
    Lines line;
//    Vec3 angle;
//	Vec3 tranlation;
//	Vec3 scale;
    
	ParticleLine();
    
};
#endif
