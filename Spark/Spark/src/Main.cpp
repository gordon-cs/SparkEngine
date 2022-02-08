#include<Color.h>
#include<Shader.h>
#include<cmath>
#include<glad/gl.h>
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

    glViewport(0, 0, 1000, 800);

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
    unsigned int vertexBuffer;
    unsigned int indexBuffer;
    unsigned int vertexArray;
    

	// Generate the VAO and VBO with only 1 object each
	glGenVertexArrays(1, &vertexArray);
	glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &indexBuffer);

	// Make the VAO the current Vertex Array Object by binding it
	glBindVertexArray(vertexArray);     

	// Bind the VBO specifying it's a GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	
    // Introduce the vertices into the VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Configure the Vertex Attribute so that OpenGL knows how to read the VBO
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	// Enable the Vertex Attribute so that OpenGL knows to use it
	glEnableVertexAttribArray(0);

	// Bind both the VBO and VAO to 0 so that we don't accidentally modify the VAO and VBO we created
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


    while(!glfwWindowShouldClose(window)) {
        glClearColor(color.red, color.green, color.blue, color.alpha);
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        shader -> Activate();
        glBindVertexArray(vertexArray);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &vertexArray);
	glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &indexBuffer);
    delete shader;
    glfwTerminate();
    return 0;
}