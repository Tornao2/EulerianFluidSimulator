#pragma once
#include "Drawer.h"
#include <memory>

class Grid {
	short int gridSize, gridWidth, gridHeight;
	GridData* gridData;
	Drawer* drawer;
public:
	Grid(short int size, short int sceneWidth, short int sceneHeight, BrushType* brush);
	void fillGridInfo();
	void drawCells();
	void paintCells(Menu menu);
	~Grid();
};