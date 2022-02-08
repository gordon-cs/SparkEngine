#pragma once
#include<OpenGLError.h>

class VertexBuffer {
    public:
        unsigned int ID;
        VertexBuffer(float* vertices, unsigned int size);
        ~VertexBuffer();

        void Bind();
        void Unbind();
};