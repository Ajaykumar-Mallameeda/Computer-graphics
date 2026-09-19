# Computer Graphics — Assignment 1

## 3D Raster Model

This project implements a 3D raster model using OpenGL and C++.

The application provides a 5×5×5 3D grid containing a movable
1×1×1 cube. The cube can be colored, filled into grid cells,
and cleared. The grid and model can also be rotated.

An additional rasterized 3D line model is included.

---

## Features

- 5×5×5 equispaced 3D grid
- 1×1×1 cube aligned with the grid
- Cube movement along the three axes
- Boundary checking
- RGB cube coloring
- Persistent cell filling
- Cell clearing
- Grid/model rotation
- 3D viewing transformation
- Perspective projection
- Additional rasterized 3D model
- Depth testing
- OpenGL rendering

---

## Controls

| Key | Action |
|-----|--------|
| Left Arrow | Move cube left |
| Right Arrow | Move cube right |
| Up Arrow | Move cube up |
| Down Arrow | Move cube down |
| U | Move cube forward/up in Z direction |
| B | Move cube backward/down in Z direction |
| C | Change cube color |
| F | Fill current cell |
| W | Clear current cell |
| L | Rotate left |
| R | Rotate right |
| T | Rotate top |
| D | Rotate down |

---

## Project Structure

```text
Computer-graphics/
├── shaders/
│   ├── basic.vert
│   └── basic.frag
│
├── src/
│   ├── main.cpp
│   ├── Application.h
│   ├── Application.cpp
│   ├── Renderer.h
│   ├── Renderer.cpp
│   ├── Shader.h
│   ├── Shader.cpp
│   ├── Grid.h
│   ├── Grid.cpp
│   ├── Cube.h
│   ├── Cube.cpp
│   ├── RasterModel.h
│   ├── RasterModel.cpp
│   ├── Math.h
│   └── Math.cpp
│
├── CMakeLists.txt
├── README.md
└── .gitignore