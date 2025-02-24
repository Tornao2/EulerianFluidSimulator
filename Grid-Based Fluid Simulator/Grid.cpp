#include "Grid.h"

Grid::Grid(short int size, short int sceneWidth, short int sceneHeight) {
	gridSize = size;
	gridWidth = sceneWidth / size;
	gridHeight = sceneHeight / size;
}