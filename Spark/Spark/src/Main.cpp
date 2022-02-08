#include<Color.h>
#include<Shader.h>
#include<VertexArray.h>
#include<VertexBuffer.h>
#include<IndexBuffer.h>
#include<OpenGLError.h>
#include<GLFW/glfw3.h>

int main() {
    Color color = Color(33.0f, 33.0f, 33.0f, 0.0f);

    /* Initialize the library */
    if(!glfwInit()) {
        return -1;
    }

    /* Specify version and core profile */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;
    
    

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 800, "Spark Engine", NULL, NULL);
    if(window == NULL) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    /* Load glad */
    gladLoadGL(glfwGetProcAddress);

    GLCall(glViewport(0, 0, 1000, 800));

    Shader* shader = new Shader
        ("../resources/shaders/defaultShader.vertex", 
         "../resources/shaders/defaultShader.fragment");

    float vertices[] = {
        -0.5f, -0.5f, // 0
         0.0f,  0.5f, // 1
         0.5f, -0.5f  // 2
    };

    //Indices for vertices order
    unsigned int indices[] = {
        0, 1, 2
    };

    /* Generate arrays and buffers */
    VertexArray* vertexArray = new VertexArray();
    vertexArray -> Bind();
    VertexBuffer* vertexBuffer = new VertexBuffer(vertices, sizeof(vertices));
    IndexBuffer* indexBuffer = new IndexBuffer(indices, sizeof(indices));

    vertexArray -> LinkVertexBuffer(vertexBuffer, 0);
    
    vertexArray -> Unbind();
    vertexBuffer -> Unbind();
    indexBuffer -> Unbind();

    while(!glfwWindowShouldClose(window)) {
        GLCall(glClearColor(color.red, color.green, color.blue, color.alpha));
        /* Render here */
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        shader -> Activate();
        vertexArray -> Bind();
        GLCall(glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0));

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    delete vertexArray;
    delete vertexBuffer;
    delete indexBuffer;
    delete shader;
    glfwTerminate();
    return 0;
}