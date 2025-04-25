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
#endif

StarTexture::StarTexture(unsigned int texture_number)
{
    texture = std::unique_ptr<Texture[]>(new Texture[texture_number]);
    total_texture_number = texture_number;
    for(int i=0;i<texture_number;i++)
    {
        texture[i].texture_width = 0;
        texture[i].texture_height = 0;
        texture[i].texture_depth = 0;
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
    image = [UIImage imageNamed : filepathString];
    
    if (!image)
    {
        starLOG("No Image\n");
        return;
    }
    imageRef = image.CGImage;
    if (!imageRef)
    {
        starLOG("No ImageRef\n");
        return;
    }
    else
    {
        texture[texture_id].texture_width = (GLuint)CGImageGetWidth(imageRef);
        texture[texture_id].texture_height = (GLuint)CGImageGetHeight(imageRef);
        
        CGRect texRect = CGRectMake(0.0, 0.0, (CGFloat)(texture[texture_id].texture_width), (CGFloat)(texture[texture_id].texture_height));
        imageData = (GLubyte *)malloc(texture[texture_id].texture_width * texture[texture_id].texture_height * 4);
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

#elif (MAC && !StarQt)
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
        starLOG("Texture not loaded\n");
    else
        starLOG("Texture loaded width : %d height : %d id: %d\n", width, height, texture_id);
    
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
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_BGRA_EXT, GL_UNSIGNED_INT_8_8_8_8_REV, myData);
    if (repeat)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
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
    free(myData);
}
#elif ANDROID
void StarTexture::createTEXTURE_ANDROID(void* array, unsigned int texture_width, unsigned int texture_height, unsigned int texture_id, bool repeat, bool opt)
{
    texture[texture_id].texture_width = texture_width;
    texture[texture_id].texture_height = texture_height;
    if (!texture[texture_id].texture_id)
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
        if (opt)
        {
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
            if(type== ToInt(TextureType::SHORT))
            {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, camera_width, camera_height, 0, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, 0);
                glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, camera_width, camera_height, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, data);
            }
            else if(type==ToInt(TextureType::FLOAT))
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
            if(type==ToInt(TextureType::SHORT))
            {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, camera_width, camera_height, 0, GL_RGB, GL_UNSIGNED_SHORT_4_4_4_4, 0);
                glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, camera_width, camera_height, GL_RGB, GL_UNSIGNED_SHORT_4_4_4_4, data);
            }
            else if(type==ToInt(TextureType::FLOAT))
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
    texture[texture_id].texture_width = texture_width;
    texture[texture_id].texture_height = texture_height;
    
    glGenTextures(1, &texture[texture_id].texture_id);
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, texture[texture_id].texture_id);
    
    glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, numOfMS, GL_RGBA8, texture_width, texture_height, true);
    //    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D_MULTISAMPLE, framebufferDesc.m_nRenderTextureId, 0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D_MULTISAMPLE, texture[texture_id].texture_id, 0);
}
#endif

#if (!MAC)
void StarTexture::createTEXTURE2DARRY_RTT(unsigned int width, unsigned int height, unsigned int depth, unsigned int texture_id, bool repeat, bool opt, GLint internalformat) {
    texture[texture_id].texture_width = width;
    texture[texture_id].texture_height = height;
    texture[texture_id].texture_depth= depth;
    
    glGenTextures(1, &texture[texture_id].texture_id);
    glBindTexture(GL_TEXTURE_2D_ARRAY, texture[texture_id].texture_id);
    glTexStorage3D(GL_TEXTURE_2D_ARRAY, 1, internalformat, width, height, depth);
        
    if (repeat)
    {
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_R, GL_REPEAT);
    }
    else
    {
        if(opt)
        {
            glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        }
        else
        {
            glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        }
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    }
}
#endif

void StarTexture::createTEXTURE_RTT(unsigned int texture_width, unsigned int texture_height, unsigned int texture_id, bool repeat, bool resize, bool opt, int type, GLint internalformat, GLenum format)
{
    texture[texture_id].texture_width = texture_width;
    texture[texture_id].texture_height = texture_height;
    
    if (!resize)
    {
        glGenTextures(1, &texture[texture_id].texture_id);
        glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);

        if(type == ToInt(TextureType::CHAR))
        {
            glTexImage2D(GL_TEXTURE_2D, 0, internalformat, texture_width, texture_height, 0, format, GL_UNSIGNED_BYTE, 0);
        }
        else if(type == ToInt(TextureType::FLOAT))
        {
            glTexImage2D(GL_TEXTURE_2D, 0, internalformat, texture_width, texture_height, 0, format, GL_FLOAT, 0);
        }
        else if(type == ToInt(TextureType::SHORT))
        {
            glTexImage2D(GL_TEXTURE_2D, 0, internalformat, texture_width, texture_height, 0, format, GL_UNSIGNED_SHORT_4_4_4_4, 0);
        }
        else if(type == ToInt(TextureType::STORAGE))
        {
            glTexStorage2D(GL_TEXTURE_2D, 1, internalformat, texture_width, texture_height);
        }

        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture[texture_id].texture_id, 0);
        
        if (repeat)
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        }
        else
        {
            if(opt)
            {
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
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
        
        if(type == ToInt(TextureType::CHAR))
            glTexImage2D(GL_TEXTURE_2D, 0, internalformat, texture_width, texture_height, 0, format, GL_UNSIGNED_BYTE, 0);
        else if(type == ToInt(TextureType::FLOAT))
            glTexImage2D(GL_TEXTURE_2D, 0, internalformat, texture_width, texture_height, 0, format, GL_FLOAT, 0);
        else if(type == ToInt(TextureType::SHORT))
            glTexImage2D(GL_TEXTURE_2D, 0, internalformat, texture_width, texture_height, 0, format, GL_UNSIGNED_SHORT_4_4_4_4, 0);
    }
}

void StarTexture::createTEXTURE_OBJ( unsigned int texture_unit, unsigned int texture_id, unsigned int bo, unsigned int width, unsigned int height, void* buffer, GLenum textureType, GLenum dataType, GLenum minFilterOpt, GLenum magFilterOpt)
{
#if(ANDROID)
    texture[texture_id].texture_width = width;
    texture[texture_id].texture_height = height;

    if(texture_unit == GL_TEXTURE_2D_ARRAY) {
        glGenTextures(1, &texture[texture_id].texture_id);
        glBindTexture(texture_unit, texture[texture_id].texture_id);
        glTexStorage3D(texture_unit, 1, textureType, width, height, 1);
        glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, 0, width, height, 1, GL_RGBA, dataType, buffer);
        glTexBufferEXT(texture_unit, textureType, bo);
        
    } else if(texture_unit == GL_TEXTURE_2D){
        
        glGenTextures(1, &texture[texture_id].texture_id);
        glBindTexture(texture_unit, texture[texture_id].texture_id);
        glTexStorage2D(GL_TEXTURE_2D, 1, textureType, width, height);
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, dataType, buffer);
        //glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA, width, height, 0, GL_RGBA, GL_FLOAT, buffer);
        
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,minFilterOpt);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,magFilterOpt);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
        //        int y = 142*2834*4;
        //        int x = 10*4;
        //        starLOG("image color before %f %f %f %f ",buffer[x+y+0], buffer[x+y+1], buffer[x+y+2], buffer[x+y+3]);
    } else {
        glGenTextures(1, &texture[texture_id].texture_id);
        glBindTexture(texture_unit, texture[texture_id].texture_id);
        glTexBufferEXT(texture_unit, textureType, bo);
    }
#endif
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

void StarTexture::bindTEXTURE_IMAGE(unsigned int layout_unit,
                                    unsigned int texture_id,
                                    unsigned int level,
                                    bool layered,
                                    unsigned int layer_number,
                                    unsigned int access,
                                    unsigned int format)
{
#if(ANDROID)
    glBindImageTexture(layout_unit, texture_id, level, layered, layer_number, access, format);
#endif
}

#ifdef ANDROID
void StarTexture::bindTEXTURE_OES(unsigned int texture_unit, unsigned int texture_id)
{
    glActiveTexture(texture_unit);
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, texture[texture_id].texture_id);
}
#endif

void StarTexture::bindTEXTURE_CUBE(unsigned int texture_unit, unsigned int texture_id)
{
    glActiveTexture(texture_unit);
    glBindTexture(GL_TEXTURE_CUBE_MAP, texture[texture_id].texture_id);
}

void StarTexture::bindTEXTURE_2DARRAY(unsigned int texture_unit, unsigned int texture_id) {
    glActiveTexture(texture_unit);
    glBindTexture(GL_TEXTURE_2D_ARRAY, texture[texture_id].texture_id);
}

void StarTexture::deleteTEXTURE(unsigned int texture_id)
{
    if (texture[texture_id].texture_id != 0)
    {
        starLOG("Delete Texture ID : %d", texture_id);
        glDeleteTextures(1, &texture[texture_id].texture_id);
        texture[texture_id].texture_id = 0;
        texture[texture_id].texture_width = 0;
        texture[texture_id].texture_height = 0;
        texture[texture_id].texture_depth = 0;
    }
}
