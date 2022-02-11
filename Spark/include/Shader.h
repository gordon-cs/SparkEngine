#pragma once
#include<glad/gl.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

/* Represents a shader */
class Shader {
    /* 
        Parses shader file 
        @param fileName - Shader file path
    */
    std::string GetFileContents(const char* fileName);

    public:
        unsigned int ID;
        Shader();
        /*
            @param vertexFile Vertex file path
            @param fragmentFile Fragment file path
         */
        Shader(const char* vertexFile, const char* fragmentFile);
        
        /* Tells OpenGL to use the shader */
        void Activate() const;
        
        void Delete();
};