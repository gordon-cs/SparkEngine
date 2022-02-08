#include<ElementBuffer.h>

ElementBuffer::ElementBuffer(unsigned int* indices, unsigned int size) {
    glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

ElementBuffer::~ElementBuffer() {
    glDeleteBuffers(1, &ID);
}

void ElementBuffer::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}


void ElementBuffer::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}