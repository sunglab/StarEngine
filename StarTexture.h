//
//  StarTexture.h
//  StarEngine
//
//  Created by sungwoo choi on 8/24/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef StarEngine_StarTexture_h
#define StarEngine_StarTexture_h

#ifdef ANDROID
#include <jni.h>
#include <stdlib.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#elif IOS
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#endif
class StarTexture
{
    public:
    StarTexture()
	{TexID = 0; width=0; height=0; }
	int width, height;
	GLuint TexID;
    
#ifdef IOS

    StarTexture Create_Texture_IOS(NSString *filename);
    
#elif ANDROID
    StarTexture Create_Texture_CAM_ANDROID(char * camData,int width,int height);  // Espcial
    StarTexture Create_Texture_ANDROID(int* array,int width, int height);
#endif
    
    StarTexture Create_Texture_FBO(int width,int height);
    void Delete_Texture(StarTexture Texture);
};
#endif
