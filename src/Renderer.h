#pragma once

#include <GL/glew.h>

#include "Grid.h"
#include "Cube.h"
#include "Shader.h"
#include "Math.h"


class Renderer
{
public:
    Renderer();

    ~Renderer();

    void initialize(
        const Grid& grid,
        const Cube& cube
    );

    void setShader(
        Shader* shader
    );

    void setViewProjection(
        const Mat4& viewProjection
    );

    void setRotation(
        float rotationX,
        float rotationY
    );

    void drawGrid() const;

    void drawCube(
        int x,
        int y,
        int z,
        float r,
        float g,
        float b
    ) const;
private:
    GLuint gridVAO;
    GLuint gridVBO;

    GLuint cubeVAO;
    GLuint cubeVBO;

    int gridVertexCount;
    int cubeVertexCount;

    Shader* shader;

    Mat4 viewProjection;
    float rotationX;
    float rotationY;
};