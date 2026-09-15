#pragma once
#include <vector>

class Cube
{
public:
    Cube();
    void generate();
    const std::vector<float>& getVertices() const;
    int getVertexCount() const;

private:
    std::vector<float> vertices;
    void addVertex(float x, float y, float z);
};