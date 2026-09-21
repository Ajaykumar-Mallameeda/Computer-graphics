# Computer Graphics — Assignment 1
## 3D Raster Model

**Course:** CS5024 — Fundamentals of Computer Graphics

**Team Members**
- M. Ajay Kumar
- V. Nandeeshwar

---

## Overview

This project implements an interactive 3D raster model using **C++17 and OpenGL 3.3 Core Profile**.

The application generates a **5×5×5 equispaced 3D grid** containing a movable **1×1×1 cube**. The cube can be moved along the X, Y, and Z axes while remaining inside the grid.

The application also supports RGB color selection, persistent grid-cell filling, cell clearing, and rotation of the complete 3D model.

An additional rasterized 3D line model is included, along with extra features such as 3D flood fill, flood-fill undo, and mouse-based scene rotation.

---

## Features

### Required Features

- 5×5×5 equispaced 3D grid
- 1×1×1 solid cube aligned with grid cells
- Cube movement along X, Y, and Z axes
- Boundary checking to prevent the cube from leaving the grid
- RGB cube color input
- Persistent grid-cell filling
- Cell clearing
- 90° rotation of the grid/model
- 3D viewing transformation
- Perspective projection
- Depth testing
- Additional rasterized 3D line model

### Additional Features

- 3D six-neighbour flood fill
- Flood-fill undo
- Mouse-based scene rotation

---

## Controls

| Key | Action |
|---|---|
| Left Arrow | Move cube along −X |
| Right Arrow | Move cube along +X |
| Up Arrow | Move cube along +Y |
| Down Arrow | Move cube along −Y |
| `U` | Move cube along +Z |
| `B` | Move cube along −Z |
| `C` | Change cube RGB color |
| `F` | Fill current grid cell |
| `W` | Clear current grid cell |
| `L` | Rotate model −90° about Y |
| `R` | Rotate model +90° about Y |
| `T` | Rotate model +90° about X |
| `D` | Rotate model −90° about X |
| `G` | Perform 3D flood fill |
| `H` | Undo latest flood fill |
| Mouse | Rotate the 3D scene |

---

## Additional 3D Raster Model

The project includes an additional 3D rasterized model consisting of three mutually perpendicular line segments aligned with the X, Y, and Z axes.

The model is constructed directly from 3D vertices and rendered using OpenGL `GL_LINES`.

This demonstrates the generation and rendering of an additional 3D geometric model beyond the required grid and movable cube.

---

## Implementation

The project is organized into separate modules for application logic, geometry generation, rendering, shaders, transformations, and flood fill.

### Main Components

- **Application** — Handles application state, keyboard/mouse input, and the main rendering loop.
- **Grid** — Generates the 5×5×5 3D grid geometry.
- **Cube** — Generates and manages the movable 1×1×1 cube.
- **RasterModel** — Generates the additional 3D line model.
- **FloodFill** — Implements six-neighbour 3D flood fill.
- **Renderer** — Manages OpenGL buffers and drawing operations.
- **Shader** — Loads and manages GLSL vertex and fragment shaders.
- **Math** — Provides matrix and transformation operations.

The rendering pipeline uses model, view, and projection transformations:

```text
Geometry
   ↓
Model Transformation
   ↓
View Transformation
   ↓
Projection
   ↓
Vertex Shader
   ↓
Rasterization
   ↓
Fragment Shader
   ↓
Framebuffer

```text
Project-1/
│
├── shaders/
│   ├── basic.vert
│   └── basic.frag
│
├── src/
│   ├── main.cpp
│   │
│   ├── Application.h
│   ├── Application.cpp
│   │
│   ├── Renderer.h
│   ├── Renderer.cpp
│   │
│   ├── Shader.h
│   ├── Shader.cpp
│   │
│   ├── Grid.h
│   ├── Grid.cpp
│   │
│   ├── Cube.h
│   ├── Cube.cpp
│   │
│   ├── RasterModel.h
│   ├── RasterModel.cpp
│   │
│   ├── FloodFill.h
│   ├── FloodFill.cpp
│   │
│   ├── Math.h
│   └── Math.cpp
│
├── CMakeLists.txt
├── README.md
└── .gitignore