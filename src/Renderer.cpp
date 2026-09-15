#include "Renderer.h"


Renderer::Renderer()
    : gridVAO(0),
      gridVBO(0),
      cubeVAO(0),
      cubeVBO(0),
      gridVertexCount(0),
      cubeVertexCount(0),
      shader(nullptr),
      viewProjection(Mat4::identity()),
      rotationX(0.0f),
      rotationY(0.0f)
{
}

void Renderer::setRotation(
    float rotationX,
    float rotationY)
{
    this->rotationX = rotationX;
    this->rotationY = rotationY;
}

Renderer::~Renderer()
{
    if (gridVBO != 0)
    {
        glDeleteBuffers(1, &gridVBO);
    }

    if (gridVAO != 0)
    {
        glDeleteVertexArrays(1, &gridVAO);
    }

    if (cubeVBO != 0)
    {
        glDeleteBuffers(1, &cubeVBO);
    }

    if (cubeVAO != 0)
    {
        glDeleteVertexArrays(1, &cubeVAO);
    }
}


void Renderer::initialize(
    const Grid& grid,
    const Cube& cube)
{
    // -----------------------------
    // Grid
    // -----------------------------

    const std::vector<float>& gridVertices =
        grid.getVertices();

    gridVertexCount =
        grid.getVertexCount();

    glGenVertexArrays(
        1,
        &gridVAO
    );

    glGenBuffers(
        1,
        &gridVBO
    );

    glBindVertexArray(gridVAO);

    glBindBuffer(
        GL_ARRAY_BUFFER,
        gridVBO
    );

    glBufferData(
        GL_ARRAY_BUFFER,
        gridVertices.size() * sizeof(float),
        gridVertices.data(),
        GL_STATIC_DRAW
    );

    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        3 * sizeof(float),
        nullptr
    );

    glEnableVertexAttribArray(0);

    glBindBuffer(
        GL_ARRAY_BUFFER,
        0
    );

    glBindVertexArray(0);


    // -----------------------------
    // Cube
    // -----------------------------

    const std::vector<float>& cubeVertices =
        cube.getVertices();

    cubeVertexCount =
        cube.getVertexCount();

    glGenVertexArrays(
        1,
        &cubeVAO
    );

    glGenBuffers(
        1,
        &cubeVBO
    );

    glBindVertexArray(cubeVAO);

    glBindBuffer(
        GL_ARRAY_BUFFER,
        cubeVBO
    );

    glBufferData(
        GL_ARRAY_BUFFER,
        cubeVertices.size() * sizeof(float),
        cubeVertices.data(),
        GL_STATIC_DRAW
    );

    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        3 * sizeof(float),
        nullptr
    );

    glEnableVertexAttribArray(0);

    glBindBuffer(
        GL_ARRAY_BUFFER,
        0
    );

    glBindVertexArray(0);
}


void Renderer::setShader(Shader* shader)
{
    this->shader = shader;
}


void Renderer::setViewProjection(
    const Mat4& viewProjection)
{
    this->viewProjection =
        viewProjection;
}

void Renderer::drawGrid() const
{
    if (shader == nullptr)
    {
        return;
    }

    shader->use();


    // Grid center
    const float center = 2.5f;


    // Rotate around grid center:
    //
    // T(center)
    //     *
    // R
    //     *
    // T(-center)

    Mat4 translateToCenter =
        Mat4::translation(
            center,
            center,
            center
        );


    Mat4 translateBack =
        Mat4::translation(
            -center,
            -center,
            -center
        );


    Mat4 rotationYMatrix =
        Mat4::rotationY(
            rotationY
        );


    Mat4 rotationXMatrix =
        Mat4::rotationX(
            rotationX
        );


    Mat4 model =
        translateToCenter *
        rotationYMatrix *
        rotationXMatrix *
        translateBack;


    Mat4 mvp =
        viewProjection * model;


    GLint mvpLocation =
        glGetUniformLocation(
            shader->getProgram(),
            "uMVP"
        );


    glUniformMatrix4fv(
        mvpLocation,
        1,
        GL_FALSE,
        mvp.m
    );


    GLint colorLocation =
        glGetUniformLocation(
            shader->getProgram(),
            "uColor"
        );


    glUniform3f(
        colorLocation,
        0.8f,
        0.8f,
        0.8f
    );


    glBindVertexArray(
        gridVAO
    );


    glDrawArrays(
        GL_LINES,
        0,
        gridVertexCount
    );


    glBindVertexArray(0);
}

void Renderer::drawCube(
    int x,
    int y,
    int z,
    float r,
    float g,
    float b) const
{
    if (shader == nullptr)
    {
        return;
    }

    shader->use();


    // -----------------------------
    // Rotation around grid center
    // -----------------------------

    const float center = 2.5f;


    Mat4 translateToCenter =
        Mat4::translation(
            center,
            center,
            center
        );


    Mat4 translateBack =
        Mat4::translation(
            -center,
            -center,
            -center
        );


    Mat4 rotationYMatrix =
        Mat4::rotationY(
            rotationY
        );


    Mat4 rotationXMatrix =
        Mat4::rotationX(
            rotationX
        );


    Mat4 globalRotation =
        translateToCenter *
        rotationYMatrix *
        rotationXMatrix *
        translateBack;


    // -----------------------------
    // Cube position
    // -----------------------------

    Mat4 cubeTranslation =
        Mat4::translation(
            static_cast<float>(x - 2),
            static_cast<float>(y - 2),
            static_cast<float>(z - 2)
        );


    // -----------------------------
    // Complete model transformation
    // -----------------------------

    Mat4 model =
        globalRotation *
        cubeTranslation;


    Mat4 mvp =
        viewProjection * model;


    GLint mvpLocation =
        glGetUniformLocation(
            shader->getProgram(),
            "uMVP"
        );


    glUniformMatrix4fv(
        mvpLocation,
        1,
        GL_FALSE,
        mvp.m
    );


    GLint colorLocation =
        glGetUniformLocation(
            shader->getProgram(),
            "uColor"
        );


    glUniform3f(
        colorLocation,
        r,
        g,
        b
    );


    glBindVertexArray(
        cubeVAO
    );


    glDrawArrays(
        GL_TRIANGLES,
        0,
        cubeVertexCount
    );


    glBindVertexArray(0);
}
