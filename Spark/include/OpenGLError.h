#pragma once
#include<glad/gl.h>
#include<signal.h>
#include<iostream>
#include<ostream>

#define ASSERT(x) if(!(x)) raise(SIGTRAP);
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__));

void GLClearError(); 
bool GLLogCall(const char* function, const char* sourceFile, int line);
