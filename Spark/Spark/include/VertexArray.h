#pragma once
#include<VertexBuffer.h>

class VertexArray {
    public:
        // ID reference for the Vertex Array Object
        GLuint ID;
        // Constructor that generates a VAO ID
        VertexArray();
        ~VertexArray();

        // Links a VBO to the VAO using a certain layout
        void LinkVertexBuffer(VertexBuffer* vertexBuffer, GLuint layout);
        // Binds the VAO
        void Bind();
        // Unbinds the VAO
        void Unbind();
};