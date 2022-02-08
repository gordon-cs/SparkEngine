#pragma once
#include<glad/gl.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

class Shader {
    std::string GetFileContents(const char* fileName);

    public:
        unsigned int ID;
        ~Shader();
        Shader(const char* vertexFile, const char* fragmentFile);
        
        void Activate() const;
        void Delete();
};