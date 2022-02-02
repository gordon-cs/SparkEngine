#pragma once
#include<fstream>
#include<sstream>
#include<string>
#include<signal.h>
#include<Color.h>
#include<Renderer.h>
#include<VertexBuffer.h>
#include<IndexBuffer.h>

class Display {
    public: 
        Display();
        ~Display();
        void Initialize();
        void Render();
        void Shutdown();
    private:
        Color _color;
        GLFWwindow* _window;
        VertexBuffer* _vertexBuffer;
        IndexBuffer* _indexBuffer;
        unsigned int _shader;

        unsigned int CreateShader
            (const std::string& vertexShader, const std::string& fragmentShader);
};