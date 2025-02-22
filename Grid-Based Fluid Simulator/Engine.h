#pragma once
#include "Display.h"
#include "Menu.h"
#include <cmath>
#include <iostream>

class Engine {
    Display* display;
    Menu* menu;
public:
    Engine();
    void setUpDisplay(short int getWidth, short int getHeight, char getFramerate);
    void setUpMenu(short int getWidth, short int getHeight);
    void drawScreen();
    Menu* getMenu();
};

/*
constexpr int GRIDCELLSIZE = 60;
constexpr int GRIDWIDTH = (SCREENWIDTH - MENUWIDTH) / GRIDCELLSIZE;
constexpr int GRIDHEIGHT = SCREENHEIGHT / GRIDCELLSIZE;
constexpr Color BACKGROUNDCOLOR = { 7, 7, 9, 255 };

typedef struct s_gridCell {
    Color cellColor;
    unsigned short int density;
}s_gridCell;



typedef struct s_gridInfo {
    s_gridCell cellInfo[GRIDWIDTH * GRIDHEIGHT];
    char horizontalMov[(GRIDWIDTH - 1) * GRIDHEIGHT];
    char verticalMov[GRIDWIDTH * (GRIDHEIGHT - 1)];
}s_gridInfo;

typedef struct s_drawHelper {
    short int initX, initY;
    unsigned char status;
}s_drawHelper;

void drawHorVelocity(char velocity, int x, int y);
void drawVerVelocity(char velocity, int x, int y);
void drawScene(s_gridInfo& readGrid, s_menuInfo readMenu);
void fillGrid(s_gridInfo& readGrid);
void fillDrawGrid(s_drawHelper readDrawGrid[GRIDHEIGHT * GRIDWIDTH]);
void clickMenu(s_paintInfo& readPaint, int x, int y, s_menuInfo& readMenu);
void clickScene(s_gridInfo& readGrid, s_paintInfo readPaint, int x, int y, int& prevX, int& prevY, s_menuInfo& readMenu, s_drawHelper readDrawGrid[GRIDHEIGHT * GRIDWIDTH]);
void paintScene(s_gridInfo& readGrid, s_paintInfo readPaint, int x, int y, int& prevX, int& prevY, s_drawHelper readDrawGrid[GRIDHEIGHT * GRIDWIDTH]);
*/