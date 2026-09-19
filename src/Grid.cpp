#include "Grid.h"
Grid::Grid(int size) : size(size){
    generate();
}

void Grid::addLine(
    float x1,float y1,float z1,
    float x2,float y2,float z2)
{
    vertices.push_back(x1);
    vertices.push_back(y1);
    vertices.push_back(z1);

    vertices.push_back(x2);
    vertices.push_back(y2);
    vertices.push_back(z2);
}

void Grid::generate(){
    vertices.clear();
    for(int y = 0; y <= size;++y){
        for(int z = 0;z <= size;++z){
            addLine(
                0.0f, static_cast<float>(y), static_cast<float>(z),
                static_cast<float>(size),
                static_cast<float>(y),
                static_cast<float>(z)
            );
        }
    }
    for(int x = 0; x <= size; ++x){
        for(int z = 0; z <= size; ++z){
            addLine(
                static_cast<float>(x), 0.0f,static_cast<float>(z),
                static_cast<float>(x),
                static_cast<float>(size),
                static_cast<float>(z)
            );
        }
    }
    for(int x = 0;x<=size;++x){
        for(int y = 0; y <= size; ++y){
            addLine(
                static_cast<float>(x),
                static_cast<float>(y),
                0.0f,

                static_cast<float>(x),
                static_cast<float>(y),
                static_cast<float>(size)
            );
        }
    }
}
const std::vector<float>& Grid::getVertices() const
{
    return vertices;
}

int Grid::getSize() const
{
    return size;
}

int Grid::getVertexCount() const
{
    return static_cast<int>(vertices.size() / 3);
}

int Grid::getLineCount() const
{
    return getVertexCount() / 2;
}