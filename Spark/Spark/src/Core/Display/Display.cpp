#include<Display.h>

Display::Display() {
    _red = ColorConvert(33.0f);
    _green = ColorConvert(33.0);
    _blue = ColorConvert(33.0f);
    _alpha = ColorConvert(0.0f);
}


float Display::ColorConvert(float colorValue) {
    return colorValue / 255.0;
}

void Display::Initialize() {
    if(!glfwInit())
        { return; }

    _window = glfwCreateWindow(640, 480, "Spark Engine", NULL, NULL);
    
    if(!_window) {
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(_window);
}


void Display::Render() {
    while(!glfwWindowShouldClose(_window)) {
        /* Render here */
        glClearColor(_red, _green, _blue, _alpha);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(_window);

        /* Poll for and process events */
        glfwPollEvents();
    }
}

void Display::Shutdown() {
    glfwTerminate();
}