#include "FloodFill.h"

#include <queue>


static bool isFilled(
    int x,
    int y,
    int z,
    const std::vector<FloodFillCell>& filledCells)
{
    for (const FloodFillCell& cell : filledCells)
    {
        if (cell.x == x &&
            cell.y == y &&
            cell.z == z)
        {
            return true;
        }
    }

    return false;
}


static bool isVisited(
    int x,
    int y,
    int z,
    const std::vector<FloodFillCell>& visited)
{
    for (const FloodFillCell& cell : visited)
    {
        if (cell.x == x &&
            cell.y == y &&
            cell.z == z)
        {
            return true;
        }
    }

    return false;
}


std::vector<FloodFillCell> FloodFill::fill(
    int startX,
    int startY,
    int startZ,
    int gridSize,
    const std::vector<FloodFillCell>& filledCells)
{
    std::vector<FloodFillCell> result;
    std::vector<FloodFillCell> visited;

    std::queue<FloodFillCell> queue;

    // Do not start flood fill from an already-filled cell.
    if (isFilled(
        startX,
        startY,
        startZ,
        filledCells))
    {
        return result;
    }

    FloodFillCell start =
    {
        startX,
        startY,
        startZ
    };

    queue.push(start);
    visited.push_back(start);

    // Six directions:
    // +X, -X, +Y, -Y, +Z, -Z

    const int directions[6][3] =
    {
        { 1,  0,  0 },
        {-1,  0,  0 },
        { 0,  1,  0 },
        { 0, -1,  0 },
        { 0,  0,  1 },
        { 0,  0, -1 }
    };

    while (!queue.empty())
    {
        FloodFillCell current =
            queue.front();

        queue.pop();

        // Fill this cell.
        result.push_back(current);

        // Check all six neighbors.
        for (int i = 0; i < 6; ++i)
        {
            int nextX =
                current.x + directions[i][0];

            int nextY =
                current.y + directions[i][1];

            int nextZ =
                current.z + directions[i][2];

            // Boundary check.
            if (nextX < 0 ||
                nextX >= gridSize ||
                nextY < 0 ||
                nextY >= gridSize ||
                nextZ < 0 ||
                nextZ >= gridSize)
            {
                continue;
            }

            // Do not cross already-filled cells.
            if (isFilled(
                nextX,
                nextY,
                nextZ,
                filledCells))
            {
                continue;
            }

            // Do not process the same cell twice.
            if (isVisited(
                nextX,
                nextY,
                nextZ,
                visited))
            {
                continue;
            }

            FloodFillCell next =
            {
                nextX,
                nextY,
                nextZ
            };

            visited.push_back(next);
            queue.push(next);
        }
    }

    return result;
}