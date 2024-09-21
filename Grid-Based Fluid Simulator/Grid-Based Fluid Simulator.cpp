#include "Draw.h"

int main(void)
{
    srand(time(0));
    gridCell* Grid = new gridCell[GRIDHEIGHT*GRIDWIDTH];
    curGrid* drawGrid = NULL;
    paintInfo Paint;
    menuInfo Info;
    fillGrid(Grid);
    fillPaint(Paint);
    fillMenu(Info);
    initScreen();
    int x = 0, y = 0, prevX = -1, prevY = -1;
    while (!WindowShouldClose())
    {
        x = GetMouseX();
        if (x >= SCREENWIDTH) x = SCREENWIDTH - 1;
        if (x < 0) x = 0;
        y = GetMouseY();
        if (y >= SCREENHEIGHT) x = SCREENHEIGHT - 1;
        if (y < 0) y = 0;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && x < SCREENWIDTH - MENUWIDTH) {
            if (drawGrid == NULL) {
                drawGrid = new curGrid[GRIDHEIGHT * GRIDWIDTH];
                fillDrawGrid(drawGrid);
            }
            clickScene(Grid, Paint, x, y, prevX, prevY, Info, drawGrid);
        }
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && drawGrid != NULL) {
            delete[] drawGrid;
            drawGrid = NULL;
            prevX = prevY = -1;
        }
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && x > SCREENWIDTH - MENUWIDTH)
            clickMenu(Paint, x, y, Info);
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