#pragma once
#include<GLFW/glfw3.h>

class Display {
    public: 
        void Initialize();
        void Render();
        void Shutdown();
    private:
        GLFWwindow* _window;
};