#pragma once
#include <glad/gl.h>

class VertexBuffer {
    public:
        unsigned int ID;
        VertexBuffer(float* vertices, GLsizeiptr size);
        ~VertexBuffer();

        void Bind();
        void Unbind();
};