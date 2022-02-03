#include <Color.h>
#include<glad/gl.h>
#include<GLFW/glfw3.h>

int main() {
    Color _color = Color(33.0f, 33.0f, 33.0f, 0.0f);
    if(!glfwInit()) { 
        return -1; 
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(800, 800, "Spark Engine", NULL, NULL);
    
    if(!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    gladLoadGL(glfwGetProcAddress);



    while(!glfwWindowShouldClose(window)) {
        /* Render here */
        glClearColor(_color.red, _color.green, _color.blue, _color.alpha);
        glClear(GL_COLOR_BUFFER_BIT);
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}