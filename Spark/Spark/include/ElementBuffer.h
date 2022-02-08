#pragma once
#include<iostream>
#include<glad/gl.h>

class ElementBuffer
{
    public:
	    // ID reference of Elements Buffer Object
	    GLuint ID;
	    // Constructor that generates a Elements Buffer Object and links it to indices
	    ElementBuffer(unsigned int* indices, unsigned int size);
        ~ElementBuffer();


	    // Binds the EBO
	    void Bind();
	    // Unbinds the EBO
	    void Unbind();
};