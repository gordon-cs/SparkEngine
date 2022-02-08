#include<IndexBuffer.h>


IndexBuffer::IndexBuffer(unsigned int* indices, unsigned int size) {
    GLCall(glGenBuffers(1, &ID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &ID);
}

void IndexBuffer::Bind() {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID));
}


void IndexBuffer::Unbind() {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}