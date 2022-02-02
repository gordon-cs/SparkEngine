#include<Application.h>

Application::Application(Display* display) {
    _display = display;
}


void Application::Start() {
    _display -> Initialize();
    Loop();
}


void Application::Loop() {
    _display -> Render();
}

void Application::Shutdown() {
    delete _display;
}
