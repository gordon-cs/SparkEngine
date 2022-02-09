#pragma once
#include<iostream>
#include<OpenGLError.h>

class IndexBuffer {
    public:
	    // ID reference of Elements Buffer Object
	    GLuint ID;
	    // Constructor that generates a Elements Buffer Object and links it to indices
        IndexBuffer();
	    IndexBuffer(uint32_t* indices, uint32_t size, uint32_t count);

        inline uint32_t GetCount() const { return _indexCount; }
	    // Binds the EBO
	    void Bind() const;
	    // Unbinds the EBO
	    void Unbind();
        void Delete();

    private:
        uint32_t _indexCount;
};