#pragma once
#include<OpenGLError.h>

class VertexBuffer {
    public:
        uint32_t ID;
        VertexBuffer();
        VertexBuffer(float* vertices, uint32_t size);

        void Bind();
        void Unbind();
        void Delete();
};