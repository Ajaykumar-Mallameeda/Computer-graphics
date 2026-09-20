#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "Grid.h"
#include "Cube.h"
#include "Renderer.h"
#include "Shader.h"
#include "Math.h"
#include "FloodFill.h"


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

    // Input
    void processInput();

    // Mouse
    void processMouse(double xpos, double ypos);

    static void mouseCallback(
        GLFWwindow* window,
        double xpos,
        double ypos
    );


    // Other functions
    void updateMVP();

    void changeCubeColor();

    void fillCurrentCell();

    void clearCurrentCell();

    void floodFillCurrentCell();

    void undoFloodFill();


    bool isCellFilled(
        int x,
        int y,
        int z
    ) const;


    // Window
    GLFWwindow* window;

    int width;
    int height;


    // Graphics
    Grid grid;

    Cube cube;

    RasterModel rasterModel;

    Renderer renderer;

    Shader shader;


    // Cube position
    int cubeX;
    int cubeY;
    int cubeZ;


    // Cube color
    float cubeR;
    float cubeG;
    float cubeB;


    // Filled cells
    std::vector<FilledCell> filledCells;

    std::vector<FilledCell> lastFloodFillCells;


    // Keyboard state
    bool leftWasPressed;
    bool rightWasPressed;

    bool upWasPressed;
    bool downWasPressed;

    bool uWasPressed;
    bool bWasPressed;

    bool cWasPressed;
    bool fWasPressed;
    bool wWasPressed;

    bool gWasPressed;
    bool hWasPressed;

    bool lWasPressed;
    bool rWasPressed;

    bool tWasPressed;
    bool dWasPressed;


    // Rotation
    float rotationX;
    float rotationY;


    // Mouse state
    double lastMouseX;
    double lastMouseY;
    bool firstMouse;


    // Camera
    Mat4 view;
    Mat4 projection;
};