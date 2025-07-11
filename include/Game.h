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
    Sound rotateSound;
    Sound clearSound;
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();

public:
    bool gameOver;
    int score;
    Music music;
    Game();
    void Draw();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    void UpdateScore(int linesCleared, int moveDownPoints);
    ~Game();
};