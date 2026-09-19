#include "Cube.h"

Cube::Cube(){
    generate();
}

void Cube::addVertex(float x, float y, float z){
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(z);
}

void Cube::generate()
{
    vertices.clear();

    const float x0 = 2.0f;
    const float x1 = 3.0f;

    const float y0 = 2.0f;
    const float y1 = 3.0f;

    const float z0 = 2.0f;
    const float z1 = 3.0f;

    //Front face
    addVertex(x0,y0,z1);
     addVertex(x1, y0, z1);
    addVertex(x1, y1, z1);

    addVertex(x0, y0, z1);
    addVertex(x1, y1, z1);
    addVertex(x0, y1, z1);


    // Back face
    addVertex(x0, y0, z0);
    addVertex(x1, y1, z0);
    addVertex(x1, y0, z0);

    addVertex(x0, y0, z0);
    addVertex(x0, y1, z0);
    addVertex(x1, y1, z0);


    // Left face
    addVertex(x0, y0, z0);
    addVertex(x0, y0, z1);
    addVertex(x0, y1, z1);

    addVertex(x0, y0, z0);
    addVertex(x0, y1, z1);
    addVertex(x0, y1, z0);


    // Right face
    addVertex(x1, y0, z0);
    addVertex(x1, y1, z1);
    addVertex(x1, y0, z1);

    addVertex(x1, y0, z0);
    addVertex(x1, y1, z0);
    addVertex(x1, y1, z1);


    // Top face
    addVertex(x0, y1, z0);
    addVertex(x0, y1, z1);
    addVertex(x1, y1, z1);

    addVertex(x0, y1, z0);
    addVertex(x1, y1, z1);
    addVertex(x1, y1, z0);


    // Bottom face
    addVertex(x0, y0, z0);
    addVertex(x1, y0, z1);
    addVertex(x0, y0, z1);

    addVertex(x0, y0, z0);
    addVertex(x1, y0, z0);
    addVertex(x1, y0, z1);
}
const std::vector<float>& Cube::getVertices() const{
    return vertices;
}

int Cube::getVertexCount() const{
    return static_cast<int>(vertices.size() / 3);
}