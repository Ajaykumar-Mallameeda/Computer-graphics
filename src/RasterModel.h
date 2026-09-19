#pragma once

#include <vector>

class RasterModel
{
public:
    RasterModel();

    const std::vector<float>& getVertices() const;

    int getVertexCount() const;

private:
    std::vector<float> vertices;
};