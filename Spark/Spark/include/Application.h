#pragma once
#include<Display.h>

class Application {
    public:
        Application(Display display);
        void Start();
        void Loop();
        void Shutdown();

    private:
        Display _display;
};