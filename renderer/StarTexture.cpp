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


StarTexture::StarTexture(unsigned int texture_number)
{
    texture = new Texture[texture_number];
//    texture = std::unique_ptr<Texture[]>(new Texture[texture_number]);
    
    for(int i=0;i<texture_number;i++)
    {
        texture[i].texture_width = 0;
        texture[i].texture_height = 0;
        texture[i].texture_id = 0;
    }
}

#ifdef IOS
void StarTexture::createTEXTURE_IOS(const char*filename, unsigned int texture_id, bool repeat, bool opt)
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

        
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture[texture_id].texture_width, texture[texture_id].texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
		if (repeat)
		{
			glGenerateMipmap(GL_TEXTURE_2D);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		}
		else
		{
			glGenerateMipmap(GL_TEXTURE_2D);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		}

		free(imageData);
	}
}

#elif MAC

void StarTexture::createTEXTURE_MAC(NSString *filename, unsigned texture_id, bool repeat, bool opt)
{
	CFURLRef url = (__bridge CFURLRef)[NSURL fileURLWithPath : filename];
	CGImageSourceRef myImageSourceRef = CGImageSourceCreateWithURL(url, NULL);
	CGImageRef myImageRef = CGImageSourceCreateImageAtIndex(myImageSourceRef, 0, NULL);

	unsigned int width = CGImageGetWidth(myImageRef);
	unsigned int height = CGImageGetHeight(myImageRef);
	texture[texture_id].texture_width = width;
	texture[texture_id].texture_height = height;

	CGRect rect = { {0, 0}, {(float)width, (float)height} };
    
	void * myData = (void*)calloc(width * 4, height);

	if (!myData)
		starLOG("texture not loaded\n");
	else
		starLOG("texture loaded width : %d height : %d id: %d\n", width, height, texture_id);

//    for(int a=0;a<width;a++)
//        for(int b=0;b<height;b++)
//        {
//        
////             Color3 color =  Color3((float)(myData[(a*height+b)*4]),(float)myData[(a*height+b)*4+1],(float)myData[(a*height+b)*4+2]);
//            
////            starLOG("%f %f %f\n", color.r, color.g, color.b);
////            starLOG("%f\n", myData[(a*height+b)*4+3]);
//            
//        }
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

//	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_REPEAT);
//	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_REPEAT);
    
//    if(texture_id!=5)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_BGRA_EXT, GL_UNSIGNED_INT_8_8_8_8_REV, myData);
//    else
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_BGR_EXT, GL_BYTE, myData);

	if (repeat)
	{
        starLOG("HAHA\n");
//        glGenerateMipmap(GL_TEXTURE_2D);
//        		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
//        		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
//        		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        
	}
	else
	{
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	}
    

	free(myData);
}
#elif ANDROID


void StarTexture::createTEXTURE_ANDROID(void* array, unsigned int texture_width, unsigned int texture_height, unsigned int texture_id, bool repeat, bool opt)
{
	texture[texture_id].texture_width = texture_width;
	texture[texture_id].texture_height = texture_height;

	glGenTextures(1, &texture[texture_id].texture_id);
	glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);
    
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_width, texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, array);
    
	if (repeat)
	{
        glGenerateMipmap(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        
        if(opt)
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        }
        else
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        }
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
	else
	{
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

        if(opt)
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        }
        else
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        }
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	}
}
#elif _WIN32
void StarTexture::createTEXTURE_WINDOWS(void* array, unsigned int width, unsigned int height, unsigned int texture_id, bool repeat,bool _float, bool opt)
{
	texture[texture_id].texture_width = width;
	texture[texture_id].texture_height = height;
	glGenTextures(1, &texture[texture_id].texture_id);
	glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);

	if (_float)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_FLOAT, array);
	else
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, array);

	if (repeat)
	{
		if (opt)
		{
			//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		}
		else
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		};
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
	else
	{
		glGenerateMipmap(GL_TEXTURE_2D);

		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		if (opt)
		{
		//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		}
		else
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	}

}

void StarTexture::createTEXTURE_CUBE_WINDOWS(void** array, unsigned int width, unsigned int height, unsigned int texture_id, bool opt)
{
	texture[texture_id].texture_width = width;
	texture[texture_id].texture_height = height;
	glGenTextures(1, &texture[texture_id].texture_id);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture[texture_id].texture_id);

	for (int i = 0; i < 6; i++)
	{
		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
			0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, array[i]);
	}

//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, array);

	if (opt)
	{
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	}
	else
	{
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE); // a new friend

	GLfloat fLargest;
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &fLargest);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, fLargest);
}
#endif

void StarTexture::createTEXTURE_CAMERA(void* data, unsigned int camera_width, unsigned int camera_height, unsigned int texture_id, bool alpha,bool _float)
{
    texture[texture_id].texture_width = camera_width;
    texture[texture_id].texture_height = camera_height;
    
    if (!texture[texture_id].texture_id)
        glGenTextures(1, &texture[texture_id].texture_id);
    
    glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);
    
    if (alpha)
    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, camera_width, camera_height, 0,GL_BGRA, GL_UNSIGNED_BYTE, data);
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, camera_width, camera_height, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }
    else
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, camera_width, camera_height, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
//        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, camera_width, camera_height, GL_RGB, GL_UNSIGNED_BYTE, data);
    }
    
    
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
//    glGenerateMipmap(GL_TEXTURE_2D);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
//    GLfloat largest;
//    glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &largest);
//    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, largest);
}
// it should know what it is the number of User defined texture ID ( userDefined TexID != computerDefined TexID);

void StarTexture::createTEXTURE_DATA(void* data, unsigned int camera_width, unsigned int camera_height, unsigned int texture_id, bool alpha,int type)
{
	texture[texture_id].texture_width = camera_width;
	texture[texture_id].texture_height = camera_height;

	if (!texture[texture_id].texture_id)
		glGenTextures(1, &texture[texture_id].texture_id);

	glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);

	if (alpha)
	{
		if (type)
		{
            if(type==TextureType::SHORT)
            {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, camera_width, camera_height, 0, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, 0);
                glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, camera_width, camera_height, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, data);
            }
            else if(type==TextureType::FLOAT)
            {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, camera_width, camera_height, 0, GL_RGBA, GL_FLOAT, 0);
                glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, camera_width, camera_height, GL_RGBA, GL_FLOAT, data);
            }
		}
		else
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, camera_width, camera_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
			glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, camera_width, camera_height, GL_RGBA, GL_UNSIGNED_BYTE, data);
		}
	}
	else
	{
		if (type)
		{
            if(type==TextureType::SHORT)
            {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, camera_width, camera_height, 0, GL_RGB, GL_UNSIGNED_SHORT_4_4_4_4, 0);
                glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, camera_width, camera_height, GL_RGB, GL_UNSIGNED_SHORT_4_4_4_4, data);
            }
            else if(type==TextureType::FLOAT)
            {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, camera_width, camera_height, 0, GL_RGB, GL_FLOAT, 0);
                glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, camera_width, camera_height, GL_RGB, GL_FLOAT, data);
            }
		}
		else
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, camera_width, camera_height, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
			glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, camera_width, camera_height, GL_RGB, GL_UNSIGNED_BYTE, data);
		}
	}


	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	GLfloat largest;
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &largest);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, largest);
}


#if (MAC||_WIN32)
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
#endif

void StarTexture::createTEXTURE_RTT(unsigned int texture_width, unsigned int texture_height, unsigned int texture_id, bool repeat,bool resize, bool opt)
{
	texture[texture_id].texture_width = texture_width;
	texture[texture_id].texture_height = texture_height;
    
	if (!resize)
	{
		glGenTextures(1, &texture[texture_id].texture_id);
		glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_width, texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture[texture_id].texture_id, 0);

		if (repeat)
		{
	//		glGenerateMipmap(GL_TEXTURE_2D);
	//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		}
		else
		{
//			glGenerateMipmap(GL_TEXTURE_2D);
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//            
            if(opt)
            {
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            }
            else
            {
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            }
            
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
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
	glActiveTexture(texture_unit);
	glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);
}
void StarTexture::bindTEXTURE_CUBE(unsigned int texture_unit, unsigned int texture_id)
{
	glActiveTexture(texture_unit);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture[texture_id].texture_id);
}

void StarTexture::deleteTEXTURE(unsigned int texture_id)
{
	if (texture[texture_id].texture_id != 0)
	{
		glDeleteTextures(1, &texture[texture_id].texture_id);
//        glDeleteTextures(1, &texture_id);
        texture[texture_id].texture_id = 0;
        texture[texture_id].texture_width = 0;
        texture[texture_id].texture_height = 0;
	}
}

