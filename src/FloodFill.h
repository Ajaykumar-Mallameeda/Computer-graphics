#pragma once

#include <vector>

struct FloodFillCell
{
    int x;
    int y;
    int z;
};

class FloodFill
{
public:
    static std::vector<FloodFillCell> fill(
        int startX,
        int startY,
        int startZ,
        int gridSize,
        const std::vector<FloodFillCell>& filledCells
    );
};