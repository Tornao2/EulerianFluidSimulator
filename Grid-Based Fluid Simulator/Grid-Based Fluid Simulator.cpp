#include "Draw.h"

int main(void)
{
    srand(time(0));
    gridCell* Grid = new gridCell[GRIDHEIGHT*GRIDWIDTH];
    paintInfo Paint;
    menuInfo Info;
    fillGrid(Grid);
    fillPaint(Paint);
    fillMenu(Info);
    initScreen();
    while (!WindowShouldClose())
    {
        int x = GetMouseX();
        int y = GetMouseY();
        int prevX;
        int prevY;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && x < SCREENWIDTH - MENUWIDTH) 
            clickScene(Grid, Paint, x, y, prevX, prevY, Info);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && x > SCREENWIDTH - MENUWIDTH)
            clickMenu(Paint, x, y, Info);
        if (Info.textField != 0)
            checkKeyboard(Paint, Info);
        if (Info.resetGrid) {
            fillGrid(Grid);
            Info.resetGrid = false;
        }
        drawScreen(Grid, Paint, Info);
        prevX = x;
        prevY = y;
    }
    delete[] Grid;
    CloseWindow();        
    return 0;
}