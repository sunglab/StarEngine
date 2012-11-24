//
//  StarTexture.cpp
//  StarEngine
//
//  Created by sungwoo choi on 8/24/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#include "StarTexture.h"

#ifdef IOS


StarTexture StarTexture::Create_Texture_IOS(NSString *filename)
{
    CGImageRef spriteImage;
	CGContextRef spriteContext;
	GLubyte *spriteData;
	
	StarTexture sTex;
	
	// Creates a Core Graphics image from an image file
	spriteImage = [UIImage imageNamed:filename].CGImage;
	// Get the width and height of the image
	sTex.width = CGImageGetWidth(spriteImage);
	sTex.height = CGImageGetHeight(spriteImage);
    
	if(spriteImage) 
	{
		// Allocated memory needed for the bitmap context
		spriteData = (GLubyte *) malloc(sTex.width * sTex.height * 4);
		// Uses the bitmatp creation function provided by the Core Graphics framework. 
		spriteContext = CGBitmapContextCreate(spriteData, sTex.width, sTex.height,  CGImageGetBitsPerComponent(spriteImage), sTex.width * 4, 
											  CGImageGetColorSpace(spriteImage), kCGImageAlphaPremultipliedLast	);
		// After you create the context, you can draw the sprite image to the context.
		CGContextDrawImage(spriteContext, CGRectMake(0.0, 0.0, (CGFloat)sTex.width, (CGFloat)sTex.height), spriteImage);
		// You don't need the context at this point, so you need to release it to avoid memory leaks.
		CGContextRelease(spriteContext);
		
		// Use OpenGL ES to generate a name for the texture.
		glGenTextures(1, &sTex.TexID);
		// Bind the texture name. 
		glBindTexture(GL_TEXTURE_2D, sTex.TexID);
		// Speidfy a 2D texture image, provideing the a pointer to the image data in memory
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sTex.width, sTex.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, spriteData);
		// Release the image data
		free(spriteData);
		
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // This is necessary for non-power-of-two textures
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		
		// Enable use of the texture
		glEnable(GL_TEXTURE_2D);
		// Set a blending function to use
        //		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //		// Enable blending
        //		glEnable(GL_BLEND);
	}
	return sTex;
}

#elif ANDROID

StarTexture StarTexture::Create_Texture_ANDROID(int * array,int width, int height)
{
    StarTexture sTex;
//	int i;
//	int *buf = (int *)malloc(sizeof(int)*width*height);
//	for (i = 0; i < width*height*4; i += 4)
//	{
//		buf[i]   = array[i+2];
//		buf[i+1] = array[i+1];
//		buf[i+2] = array[i];
//		buf[i+3] = array[i+3];
//	}
    
	sTex.width  = width;
	sTex.height = height;
    
    // Use OpenGL ES to generate a name for the texture.
    glGenTextures(1, &sTex.TexID);
    // Bind the texture name. 
    glBindTexture(GL_TEXTURE_2D, sTex.TexID);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // This is necessary for non-power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,GL_RGBA, GL_UNSIGNED_BYTE, array);
    

    
    // Enable use of the texture
    glEnable(GL_TEXTURE_2D);
    
    return sTex;
}
StarTexture StarTexture::Create_Texture_CAM_ANDROID(char * camData,int width,int height)
{
    StarTexture sTex;
    sTex.width  = width;
	sTex.height = height;
    
    // Use OpenGL ES to generate a name for the texture.
    glGenTextures(1, &sTex.TexID);
    // Bind the texture name. 
    glBindTexture(GL_TEXTURE_2D, sTex.TexID);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // This is necessary for non-power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,GL_RGBA, GL_UNSIGNED_BYTE, camData);
//    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, camData);	
//        glEnable(GL_TEXTURE_2D);
    return sTex;
}
#endif

StarTexture StarTexture::Create_Texture_FBO( int width, int height)
{
    StarTexture fboTex;
    fboTex.width = width;
    fboTex.height = height;
	glGenTextures(1, &fboTex.TexID);
	glBindTexture(GL_TEXTURE_2D,fboTex.TexID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fboTex.TexID, 0);
	return fboTex;
}

void StarTexture::Delete_Texture(StarTexture Texture)
{
	if(Texture.TexID!=0)
		glDeleteTextures(1, &Texture.TexID);
}