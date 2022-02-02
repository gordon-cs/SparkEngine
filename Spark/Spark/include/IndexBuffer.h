#pragma once
#include<Renderer.h>

class IndexBuffer {
    public:
        IndexBuffer(const unsigned int* data, unsigned int count); 
        ~IndexBuffer();

        void Bind() const;
        void Unbind() const;

    private: 
        unsigned int _rendererID;
        unsigned int _count;
        inline unsigned int GetCount() const { return _count; }
};