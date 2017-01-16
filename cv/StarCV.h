//
//  StarGeo.h
//
//  Created by Sungwoo Choi on 7/30/15.
//  Copyright (c) 2015 SungLab. All rights reserved.
//


#ifndef STARCV_H
#define STARCV_H
#include "../StarMain.h"

class StarCV
{
private:
    char* img;
    Vec2 image_size;
    Vec2 screen_size;
protected:
    
public:
    
    Vec4 final_rect;
    
    StarCV(char* _img, Vec2 _screen_size, Vec2 _image_size)
    :img(_img)
    ,screen_size(_screen_size)
    ,image_size(_image_size)
    {
    }
    
    StarCV* place()
    {
    
        float ratio_w = image_size.x/screen_size.x;
        
        Vec2 final_image = Vec2(0.f,0.f);
        
        if((image_size.y/ratio_w)<=screen_size.y)
        {
            if((image_size.y/ratio_w)==screen_size.y) // same ratio as opengl resolution
            {
                final_image = screen_size;
                final_rect = Vec4(0.0f, 0.0f, final_image.x, final_image.y);
            }
            else // short height
            {
                final_image = Vec2(screen_size.x,image_size.y/ratio_w);
                final_rect = Vec4(0.0f, (screen_size.y-final_image.y)*0.5,
                                  final_image.x, final_image.y);
            }
        }
        else // long height
        {
            float ratio_h = image_size.y/screen_size.y;
            
            if((image_size.x/ratio_h) <= screen_size.x)
            {
                final_image = Vec2(image_size.x/ratio_h, screen_size.y);
                
                final_rect = Vec4((screen_size.x-final_image.x)*0.5,0.0,
                                  final_image.x, final_image.y);
            }
            else
            {
                exception();
            }
        }
            
        
        return this;
    }
    
    Vec4& get_final_rect()
    {
        return final_rect;
    }
    
};

class StarFace:public StarCV
{
    
private:
    
public:
    
};
#endif
