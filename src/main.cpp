#include <raylib.h>
#include "../include/Game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

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
        game.HandleInput();
        if (EventTriggered(0.2)) // Move block down every 0.2 seconds
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}