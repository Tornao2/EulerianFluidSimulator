#include "Grid.h"

Grid::Grid(short int size, short int sceneWidth, short int sceneHeight) {
	gridSize = size;
	gridWidth = sceneWidth / size;
	gridHeight = sceneHeight / size;
	gridData = new GridData[gridHeight* gridWidth];
	drawer = new Drawer(&gridSize, &gridWidth, &gridHeight);
	fillGridInfo();
}

Grid::~Grid() {
	delete[] gridData;
	delete drawer;
}

void Grid::fillGridInfo() {
	memset(gridData, 0, sizeof(*gridData)* gridHeight * gridWidth);
}

void Grid::drawCells() {
	for (int row = 0; row < gridHeight; row++)
		for (int col = 0; col < gridWidth; col++) 
			DrawRectangle(gridSize * col, gridSize * row, gridSize, gridSize, gridData[row * gridWidth + col].cellColor);
}

void Grid::clickScene(Menu* menu, int x, int y) {
	menu->setTextField(0);
	drawer->paint(gridData, *menu, x, y);
}

Drawer* Grid::getDrawer() {
	return drawer;
}