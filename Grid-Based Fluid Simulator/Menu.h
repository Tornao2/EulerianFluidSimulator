#pragma once
#include "BrushType.h"

constexpr int FONTSIZE = 36;
constexpr Color MENUCOLOR = { 225, 225, 225, 255 };
constexpr Color SELECTCOLOR = { 200, 230, 200, 255 };

class Menu {
	short int x, y, width, height;
	unsigned char textField, selectedColor, brushSize, specialType;
	bool resetGrid, displayVelocities;
	Color colorArray[9];
	e_brushType* brushType;
public:
	Menu(short int getX, short int getY, short int getWidth, short int getHeight);
	void drawMenu();
};