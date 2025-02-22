#include "Engine.h"

Engine::Engine() {
    display = nullptr;
    menu = nullptr;
}

void Engine::setUpDisplay(short int getWidth, short int getHeight, char getFramerate) {
    display = new Display(getWidth, getHeight, getFramerate);
    display->initScreen();
}

void Engine::setUpMenu(short int getWidth, short int getHeight) {
    menu = new Menu(display->getWidth() - getWidth, display->getHeight() - getHeight, getWidth, getHeight);
}

Menu* Engine::getMenu() {
    return menu;
}

void Engine::drawScreen() {
    BeginDrawing();
    ClearBackground(MENUCOLOR);
    //drawScene(readGrid, readMenu);
    menu->drawMenu();
    EndDrawing();
}

/*
void drawHorVelocity(char velocity, int x, int y) {
    DrawRectangle(GRIDCELLSIZE * (y + 1) - abs(velocity), GRIDCELLSIZE * x + GRIDCELLSIZE / 2 - 6, abs(velocity)*2, 12, {200, 80, 80, 255});
    DrawRectangle(GRIDCELLSIZE * (y + 1) - (velocity < 0 ? abs(velocity) : 0), GRIDCELLSIZE * x + GRIDCELLSIZE / 2 - 6, abs(velocity), 12, { 40, 130, 200, 255 });
}

void drawVerVelocity(char velocity, int x, int y) {
    DrawRectangle(GRIDCELLSIZE * y + GRIDCELLSIZE / 2 - 6, GRIDCELLSIZE * (x + 1) - abs(velocity), 12, abs(velocity) * 2, { 200, 80, 80, 255 });
    DrawRectangle(GRIDCELLSIZE * y + GRIDCELLSIZE / 2 - 6, GRIDCELLSIZE * (x + 1) - (velocity < 0 ? abs(velocity) : 0), 12, abs(velocity), { 40, 130, 200, 255 });
}

void drawScene(s_gridInfo& readGrid, s_menuInfo readMenu) {
    DrawRectangle(0, 0, SCREENWIDTH - MENUWIDTH, SCREENHEIGHT, BACKGROUNDCOLOR);
    for (unsigned short int row = 0; row < GRIDHEIGHT; row++)
        for (unsigned short int col = 0; col < GRIDWIDTH; col++) 
            DrawRectangle(GRIDCELLSIZE * col, GRIDCELLSIZE * row, GRIDCELLSIZE, GRIDCELLSIZE, { readGrid.cellInfo[row * GRIDWIDTH + col].cellColor.r, readGrid.cellInfo[row * GRIDWIDTH + col].cellColor.g, readGrid.cellInfo[row * GRIDWIDTH + col].cellColor.b, readGrid.cellInfo[row * GRIDWIDTH + col].density > 255 ? (unsigned char) 255 : (unsigned char) readGrid.cellInfo[row * GRIDWIDTH + col].density });               
    if (readMenu.displayVelocities) {
        for (unsigned short int row = 0; row < GRIDHEIGHT; row++)
            for (unsigned short int col = 0; col < GRIDWIDTH; col++) {
                if (col < GRIDWIDTH - 1)
                    drawHorVelocity(readGrid.horizontalMov[row * (GRIDWIDTH - 1) + col], row, col);
                if (row < GRIDHEIGHT - 1) 
                    drawVerVelocity(readGrid.verticalMov[row * GRIDWIDTH + col], row, col);                           
            }
    }
}   

void fillGrid(s_gridInfo& readGrid) {
    for (int row = 0; row < GRIDHEIGHT; row++)
        for (int col = 0; col < GRIDWIDTH; col++) {
            readGrid.cellInfo[row * GRIDWIDTH + col].cellColor = BACKGROUNDCOLOR;
            readGrid.cellInfo[row * GRIDWIDTH + col].density = 0;
        }
    for (int i = 0; i < GRIDHEIGHT-1; i++)
        for (int j = 0; j < GRIDWIDTH; j++)
            readGrid.verticalMov[j + i * GRIDWIDTH] = 0;
    for (int i = 0; i < GRIDWIDTH - 1; i++)
        for (int j = 0; j < GRIDHEIGHT; j++) 
            readGrid.horizontalMov[j + i * GRIDHEIGHT] = 0;
      
}

void fillDrawGrid(s_drawHelper readDrawGrid[GRIDHEIGHT * GRIDWIDTH]) {
    for (int row = 0; row < GRIDHEIGHT; row++)
        for (int col = 0; col < GRIDWIDTH; col++) {
            readDrawGrid[row * GRIDWIDTH + col].initX = readDrawGrid[row * GRIDWIDTH + col].initY = -1;
            readDrawGrid[row * GRIDWIDTH + col].status = 0;
        }
}

void clickMenu(s_paintInfo& readPaint, int x, int y, s_menuInfo& readMenu) {
    readMenu.textField = 0;
    if (y > 45 && y < 125) {
        if (x < 1285)
            readPaint.selectedColor = 1;
        else if (x < 1350)
            readPaint.selectedColor = 2;
        else if (x < 1425)
            readPaint.selectedColor = 3;
        else
            readPaint.selectedColor = 4;
    }
    else if (y >= 125 && y < 205) {
        if (x < 1285)
            readPaint.selectedColor = 5;
        else if (x < 1350)
            readPaint.selectedColor = 6;
        else if (x < 1425)
            readPaint.selectedColor = 7;
        else
            readPaint.selectedColor = 8;
    }
    else if (y >= 205 && y < 240)
        readPaint.selectedColor = 0;
    else if (y > 248 && y < 290) {
        if (x < 1295 && x > 1220)
            readMenu.textField = 1;
        else if (x < 1390 && x > 1312)
            readMenu.textField = 2;
        else if (x < 1484 && x > 1407)
            readMenu.textField = 3;
    }
    else if (y > 350 && y < 378)
        readMenu.resetGrid = true;
    else if (y < 418 && y > 384 && x > SCREENWIDTH - (MENUWIDTH / 4) && x < SCREENWIDTH - (MENUWIDTH * 1 / 8))
        readMenu.textField = 4;
    else if (y < 458 && y > 424 && x > SCREENWIDTH - (MENUWIDTH / 4) && x < SCREENWIDTH - (MENUWIDTH * 1 / 8)) 
        readMenu.displayVelocities = !readMenu.displayVelocities;
    else if (y > 508 && y < 535) {
        if (x > 1218 && x < 1285)
            readPaint.type = gens;
        else if (x > 1295 && x < 1408)
            readPaint.type = vel;
        else if (x > 1415 && x < 1488)
            readPaint.type = color;
        readPaint.specialType = 0;
    }
    else if (y > 538 && y < 565) {
        readPaint.type = colorAndVelocity;
        readPaint.specialType = 0;
    }
    else if (y > 570 && y < 610 && readPaint.type == gens) {
        for (int i = 0; i < 4; i++)
            if (x > 1230 + i * 70 && x < 1270 + i * 70) {
                readPaint.specialType = i + 1;
                break;
            }
    }
}

void clickScene(s_gridInfo& readGrid, s_paintInfo readPaint, int x, int y, int& prevX, int& prevY, s_menuInfo& readMenu, s_drawHelper readDrawGrid[GRIDHEIGHT * GRIDWIDTH]) {
    readMenu.textField = 0;
    if(readPaint.brushSize != 0) paintScene(readGrid, readPaint, x, y, prevX, prevY, readDrawGrid);
}

void paintScene(s_gridInfo& readGrid, s_paintInfo readPaint, int x, int y, int& prevX, int& prevY, s_drawHelper readDrawGrid[GRIDHEIGHT * GRIDWIDTH]) {
    unsigned char alphaDelta = 255 / ((readPaint.brushSize + 1) / 2 + 1);
    if (readDrawGrid[y / GRIDCELLSIZE * GRIDWIDTH + x/ GRIDCELLSIZE].status == 0) {
        if (prevX != -1)
            readDrawGrid[prevY * GRIDWIDTH + prevX].status = 3;
        readDrawGrid[y / GRIDCELLSIZE * GRIDWIDTH + x / GRIDCELLSIZE].status = 1;
        readDrawGrid[y / GRIDCELLSIZE * GRIDWIDTH + x / GRIDCELLSIZE].initX = x;
        readDrawGrid[y / GRIDCELLSIZE * GRIDWIDTH + x / GRIDCELLSIZE].initY = y;
    }
    if (readDrawGrid[y / GRIDCELLSIZE * GRIDWIDTH + x / GRIDCELLSIZE].status == 1 && (readPaint.type == color || readPaint.type == colorAndVelocity))
        for(int i = -readPaint.brushSize/2; i <= (readPaint.brushSize-1)/2; i++){
            for (int j = -(readPaint.brushSize / 2 - abs(i)); j <= ((readPaint.brushSize - 1) / 2 - abs(i)); j++) {
                if (y / GRIDCELLSIZE + i >= 0 && y / GRIDCELLSIZE + i < GRIDHEIGHT && x / GRIDCELLSIZE + j >= 0 && x / GRIDCELLSIZE + j < GRIDWIDTH)
                {
                    readGrid.cellInfo[(y / GRIDCELLSIZE + i) * GRIDWIDTH + x / GRIDCELLSIZE + j].cellColor = readPaint.colorArray[readPaint.selectedColor];
                    readGrid.cellInfo[(y / GRIDCELLSIZE + i) * GRIDWIDTH + x / GRIDCELLSIZE + j].density = 255 - (abs(i) + abs(j)) * alphaDelta;
                    readDrawGrid[y / GRIDCELLSIZE * GRIDWIDTH + x / GRIDCELLSIZE].status = 2;   
                }
            }
        }
    if ((readPaint.type == vel || readPaint.type == colorAndVelocity)&&readDrawGrid[prevY*GRIDWIDTH + prevX].status == 3)
    {     
        for (int i = -readPaint.brushSize / 2; i <= (readPaint.brushSize - 1) / 2; i++) {
            for (int j = -(readPaint.brushSize / 2 - abs(i)); j <= ((readPaint.brushSize - 1) / 2 - abs(i)); j++) {
                if (prevY + i >= 0 && prevY + i < GRIDHEIGHT && prevX + j >= 0 && prevX + j < GRIDWIDTH)
                {
                    readDrawGrid[(prevY + i) * GRIDWIDTH + (prevX + j)].status = 4;
                    if ((prevY + i) * (GRIDWIDTH - 1) + (prevX + j) < 280) readGrid.verticalMov[(prevY + i) * (GRIDWIDTH-1)+(prevX + j)] = (y - readDrawGrid[prevY * GRIDWIDTH + prevX].initY) / 3;
                    readGrid.horizontalMov[(prevY + i) * (GRIDWIDTH - 1) + (prevX + j)] = (x - readDrawGrid[prevY * GRIDWIDTH + prevX].initX) / 3;
                }
            }
        }
    }
    prevX = x / GRIDCELLSIZE;
    prevY = y / GRIDCELLSIZE;
}
*/