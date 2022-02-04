#include<Color.h>
#include<Shader.h>
#include<GLFW/glfw3.h>

int main() {
    Color color = Color(33.0f, 33.0f, 33.0f, 0.0f);

    /* Specify version and core profile */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    float vertecies[] = {
        -0.5f, -0.5f,    // 0
         0.5f, -0.5f,    // 1
         0.5f,  0.5f,    // 2
        -0.5f,  0.5f     // 3
    };

    unsigned int indicies[] = {
        0, 1, 2,
        2, 3, 0
    };


    GLFWwindow* window;
    
    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 800, "Spark Engine", NULL, NULL);
    if(!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    /* Load glad */
    gladLoadGL(glfwGetProcAddress);

    glViewport(0, 0, 1000, 800);

    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;

    /* Generate arrays and buffers */
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO); 
    glGenBuffers(1, &EBO);

    /* Bind vertex and array buffer */
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertecies), vertecies, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    /* Unbind buffers */
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    Shader shader = Shader
        ("../resources/shaders/defaultShader.vertex", 
         "../resources/shaders/defaultShader.fragment");

    /* Loop until the user closes the window */
    while(!glfwWindowShouldClose(window))
    {
        /* Set window background color */
        glClearColor(color.red, color.green, color.blue, color.alpha);
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Activate();
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    shader.Delete();
    glfwTerminate();
    return 0;
}