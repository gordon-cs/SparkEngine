#include<IndexBuffer.h>


IndexBuffer::IndexBuffer(unsigned int* indices, unsigned int size, unsigned int count) {
    _indexCount = count;
    GLCall(glGenBuffers(1, &ID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &ID);
}

void IndexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID));
}


void IndexBuffer::Unbind() {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}