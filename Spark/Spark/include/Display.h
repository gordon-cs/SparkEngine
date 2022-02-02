#pragma once
#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
#include<signal.h>
#include<Color.h>
#include<Renderer.h>
#include<VertexBuffer.h>
#include<VertexBufferLayout.h>
#include<VertexArray.h>
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
        VertexBuffer _vertexBuffer;
        IndexBuffer _indexBuffer;
        unsigned int _shader;

};