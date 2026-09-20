#include "RasterModel.h"

RasterModel::RasterModel()
{
    // A simple 3D rasterized model.
    //
    // The model consists of three perpendicular
    // line segments crossing at the center.
    //
    // X-axis
    vertices = {
        -1.0f, 0.0f, 0.0f,
         1.0f, 0.0f, 0.0f,

         // Y-axis
         0.0f, -1.0f, 0.0f,
         0.0f,  1.0f, 0.0f,

         // Z-axis
         0.0f, 0.0f, -1.0f,
         0.0f, 0.0f,  1.0f
    };
}

const std::vector<float>& RasterModel::getVertices() const
{
    return vertices;
}

int RasterModel::getVertexCount() const
{
    return static_cast<int>(vertices.size() / 3);
}