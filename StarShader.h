


#ifndef _Included_Shader
#define _Included_Shader

#ifdef ANDROID
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#elif IOS
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
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
