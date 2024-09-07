#include "Draw.h"

void initScreen() {
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Fluid Simulator");
    SetTargetFPS(FRAMERATE);
}

void drawScene(gridCell readGrid[GRIDHEIGHT*GRIDWIDTH]) {
    for (int col = 0; col < GRIDHEIGHT; col++) 
        for (int row = 0; row < GRIDWIDTH; row++) 
            DrawRectangle(GRIDCELLSIZE * row, GRIDCELLSIZE * col, GRIDCELLSIZE, GRIDCELLSIZE, readGrid[col*GRIDHEIGHT + row].cellColor);
}

void drawMenu(paintInfo readPaint) {
    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 4; j++) 
            DrawRectangle(SCREENWIDTH - MENUWIDTH * (58 - 15 * j) / 64, (80 + i * 80), MENUWIDTH / 8, MENUWIDTH / 8, BLACK);
    for (int i = 0; i < 8; i++)
        DrawRectangle(SCREENWIDTH - MENUWIDTH * (58 - 15 * (i % 4)) / 64 + MENUWIDTH/48, 80 + i/4 * 80 + MENUWIDTH / 48, MENUWIDTH / 12, MENUWIDTH / 12, readPaint.colorArray[i+1]);
    DrawText("Colors", SCREENWIDTH - MENUWIDTH / 2 - MeasureText("Colors", FONTSIZE) / 2, 5, FONTSIZE, BLACK);
    DrawText("1", SCREENWIDTH - MENUWIDTH * 8 / 9 + MeasureText("1", FONTSIZE) / 2, 45, FONTSIZE, readPaint.selectedColor == 1 ? DARKGREEN : BLACK);
    DrawText("2", SCREENWIDTH - MENUWIDTH * 6 / 9 + MeasureText("2", FONTSIZE) / 2, 45, FONTSIZE, readPaint.selectedColor == 2 ? DARKGREEN : BLACK);
    DrawText("3", SCREENWIDTH - MENUWIDTH * 4 / 9 + MeasureText("3", FONTSIZE) / 2, 45, FONTSIZE, readPaint.selectedColor == 3 ? DARKGREEN : BLACK);
    DrawText("4", SCREENWIDTH - MENUWIDTH * 2 / 9 + MeasureText("4", FONTSIZE) / 2, 45, FONTSIZE, readPaint.selectedColor == 4 ? DARKGREEN : BLACK);
    DrawText("5", SCREENWIDTH - MENUWIDTH * 8 / 9 + MeasureText("5", FONTSIZE) / 2, 125, FONTSIZE, readPaint.selectedColor == 5 ? DARKGREEN : BLACK);
    DrawText("6", SCREENWIDTH - MENUWIDTH * 6 / 9 + MeasureText("6", FONTSIZE) / 2, 125, FONTSIZE, readPaint.selectedColor == 6 ? DARKGREEN : BLACK);
    DrawText("7", SCREENWIDTH - MENUWIDTH * 4 / 9 + MeasureText("7", FONTSIZE) / 2, 125, FONTSIZE, readPaint.selectedColor == 7 ? DARKGREEN : BLACK);
    DrawText("8", SCREENWIDTH - MENUWIDTH * 2 / 9 + MeasureText("8", FONTSIZE) / 2, 125, FONTSIZE, readPaint.selectedColor == 8 ? DARKGREEN : BLACK);
    DrawText("Obstruction", SCREENWIDTH - MENUWIDTH / 2 - MeasureText("Obstruction", FONTSIZE)/2, 205, FONTSIZE, readPaint.selectedColor == 0 ? DARKGREEN : BLACK);
    if (readPaint.selectedColor != 0) {
        for(int i = 0; i < 3; i++)
            DrawRectangle(SCREENWIDTH - MENUWIDTH *(15-i*5)/16, 250, MENUWIDTH / 4, 40, WHITE);
        DrawText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].r), SCREENWIDTH - MENUWIDTH * 13 / 16 - MeasureText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].r), FONTSIZE) / 2, 252, FONTSIZE, BLACK);
        DrawText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].g), SCREENWIDTH - MENUWIDTH / 2 - MeasureText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].g), FONTSIZE) / 2, 252, FONTSIZE, BLACK);
        DrawText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].b), SCREENWIDTH - MENUWIDTH * 3 / 16 - MeasureText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].b), FONTSIZE) / 2, 252, FONTSIZE, BLACK);
        DrawText("R", SCREENWIDTH - MENUWIDTH * 13 / 16 - MeasureText("R", FONTSIZE) / 2, 295, FONTSIZE, BLACK);
        DrawText("G", SCREENWIDTH - MENUWIDTH / 2 - MeasureText("G", FONTSIZE) / 2, 295, FONTSIZE, BLACK);
        DrawText("B", SCREENWIDTH - MENUWIDTH * 3 / 16 - MeasureText("B", FONTSIZE) / 2, 295, FONTSIZE, BLACK);
    }
}

void drawScreen(gridCell readGrid[GRIDHEIGHT*GRIDWIDTH], paintInfo readPaint) {
    BeginDrawing();
    ClearBackground(MENUCOLOR);
    drawScene(readGrid);
    drawMenu(readPaint);
    EndDrawing();
}

void fillGrid(gridCell readGrid[GRIDHEIGHT*GRIDWIDTH]) {
    for (int col = 0; col < GRIDHEIGHT; col++) 
        for (int row = 0; row < GRIDWIDTH; row++) 
            readGrid[col * GRIDHEIGHT + row].cellColor = BACKGROUNDCOLOR;
}

void fillPaint(paintInfo& readPaint) {
    readPaint.colorArray[0] = BLACK;
    for (int i = 1; i < 9; i++) 
        readPaint.colorArray[i] = WHITE;
    readPaint.selectedColor = 1;
}

void clickMenu(paintInfo& readPaint, int x, int y) {
    if (y > 45 && y < 125) {
        if (x < 1285)
            readPaint.selectedColor = 1;
        else if (x < 1350)
            readPaint.selectedColor = 2;
        else if (x < 1425)
            readPaint.selectedColor = 3;
        else 
            readPaint.selectedColor = 4;
    }
    else if (y >= 125 && y < 205) {
        if (x < 1285)
            readPaint.selectedColor = 5;
        else if (x < 1350)
            readPaint.selectedColor = 6;
        else if (x < 1425)
            readPaint.selectedColor = 7;
        else
            readPaint.selectedColor = 8;
    }
    else if (y >= 205 && y < 240) 
        readPaint.selectedColor = 0;
}