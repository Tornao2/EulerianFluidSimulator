#include "Drawer.h"
#include <xstring>

Drawer::Drawer(short int* gridSize, short int* gridWidth, short int* gridHeight) {
	pointerGridHeight = gridHeight;
	pointerGridSize = gridSize;
	pointerGridWidth = gridWidth;
}

void Drawer::paint(GridData* gridData, Menu menu, int x, int y) {
	if (menu.getBrushSize() != 0) {
		unsigned char alphaDelta = 255 / menu.getBrushSize();
		if (menu.getBrush() == color || menu.getBrush() == colorAndVelocity) {
			int cellHeight = y / (*pointerGridSize);
			int cellWidth = x / (*pointerGridSize);
			for (int i = -(menu.getBrushSize()-1); i < menu.getBrushSize(); i++) {
				for (int j = -(menu.getBrushSize()-1); j < menu.getBrushSize(); j++) {
					if (cellHeight + i < *pointerGridHeight && cellHeight + i > 0 && cellWidth + j < *pointerGridWidth && cellWidth + j > 0 && abs(i) + abs(j) < menu.getBrushSize()) {
						gridData[(cellHeight+i) * (*pointerGridWidth) + cellWidth +j].materialCount = 255;
					}
				}
			}
		}
	}
}