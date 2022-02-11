#pragma once
#include<VertexArray.h>
#include<IndexBuffer.h>
#include<Shader.h>  

class Renderer {
    public:
        Renderer(VertexArray& vertexArray, VertexBuffer& vertexBuffer, IndexBuffer& indexBuffer);
        void Clear() const;
        void Render(VertexArray& vertexArray, IndexBuffer& indexBuffer, Shader& shader) const;
};