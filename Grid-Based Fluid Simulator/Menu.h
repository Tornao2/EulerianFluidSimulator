#pragma once
#include "BrushType.h"

constexpr int FONTSIZE = 36;
constexpr Color MENUCOLOR = { 225, 225, 225, 255 };
constexpr Color SELECTCOLOR = { 200, 230, 200, 255 };

class Menu {
	short int x, y, width, height;
	unsigned char textField, selectedColor, brushSize;
	bool resetGrid, displayVelocities;
	Color colorArray[9];
	BrushType brushType;
	void handleNumbers(int min, int max, unsigned char& number);
public:
	Menu(short int getX, short int getY, short int getWidth, short int getHeight);
	void drawMenu();
	bool getResetGrid();
	void setResetGrid(bool setReset);
	void checkKeyboard();
	unsigned char getTextField();
	void clickMenu(int readX, int readY);
	short int getWidth();
	short int getHeight();
	unsigned char getBrushSize();
	BrushType getBrush();
	void setTextField(unsigned char fieldNum);
};