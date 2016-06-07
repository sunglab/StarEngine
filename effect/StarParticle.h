#ifndef PARTICLE_H
#define PARTICLE_H

#include "../math/Starmath.h"
#include "../tool/StarTouch.h"
#include <iostream>
#include <vector>

using namespace std;

typedef enum FLAME_MODE_ // change shape corre  corresponding to  in generate() // also it must be controled in update()
{
    FLAME_SMALL,
    FLAME_MID,
    FLAME_BIG,
    
    FLAME_ROYAL,
    FLAME_DIAMOND,
    FLAME_STAR,
    
}FLAME_MODE;

typedef enum FIREWORKS_MODE_ // animation BIG and SHAPE and so on in  update()
{
    FIREWORKS_SMALL,
    FIREWORKS_MID,
    FIREWORKS_BIG,
    
    FIREWORKS_ROYAL,
    FIREWORKS_TORNADO,
    FIREWORKS_ROCKET,
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
        //        angle = 3.14159265*0.5;
        //        lifetile = 7.0;
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
//template <>
//class StarParticleLINE<Vec2>
//{
//public:
//    Vec2 position;
//    Color4 color;
//public:
//    StarParticleLINE()
//    {
//        position.zero();
//        color.zero();
//    }
//};
//
//template <>
//class StarParticleLINE<Vec3>
//{
//public:
//    Vec3 position;
//    Color4 color;
//public:
//    StarParticleLINE()
//    {
//        position.zero();
//        color.zero();
//    }
//};

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
            //            particle_position[i*2] = particle_position[i*2+1] = Vec2(-10000.-10000.);
            particle_index[i*2+0] = (i*2+0);
            particle_index[i*2+1] = (i*2+1);
            //            particle_index.push_back(i*2+0);
            //            particle_index.push_back(i*2+1);
        }
        //        starLOG("%d %d %d\n", particle_index.size(),particle_power.size(), particle_position.size());
        //        printf("%d %d %d\n", particle_index.capacity(),particle_power.size(), particle_position.size());
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
 * Manager
 */

//template <typename t>
//class StarParticle_O_Array
//{
//public:
//    vector<t> pList;
//    
//};

/*
 * for supporting effects
 */

namespace starparticle
{
    
//    void getPolar(Vec3* position, Vec2* center, int idx, int total)
//    {
//        particle_position [idx*2+1] = particle_position [idx*2] = Vec3(center->x+cosf(2*M_PI*((float)idx/(float)total)), center->y+sinf(2*M_PI*((float)idx/(float)total)),particle_position [idx*2].z);
//    }
//    
   template<typename t>
    void setZeroTimer(unsigned int* timer,unsigned int exception)
    {
        for(int i=0;i<10;i++)
        {
            if(i!=exception)
            timer[i] = 0;
        }
    }

    template <typename t>
    void getAVG(StarTouch* startouch, t& avg)
    {
        int fingers = (startouch->fingers);
        Vec2* nowPos = (startouch->nowPos);
        if(fingers)
        {
        for(int a=0; a<fingers; a++ )
        {
            avg += nowPos[a];
        }
        avg /= fingers;
        }
        avg.z = 0;
        
    }
    
    template <typename t>
    void getCircleFingers(StarTouch* startouch, Vec2 *circle_finger_pos[], float& circumference, t& avg)
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
    
        
//        boom(Vec3* p,int count)
//        {
//            
//        }
        //        averA /= touch_number; // ANGLE
    
    
    
 
    
    
    //template <typename t>
    //bool isinCircle(float r,Vec2* finger,t particle)
    //{
    ////    if(r>(finger.x))
    //}
    
    //template <typename t>
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
    //template<typename t>
    //void getCircumference(StarTouch* startouch, float& circumference)//, t& avg) //taken out 'cause I don't need it yet
    //{
    //    int touch_number = startouch->fingers;
    //    if(touch_number>0)
    //    {
    //        for(int i=0;i<touch_number;i++)
    //        {
    //            if(i==(touch_number-1))
    //            {
    //                
    //                float lastx = ((*l_temp_touch_pos[0]).x-(*l_temp_touch_pos[i]).x);
    //                float lasty = ((*l_temp_touch_pos[0]).y-(*l_temp_touch_pos[i]).y);
    //                circumference += sqrt(lastx*lastx+lasty*lasty);
    //            }
    //            else
    //            {
    //                float norx =((*l_temp_touch_pos[i+1]).x-(*l_temp_touch_pos[i]).x);
    //                float nory =((*l_temp_touch_pos[i+1]).y-(*l_temp_touch_pos[i]).y);
    //                circumference += sqrt(norx*norx+nory*nory);
    //            }
    //            //            averA += atan2f(avg.y- (*l_temp_touch_pos[i]).y, avg.x- (*l_temp_touch_pos[i]).x);
    //        }
    //        //        averA /= touch_number; // ANGLE
    //    }
    //}
    
}
#endif
