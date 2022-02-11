#pragma once
#include<VertexArray.h>
#include<IndexBuffer.h>
#include<Shader.h>  

/* This class is responsible for drawing elements to the screen */
class Renderer {
    public:
        /*  
            @param vertexArray Vertex array to be used in rendering
            @param vertexBuffer Vertex buffer to be used in rendering
            @param indexBuffer Index buffer to be used in rendering
        */
        Renderer(VertexArray& vertexArray, VertexBuffer& vertexBuffer, IndexBuffer& indexBuffer);
        /* Clears the screen */
        void Clear() const;
        /* 
            Renders the elements to the screen
            @param shader Shader to use
         */
        void Render(VertexArray& vertexArray, IndexBuffer& indexBuffer, Shader& shader) const;
};