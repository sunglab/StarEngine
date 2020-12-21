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
    std::unique_ptr<Texture[]> texture;
    unsigned int total_texture_number = 0;
    StarTexture(unsigned int texture_number);
    
    ~StarTexture()
    {
        if(texture) {
            for(int i=0; i < total_texture_number; i++)
                deleteTEXTURE(i);
        }
    }
    
#ifdef IOS
    void createTEXTURE_IOS(const char*, unsigned texture_id,bool repeat = false, bool opt = false);
#elif (MAC && !starQt)
    void createTEXTURE_MAC(NSString *filename, unsigned texture_id,bool repeat = false, bool opt = false);
#elif ANDROID
    void createTEXTURE_ANDROID(void* array,unsigned int width, unsigned int height, unsigned int texture_id, bool repeat = false, bool opt = false);
#elif _WIN32
    void createTEXTURE_WINDOWS( void* array, unsigned int width, unsigned int height, unsigned int texture_id,bool repeat = false,bool _float = false, bool opt=false); // for camera
    void createTEXTURE_CUBE_WINDOWS(void** array, unsigned int width, unsigned int height, unsigned int texture_id,bool opt=false);
#endif
    void createTEXTURE_CAMERA( void* data, unsigned int width, unsigned int height, unsigned int texture_id,bool alpha = true,bool _float = false); // for camera
    void createTEXTURE_DATA( void* data, unsigned int width, unsigned int height, unsigned int texture_id,bool alpha = true,int type= 0); // for camera
    void createTEXTURE_RTT( unsigned int width, unsigned int height, unsigned int texture_id,bool repeat = false,bool resize=false, bool opt = false, int type = 0);
    void createTEXTURE_OBJ( unsigned int texture_unit, unsigned int texture_id, unsigned int bo);
    
#if (MAC||_WIN32)
    void createTEXTURE_RTF( unsigned int width, unsigned int height, unsigned int texture_id,unsigned int numOfMS);
#endif
    Texture* getTEXTURE(unsigned int texture_id);
    
    void bindTEXTURE( unsigned int texture_unit, unsigned int texture_id);
    void bindTEXTURE_IMAGE(unsigned int layout_unit,
                           unsigned int texture_id,
                           unsigned int level,
                           bool layered,
                           unsigned int layer_number,
                           unsigned int access,
                           unsigned int format);
    
#ifdef ANDROID
    void bindTEXTURE_OES( unsigned int texture_unit, unsigned int texture_id);
#endif
    void bindTEXTURE_CUBE( unsigned int texture_unit, unsigned int texture_id);
    void unbindTEXTURE();
    
    void deleteTEXTURE(unsigned int texture_id);
    
    
};
#endif
