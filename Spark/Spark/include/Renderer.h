#pragma once
#include<VertexArray.h>
#include<IndexBuffer.h>
#include<Shader.h>  

class Renderer {
    public:
        Renderer(VertexArray& vertexArray, VertexBuffer& vertexBuffer, IndexBuffer& indexBuffer);
        void Clear() const;
        void Render(const Shader& shader) const;

    private: 
        VertexArray _vertexArray;
        VertexBuffer _vertexBuffer;
        IndexBuffer _indexBuffer;
};