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

class StarTexture
{
    public:
    unsigned int texture_width, texture_height;
	GLuint texture_id;
    
    StarTexture()
	{texture_id = 0; texture_width=0; texture_height=0; }

#ifdef IOS
    StarTexture Create_Texture_IOS(NSString *filename);
#elif ANDROID
    StarTexture Create_Texture_CAM_ANDROID(char * camData,int width,int height);  // Espcial
    StarTexture Create_Texture_ANDROID(int* array,int width, int height);
#endif
    StarTexture Create_Texture_PIXEL(char*,int,int);
    
    StarTexture Create_Texture_FBO_FIRST(int width,int height);
    StarTexture Create_Texture_FBO_SECOND(int width,int height);
    StarTexture Create_Texture_FBO_THIRD(int width,int height);
    void Delete_Texture(StarTexture Texture);
};
#endif
