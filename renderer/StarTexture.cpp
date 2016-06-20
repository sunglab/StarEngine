//
//  StarTexture.cpp
//  StarEngine
//
//  Created by sungwoo choi on 8/24/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#include "StarTexture.h"
#ifdef IOS
#import <UIKit/UIKit.h>
//#elif MAC
//#import <Cocoa/Cocoa.h>
#endif

//#ifdef MAC
//#import <Cocoa/Cocoa.h>
//#endif

StarTexture::StarTexture(unsigned int texture_number)
{
	texture = new Texture[texture_number];
	texture->texture_width = 0;
	texture->texture_height = 0;
	texture->texture_id = 0;
}

#ifdef IOS
void StarTexture::createTEXTURE_IOS(const char*filename, unsigned int texture_id, bool repeat)
{

	CGImageRef imageRef;
	UIImage *image;
	CGContextRef context;
	GLubyte *imageData;

	NSString *filepathString = [[NSString alloc] initWithUTF8String:filename];

	//	image = [[UIImage alloc] initWithContentsOfFile:filepathString];
	image = [UIImage imageNamed : filepathString];

	if (!image)
	{
		starLOG("if no image why 1?\n");
		return;
	}
	imageRef = image.CGImage;
	if (!imageRef)
	{
		starLOG("if no image why 2?\n");
		return;
	}
	else
	{
		texture[texture_id].texture_width = (GLuint)CGImageGetWidth(imageRef);
		texture[texture_id].texture_height = (GLuint)CGImageGetHeight(imageRef);

		CGRect texRect = CGRectMake(0.0, 0.0, (CGFloat)(texture[texture_id].texture_width), (CGFloat)(texture[texture_id].texture_height));

		starLOG("\ngoood texture %d %d\n", texture[texture_id].texture_width, texture[texture_id].texture_height);
		imageData = (GLubyte *)malloc(texture[texture_id].texture_width * texture[texture_id].texture_height * 4);

		//    imageData = (GLubyte *) calloc(texture[texture_id].texture_width * texture[texture_id].texture_height * 4,sizeof(GLubyte));

		//    context = CGBitmapContextCreate(image, texture[texture_id].texture_width, texture[texture_id].texture_height, 8, texture[texture_id].texture_width*4, CGImageGetColorSpace(imageRef), kCGBitmapAlphaInfoMask & kCGImageAlphaNoneSkipLast);

		//           brushContext = CGBitmapContextCreate(brushData, width, height, 8, width * 4, CGImageGetColorSpace(brushImage), kCGImageAlphaPremultipliedLast);
		//      brushContext = CGBitmapContextCreate(brushData, width, height, 8, width * 4, CGImageGetColorSpace(brushImage), kCGImageAlphaPremultipliedLast);

		context = CGBitmapContextCreate(imageData,
			texture[texture_id].texture_width,
			texture[texture_id].texture_height,
			8,
			texture[texture_id].texture_width * 4,
			CGImageGetColorSpace(imageRef),
			kCGImageAlphaPremultipliedLast);

		CGContextSetBlendMode(context, kCGBlendModeCopy);
		CGContextDrawImage(context, texRect, imageRef);
		CGContextRelease(context);

		glGenTextures(1, &texture[texture_id].texture_id);
		glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);

		if (repeat)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		}
		else
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		}

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture[texture_id].texture_width, texture[texture_id].texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
		free(imageData);
	}
}
#elif MAC
void StarTexture::createTEXTURE_MAC(NSString *filename, unsigned texture_id, bool repeat)
{
	CFURLRef url = (__bridge CFURLRef)[NSURL fileURLWithPath : filename];
	CGImageSourceRef myImageSourceRef = CGImageSourceCreateWithURL(url, NULL);
	CGImageRef myImageRef = CGImageSourceCreateImageAtIndex(myImageSourceRef, 0, NULL);

	size_t width = CGImageGetWidth(myImageRef);
	size_t height = CGImageGetHeight(myImageRef);
	texture[texture_id].texture_width = width;
	texture[texture_id].texture_height = height;

	CGRect rect = { {0, 0}, {(float)width, (float)height} };
	void * myData = calloc(width * 4, height);

	if (!myData)
		starLOG("texture not loaded\n");
	else
		starLOG("texture loaded width : %d height : %d\n", width, height);

	CGColorSpaceRef space = CGColorSpaceCreateDeviceRGB();
	CGContextRef myBitmapContext = CGBitmapContextCreate(myData,
		width, height, 8,
		width * 4, space,
		kCGBitmapByteOrder32Host |
		kCGImageAlphaPremultipliedFirst);
	CGContextSetBlendMode(myBitmapContext, kCGBlendModeCopy);
	CGContextDrawImage(myBitmapContext, rect, myImageRef);
	CGContextRelease(myBitmapContext);

	glGenTextures(1, &texture[texture_id].texture_id);
	glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);

	//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_REPEAT);
	//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_REPEAT);
	if (repeat)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
	else
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_BGRA_EXT, GL_UNSIGNED_INT_8_8_8_8_REV, myData);

	free(myData);
}
#elif ANDROID

void StarTexture::createTEXTURE_ANDROID(void* array, unsigned int texture_width, unsigned int texture_height, unsigned int texture_id, bool repeat)
{
	texture[texture_id].texture_width = texture_width;
	texture[texture_id].texture_height = texture_height;

	glGenTextures(1, &texture[texture_id].texture_id);
	glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);

	if (repeat)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
	else
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	}

	starLOG("1here?");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_width, texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, array);
	starLOG("2here?");

}
#elif _WIN32
void StarTexture::createTEXTURE_WINDOWS(void* array, unsigned int width, unsigned int height, unsigned int texture_id, bool repeat)
{
	texture[texture_id].texture_width = width;
	texture[texture_id].texture_height = height;
	glGenTextures(1, &texture[texture_id].texture_id);
	glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, array);

	if (repeat)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
	else
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	}
}
#endif

// it should know what it is the number of User defined texture ID ( userDefined TexID != computerDefined TexID);
void StarTexture::createTEXTURE_DATA(void* data, unsigned int camera_width, unsigned int camera_height, unsigned int texture_id, bool alpha)
{
	texture[texture_id].texture_width = camera_width;
	texture[texture_id].texture_height = camera_height;

	if (!texture[texture_id].texture_id)
		glGenTextures(1, &texture[texture_id].texture_id);

	glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);

	if (alpha)
	{
#ifdef ANDROID
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, camera_width, camera_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, camera_width, camera_height, GL_RGBA, GL_UNSIGNED_BYTE, data);
#elif IOS
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, camera_width, camera_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, camera_width, camera_height, GL_RGBA, GL_UNSIGNED_BYTE, data);
#elif MAC
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, camera_width, camera_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, camera_width, camera_height, GL_RGBA, GL_UNSIGNED_BYTE, data);
#elif _WIN32
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, camera_width, camera_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, camera_width, camera_height, GL_RGBA, GL_UNSIGNED_BYTE, data); 
	//	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, camera_width, camera_height, GL_RGB, GL_UNSIGNED_BYTE, data);
		//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, camera_width, camera_height,0, GL_RGB, GL_UNSIGNED_BYTE, data); 
#endif
	}
	else
	{

	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

}


void StarTexture::createTEXTURE_RTF(unsigned int texture_width, unsigned int texture_height, unsigned int texture_id, unsigned int numOfMS)
{

	int err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		starLOG("\n\nOpenGL error MS TEXTURE second -3: %x\n\n", err);
	}
	texture[texture_id].texture_width = texture_width;
	texture[texture_id].texture_height = texture_height;

	glGenTextures(1, &texture[texture_id].texture_id);
	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, texture[texture_id].texture_id);

	while ((err = glGetError()) != GL_NO_ERROR) {
		starLOG("\n\nOpenGL error MS TEXTURE second -2: %x\n\n", err);
	}
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

//	glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, 4, GL_RGBA8, nWidth, nHeight, true);
	glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, numOfMS, GL_RGBA8, texture_width, texture_height, true);
//	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D_MULTISAMPLE, framebufferDesc.m_nRenderTextureId, 0);
while ((err = glGetError()) != GL_NO_ERROR) {
		starLOG("\n\nOpenGL error MS TEXTURE second -1: %x\n\n", err);
	}
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D_MULTISAMPLE, texture[texture_id].texture_id, 0);

	//int err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		starLOG("\n\nOpenGL error MS TEXTURE second 0: %x\n\n", err);
	}

}
void StarTexture::createTEXTURE_RTT(unsigned int texture_width, unsigned int texture_height, unsigned int texture_id, bool resize)
{

	texture[texture_id].texture_width = texture_width;
	texture[texture_id].texture_height = texture_height;
	if (!resize)
	{
		glGenTextures(1, &texture[texture_id].texture_id);
		glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_width, texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture[texture_id].texture_id, 0);
		int err;
		while ((err = glGetError()) != GL_NO_ERROR) {
			starLOG("\n\nOpenGL error TURNON RTT???: %x\n\n", err);
		}
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_width, texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
	}
}

Texture* StarTexture::getTEXTURE(unsigned int texture_id)
{
	return &texture[texture_id];
}


void StarTexture::unbindTEXTURE()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
void StarTexture::bindTEXTURE(unsigned int texture_unit, unsigned int texture_id)
{
	int err = 0;
	//    if(texture_unit)
	glActiveTexture(texture_unit);
	while ((err = glGetError()) != GL_NO_ERROR) {
		printf("\n\nOpenGL proof-00:%d err%x\n\n", texture_id, err);
	}

	glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);
	while ((err = glGetError()) != GL_NO_ERROR) {
		printf("\n\nOpenGL proof-01: %x\n\n", err);
	}

}

void StarTexture::deleteTEXTURE(unsigned int texture_id)
{
	if (texture[texture_id].texture_id != 0)
	{
		texture[texture_id].texture_id = 0;
		texture[texture_id].texture_width = 0;
		texture[texture_id].texture_height = 0;
		glDeleteTextures(1, &texture[texture_id].texture_id);
	}
}

