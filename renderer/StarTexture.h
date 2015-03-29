//
//  StarTexture.h
//  StarEngine
//
//  Created by sungwoo choi on 8/24/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef StarEngine_StarTexture_h
#define StarEngine_StarTexture_h

#include "../StarMain.h"

class Texture
{
public:
    Texture(){texture_id = 0; texture_width=0; texture_height=0; }
//    Texture(unsigned int tex_id);
    unsigned int texture_width;
    unsigned int texture_height;
    unsigned  int texture_id;
};

class StarImage
{
    public:
    unsigned int width;
    unsigned int height;
    unsigned int format;
    unsigned int type;
    unsigned int rowByteSize;
    char* data;
};

class StarTexture
{
    public:
    Texture* texture;
    
//    StarTexture(void);
    StarTexture(unsigned int texture_number);

#ifdef IOS
    void createTEXTURE_IOS(NSString *filename, unsigned texture_id);
#elif MAC
//    void createTEXTURE_MAC(NSString *filename, unsigned texture_id);
#elif ANDROID
    void createTEXTURE_ANDROID(int* array,unsigned int width, unsigned int height, unsigned int texture_id);
#endif
    
//#ifndef ANDROID
//    StarImage* createImage(const char* filename,bool flip);
//    void deleteImage(StarImage* image);
//#endif
    void createTEXTURE_DATA( void* data, unsigned int width, unsigned int height, unsigned int texture_id);
    void createTEXTURE_RTT( unsigned int width, unsigned int height, unsigned int texutre_id,bool resize=false);
    
    Texture* getTEXTURE(unsigned int texture_id);
    void bindTEXTURE( unsigned int texture_unit, unsigned int texture_id);
    void deleteTEXTURE(unsigned int texture_id);
   
};
#endif
