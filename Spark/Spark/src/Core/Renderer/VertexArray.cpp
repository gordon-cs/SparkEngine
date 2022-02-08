#include<VertexArray.h>


VertexArray::VertexArray() {
    GLCall(glGenVertexArrays(1, &ID));
}

VertexArray::~VertexArray() {
    GLCall(glDeleteVertexArrays(1, &ID));
}

void VertexArray::LinkVertexBuffer(VertexBuffer* vertexBuffer, unsigned int layout) {
    vertexBuffer -> Bind();
	GLCall(glVertexAttribPointer(layout, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0));
	GLCall(glEnableVertexAttribArray(layout));
	vertexBuffer -> Unbind();
}

void VertexArray::Bind() {
    GLCall(glBindVertexArray(ID));
}

void VertexArray::Unbind() {
    GLCall(glBindVertexArray(0));
}