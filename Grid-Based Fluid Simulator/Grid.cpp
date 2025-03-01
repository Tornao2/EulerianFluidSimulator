#include "Grid.h"

Grid::Grid(short int size, short int sceneWidth, short int sceneHeight, BrushType* brush) {
	gridSize = size;
	gridWidth = sceneWidth / size;
	gridHeight = sceneHeight / size;
	gridData = new GridData[gridHeight* gridWidth];
	drawer = new Drawer(brush);
	fillGridInfo();
}

Grid::~Grid() {
	delete[] gridData;
	delete drawer;
}

void Grid::fillGridInfo() {
	memset(gridData, 0, sizeof(unsigned char) * gridHeight * gridWidth);
}

void Grid::drawCells() {
	for (int row = 0; row < gridHeight; row++)
		for (int col = 0; col < gridWidth; col++) 
			DrawRectangle(gridSize * col, gridSize * row, gridSize, gridSize, {255, 255, 255, gridData[row*gridWidth+col].materialCount});
}

void Grid::paintCells(Menu menu) {
	drawer->paint(gridData, menu);
}