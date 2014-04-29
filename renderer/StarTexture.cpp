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
	
	spriteImage = [UIImage imageNamed:filename].CGImage;
	sTex.texture_width= CGImageGetWidth(spriteImage);
	sTex.texture_height = CGImageGetHeight(spriteImage);
    
	if(spriteImage) 
	{
		// Allocated memory needed for the bitmap context
		spriteData = (GLubyte *) malloc(sTex.texture_width * sTex.texture_height * 4);
		// Uses the bitmatp creation function provided by the Core Graphics framework. 
		spriteContext = CGBitmapContextCreate(spriteData, sTex.texture_width, sTex.texture_height,  CGImageGetBitsPerComponent(spriteImage), sTex.texture_width * 4, 
											  CGImageGetColorSpace(spriteImage), kCGImageAlphaPremultipliedLast	);
		// After you create the context, you can draw the sprite image to the context.
		CGContextDrawImage(spriteContext, CGRectMake(0.0, 0.0, (CGFloat)sTex.texture_width, (CGFloat)sTex.texture_height), spriteImage);
		// You don't need the context at this point, so you need to release it to avoid memory leaks.
		CGContextRelease(spriteContext);
		
		// Use OpenGL ES to generate a name for the texture.
		glGenTextures(1, &sTex.texture_id);
		// Bind the texture name. 
		glBindTexture(GL_TEXTURE_2D, sTex.texture_id);
		// Speidfy a 2D texture image, provideing the a pointer to the image data in memory
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sTex.texture_width, sTex.texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, spriteData);
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

StarTexture StarTexture::Create_Texture_ANDROID(int * array,int texture_width, int texture_height)
{
    StarTexture sTex;
	sTex.texture_width  = texture_width;
	sTex.texture_height = texture_height;
    
    // Use OpenGL ES to generate a name for the texture.
    glGenTextures(1, &sTex.texture_id);
    // Bind the texture name. 
    glBindTexture(GL_TEXTURE_2D, sTex.texture_id);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // This is necessary for non-power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_width, texture_height, 0,GL_RGBA, GL_UNSIGNED_BYTE, array); // The array comes from JAVA
    
    // Enable use of the texture
    glEnable(GL_TEXTURE_2D);
    
    return sTex;
}
StarTexture StarTexture::Create_Texture_CAM_ANDROID(char * camData,int texture_width,int texture_height)
{
    StarTexture sTex;
    sTex.texture_width  = texture_width;
	sTex.texture_height = texture_height;
    
    // Use OpenGL ES to generate a name for the texture.
    glGenTextures(1, &sTex.texture_id);
    // Bind the texture name.
    glBindTexture(GL_TEXTURE_2D, sTex.texture_id);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // This is necessary for non-power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_width, texture_height, 0,GL_RGBA, GL_UNSIGNED_BYTE, camData);
    //    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, texture_width, texture_height, GL_RGBA, GL_UNSIGNED_BYTE, camData);
    //        glEnable(GL_TEXTURE_2D);
    return sTex;
}
#endif
StarTexture StarTexture::Create_Texture_PIXEL(char* pixel,int texture_width,int texture_height)
{
    StarTexture sTex;
    sTex.texture_width  = texture_width;
	sTex.texture_height = texture_height;
    
    // Use OpenGL ES to generate a name for the texture.
    glGenTextures(1, &sTex.texture_id);
    // Bind the texture name.
    glBindTexture(GL_TEXTURE_2D, sTex.texture_id);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // This is necessary for non-power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_width, texture_height, 0,GL_RGBA, GL_UNSIGNED_BYTE, pixel);
    //    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, texture_width, texture_height, GL_RGBA, GL_UNSIGNED_BYTE, camData);
    //        glEnable(GL_TEXTURE_2D);
    return sTex;
    
}
StarTexture StarTexture::Create_Texture_FBO_FIRST( int texture_width, int texture_height)
{
    StarTexture fboTex;
    fboTex.texture_width = texture_width;
    fboTex.texture_height = texture_height;
	glGenTextures(1, &fboTex.texture_id);
	glBindTexture(GL_TEXTURE_2D,fboTex.texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_width, texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fboTex.texture_id, 0);
	return fboTex;
}

StarTexture StarTexture::Create_Texture_FBO_SECOND(int texture_width, int texture_height)
{
    StarTexture fboTex;
    fboTex.texture_width = texture_width;
    fboTex.texture_height = texture_height;
	glGenTextures(1, &fboTex.texture_id);
	glBindTexture(GL_TEXTURE_2D,fboTex.texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_width, texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fboTex.texture_id, 0);
	return fboTex;
}

StarTexture StarTexture::Create_Texture_FBO_THIRD(int texture_width, int texture_height)
{
    StarTexture fboTex;
    fboTex.texture_width = texture_width;
    fboTex.texture_height = texture_height;
	glGenTextures(1, &fboTex.texture_id);
	glBindTexture(GL_TEXTURE_2D,fboTex.texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_width, texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fboTex.texture_id, 0);
	return fboTex;
}

void StarTexture::Delete_Texture(StarTexture Texture)
{
	if(Texture.texture_id!=0)
		glDeleteTextures(1, &Texture.texture_id);
}
