#pragma once

#include <GL/glew.h>

#include <string>


class Shader
{
public:

    Shader();

    ~Shader();

    bool load(
        const std::string& vertexPath,
        const std::string& fragmentPath
    );

    void use() const;

    GLuint getProgram() const;

private:

    GLuint program;

    std::string readFile(
        const std::string& path
    );

    GLuint compileShader(
        GLenum type,
        const std::string& source
    );
};