#pragma once
#include "raylib.h"
#include <cmath>

typedef enum BrushType {
	color,
	vel,
	colorAndVelocity
}BrushType;

bool operator==(Color x, Color y);
Color averageColors(Color x, Color y);
Color calculateAfterFade(Color x, int steps, int fadeStrength);