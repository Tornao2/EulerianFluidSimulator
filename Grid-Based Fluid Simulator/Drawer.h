#pragma once
#include "Menu.h"

typedef struct GridData {
	unsigned char materialCount;
}GridData;

class Drawer {
	short int* pointerGridSize, * pointerGridWidth, * pointerGridHeight;
public:
	Drawer(short int* gridSize, short int* gridWidth, short int* gridHeight);
	void paint(GridData* gridData, Menu menu, int x, int y);
};