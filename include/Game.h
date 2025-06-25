#pragma once

#include "Grid.h"
#include "../src/Blocks.cpp"
class Game
{
private:
    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
public:
    Game(/* args */);
    void Draw();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    ~Game();
};