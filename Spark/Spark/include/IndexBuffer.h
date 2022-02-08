#pragma once
#include<iostream>
#include<OpenGLError.h>

class IndexBuffer
{
    public:
	    // ID reference of Elements Buffer Object
	    GLuint ID;
	    // Constructor that generates a Elements Buffer Object and links it to indices
	    IndexBuffer(unsigned int* indices, unsigned int size);
        ~IndexBuffer();


	    // Binds the EBO
	    void Bind();
	    // Unbinds the EBO
	    void Unbind();
};