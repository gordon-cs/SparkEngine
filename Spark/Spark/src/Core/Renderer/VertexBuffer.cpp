#include<VertexBuffer.h>


VertexBuffer::VertexBuffer(float* vertices, unsigned int size) {
    GLCall(glGenBuffers(1, &ID));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, ID));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer() {
    GLCall(glDeleteBuffers(1, &ID));
}


void VertexBuffer::Bind() {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, ID));
}

void VertexBuffer::Unbind() {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}