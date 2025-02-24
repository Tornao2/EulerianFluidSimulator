#pragma once
#include "BrushType.h"

constexpr Color BACKGROUNDCOLOR = { 7, 7, 9, 255 };

class Grid {
	short int gridSize, gridWidth, gridHeight;
public:
	Grid(short int size, short int sceneWidth, short int sceneHeight);
};