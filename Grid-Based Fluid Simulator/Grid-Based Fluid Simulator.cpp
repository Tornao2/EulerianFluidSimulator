#include "Draw.h"

int main(void)
{
    initScreen();
    srand((unsigned int) time(0));
    s_gridInfo gridInfo;
    s_drawHelper* drawGrid = NULL;
    s_paintInfo paintInfo;
    s_menuInfo menuInfo;
    fillGrid(gridInfo);
    fillPaint(paintInfo);
    fillMenu(menuInfo);
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
                drawGrid = new s_drawHelper[GRIDHEIGHT * GRIDWIDTH];
                fillDrawGrid(drawGrid);
            }
            clickScene(gridInfo, paintInfo, x, y, prevX, prevY, menuInfo, drawGrid);
        }
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && drawGrid != NULL) {
            delete[] drawGrid;
            drawGrid = NULL;
            prevX = prevY = -1;
        }
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && x > SCREENWIDTH - MENUWIDTH)
            clickMenu(paintInfo, x, y, menuInfo);
        if (menuInfo.textField != 0)
            checkKeyboard(paintInfo, menuInfo);
        if (menuInfo.resetGrid) {
            fillGrid(gridInfo);
            menuInfo.resetGrid = false;
        }
        drawScreen(gridInfo, paintInfo, menuInfo);
    }
    CloseWindow();        
    return 0;
}
