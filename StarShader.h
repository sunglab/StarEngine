


#ifndef _Included_Shader
#define _Included_Shader

#ifdef ANDROID
#include <jni.h>
#include <android/log.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <stdlib.h>
#define  LOG_TAG    "StarEngine"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


#endif

class StarShader
{
public:
unsigned int ShaderLoadSourceFromMemory(	const char* pszShaderCode,
											const GLenum Type,
											GLuint* const pObject);
											//string const pReturnError);


unsigned int CreateProgram(	GLuint* const pProgramObject,
						    const GLuint VertexShader,
						    const GLuint FragmentShader,
						    const char** const pszAttribs,
						    const int i32NumAttribs);


};
#endif
