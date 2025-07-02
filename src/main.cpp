#include <raylib.h>
#include "../include/Game.h"
#include "../include/Colors.h"
#include <iostream>

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
    constexpr int screenWidth = 500;
    constexpr int screenHeight = 620;
    
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    
    InitWindow(screenWidth, screenHeight, "TETRIS");
    SetTargetFPS(60);

    Game game = Game();
    
    while(!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if (EventTriggered(0.2)) // Move block down every 0.2 seconds
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {360, 15}, 38, 2, WHITE);
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
        char score[10];
        sprintf(score, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, score, 38, 2);
        DrawTextEx(font, score, {320 + (150 - textSize.x) / 2, 65}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        if(game.gameOver)
        {
            DrawTextEx(font, "GAME", {355, 450}, 38, 2, WHITE);  
            DrawTextEx(font, "OVER", {355, 480}, 38, 2, WHITE);  
        }
        
        game.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}