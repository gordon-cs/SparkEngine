#pragma once
#include<iostream>
#include<OpenGLError.h>
/* Represents an index buffer */
class IndexBuffer {
    public:
	    // ID reference of index buffer
	    GLuint ID;
	    
        IndexBuffer();
        /* 
            @param indices Array of indicies 
            @param size Size of the index array in bytes
            @param count Number of elements in the indices array
        */
	    IndexBuffer(uint32_t* indices, uint32_t size, uint32_t count);

        inline uint32_t GetCount() const { return _indexCount; }
	    // Binds the index buffer
	    void Bind() const;
	    // Unbinds the index buffer
	    void Unbind();
        void Delete();

    private:
        uint32_t _indexCount;
};