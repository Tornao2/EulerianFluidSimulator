#pragma once
#include "Drawer.h"
#include <memory>

class Grid {
	short int gridSize, gridWidth, gridHeight;
	GridData* gridData;
	Drawer* drawer;
public:
	Grid(short int size, short int sceneWidth, short int sceneHeight);
	void fillGridInfo();
	void drawCells();
	void clickScene(Menu* menu, int x, int y);
	~Grid();
};