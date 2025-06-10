#include <raylib.h>
#include "../include/Grid.h"

int main() 
{
    const Color darkBlue = {44, 44, 127, 255};
    
    constexpr int screenWidth = 300;
    constexpr int screenHeight = 600;
    
    
    InitWindow(screenWidth, screenHeight, "TETRIS");
    SetTargetFPS(60);

    Grid grid = Grid();
    
    //grid.Print();
    
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}