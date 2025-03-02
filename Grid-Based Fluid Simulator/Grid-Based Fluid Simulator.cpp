#include "Engine.h"

constexpr int MENUWIDTH = 300;
constexpr int MENUHEIGHT = 900;
constexpr int SCREENWIDTH = 1500;
constexpr int SCREENHEIGHT = 900;
constexpr int FRAMERATE = 60;
constexpr int GRIDCELLSIZE = 60;

int main(void)
{
    Engine engine;
    engine.setUpDisplay(SCREENWIDTH, SCREENHEIGHT, FRAMERATE);
    engine.setUpMenu(MENUWIDTH, MENUHEIGHT);
    engine.setUpGrid(GRIDCELLSIZE);
    int x = 0, y = 0;
    while (!WindowShouldClose())
    { 
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            x = GetMouseX();
            y = GetMouseY();
            if (x >= SCREENWIDTH) x = SCREENWIDTH - 1;
            else if (x < 0) x = 0;
            if (y >= SCREENHEIGHT) x = SCREENHEIGHT - 1;
            else if (y < 0) y = 0;
            if (x < SCREENWIDTH - MENUWIDTH) 
                engine.getGrid()->clickScene(engine.getMenu(), x, y);
            else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                engine.getMenu()->clickMenu(x, y);
                if (engine.getMenu()->getResetGrid()) {
                    engine.getGrid()->fillGridInfo();
                    engine.getMenu()->setResetGrid(false);
                }
            }
        }    
        if (engine.getMenu()->getTextField() != 0)
            engine.getMenu()->checkKeyboard();   
        engine.drawScreen();
    }
    CloseWindow();        
    return 0;
}
