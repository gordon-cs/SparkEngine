#include<Display.h>

Display::Display() {
    _color = Color(33.0f, 33.0f, 33.0, 0.0f);
}

void Display::Initialize() {
    if(!glfwInit())
        { return; }

    _window = glfwCreateWindow(800, 800, "Spark Engine", NULL, NULL);
    
    if(!_window) {
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(_window);
}


void Display::Render() {
    while(!glfwWindowShouldClose(_window)) {
        /* Render here */
        glClearColor(_color.red, _color.green, _color.blue, _color.alpha);
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