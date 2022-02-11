#include<Renderer.h>

Renderer::Renderer(VertexArray& vertexArray, VertexBuffer& vertexBuffer, IndexBuffer& indexBuffer) {
    vertexArray.LinkVertexBuffer(vertexBuffer, 0);
    vertexArray.Unbind();
    vertexBuffer.Unbind();
    indexBuffer.Unbind();
}

void Renderer::Clear() const {
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Render(VertexArray& vertexArray, IndexBuffer& indexBuffer, Shader& shader) const {
    shader.Activate();
    vertexArray.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, 0)); 
}