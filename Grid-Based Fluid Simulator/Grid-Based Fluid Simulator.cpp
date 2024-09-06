#include "raylib.h"

constexpr int SCREENWIDTH = 1600;
constexpr int SCREENHEIGHT = 900;
constexpr int FRAMERATE = 60;
constexpr int gridCellSize = 5;

Color colorArray[9];

typedef struct gridCell {
    Color cellColor;
}gridCell;

gridCell Grid[SCREENHEIGHT / gridCellSize][SCREENWIDTH / gridCellSize];

void initScreen() {
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Fluid Simulator");
    SetTargetFPS(FRAMERATE);
}

void drawScreen() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    for (int col = 0; col < SCREENHEIGHT / gridCellSize; col++) {
        for (int row = 0; row < SCREENWIDTH / gridCellSize; row++) {
            DrawRectangle(gridCellSize * row, gridCellSize * col, gridCellSize, gridCellSize, Grid[col][row].cellColor);
        }
    }
    EndDrawing();
}

int main(void)
{
    colorArray[0] = BLACK;
    for (int col = 0; col < SCREENHEIGHT / gridCellSize; col++) {
        for (int row = 0; row < SCREENWIDTH / gridCellSize; row++) {
            Grid[col][row].cellColor = BLACK;
        }
    }
    initScreen();
    while (!WindowShouldClose())
    {
        drawScreen();
    }
    CloseWindow();        
    return 0;
}