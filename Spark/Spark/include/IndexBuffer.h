#pragma once
#include<iostream>
#include<OpenGLError.h>

class IndexBuffer
{
    public:
	    // ID reference of Elements Buffer Object
	    GLuint ID;
	    // Constructor that generates a Elements Buffer Object and links it to indices
	    IndexBuffer(unsigned int* indices, unsigned int size, unsigned int count);
        ~IndexBuffer();

        inline unsigned int GetCount() const { return _indexCount; }
	    // Binds the EBO
	    void Bind() const;
	    // Unbinds the EBO
	    void Unbind();

    private:
        unsigned int _indexCount;
};