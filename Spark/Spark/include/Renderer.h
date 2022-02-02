#pragma once
#include<iostream>
#include<signal.h>
#include<glad/gl.h>
#include<GLFW/glfw3.h>


#define ASSERT(x) if(!(x)) raise(SIGTRAP);
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__));


void GLClearError();
bool GLLogCall(const char* function, const char* sourceFile, int line); 