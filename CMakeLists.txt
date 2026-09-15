cmake_minimum_required(VERSION 3.20)

project(Assignment1
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW CONFIG REQUIRED)

add_executable(Project-1
    src/main.cpp

    src/Application.cpp
    src/Application.h

    src/Shader.cpp
    src/Shader.h

    src/Grid.cpp
    src/Grid.h

    src/Cube.cpp
    src/Cube.h

    src/Renderer.cpp
    src/Renderer.h 

    src/Math.cpp
    src/Math.h
)

target_link_libraries(Project-1
    PRIVATE
        OpenGL::GL
        glfw
        GLEW::GLEW
)

add_custom_command(TARGET Project-1 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/shaders
    $<TARGET_FILE_DIR:Project-1>/shaders
)