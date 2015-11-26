#include "StarParticle.h"

void StarParticleManager<StarParticleLINE>::update()
{
    
    srand((unsigned)time(NULL));
    float angle;
    for(int i=0;i<count; i++)
    {
        pList[i*2+1].position= pList[i*2].position;
        angle = rand()%629*0.01;
        particle_power[i] += Vec2(cosf(angle),sinf(angle)) * 0.1;
        particle_position[i] += particle_power[i];
        particle_power[i] *= 0.9;
        pList[i*2].position = particle_position[i];
    }
    
}