#include<Renderer.h>

Renderer::Renderer(VertexArray& vertexArray, VertexBuffer& vertexBuffer, IndexBuffer& indexBuffer) {
    _vertexArray = vertexArray;
    _vertexBuffer = vertexBuffer;
    _indexBuffer = indexBuffer;
    
    _vertexArray.Bind();
    _vertexArray.LinkVertexBuffer(_vertexBuffer, 0);
    
    _vertexArray.Unbind();
    _vertexBuffer.Unbind();
    _indexBuffer.Unbind();
}

Renderer::~Renderer() {
    _vertexArray.Delete();
    _vertexBuffer.Delete();
    _indexBuffer.Delete();
}

void Renderer::Clear() const {
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Render(const Shader& shader) const {
    shader.Activate();
    _vertexArray.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, _indexBuffer.GetCount(), GL_UNSIGNED_INT, 0)); 
}