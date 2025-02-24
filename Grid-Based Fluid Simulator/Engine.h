#pragma once
#include "Display.h"
#include "Menu.h"
#include "Grid.h"
#include <cmath>
#include <iostream>

class Engine {
    Display* display;
    Menu* menu;
    Grid* grid;
public:
    void setUpDisplay(short int getWidth, short int getHeight, char getFramerate);
    void setUpMenu(short int getWidth, short int getHeight);
    void setUpGrid(short int size);
    void drawScreen();
    Menu* getMenu();
};

/*
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
void clickScene(s_gridInfo& readGrid, s_paintInfo readPaint, int x, int y, int& prevX, int& prevY, s_menuInfo& readMenu, s_drawHelper readDrawGrid[GRIDHEIGHT * GRIDWIDTH]);
void paintScene(s_gridInfo& readGrid, s_paintInfo readPaint, int x, int y, int& prevX, int& prevY, s_drawHelper readDrawGrid[GRIDHEIGHT * GRIDWIDTH]);
*/