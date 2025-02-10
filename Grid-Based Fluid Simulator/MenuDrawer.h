#pragma once
#include "BrushType.h"

class MenuDrawer {
	short int menuWidth, menuHeight;
	unsigned char textField, selectedColor, brushSize, specialType;
	bool resetGrid, displayVelocities;
	Color colorArray[9];
	e_brushType* brushType;
public:
	MenuDrawer(short int getWidth, short int getHeight);
	void drawMenu();
};