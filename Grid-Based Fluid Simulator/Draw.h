#pragma once
#include "raylib.h"

constexpr int SCREENWIDTH = 1500;
constexpr int SCREENHEIGHT = 900;
constexpr int FRAMERATE = 60;
constexpr int GRIDCELLSIZE = 5;
constexpr int MENUWIDTH = 300;
constexpr int GRIDWIDTH = (SCREENWIDTH - MENUWIDTH) / GRIDCELLSIZE;
constexpr int GRIDHEIGHT = SCREENHEIGHT / GRIDCELLSIZE;
constexpr Color BACKGROUNDCOLOR = { 4, 4, 8, 255 };
constexpr Color MENUCOLOR = { 225, 225, 225, 255 };
constexpr int FONTSIZE = 36;

typedef struct gridCell {
    Color cellColor;
}gridCell;

typedef struct paintInfo {
    Color colorArray[9];
    int selectedColor;
}paintInfo;

void initScreen();
void drawScene(gridCell readGrid[GRIDHEIGHT*GRIDWIDTH]);
void drawMenu(paintInfo readPaint);
void drawScreen(gridCell readGrid[GRIDHEIGHT*GRIDWIDTH], paintInfo readPaint);
void fillGrid(gridCell readGrid[GRIDHEIGHT*GRIDWIDTH]);
void fillPaint(paintInfo& readPaint);
void clickMenu(paintInfo& readPaint, int x, int y);