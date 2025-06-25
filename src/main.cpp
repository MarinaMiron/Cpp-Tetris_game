#include <raylib.h>
#include "../include/Game.h"

int main() 
{
    const Color darkBlue = {44, 44, 127, 255};
    
    constexpr int screenWidth = 300;
    constexpr int screenHeight = 600;
    
    
    InitWindow(screenWidth, screenHeight, "TETRIS");
    SetTargetFPS(60);

    Game game = Game();
    
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}