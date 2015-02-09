
#ifndef  _Included_Shader
#define _Included_Shader

#include "../StarMain.h"


class StarShader
{
public:
unsigned int ShaderLoadSourceFromMemory(	const char* pszShaderCode,
											const GLenum Type,
											GLuint* const pObject);

unsigned int CreateProgram(	GLuint* const pProgramObject,
						    const GLuint VertexShader,
						    const GLuint FragmentShader,
						    const char** const pszAttribs,
						    const int i32NumAttribs);
};
#endif
