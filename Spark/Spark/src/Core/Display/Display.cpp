#include<Display.h>

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