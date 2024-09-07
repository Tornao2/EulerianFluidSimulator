#include "Draw.h"
#include <stdlib.h>

int main(void)
{
    gridCell* Grid = new gridCell[GRIDHEIGHT*GRIDWIDTH];
    paintInfo Paint;
    fillGrid(Grid);
    fillPaint(Paint);
    initScreen();
    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int x = GetMouseX();
            int y = GetMouseY();
            if (x > SCREENWIDTH - MENUWIDTH)
                clickMenu(Paint, x, y);
        }
        drawScreen(Grid, Paint);
    }
    delete[] Grid;
    CloseWindow();        
    return 0;
}