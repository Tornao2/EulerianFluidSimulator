#pragma once
#include "raylib.h"
#include <math.h>
#include <iostream>
#include <time.h>

constexpr int SCREENWIDTH = 1500;
constexpr int SCREENHEIGHT = 900;
constexpr int FRAMERATE = 60;
constexpr int GRIDCELLSIZE = 60;
constexpr int MENUWIDTH = 300;
constexpr int GRIDWIDTH = (SCREENWIDTH - MENUWIDTH) / GRIDCELLSIZE;
constexpr int GRIDHEIGHT = SCREENHEIGHT / GRIDCELLSIZE;
constexpr Color BACKGROUNDCOLOR = { 7, 7, 9, 255 };
constexpr Color MENUCOLOR = { 225, 225, 225, 255 };
constexpr Color SELECTCOLOR = { 200, 230, 200, 255 };
constexpr int FONTSIZE = 36;

typedef struct gridCell {
    Color cellColor;
    unsigned char density;
    unsigned char moveVert;
    unsigned char moveHor;
    unsigned char angle;
}gridCell;

typedef struct paintInfo {
    Color colorArray[9];
    int selectedColor;
    unsigned char brushSize;
}paintInfo;

typedef struct menuInfo {
    int textField;
    bool resetGrid;
    bool displayAngles;
}menuInfo;

void initScreen();
void drawVelocity(gridCell readCell, int readRow, int readCol);
void drawScene(gridCell readGrid[GRIDHEIGHT*GRIDWIDTH], menuInfo readInfo);
void drawMenu(paintInfo readPaint, menuInfo readInfo);
void drawScreen(gridCell readGrid[GRIDHEIGHT*GRIDWIDTH], paintInfo readPaint, menuInfo readInfo);
void fillGrid(gridCell readGrid[GRIDHEIGHT*GRIDWIDTH]);
void fillPaint(paintInfo& readPaint);
void fillMenu(menuInfo& readInfo);
void clickMenu(paintInfo& readPaint, int x, int y, menuInfo& readInfo);
void clickScene(gridCell readGrid[GRIDHEIGHT * GRIDWIDTH], paintInfo readPaint, int x, int y, menuInfo& readInfo);
void paintScene(gridCell readGrid[GRIDHEIGHT * GRIDWIDTH], paintInfo readPaint, int x, int y);
void checkKeyboard(paintInfo& readPaint, menuInfo readInfo);
void handleNumbers(int min, int max, unsigned char& number);

bool operator==(Color x, Color y);