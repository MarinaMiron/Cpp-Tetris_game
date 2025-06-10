#pragma once

#include <vector>
#include <raylib.h>

class Grid
{
private:
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;

public:
    int grid[20][10];
    Grid();
    void Initialize();
    void Print();
    std::vector<Color> GetCellColors();
    void Draw();
    ~Grid();
};