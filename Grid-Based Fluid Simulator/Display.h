#pragma once
#include "raylib.h"

class Display {
private:
	short int screenWidth, screenHeight;
	char framerate;
public:
	Display(short int getWidth, short int getHeight, char getFramerate);
	void initScreen();
	short int getWidth();
	short int getHeight();
	char getFramerate();
};