#pragma once
#include<GLFW/glfw3.h>

class Display {
    public: 
        Display();
        void Initialize();
        void Render();
        void Shutdown();
    private:
        float ColorConvert(float colorValue);


        GLFWwindow* _window;
        float _red;
        float _green;
        float _blue;
        float _alpha;
};