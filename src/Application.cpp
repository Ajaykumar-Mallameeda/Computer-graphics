#include "Application.h"
#include "RasterModel.h"

#include <iostream>


Application::Application()
    : window(nullptr),
      width(800),
      height(600),
      grid(5),
      cube(),
      rasterModel(),
      cubeX(2),
      cubeY(2),
      cubeZ(2),

      cubeR(0.2f),
      cubeG(0.6f),
      cubeB(1.0f),

      leftWasPressed(false),
      rightWasPressed(false),
      upWasPressed(false),
      downWasPressed(false),
      uWasPressed(false),
      bWasPressed(false),

      cWasPressed(false),
      fWasPressed(false),
      wWasPressed(false),

      lWasPressed(false),
      rWasPressed(false),
      tWasPressed(false),
      dWasPressed(false),

      rotationX(0.0f),
      rotationY(0.0f)
{
}


bool Application::initialize()
{
    // -----------------------------
    // GLFW
    // -----------------------------

    if (!glfwInit())
    {
        std::cerr
            << "Failed to initialize GLFW\n";

        return false;
    }


    glfwWindowHint(
        GLFW_CONTEXT_VERSION_MAJOR,
        3
    );

    glfwWindowHint(
        GLFW_CONTEXT_VERSION_MINOR,
        3
    );

    glfwWindowHint(
        GLFW_OPENGL_PROFILE,
        GLFW_OPENGL_CORE_PROFILE
    );

    glfwWindowHint(
        GLFW_OPENGL_FORWARD_COMPAT,
        GL_TRUE
    );


    // -----------------------------
    // Window
    // -----------------------------

    window =
        glfwCreateWindow(
            width,
            height,
            "Project-1",
            nullptr,
            nullptr
        );

    if (!window)
    {
        std::cerr
            << "Failed to create GLFW window\n";

        glfwTerminate();

        return false;
    }


    glfwMakeContextCurrent(window);


    // -----------------------------
    // GLEW
    // -----------------------------

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
    {
        std::cerr
            << "Failed to initialize GLEW\n";

        glfwDestroyWindow(window);
        glfwTerminate();

        return false;
    }


    std::cout
        << "OpenGL Version : "
        << glGetString(GL_VERSION)
        << '\n';

    std::cout
        << "GPU Renderer   : "
        << glGetString(GL_RENDERER)
        << '\n';


    glViewport(
        0,
        0,
        width,
        height
    );


    glEnable(GL_DEPTH_TEST);


    // -----------------------------
    // Shader
    // -----------------------------

    if (!shader.load(
            "shaders/basic.vert",
            "shaders/basic.frag"))
    {
        std::cerr
            << "Failed to load shaders\n";

        shutdown();

        return false;
    }


    // -----------------------------
    // Renderer
    // -----------------------------

    renderer.initialize(
        grid,
        cube,
        rasterModel
    );

    renderer.setShader(
        &shader
    );


    // -----------------------------
    // View
    // -----------------------------

    view =
        Mat4::lookAt(
            9.0f, 8.0f, 9.0f,
            2.5f, 2.5f, 2.5f,
            0.0f, 1.0f, 0.0f
        );


    // -----------------------------
    // Projection
    // -----------------------------

    float aspect =
        static_cast<float>(width) /
        static_cast<float>(height);


    projection =
        Mat4::perspective(
            45.0f,
            aspect,
            0.1f,
            100.0f
        );


    // -----------------------------
    // ViewProjection
    // -----------------------------

    Mat4 viewProjection =
        projection * view;


    renderer.setViewProjection(
        viewProjection
    );
    renderer.setRotation(
    rotationX,
    rotationY);


    glfwSwapInterval(1);

    return true;
}


void Application::processInput()
{
    // ==========================================
    // X AXIS
    // ==========================================

    bool leftPressed =
        glfwGetKey(
            window,
            GLFW_KEY_LEFT
        ) == GLFW_PRESS;


    if (leftPressed && !leftWasPressed)
    {
        if (cubeX > 0)
        {
            cubeX--;

            std::cout
                << "Cube position: ("
                << cubeX << ", "
                << cubeY << ", "
                << cubeZ << ")\n";
        }
    }

    leftWasPressed =
        leftPressed;


    bool rightPressed =
        glfwGetKey(
            window,
            GLFW_KEY_RIGHT
        ) == GLFW_PRESS;


    if (rightPressed && !rightWasPressed)
    {
        if (cubeX < grid.getSize() - 1)
        {
            cubeX++;

            std::cout
                << "Cube position: ("
                << cubeX << ", "
                << cubeY << ", "
                << cubeZ << ")\n";
        }
    }

    rightWasPressed =
        rightPressed;


    // ==========================================
    // Y AXIS
    // ==========================================

    bool downPressed =
        glfwGetKey(
            window,
            GLFW_KEY_DOWN
        ) == GLFW_PRESS;


    if (downPressed && !downWasPressed)
    {
        if (cubeY > 0)
        {
            cubeY--;

            std::cout
                << "Cube position: ("
                << cubeX << ", "
                << cubeY << ", "
                << cubeZ << ")\n";
        }
    }

    downWasPressed =
        downPressed;


    bool upPressed =
        glfwGetKey(
            window,
            GLFW_KEY_UP
        ) == GLFW_PRESS;


    if (upPressed && !upWasPressed)
    {
        if (cubeY < grid.getSize() - 1)
        {
            cubeY++;

            std::cout
                << "Cube position: ("
                << cubeX << ", "
                << cubeY << ", "
                << cubeZ << ")\n";
        }
    }

    upWasPressed =
        upPressed;


    // ==========================================
    // Z AXIS
    // ==========================================

    bool uPressed =
        glfwGetKey(
            window,
            GLFW_KEY_U
        ) == GLFW_PRESS;


    if (uPressed && !uWasPressed)
    {
        if (cubeZ < grid.getSize() - 1)
        {
            cubeZ++;

            std::cout
                << "Cube position: ("
                << cubeX << ", "
                << cubeY << ", "
                << cubeZ << ")\n";
        }
    }

    uWasPressed =
        uPressed;


    bool bPressed =
        glfwGetKey(
            window,
            GLFW_KEY_B
        ) == GLFW_PRESS;


    if (bPressed && !bWasPressed)
    {
        if (cubeZ > 0)
        {
            cubeZ--;

            std::cout
                << "Cube position: ("
                << cubeX << ", "
                << cubeY << ", "
                << cubeZ << ")\n";
        }
    }

    bWasPressed =
        bPressed;


    // ==========================================
    // C — CHANGE COLOR
    // ==========================================

    bool cPressed =
        glfwGetKey(
            window,
            GLFW_KEY_C
        ) == GLFW_PRESS;


    if (cPressed && !cWasPressed)
    {
        changeCubeColor();
    }

    cWasPressed =
        cPressed;


    // ==========================================
    // F — FILL CELL
    // ==========================================

    bool fPressed =
        glfwGetKey(
            window,
            GLFW_KEY_F
        ) == GLFW_PRESS;


    if (fPressed && !fWasPressed)
    {
        fillCurrentCell();
    }

    fWasPressed =
        fPressed;


    // ==========================================
    // W — CLEAR CELL
    // ==========================================

    bool wPressed =
        glfwGetKey(
            window,
            GLFW_KEY_W
        ) == GLFW_PRESS;


    if (wPressed && !wWasPressed)
    {
        clearCurrentCell();
    }

    wWasPressed =
        wPressed;

    // ==========================================
// L — ROTATE LEFT
// ==========================================

bool lPressed =
    glfwGetKey(
        window,
        GLFW_KEY_L
    ) == GLFW_PRESS;


if (lPressed && !lWasPressed)
{
    rotationY -= 90.0f;

    renderer.setRotation(
        rotationX,
        rotationY
    );

    std::cout
        << "Grid rotation: X="
        << rotationX
        << " Y="
        << rotationY
        << '\n';
}

lWasPressed =
    lPressed;


// ==========================================
// R — ROTATE RIGHT
// ==========================================

bool rPressed =
    glfwGetKey(
        window,
        GLFW_KEY_R
    ) == GLFW_PRESS;


if (rPressed && !rWasPressed)
{
    rotationY += 90.0f;

    renderer.setRotation(
        rotationX,
        rotationY
    );

    std::cout
        << "Grid rotation: X="
        << rotationX
        << " Y="
        << rotationY
        << '\n';
}

rWasPressed =
    rPressed;


// ==========================================
// T — ROTATE TOP
// ==========================================

bool tPressed =
    glfwGetKey(
        window,
        GLFW_KEY_T
    ) == GLFW_PRESS;


if (tPressed && !tWasPressed)
{
    rotationX += 90.0f;

    renderer.setRotation(
        rotationX,
        rotationY
    );

    std::cout
        << "Grid rotation: X="
        << rotationX
        << " Y="
        << rotationY
        << '\n';
}

tWasPressed =
    tPressed;


// ==========================================
// D — ROTATE DOWN
// ==========================================

bool dPressed =
    glfwGetKey(
        window,
        GLFW_KEY_D
    ) == GLFW_PRESS;


if (dPressed && !dWasPressed)
{
    rotationX -= 90.0f;

    renderer.setRotation(
        rotationX,
        rotationY
    );

    std::cout
        << "Grid rotation: X="
        << rotationX
        << " Y="
        << rotationY
        << '\n';
}

dWasPressed =
    dPressed;
}


void Application::changeCubeColor()
{
    int r;
    int g;
    int b;


    std::cout
        << "\nEnter RGB values "
        << "(0-255): ";


    std::cin
        >> r
        >> g
        >> b;


    if (std::cin.fail())
    {
        std::cin.clear();

        std::cin.ignore(
            10000,
            '\n'
        );

        std::cerr
            << "Invalid RGB input.\n";

        return;
    }


    if (
        r < 0 || r > 255 ||
        g < 0 || g > 255 ||
        b < 0 || b > 255
    )
    {
        std::cerr
            << "RGB values must be "
            << "between 0 and 255.\n";

        return;
    }


    cubeR =
        static_cast<float>(r) / 255.0f;

    cubeG =
        static_cast<float>(g) / 255.0f;

    cubeB =
        static_cast<float>(b) / 255.0f;


    std::cout
        << "Cube color changed to RGB("
        << r << ", "
        << g << ", "
        << b << ")\n";
}


bool Application::isCellFilled(
    int x,
    int y,
    int z) const
{
    for (const FilledCell& cell :
         filledCells)
    {
        if (
            cell.x == x &&
            cell.y == y &&
            cell.z == z
        )
        {
            return true;
        }
    }

    return false;
}


void Application::fillCurrentCell()
{
    for (FilledCell& cell :
         filledCells)
    {
        if (
            cell.x == cubeX &&
            cell.y == cubeY &&
            cell.z == cubeZ
        )
        {
            // Update existing filled cell
            // to current cube color.

            cell.r = cubeR;
            cell.g = cubeG;
            cell.b = cubeB;

            std::cout
                << "Updated filled cell at ("
                << cubeX << ", "
                << cubeY << ", "
                << cubeZ << ")\n";

            return;
        }
    }


    FilledCell cell;

    cell.x = cubeX;
    cell.y = cubeY;
    cell.z = cubeZ;

    cell.r = cubeR;
    cell.g = cubeG;
    cell.b = cubeB;


    filledCells.push_back(cell);


    std::cout
        << "Filled cell at ("
        << cubeX << ", "
        << cubeY << ", "
        << cubeZ << ")\n";
}


void Application::clearCurrentCell()
{
    for (
        auto it = filledCells.begin();
        it != filledCells.end();
        ++it)
    {
        if (
            it->x == cubeX &&
            it->y == cubeY &&
            it->z == cubeZ
        )
        {
            filledCells.erase(it);

            std::cout
                << "Cleared cell at ("
                << cubeX << ", "
                << cubeY << ", "
                << cubeZ << ")\n";

            return;
        }
    }


    std::cout
        << "No filled cell at ("
        << cubeX << ", "
        << cubeY << ", "
        << cubeZ << ")\n";
}


void Application::updateMVP()
{
    // No longer needed for CP-5.
    //
    // Renderer now receives ViewProjection
    // and creates a Model matrix for each cube.
}


void Application::run()
{
    while (!glfwWindowShouldClose(window))
    {
        processInput();


        glClear(
            GL_COLOR_BUFFER_BIT |
            GL_DEPTH_BUFFER_BIT
        );


        // -----------------------------
        // Draw grid
        // -----------------------------

        renderer.drawGrid();
        renderer.drawRasterModel();


        // -----------------------------
        // Draw permanently filled cells
        // -----------------------------

        for (const FilledCell& cell :
             filledCells)
        {
            renderer.drawCube(
                cell.x,
                cell.y,
                cell.z,
                cell.r,
                cell.g,
                cell.b
            );
        }


        // -----------------------------
        // Draw current movable cube
        // -----------------------------

        renderer.drawCube(
            cubeX,
            cubeY,
            cubeZ,
            cubeR,
            cubeG,
            cubeB
        );


        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    shutdown();
}


void Application::shutdown()
{
    if (window != nullptr)
    {
        glfwDestroyWindow(window);

        window = nullptr;
    }

    glfwTerminate();
}