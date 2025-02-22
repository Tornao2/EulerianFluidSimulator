#include "Engine.h"

constexpr int MENUWIDTH = 300;
constexpr int MENUHEIGHT = 900;
constexpr int SCREENWIDTH = 1500;
constexpr int SCREENHEIGHT = 900;
constexpr int FRAMERATE = 60;

int main(void)
{
    Engine engine;
    engine.setUpDisplay(SCREENWIDTH, SCREENHEIGHT, FRAMERATE);
    engine.setUpMenu(MENUWIDTH, MENUHEIGHT);
    //s_gridInfo gridInfo;
    //s_drawHelper* drawGrid = NULL;
    //fillGrid(gridInfo);
    int x = 0, y = 0, prevX = -1, prevY = -1;
    while (!WindowShouldClose())
    {
        x = GetMouseX();
        if (x >= SCREENWIDTH) x = SCREENWIDTH - 1;
        if (x < 0) x = 0;
        y = GetMouseY();
        if (y >= SCREENHEIGHT) x = SCREENHEIGHT - 1;
        if (y < 0) y = 0;
        /*
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && x < SCREENWIDTH - MENUWIDTH) {
            //if (drawGrid == NULL) {
            //    drawGrid = new s_drawHelper[GRIDHEIGHT * GRIDWIDTH];
            //    fillDrawGrid(drawGrid);
            //}
            //clickScene(gridInfo, paintInfo, x, y, prevX, prevY, menuInfo, drawGrid);
        }
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && drawGrid != NULL) {
            //delete[] drawGrid;
            //drawGrid = NULL;
            //prevX = prevY = -1;
        }
        //if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && x > SCREENWIDTH - MENUWIDTH)
            //clickMenu(paintInfo, x, y, menuInfo);
            */
        if (engine.getMenu()->getTextField() != 0)
            engine.getMenu()->checkKeyboard();
        if (engine.getMenu()->getResetGrid()) {
            //fillGrid(gridInfo);
            engine.getMenu()->setResetGrid(false);
        }
        engine.drawScreen();
    }
    CloseWindow();        
    return 0;
}
