#include<Color.h>
#include<Shader.h>
#include<VertexArray.h>
#include<ElementBuffer.h>
#include<GLFW/glfw3.h>

int main() {
    Color color = Color(33.0f, 33.0f, 33.0f, 0.0f);

    /* Specify version and core profile */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_CORE_PROFILE);

float vertices[] = {
     -0.5f, -0.5f, // 0
      0.5f, -0.5f, // 1
      0.5f,  0.5f, // 2
     -0.5f,  0.0f  // 3
};

// Indices for vertices order
unsigned int indices[] = {
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

    Shader shader = Shader
        ("../resources/shaders/defaultShader.vertex", 
         "../resources/shaders/defaultShader.fragment");

    /* Generate arrays and buffers */
    VertexArray* vertexArray = new VertexArray();
	vertexArray -> Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VertexBuffer* vertexBuffer =  new VertexBuffer(vertices, sizeof(vertices));

	// Generates Element Buffer Object and links it to indices
	ElementBuffer* elementBuffer = new ElementBuffer(indices, sizeof(indices));
	// Links VBO to VAO
	vertexArray -> LinkVertexBuffer(vertexBuffer, 0);
	// Unbind all to prevent accidentally modifying them
	vertexArray -> Unbind();
	vertexBuffer -> Unbind();
	elementBuffer -> Unbind();

    /* Loop until the user closes the window */
    while(!glfwWindowShouldClose(window))
    {
        /* Set window background color */
        glClearColor(color.red, color.green, color.blue, color.alpha);
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Activate();
        vertexArray -> Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    delete vertexArray;
    delete vertexBuffer;
    delete elementBuffer;
    shader.Delete();
    glfwTerminate();
    return 0;
}