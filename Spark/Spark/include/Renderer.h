#pragma once
#include<iostream>

#include<glad/gl.h>
#include<GLFW/glfw3.h>


#define ASSERT(x) if(!(x)) raise(SIGTRAP);
#define GLCall(x) GlClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__));


void GlClearError();
bool GLLogCall(const char* function, const char* sourceFile, int line); 