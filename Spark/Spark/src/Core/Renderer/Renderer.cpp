#include<Renderer.h>


void GLClearError() {
    while(glGetError() != GL_NO_ERROR);
}


bool GLLogCall(const char* function, const char* sourceFile, int line) {
    while(GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] (" << error << "): " << function << 
            " " << sourceFile << ":" << line <<  std::endl;
        return false;
    }
    return true;
}