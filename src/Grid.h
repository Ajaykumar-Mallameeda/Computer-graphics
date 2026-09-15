#pragma once
#include <vector>
class Grid{
public:
    explicit Grid(int size = 5);
    void generate();
    const std::vector<float>& getVertices() const;
    int getSize() const;
    int getVertexCount() const;
    int getLineCount() const;

private:
    int size;
    std::vector<float> vertices;
    void addLine(
        float x1,float y1,float z1,
        float x2,float y2,float z2
    );
};