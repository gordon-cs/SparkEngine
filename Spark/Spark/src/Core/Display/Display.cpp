#include<Display.h>

Display::Display() {
    _color = Color(33.0f, 33.0f, 33.0, 0.0f);
}

unsigned int CompileShader(unsigned int type, const std::string& source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE) {
        int length; 
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        
        char message[length];
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " << 
            ( type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
        std::cout << message << std::endl; 
        glDeleteShader(id);
        return 0;
    }

    return id;
}

unsigned int Display::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vertShader = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fragShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    return program;
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
    gladLoadGL(glfwGetProcAddress);
   
    // ========================= Buffers ==================== //
    float positions[6] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f    
    };
    
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer); 
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    std::string vertexShader = R"(
        #version 330 core
        layout(location = 0) in vec4 position; 
        void main() {
            gl_Position = position;
        }
    )";

        std::string fragmentShader = R"(
        #version 330 core
        layout(location = 0) out vec4 color;  
        void main() {
            color = vec4(1.0, 0.0, 0.0, 1.0);
        }
    )";

    _shader = CreateShader(vertexShader, fragmentShader);
    glUseProgram(_shader);
}


void Display::Render() {
    while(!glfwWindowShouldClose(_window)) {
        /* Render here */
        glClearColor(_color.red, _color.green, _color.blue, _color.alpha);

        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(_window);

        /* Poll for and process events */
        glfwPollEvents();
    }
}

void Display::Shutdown() {
    glDeleteProgram(_shader);
    glfwTerminate();
}