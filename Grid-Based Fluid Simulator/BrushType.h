#pragma once
#include "raylib.h"

typedef enum BrushType {
	color,
	vel,
	colorAndVelocity
}BrushType;

bool operator==(Color x, Color y);