#pragma once
#include "Display.h"
#include "Grid.h"
#include <cmath>
#include <iostream>

constexpr Color BACKGROUNDCOLOR = { 5, 5, 5, 255 };

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
void drawHorVelocity(char velocity, int x, int y);
void drawVerVelocity(char velocity, int x, int y);
void drawScene(s_gridInfo& readGrid, s_menuInfo readMenu);
void fillGrid(s_gridInfo& readGrid);
void paintScene(s_gridInfo& readGrid, s_paintInfo readPaint, int x, int y, int& prevX, int& prevY, s_drawHelper readDrawGrid[GRIDHEIGHT * GRIDWIDTH]);
*/