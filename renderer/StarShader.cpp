

#include "StarShader.h"


#define SUCCESS			1
#define FAIL			0




unsigned int StarShader::ShaderLoadSourceFromMemory(	const char* pszShaderCode,
                                        const GLenum Type, 
                                        GLuint* const pObject)
//string const pReturnError)
{
    
	// Create the shader object. 
    *pObject = glCreateShader(Type);
 
	// Load the source code into it.
    glShaderSource(*pObject, 1, &pszShaderCode, NULL);
	
//    printf("%d",*pObject);
	// Compile the source code.
    glCompileShader(*pObject);
    
    
	// Test if compilation succeeded.
	GLint bShaderCompiled;
    glGetShaderiv(*pObject, GL_COMPILE_STATUS, &bShaderCompiled);
	if (!bShaderCompiled)
	{
       
        GLint logLength = 0;
		glGetShaderiv(*pObject, GL_INFO_LOG_LENGTH, &logLength);
		GLchar *log = (GLchar*) malloc(logLength);
		glGetShaderInfoLog(*pObject, logLength, &logLength, log);
		printf("Shader compile log\n %s", log);
		free(log);

        
		// There was an error here, first get the length of the log message.
		int i32InfoLogLength, i32CharsWritten;
		glGetShaderiv(*pObject, GL_INFO_LOG_LENGTH, &i32InfoLogLength);
		
		// Allocate enough space for the message, and retrieve it.
		char* pszInfoLog = new char[i32InfoLogLength];
        glGetShaderInfoLog(*pObject, i32InfoLogLength, &i32CharsWritten, pszInfoLog);
		
		// Displays the error!
		//printf("Failed to compile fragment shader: %s\n", pszInfoLog);
		delete [] pszInfoLog;
		
		// Delete shader.
		glDeleteShader(*pObject);
		
		// Return false, couldn't compile.
		return FAIL;
	}
	

	return SUCCESS;
}

unsigned int StarShader::CreateProgram(	GLuint* const pProgramObject,
                           const GLuint VertexShader, 
                           const GLuint FragmentShader, 
                           const char** const pszAttribs,
                           const int i32NumAttribs)
//CString* const pReturnError)
{
	// Create the shader program.
	*pProgramObject = glCreateProgram();
    
	// Attach the fragment and vertex shaders to it.
	glAttachShader(*pProgramObject, FragmentShader);
	glAttachShader(*pProgramObject, VertexShader);
    
	// For every member in pszAttribs, bind the proper attributes.
	for (int i = 0; i < i32NumAttribs; ++i)
	{
		glBindAttribLocation(*pProgramObject, i, pszAttribs[i]);
    
	}
    
	// Link the program object
	glLinkProgram(*pProgramObject);
	
	// Check if linking succeeded.
	GLint bLinked;
	glGetProgramiv(*pProgramObject, GL_LINK_STATUS, &bLinked);
	if (!bLinked)
	{
		int i32InfoLogLength, i32CharsWritten;
		glGetProgramiv(*pProgramObject, GL_INFO_LOG_LENGTH, &i32InfoLogLength);
		char* pszInfoLog = new char[i32InfoLogLength];
		glGetProgramInfoLog(*pProgramObject, i32InfoLogLength, &i32CharsWritten, pszInfoLog);
		//*pReturnError = CString("Failed to link: ") + pszInfoLog + "\n";
		delete [] pszInfoLog;
		return FAIL;
	}
    
	// Actually use the created program.
	glUseProgram(*pProgramObject);
    
    GLint logLength, status;
	// String to pass to glShaderSource
    
    glGetProgramiv(*pProgramObject, GL_INFO_LOG_LENGTH, &logLength);
	if (logLength > 0)
	{
		GLchar *log = (GLchar*)malloc(logLength);
		glGetProgramInfoLog(*pProgramObject, logLength, &logLength, log);
		printf("Program link log:\n%s <- ENDLINE\n", log);
		free(log);
	}
	
	glGetProgramiv(*pProgramObject, GL_LINK_STATUS, &status);
	if (status == 0)
	{
		printf("Failed to link program\n\n");
		return 0;
	}
	
	glValidateProgram(*pProgramObject);
	glGetProgramiv(*pProgramObject, GL_INFO_LOG_LENGTH, &logLength);
	if (logLength > 0)
	{
		GLchar *log = (GLchar*)malloc(logLength);
		glGetProgramInfoLog(*pProgramObject, logLength, &logLength, log);
		printf("Program validate log:\n%s\n", log);
		free(log);
	}
	
	glGetProgramiv(*pProgramObject, GL_VALIDATE_STATUS, &status);
	if (status == 0)
	{
		printf("Failed to validate program\n");
		return 0;
	}
	return SUCCESS;
}
