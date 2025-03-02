#include "Drawer.h"

Drawer::Drawer(short int* gridSize, short int* gridWidth, short int* gridHeight) {
	pointerGridHeight = gridHeight;
	pointerGridSize = gridSize;
	pointerGridWidth = gridWidth;
}

void Drawer::paint(GridData* gridData, Menu menu, int x, int y) {
	unsigned char alphaDelta = 255 / menu.getBrushSize();
	if (menu.getBrush() == color || menu.getBrush() == colorAndVelocity) {
		gridData[y / (*pointerGridSize) * (*pointerGridWidth) + x / (*pointerGridSize)].materialCount = 255;
	}
}