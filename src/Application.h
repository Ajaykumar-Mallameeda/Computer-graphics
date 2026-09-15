#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "Grid.h"
#include "Cube.h"
#include "Renderer.h"
#include "Shader.h"
#include "Math.h"


struct FilledCell
{
    int x;
    int y;
    int z;

    float r;
    float g;
    float b;
};


class Application
{
public:
    Application();

    bool initialize();

    void run();

    void shutdown();

private:
    void processInput();

    void updateMVP();

    void changeCubeColor();

    void fillCurrentCell();

    void clearCurrentCell();

    bool isCellFilled(
        int x,
        int y,
        int z
    ) const;

    GLFWwindow* window;

    int width;
    int height;

    Grid grid;
    Cube cube;

    Renderer renderer;
    Shader shader;

    // Current cube position
    int cubeX;
    int cubeY;
    int cubeZ;

    // Current cube color
    float cubeR;
    float cubeG;
    float cubeB;

    // Permanently filled cells
    std::vector<FilledCell> filledCells;

    // Key state
    bool leftWasPressed;
    bool rightWasPressed;
    bool upWasPressed;
    bool downWasPressed;
    bool uWasPressed;
    bool bWasPressed;

    bool cWasPressed;
    bool fWasPressed;
    bool wWasPressed;

    bool lWasPressed;
    bool rWasPressed;
    bool tWasPressed;
    bool dWasPressed;

    float rotationX;
    float rotationY;

    // Viewing matrices
    Mat4 view;
    Mat4 projection;
};