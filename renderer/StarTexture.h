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
#include <iostream>

enum class TextureType
{
    CHAR,
    FLOAT,
    SHORT,
};

class Texture
{
public:
    
    Texture(){texture_id = 0; texture_width=0; texture_height=0; }
//    Texture(unsigned int tex_id);
    unsigned int texture_width;
    unsigned int texture_height;
    unsigned int texture_id;
};

//class StarImage
//{
//    public:
//    unsigned int width;
//    unsigned int height;
//    unsigned int format;
//    unsigned int type;
//    unsigned int rowByteSize;
//    char* data;
//};

class StarTexture
{
    public:
    Texture* texture;
//    std::unique_ptr<Texture[]> texture;
    StarTexture(unsigned int texture_number);

#ifdef IOS
    void createTEXTURE_IOS(const char*, unsigned texture_id,bool repeat = false, bool opt = false);
#elif MAC
    void createTEXTURE_MAC(NSString *filename, unsigned texture_id,bool repeat = false, bool opt = false);
#elif ANDROID
    void createTEXTURE_ANDROID(void* array,unsigned int width, unsigned int height, unsigned int texture_id, bool repeat = false, bool opt = false);
#elif _WIN32
    void createTEXTURE_WINDOWS( void* array, unsigned int width, unsigned int height, unsigned int texture_id,bool repeat = false,bool _float = false, bool opt=false); // for camera
	void createTEXTURE_CUBE_WINDOWS(void** array, unsigned int width, unsigned int height, unsigned int texture_id,bool opt=false);
#endif
    void createTEXTURE_CAMERA( void* data, unsigned int width, unsigned int height, unsigned int texture_id,bool alpha = true,bool _float = false); // for camera
    void createTEXTURE_DATA( void* data, unsigned int width, unsigned int height, unsigned int texture_id,bool alpha = true,int _float = 0); // for camera
    void createTEXTURE_RTT( unsigned int width, unsigned int height, unsigned int texture_id,bool repeat = false,bool resize=false, bool opt = false);

#if (MAC||_WIN32)
    void createTEXTURE_RTF( unsigned int width, unsigned int height, unsigned int texture_id,unsigned int numOfMS);
#endif 
    Texture* getTEXTURE(unsigned int texture_id);

    void bindTEXTURE( unsigned int texture_unit, unsigned int texture_id);
    void bindTEXTURE_CUBE( unsigned int texture_unit, unsigned int texture_id);
	void unbindTEXTURE();

    void deleteTEXTURE(unsigned int texture_id);

   
};
#endif
