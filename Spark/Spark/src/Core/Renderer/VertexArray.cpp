#include<VertexArray.h>

VertexArray::VertexArray() {
    glGenVertexArrays(1, &ID);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &ID);
}

void VertexArray::LinkVertexBuffer(VertexBuffer* vertexBuffer, unsigned int layout) {
    vertexBuffer -> Bind();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(layout);
	vertexBuffer -> Unbind();
}

void VertexArray::Bind() {
    glBindVertexArray(ID);
}

void VertexArray::Unbind() {
    glBindVertexArray(0);
}