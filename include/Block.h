#pragma once

#include <vector>
#include <map>
#include "Position.h"
#include "Colors.h"

class Block
{
private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
public:
    int id;
    std::map<int, std::vector<Position>> cells;
    Block();
    void Draw();
    void Move(int rows, int column);
    std::vector<Position> GetCellPositions();
    ~Block();
};