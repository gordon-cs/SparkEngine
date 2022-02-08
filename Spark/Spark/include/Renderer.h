#pragma once
#include<VertexArray.h>
#include<IndexBuffer.h>
#include<Shader.h>  

class Renderer {
    public:
        void Clear() const;
        void Render(const VertexArray* vertexArray, const IndexBuffer* indexBuffer, 
            const Shader* shader) const;
};