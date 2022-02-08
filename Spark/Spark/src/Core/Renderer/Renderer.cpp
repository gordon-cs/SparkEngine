#include<Renderer.h>

void Renderer::Clear() const {
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Render(const VertexArray* vertexArray, const IndexBuffer* indexBuffer, 
    const Shader* shader) const {
    shader -> Activate();
    vertexArray -> Bind();
    GLCall(glDrawElements(GL_TRIANGLES, indexBuffer -> GetCount(), GL_UNSIGNED_INT, 0)); 
}