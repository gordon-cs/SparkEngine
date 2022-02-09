#include<VertexBuffer.h>

VertexBuffer::VertexBuffer() {} 
VertexBuffer::VertexBuffer(float* vertices, uint32_t size) {
    GLCall(glGenBuffers(1, &ID));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, ID));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW));
}

void VertexBuffer::Delete() {
    GLCall(glDeleteBuffers(1, &ID));
}


void VertexBuffer::Bind() {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, ID));
}

void VertexBuffer::Unbind() {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}