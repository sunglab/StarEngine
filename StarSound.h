//
//  StarSound.h
//  StarEngine
//
//  Created by sungwoo choi on 9/5/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#ifndef StarEngine_StarSound_h
#define StarEngine_StarSound_h
#ifdef ANDROID
#include <AL/al.h>
#include <AL/alc.h>
#include <ivorbisfile.h>

#include <android/log.h>
#include <jni.h>

#include <stddef.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#define LOG(...) __android_log_print(ANDROID_LOG_INFO, "OpenAL", __VA_ARGS__)

#define AL_CHECK(...) \
do { \
if ((err = alGetError()) != AL_NO_ERROR) { \
LOG("OpenAL error: %x at %s(%i)", err, __FILE__, __LINE__); \
goto exitpoint; \
} \
} while (0)

#define BUFFER_SIZE (8 * 1024)
#define BUFFER_COUNT 4

// simple non-seekable memory stream
typedef struct
{
    unsigned char* buffer;
    size_t size;
    size_t offset;
} MemoryStream;

static size_t read_func(void *ptr, size_t size, size_t nmemb, void *datasource)
{
    MemoryStream* stream = (MemoryStream*)datasource;
    
    // size always is 1
    assert(size == 1);
    
    size_t length = nmemb;
    if (length > stream->size - stream->offset)
    {
        length = stream->size - stream->offset;
    }
    
    if (length > 0)
    {
        memcpy(ptr, stream->buffer + stream->offset, length);
        stream->offset += length;
    }
    return length;
}

static int seek_func(void *datasource, ogg_int64_t offset, int whence)
{
    return -1;
}

static int close_func(void *datasource)
{
    return 0;
}

static ov_callbacks cb = {
    read_func,
    seek_func,
    close_func,
    NULL,
};

// make buffer global, so we are not wasting stack space
char temp[BUFFER_SIZE];

// will decode ogg file as much as can into temp buffer
static size_t decode(OggVorbis_File* vf)
{
    char* buffer = temp;
    size_t left = sizeof(temp);
    
    while (left != 0)
    {
        long decoded = ov_read(vf, buffer, left, NULL);
        if (decoded > 0)
        {
            buffer += decoded;
            left -= decoded;
        }
        else if (decoded == 0)
        {
            break;
        }
        else
        {
            LOG("Ogg decoding error, will try to resume decoding");
        }
    }
    
    return sizeof(temp) - left;
}

JNIEXPORT void JNICALL Java_net_strangesoft_kcat_OpenAL_run(JNIEnv* env, jclass klass, jarray data)
{
    int i;
    
    ALCdevice* device = NULL;
    ALCcontext* context = NULL;
    
    ALint state;
    ALenum err;
    ALuint source = 0;
    ALuint buffers[BUFFER_COUNT] = { 0 };
    
    static const ALint context_attribs[] = { ALC_FREQUENCY, 22050, 0 };
    
    MemoryStream* stream = NULL;
    
    OggVorbis_File vf = { 0 };   
    
    // 5 miliseconds
    struct timespec sleepTime;
    sleepTime.tv_sec = 0;
    sleepTime.tv_nsec = 5 * 1000 * 1000;
    
    stream = (MemoryStream*)malloc(sizeof(MemoryStream));
    if (!stream)
    {
        LOG("Failed to allocate memory for MemoryStream");
        goto exitpoint;
    }
    
    stream->offset = 0;
    stream->size = (*env)->GetArrayLength(env, data);
    stream->buffer = (*env)->GetByteArrayElements(env, data, NULL);
    
    if (ov_open_callbacks(stream, &vf, NULL, 0, cb) != 0)
    {
        LOG("Failed to open ogg file");
        goto exitpoint;
    }
    
    int channels = ov_info(&vf, 0)->channels;
    if (channels != 1 && channels != 2)
    {
        LOG("Unsupported ogg file - %i channels. Only mono or stereo supported", channels);
        goto exitpoint;
    }
    
    LOG("Opening device");
    device = alcOpenDevice(NULL);
    if (!device)
    {
        LOG("Failed to open OpenAL device");
        goto exitpoint;
    }
    
    LOG("Creating context");
    context = alcCreateContext(device, context_attribs);
    if (!context)
    {
        LOG("Failed to create OpenAL context");
        goto exitpoint;
    }
    alcMakeContextCurrent(context);
    
    LOG("Creating source");
    alGenSources(1, &source);
    AL_CHECK();
    
    LOG("Creating %i buffers", BUFFER_COUNT);
    alGenBuffers(BUFFER_COUNT, buffers);
    AL_CHECK();
    
    ALenum format = (channels == 1 ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16);
    ALsizei freq = ov_info(&vf, 0)->rate;
    
    LOG("Filling initial buffers");
    for (i=0; i<BUFFER_COUNT; i++)
    {
        size_t decoded = decode(&vf);
        if (decoded)
        {
            alBufferData(buffers[i], format, temp, decoded, freq);
            AL_CHECK();
            
            alSourceQueueBuffers(source, 1, &buffers[i]);
            AL_CHECK();
        }
    }
    
    alSourcef(source, AL_GAIN, 0.3f);
    AL_CHECK();
    
    LOG("Starting playback");
    alSourcePlay(source);
    AL_CHECK();
    
    while (stream->offset < stream->size)
    {
        ALint processed;
        
        alGetSourcei(source, AL_BUFFERS_PROCESSED, &processed);
        AL_CHECK();
        
        // unqueue and refill processed buffers
        while (processed-- > 0)
        {
            ALuint buf;
            
            alSourceUnqueueBuffers(source, 1, &buf);
            AL_CHECK();
            
            size_t decoded = decode(&vf);
            
            if (decoded)
            {
                alBufferData(buf, format, temp, decoded, freq);
                AL_CHECK();
                
                alSourceQueueBuffers(source, 1, &buf);
                AL_CHECK();
            }
        }
        
        alGetSourcei(source, AL_SOURCE_STATE, &state);
        AL_CHECK();
        
        // if source has been stopped playing, then resume it
        if (state != AL_PLAYING)
        {
            alSourcePlay(source);
        }
        
        // sleeping a bit to free the CPU from polling OpenAL source
        nanosleep(&sleepTime, NULL);
    }
    
    // when everything is read from stream, wait for source to finish
    do
    {
        nanosleep(&sleepTime, NULL);
        
        alGetSourcei(source, AL_SOURCE_STATE, &state);
        AL_CHECK();
    }
    while (state == AL_PLAYING);
    
    LOG("Playback finished");
    
exitpoint:
    // release the resources
    
    if (buffers[0])
    {
        alDeleteBuffers(BUFFER_COUNT, buffers);
    }
    
    if (source)
    {
        alDeleteSources(1, &source);
    }
    
    if (context)
    {
        alcMakeContextCurrent(NULL);
        alcDestroyContext(context);
    }
    
    if (device)
    {
        alcCloseDevice(device);
    }
    
    if (vf.datasource)
    {
        ov_clear(&vf);
    }
    
    if (stream)
    {
        // JNI_ABORT means that we do not want to copy native data back to Java world
        (*env)->ReleaseByteArrayElements(env, data, stream->buffer, JNI_ABORT);
        free(stream);
    }   
}




#elif IOS


#endif
#endif
