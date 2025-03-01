#include "Drawer.h"

Drawer::Drawer(BrushType* brush) {
	brushType = brush;
}

Drawer::~Drawer() {
	brushType = nullptr;
}

void Drawer::paint(GridData* gridData, Menu menu) {
	unsigned char alphaDelta = 255 / menu.getBrushSize();
}