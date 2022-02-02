#pragma once
#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
#include<glad/gl.h>


struct ShaderProgramSource {
    std::string VertexSource;
    std::string FragmentSource;
};

class ShaderUtility {
    public:
        ShaderProgramSource ParseShader(const std::string filePath);
        unsigned int CompileShader(unsigned int type, const std::string& source);
        unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
};