#pragma once
#include<glad/gl.h>
#include<signal.h>
#include<iostream>
#include<ostream>

/* Macro for OpenGL error checks. Wrap every gl function in the GLCall macro */
#define ASSERT(x) if(!(x)) raise(SIGTRAP);
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__));

void GLClearError(); 
bool GLLogCall(const char* function, const char* sourceFile, int line);
