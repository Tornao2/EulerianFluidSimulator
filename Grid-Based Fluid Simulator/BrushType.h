#pragma once
#include "raylib.h"

typedef enum e_brushType {
	color,
	vel,
	colorAndVelocity
}e_brushType;

bool operator==(Color x, Color y);