#pragma once
#include "raylib.h"

typedef enum e_brushType {
	color,
	vel,
	gens,
	colorAndVelocity
}e_brushType;

bool operator==(Color x, Color y);