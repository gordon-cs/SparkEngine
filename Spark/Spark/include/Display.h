#pragma once
#include<iostream>
#include<Color.h>
#include<glad/gl.h>
#include<GLFW/glfw3.h>

class Display {
    public: 
        Display();
        void Initialize();
        void Render();
        void Shutdown();
    private:
        Color _color;
        GLFWwindow* _window;
        unsigned int _shader;

        unsigned int CreateShader
            (const std::string& vertexShader, const std::string& fragmentShader);
};