#pragma once
#include<VertexBuffer.h>

class VertexArray {
    public:
        // ID reference for the Vertex Array Object
        GLuint ID;
        // Constructor that generates a VAO ID
        VertexArray();

         /* 
            Links a vertex buffer to the vertex array using a certain layout 
            @param vertexBuffer The vertex buffer to bind
            @param The layout of the vertex buffer
        */
        void LinkVertexBuffer(VertexBuffer& vertexBuffer, uint32_t layout);
        /* Binds the Vertex array */
        void Bind() const;
        /* Unbinds the vertex array */
        void Unbind();
        void Delete();
};