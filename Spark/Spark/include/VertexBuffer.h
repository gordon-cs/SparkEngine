#pragma once
#include <glad/gl.h>

class VertexBuffer {
    public:
        unsigned int ID;
        VertexBuffer(float* vertices, unsigned int size);
        ~VertexBuffer();

        void Bind();
        void Unbind();
};