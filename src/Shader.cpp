#include "Shader.h"

#include <GL/glew.h>

#include <fstream>
#include <iostream>
#include <sstream>


Shader::Shader()
    : program(0)
{
}


Shader::~Shader()
{
    if (program != 0)
    {
        glDeleteProgram(program);
    }
}


std::string Shader::readFile(const std::string& path)
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cerr << "Failed to open shader file: "
                  << path << '\n';

        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}


GLuint Shader::compileShader(
    GLenum type,
    const std::string& source)
{
    GLuint shader = glCreateShader(type);

    const char* sourceCode = source.c_str();

    glShaderSource(
        shader,
        1,
        &sourceCode,
        nullptr
    );

    glCompileShader(shader);

    GLint success = 0;

    glGetShaderiv(
        shader,
        GL_COMPILE_STATUS,
        &success
    );

    if (!success)
    {
        char infoLog[512];

        glGetShaderInfoLog(
            shader,
            512,
            nullptr,
            infoLog
        );

        std::cerr
            << "Shader compilation failed:\n"
            << infoLog
            << '\n';

        glDeleteShader(shader);

        return 0;
    }

    return shader;
}


bool Shader::load(
    const std::string& vertexPath,
    const std::string& fragmentPath)
{
    std::string vertexSource = readFile(vertexPath);
    std::string fragmentSource = readFile(fragmentPath);

    if (vertexSource.empty() || fragmentSource.empty())
    {
        return false;
    }

    GLuint vertexShader =
        compileShader(
            GL_VERTEX_SHADER,
            vertexSource
        );

    GLuint fragmentShader =
        compileShader(
            GL_FRAGMENT_SHADER,
            fragmentSource
        );

    if (vertexShader == 0 || fragmentShader == 0)
    {
        return false;
    }

    program = glCreateProgram();

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    GLint success = 0;

    glGetProgramiv(
        program,
        GL_LINK_STATUS,
        &success
    );

    if (!success)
    {
        char infoLog[512];

        glGetProgramInfoLog(
            program,
            512,
            nullptr,
            infoLog
        );

        std::cerr
            << "Shader linking failed:\n"
            << infoLog
            << '\n';

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        glDeleteProgram(program);

        program = 0;

        return false;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return true;
}


void Shader::use() const
{
    glUseProgram(program);
}


GLuint Shader::getProgram() const
{
    return program;
}