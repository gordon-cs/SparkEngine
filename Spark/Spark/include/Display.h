#pragma once
#include<Color.h>
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
};