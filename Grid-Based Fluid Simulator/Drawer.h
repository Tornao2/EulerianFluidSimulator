#pragma once
#include "Menu.h"

typedef struct GridData {
	unsigned char materialCount;
}GridData;

class Drawer {
	BrushType* brushType;
public:
	Drawer(BrushType* brush);
	~Drawer();
	void paint(GridData* gridData, Menu menu);
};