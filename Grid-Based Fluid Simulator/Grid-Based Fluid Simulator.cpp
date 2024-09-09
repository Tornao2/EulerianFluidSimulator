#include "Draw.h"

int main(void)
{
    gridCell* Grid = new gridCell[GRIDHEIGHT*GRIDWIDTH];
    paintInfo Paint;
    menuInfo Info;
    fillGrid(Grid);
    fillPaint(Paint);
    fillMenu(Info);
    initScreen();
    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int x = GetMouseX();
            int y = GetMouseY();
            if (x > SCREENWIDTH - MENUWIDTH)
                clickMenu(Paint, x, y, Info);
            else 
                clickScene(Paint, x, y, Info);
        }
        if (Info.textField != 0)
            checkKeyboard(Paint, Info);
        if (Info.resetGrid) {
            fillGrid(Grid);
            Info.resetGrid = false;
        }
        drawScreen(Grid, Paint, Info);
    }
    delete[] Grid;
    CloseWindow();        
    return 0;
}