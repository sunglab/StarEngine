//
//  StarParticle.h
//
//  Created by Sungwoo Choi on 7/30/15.
//  Copyright (c) 2015 SungLab. All rights reserved.
//

#ifndef PARTICLE_H
#define PARTICLE_H

#include "../tool/StarTouch.h"
#include <iostream>
#include <vector>

using namespace std;

typedef enum FLAME_MODE_ // change shape corresponding to  in generate() // also it must be controled in update()
{
    FLAME_SMALL,
    FLAME_MID,
    FLAME_BIG,
    
    FLAME_ROYAL,
    FLAME_DIAMOND,
    FLAME_STAR,
    
}FLAME_MODE;

typedef enum 
{
    FIREWORKS_MID,
    
    FIREWORKS_MULTI,
    
    FIREWORKS_RAINBOW,
    
}FIREWORKS_MODE;

class StarParticleTEX
{
    
public:
    Vec2 position;
    Vec2 texCoord;
    Color4 color;
    
public:
    StarParticleTEX()
    {
        position.zero();
        texCoord.zero();
        color.zero();
    }
};

//template <typename t>
class StarParticleLINE
{
public:
    Vec2 position;
    Color4 color;
public:
    StarParticleLINE()
    {
        position.zero();
        color.zero();
    }
    
};

template <typename t> class StarParticleManager
{
public:
    vector<t> pList;
};

template <> class StarParticleManager<StarParticleLINE>
{
public:
    vector<StarParticleLINE> pList;
public:
    vector<Vec2> particle_position;
    vector<Vec2> particle_power;
    vector<unsigned short> particle_index;
    
    unsigned int index;
    unsigned int count;
public:
    StarParticleManager(unsigned int howmany)
    {
        
        index = 0;
        count = howmany;
        
        pList.reserve(howmany*2);
        particle_position.reserve(howmany*2);
        particle_index.reserve(howmany*2);
        particle_power.reserve(howmany);
        
        for(int i=0; i<howmany; i++)
        {
            particle_index[i*2+0] = (i*2+0);
            particle_index[i*2+1] = (i*2+1);
        }
    }
    
    StarParticleLINE& getPosition()
    {
        return pList[0];
    }
    StarParticleLINE& getColor()
    {
        return (pList[sizeof(pList[0].position)]);
    }
    unsigned short* getIndex()
    {
        return (&particle_index[0]);
    }
    unsigned int getIndexNum()
    {
        return particle_index.capacity();
    }
    unsigned int getOffset()
    {
        return sizeof(StarParticleLINE);
    }
    void update();
};

template <> class StarParticleManager<StarParticleTEX>
{
public:
    vector<StarParticleTEX> pList;
    
public:
    vector<Vec2> particle_position;
    vector<Vec2> particle_power;
    vector<unsigned short> particle_index;
    vector<float> particle_angle;
    vector<float> particle_lifetime;
    
    vector<FLAME_MODE> particle_mode; // it'll be decided by gen(), it will decide TEX_COORD
    
public:
    StarParticleManager(unsigned int howmany)
    {
        
    }
};

/*
 * for supporting effects
 */

namespace starparticle
{
    
   template<typename t>
    void setZeroTimer(unsigned int* timer,unsigned int exception)
    {
        for(int i=0;i<10;i++)
        {
            if(i!=exception)
            timer[i] = 0;
        }
    }

    void getAVG(std::shared_ptr<StarTouch> startouch, Vec3& avg, const int fingers)
    {
        if(fingers == 0)
            return;
        
        Vec2* nowPos = (startouch->nowPos);
        for(int a=0; a<fingers; a++)
            avg += nowPos[a];
        avg /= fingers;
    }
    
    void getCircleFingers(std::shared_ptr<StarTouch> startouch, Vec2 *circle_finger_pos[], float& circumference, Vec3& avg)
    {
        for(int i = 0;i<10;i++)//total touch must be 10
        {
            (circle_finger_pos[i]) = &(startouch->nowPos[i]);
        }
        
        // Circle Finger
        int touch_number = startouch->fingers;
        Vec2* temp_finger_pos;
        Vec2** l_temp_touch_pos = circle_finger_pos;
        
        circumference = 0.0;
        if(touch_number>0)
        {
            for(int cc=0;cc<touch_number-1;cc++)
                for(int dd=0;dd<touch_number-1;dd++)
                {
                    if(atan2f(avg.y-(*l_temp_touch_pos[dd]).y, avg.x-(*l_temp_touch_pos[dd]).x)<atan2f(avg.y-(*l_temp_touch_pos[dd+1]).y, avg.x-(*l_temp_touch_pos[dd+1]).x))//when angle is small than other
                    {
                        temp_finger_pos=(l_temp_touch_pos[dd]);
                        (l_temp_touch_pos[dd])= (l_temp_touch_pos[dd+1]);
                        (l_temp_touch_pos[dd+1]) = temp_finger_pos;
                    }
                }
            
            for(int i=0;i<touch_number;i++)
            {
                if(i==(touch_number-1))
                {
                    
                    float lastx = ((*l_temp_touch_pos[0]).x-(*l_temp_touch_pos[i]).x);
                    float lasty = ((*l_temp_touch_pos[0]).y-(*l_temp_touch_pos[i]).y);
                    circumference += sqrt(lastx*lastx+lasty*lasty);
                }
                else
                {
                    float norx =((*l_temp_touch_pos[i+1]).x-(*l_temp_touch_pos[i]).x);
                    float nory =((*l_temp_touch_pos[i+1]).y-(*l_temp_touch_pos[i]).y);
                    circumference += sqrt(norx*norx+nory*nory);
                }
                            avg.z += atan2f(avg.y- (*l_temp_touch_pos[i]).y, avg.x- (*l_temp_touch_pos[i]).x);
            }
            avg.z /= touch_number;
        }
    }
    
    
    void getCircleFingers(Vec2* nowPos,int fingers, Vec2 *circle_finger_pos[], float& circumference, Vec3& avg)
    {
        for(int i = 0;i<10;i++)//total touch must be 10
        {
            (circle_finger_pos[i]) = &nowPos[i];
        }
        
        // Circle Finger
        int touch_number = fingers;
        Vec2* temp_finger_pos;
        Vec2** l_temp_touch_pos = circle_finger_pos;
        
        circumference = 0.0;
        if(touch_number>0)
        {
            for(int cc=0;cc<touch_number-1;cc++)
                for(int dd=0;dd<touch_number-1;dd++)
                {
                    if(atan2f(avg.y-(*l_temp_touch_pos[dd]).y, avg.x-(*l_temp_touch_pos[dd]).x)<atan2f(avg.y-(*l_temp_touch_pos[dd+1]).y, avg.x-(*l_temp_touch_pos[dd+1]).x))//when angle is small than other
                    {
                        temp_finger_pos=(l_temp_touch_pos[dd]);
                        (l_temp_touch_pos[dd])= (l_temp_touch_pos[dd+1]);
                        (l_temp_touch_pos[dd+1]) = temp_finger_pos;
                    }
                }
            
            for(int i=0;i<touch_number;i++)
            {
                if(i==(touch_number-1))
                {
                    
                    float lastx = ((*l_temp_touch_pos[0]).x-(*l_temp_touch_pos[i]).x);
                    float lasty = ((*l_temp_touch_pos[0]).y-(*l_temp_touch_pos[i]).y);
                    circumference += sqrt(lastx*lastx+lasty*lasty);
                }
                else
                {
                    float norx =((*l_temp_touch_pos[i+1]).x-(*l_temp_touch_pos[i]).x);
                    float nory =((*l_temp_touch_pos[i+1]).y-(*l_temp_touch_pos[i]).y);
                    circumference += sqrt(norx*norx+nory*nory);
                }
                avg.z += atan2f(avg.y- (*l_temp_touch_pos[i]).y, avg.x- (*l_temp_touch_pos[i]).x);
            }
            avg.z /= touch_number;
        }
    }
    
    typedef struct isinCircle_
    {
        bool operator()(Vec2* dis,float r)
        {
            if(((*dis).x*(*dis).x+(*dis).y*(*dis).y)<r)
                return 1;
            else
                return 0;
        }
    }IsinCircle;
    
    //template <typename t>
    typedef struct IsoutRect_
    {
        bool operator()(Vec2* particle, Vec2* rect)
        {
            if( ((*particle).x < 0.) ||  ((*particle).x > (*rect).x) || ((*particle).y < 0) || ((*particle).y < (*rect).y))
                return 1;
            else
                return 0;
        }
        bool operator()(Vec3* particle,Vec2* rect)
        {
            if( ((*particle).x < 0.) ||  ((*particle).x > (*rect).x) || ((*particle).y < 0) || ((*particle).y > (*rect).y))
                return 1;
            else
                return 0;
        }
        
    }IsoutRect;
}
#endif
