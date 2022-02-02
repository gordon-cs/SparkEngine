#include<Display.h>

Display::Display() {
    _color = Color(33.0f, 33.0f, 33.0, 0.0f);
}

Display::~Display() {
    GLCall(glDeleteProgram(_shader));
    delete _vertexBuffer;
    delete _indexBuffer;
    glfwTerminate();
}


struct ShaderProgramSource {
    std::string VertexSource;
    std::string FragmentSource;
};


ShaderProgramSource ParseShader(const std::string filePath) {
    enum class ShaderType {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };
    std::ifstream stream(filePath);
    std::stringstream stringStream[2];
    std::string line;
    ShaderType type = ShaderType::NONE;
    while(getline(stream, line)) {
        if(line.find("#shader") != std::string::npos) {
            if(line.find("vertex") != std::string::npos) {
                type = ShaderType::VERTEX;
            } else if(line.find("fragment") != std::string::npos) {
                type = ShaderType::FRAGMENT;
            }
        } else {
            stringStream[(int)type] << line << '\n';
        }
    }
    return { stringStream[0].str(), stringStream[1].str() };
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

unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
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
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    _window = glfwCreateWindow(800, 800, "Spark Engine", NULL, NULL);
    
    if(!_window) {
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(_window);
    glfwSwapInterval(1);
    gladLoadGL(glfwGetProcAddress);
    


    // ========================= Buffers ==================== //
    float positions[] = {
        -0.5f, -0.5f,  // 0
         0.5f, -0.5f,  // 1
         0.5f,  0.5f,  // 2 
        -0.5f,  0.5f   // 3
    };
    
    unsigned int indicies[] = {
        0, 1, 2,
        2, 3, 0 
    }; 


    

    _vertexBuffer = new VertexBuffer(positions, 4 * 2 * sizeof(float));

    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);


    _indexBuffer = new IndexBuffer(indicies, 6);
 


 
    // ==========================Shaders======================================== //
    ShaderProgramSource source = ParseShader("../resources/shaders/Basic.shader");
    _shader = CreateShader(source.VertexSource, source.FragmentSource);
    glUseProgram(_shader);
    
    int location = glGetUniformLocation(_shader, "uniformColor");
    ASSERT(location != 1);
    glUniform4f(location, 0.2f, 0.3f, 0.8f, 1.0f); // Set color of shader
}



void Display::Render() {
    while(!glfwWindowShouldClose(_window)) {
        /* Render here */
        GLCall(glClearColor(_color.red, _color.green, _color.blue, _color.alpha));

        GLCall(glClear(GL_COLOR_BUFFER_BIT));
        
        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));        
        /* Swap front and back buffers */
        glfwSwapBuffers(_window);

        /* Poll for and process events */
        glfwPollEvents();
    }
}