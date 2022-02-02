#include<VertexArray.h>

VertexArray::VertexArray() {
    GLCall(glGenVertexArrays(1, &_rendererID ));
}

VertexArray::~VertexArray() {
    GLCall(glDeleteVertexArray(1, &_rendererID));
}


void VertexArray::Bind() const {
    GLCall(glBindVertexVertexArray(_rendererID));
}

void VertexArray::Unbind() const {
    GLCall(glBindVertexArray(0));
}


void VertexArray::AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout) {
    Bind();
    vertexBuffer.Bind();
    unsigned int offset = 0;
    const auto& elements = layout.GetElements();
    for(unsigned int i 0 i < elements.size(); i++) {
        const auto& element = elements[i];
        GLCall(glEnableVertexAttribArray(i));
        GLCall(glVertexAttribPointer
            (i, element.count, element.type, element.normalized, 
                layout.GetStride(), (const void*)offset));
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}