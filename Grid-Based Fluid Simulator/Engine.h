#pragma once
#include "Display.h"
#include "Grid.h"
#include <cmath>
#include <iostream>

class Engine {
    Display* display;
    Menu* menu;
    Grid* grid;
public:
    ~Engine();
    void setUpDisplay(short int getWidth, short int getHeight, char getFramerate);
    void setUpMenu(short int getWidth, short int getHeight);
    void setUpGrid(short int size);
    void drawScreen();
    Menu* getMenu();
    Grid* getGrid();
};

/*
typedef struct s_gridInfo {
    s_gridCell cellInfo[GRIDWIDTH * GRIDHEIGHT];
    char horizontalMov[(GRIDWIDTH - 1) * GRIDHEIGHT];
    char verticalMov[GRIDWIDTH * (GRIDHEIGHT - 1)];
}s_gridInfo;

void drawHorVelocity(char velocity, int x, int y);
void drawVerVelocity(char velocity, int x, int y);
void drawScene(s_gridInfo& readGrid, s_menuInfo readMenu);
void fillGrid(s_gridInfo& readGrid);
void paintScene(s_gridInfo& readGrid, s_paintInfo readPaint, int x, int y, int& prevX, int& prevY, s_drawHelper readDrawGrid[GRIDHEIGHT * GRIDWIDTH]);
*/