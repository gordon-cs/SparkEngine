#pragma once
#include<OpenGLError.h>

/* Represents a vertex buffer */
class VertexBuffer {
    public:
        uint32_t ID;
        VertexBuffer();
        /* 
            @param vertices The vertex array of the object to draw
            @param The size of vertices in bytes
         */
        VertexBuffer(float* vertices, uint32_t size);

        /* Binds the vertex buffer */
        void Bind();
        /* Unbinds the vertex buffer */
        void Unbind();
        void Delete();
};