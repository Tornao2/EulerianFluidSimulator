#include "Draw.h"

void initScreen() {
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Fluid Simulator");
    SetTargetFPS(FRAMERATE);
}

void drawAngles(s_gridCell readCell, int readRow, int readCol) {
    DrawRectanglePro({ (float)GRIDCELLSIZE * readCol + GRIDCELLSIZE / 2, (float)GRIDCELLSIZE * readRow + GRIDCELLSIZE / 2, GRIDCELLSIZE * 3 / 4, GRIDCELLSIZE / 2 }, { GRIDCELLSIZE * 3 / 8, GRIDCELLSIZE / 4 }, readCell.angle, { 200, 80, 80, 255 });
    DrawRectanglePro({ (float)GRIDCELLSIZE * readCol + GRIDCELLSIZE / 2, (float)GRIDCELLSIZE * readRow + GRIDCELLSIZE / 2, GRIDCELLSIZE * 3 / 8, GRIDCELLSIZE / 2 }, { GRIDCELLSIZE * 3 / 8, GRIDCELLSIZE / 4 }, readCell.angle, { 40, 130, 200, 255 });
}

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
        for (unsigned short int col = 0; col < GRIDWIDTH; col++) {
            DrawRectangle(GRIDCELLSIZE * col, GRIDCELLSIZE * row, GRIDCELLSIZE, GRIDCELLSIZE, { readGrid.cellInfo[row * GRIDWIDTH + col].cellColor.r, readGrid.cellInfo[row * GRIDWIDTH + col].cellColor.g, readGrid.cellInfo[row * GRIDWIDTH + col].cellColor.b, readGrid.cellInfo[row * GRIDWIDTH + col].density > 255 ? (unsigned char) 255 : (unsigned char) readGrid.cellInfo[row * GRIDWIDTH + col].density });         
            if (readMenu.displayAngles && !(readGrid.cellInfo[row * GRIDWIDTH + col].cellColor == BLACK) && readGrid.cellInfo[row * GRIDWIDTH + col].angle != 360) drawAngles(readGrid.cellInfo[row * GRIDWIDTH + col], row, col);               
        }
    if (readMenu.displayVelocities) {
        for (unsigned short int row = 0; row < GRIDHEIGHT; row++)
            for (unsigned short int col = 0; col < GRIDWIDTH; col++) {
                if (col < GRIDWIDTH - 1)
                    drawHorVelocity(readGrid.horizontalMov[row * (GRIDWIDTH - 1) + col], row, col);
                if (row < GRIDHEIGHT - 1)
                    drawVerVelocity(readGrid.verticalMov[row * (GRIDWIDTH - 1) + col], row, col);
            }
    }
}

void drawMenu(s_paintInfo readPaint, s_menuInfo readMenu) {
    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 4; j++) 
            DrawRectangle(SCREENWIDTH - MENUWIDTH * (58 - 15 * j) / 64, (80 + i * 80), MENUWIDTH / 8, MENUWIDTH / 8, BLACK);
    for (int i = 0; i < 8; i++)
        DrawRectangle(SCREENWIDTH - MENUWIDTH * (58 - 15 * (i % 4)) / 64 + MENUWIDTH/48, 80 + i/4 * 80 + MENUWIDTH / 48, MENUWIDTH / 12, MENUWIDTH / 12, readPaint.colorArray[i+1]);
    DrawText("Colors", SCREENWIDTH - MENUWIDTH / 2 - MeasureText("Colors", FONTSIZE) / 2, 5, FONTSIZE, BLACK);
    DrawText("1", SCREENWIDTH - MENUWIDTH * 8 / 9 + MeasureText("1", FONTSIZE) / 2, 45, FONTSIZE, readPaint.selectedColor == 1 ? DARKGREEN : BLACK);
    DrawText("2", SCREENWIDTH - MENUWIDTH * 6 / 9 + MeasureText("2", FONTSIZE) / 2, 45, FONTSIZE, readPaint.selectedColor == 2 ? DARKGREEN : BLACK);
    DrawText("3", SCREENWIDTH - MENUWIDTH * 4 / 9 + MeasureText("3", FONTSIZE) / 2, 45, FONTSIZE, readPaint.selectedColor == 3 ? DARKGREEN : BLACK);
    DrawText("4", SCREENWIDTH - MENUWIDTH * 2 / 9 + MeasureText("4", FONTSIZE) / 2, 45, FONTSIZE, readPaint.selectedColor == 4 ? DARKGREEN : BLACK);
    DrawText("5", SCREENWIDTH - MENUWIDTH * 8 / 9 + MeasureText("5", FONTSIZE) / 2, 125, FONTSIZE, readPaint.selectedColor == 5 ? DARKGREEN : BLACK);
    DrawText("6", SCREENWIDTH - MENUWIDTH * 6 / 9 + MeasureText("6", FONTSIZE) / 2, 125, FONTSIZE, readPaint.selectedColor == 6 ? DARKGREEN : BLACK);
    DrawText("7", SCREENWIDTH - MENUWIDTH * 4 / 9 + MeasureText("7", FONTSIZE) / 2, 125, FONTSIZE, readPaint.selectedColor == 7 ? DARKGREEN : BLACK);
    DrawText("8", SCREENWIDTH - MENUWIDTH * 2 / 9 + MeasureText("8", FONTSIZE) / 2, 125, FONTSIZE, readPaint.selectedColor == 8 ? DARKGREEN : BLACK);
    DrawText("Obstruction", SCREENWIDTH - MENUWIDTH / 2 - MeasureText("Obstruction", FONTSIZE)/2, 205, FONTSIZE, readPaint.selectedColor == 0 ? DARKGREEN : BLACK);
    if (readPaint.selectedColor != 0) {
        for(int i = 0; i < 3; i++)
            DrawRectangle(SCREENWIDTH - MENUWIDTH * (15 - i * 5) / 16, 250, MENUWIDTH / 4, 40, (readMenu.textField - 1) == i ? SELECTCOLOR : WHITE);
        DrawText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].r), SCREENWIDTH - MENUWIDTH * 13 / 16 - MeasureText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].r), FONTSIZE) / 2, 252, FONTSIZE, BLACK);
        DrawText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].g), SCREENWIDTH - MENUWIDTH / 2 - MeasureText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].g), FONTSIZE) / 2, 252, FONTSIZE, BLACK);
        DrawText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].b), SCREENWIDTH - MENUWIDTH * 3 / 16 - MeasureText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].b), FONTSIZE) / 2, 252, FONTSIZE, BLACK);
        DrawText("R", SCREENWIDTH - MENUWIDTH * 13 / 16 - MeasureText("R", FONTSIZE) / 2, 295, FONTSIZE, BLACK);
        DrawText("G", SCREENWIDTH - MENUWIDTH / 2 - MeasureText("G", FONTSIZE) / 2, 295, FONTSIZE, BLACK);
        DrawText("B", SCREENWIDTH - MENUWIDTH * 3 / 16 - MeasureText("B", FONTSIZE) / 2, 295, FONTSIZE, BLACK);
    }
    DrawText("Reset scene", SCREENWIDTH - MENUWIDTH / 2 - MeasureText("Reset scene", FONTSIZE) / 2, 340, FONTSIZE, RED);
    DrawText("Brush size:", SCREENWIDTH - MENUWIDTH * 19 / 20, 385, FONTSIZE * 3 / 4, BLACK);
    DrawRectangle(SCREENWIDTH - MENUWIDTH / 4, 384, MENUWIDTH / 8, MENUWIDTH / 10, readMenu.textField == 4 ? SELECTCOLOR : WHITE);
    DrawText(TextFormat("%i", readPaint.brushSize), SCREENWIDTH - MENUWIDTH * 3 / 16 - MeasureText(TextFormat("%i", readPaint.brushSize), FONTSIZE*3/4) / 2, 386, FONTSIZE*3/4, BLACK);
    DrawText("Toggle angles:", SCREENWIDTH - MENUWIDTH * 19/20, 426, FONTSIZE*3/4, BLACK);
    DrawRectangle(SCREENWIDTH - MENUWIDTH / 4, 424, MENUWIDTH / 8, MENUWIDTH / 10, readMenu.displayAngles ? GREEN : RED);
    DrawText("Toggle velocity:", SCREENWIDTH - MENUWIDTH * 19 / 20, 466, FONTSIZE * 3 / 4, BLACK);
    DrawRectangle(SCREENWIDTH - MENUWIDTH / 4, 464, MENUWIDTH / 8, MENUWIDTH / 10, readMenu.displayVelocities ? GREEN : RED);
    DrawText("Brush mode:", SCREENWIDTH - MENUWIDTH/2 - (MeasureText("Brush mode", FONTSIZE))/2, 508, FONTSIZE, BLACK);
    DrawText("Color", SCREENWIDTH - MENUWIDTH * 1 / 6 - (MeasureText("Color", FONTSIZE*3/4)) / 2, 548, FONTSIZE*3/4, readPaint.type == color ? DARKGREEN : BLACK);
    DrawText("Angle", SCREENWIDTH - MENUWIDTH * 3 / 6 - (MeasureText("Angle", FONTSIZE * 3 / 4)) / 2, 548, FONTSIZE * 3 / 4, readPaint.type == angle ? DARKGREEN : BLACK);
    DrawText("Gens", SCREENWIDTH - MENUWIDTH * 5 / 6 - (MeasureText("Gens", FONTSIZE * 3 / 4)) / 2, 548, FONTSIZE * 3 / 4, readPaint.type == gens ? DARKGREEN : BLACK);
    DrawText("Color + Angle", SCREENWIDTH - MENUWIDTH /2  - (MeasureText("Color + Angle", FONTSIZE * 3 / 4)) / 2, 578, FONTSIZE * 3 / 4, readPaint.type == colorAndAngle ? DARKGREEN : BLACK);
    if (readPaint.type == gens)
        for (int i = 0; i < 4; i++) {
            DrawRectangle(1230 + i * 70, 610, 40, 40, readPaint.specialType == i + 1 ? SELECTCOLOR : WHITE);
            DrawRectanglePro({ (float) 1250 + i * 70, (float) 630, 26, 16 }, { 13, 8 }, (float)i * 90, BLACK);
            DrawRectanglePro({ (float)1250 + i * 70, (float)630, 13, 16 }, { 13, 8 }, (float)i * 90, BLUE);
        }
}

void drawScreen(s_gridInfo& readGrid, s_paintInfo readPaint, s_menuInfo readMenu) {
    BeginDrawing();
    ClearBackground(MENUCOLOR);
    drawScene(readGrid, readMenu);
    drawMenu(readPaint, readMenu);
    EndDrawing();
}

void fillGrid(s_gridInfo& readGrid) {
    for (int row = 0; row < GRIDHEIGHT; row++)
        for (int col = 0; col < GRIDWIDTH; col++) {
            readGrid.cellInfo[row * GRIDWIDTH + col].cellColor = BACKGROUNDCOLOR;
            readGrid.cellInfo[row * GRIDWIDTH + col].density = 0;
            readGrid.cellInfo[row * GRIDWIDTH + col].angle = 360;
        }
    for (int i = 0; i < GRIDHEIGHT-1; i++)
        for (int j = 0; j < GRIDWIDTH; j++)
            readGrid.verticalMov[j + i * GRIDWIDTH] = 0;
    for (int i = 0; i < GRIDWIDTH - 1; i++)
        for (int j = 0; j < GRIDHEIGHT; j++) 
            readGrid.horizontalMov[j + i * GRIDHEIGHT] = 0;
      
}

void fillPaint(s_paintInfo& readPaint) {
    readPaint.colorArray[0] = BLACK;
    for (int i = 1; i < 9; i++) 
        readPaint.colorArray[i] = WHITE;
    readPaint.selectedColor = 1;
    readPaint.brushSize = 1;
    readPaint.type = colorAndAngle;
    readPaint.specialType = 0;
}

void fillMenu(s_menuInfo& readMenu){
    readMenu.textField = 0;
    readMenu.resetGrid = false;
    readMenu.displayAngles = false;
    readMenu.displayVelocities = false;
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
    else if (y < 458 && y > 424 && x > SCREENWIDTH - (MENUWIDTH / 4) && x < SCREENWIDTH - (MENUWIDTH * 1 / 8)) {
        readMenu.displayAngles = !readMenu.displayAngles;
        readMenu.displayVelocities = false;
    }
    else if (y < 498 && y > 464 && x > SCREENWIDTH - (MENUWIDTH / 4) && x < SCREENWIDTH - (MENUWIDTH * 1 / 8)) {
        readMenu.displayVelocities = !readMenu.displayVelocities;
        readMenu.displayAngles = false;
    }
    else if (y > 548 && y < 575) {
        if (x > 1218 && x < 1285)
            readPaint.type = gens;
        else if (x > 1295 && x < 1408)
            readPaint.type = angle;
        else if (x > 1415 && x < 1488)
            readPaint.type = color;
        readPaint.specialType = 0;
    }
    else if (y > 578 && y < 605) {
        readPaint.type = colorAndAngle;
        readPaint.specialType = 0;
    }
    else if (y > 610 && y < 650 && readPaint.type == gens) {
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
    if (readDrawGrid[y / GRIDCELLSIZE * GRIDWIDTH + x / GRIDCELLSIZE].status == 1 && (readPaint.type == color || readPaint.type == colorAndAngle))
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
    if ((readPaint.type == angle || readPaint.type == colorAndAngle)&&readDrawGrid[prevY*GRIDWIDTH + prevX].status == 3)
    {     
        for (int i = -readPaint.brushSize / 2; i <= (readPaint.brushSize - 1) / 2; i++) {
            for (int j = -(readPaint.brushSize / 2 - abs(i)); j <= ((readPaint.brushSize - 1) / 2 - abs(i)); j++) {
                if (prevY + i >= 0 && prevY + i < GRIDHEIGHT && prevX + j >= 0 && prevX + j < GRIDWIDTH)
                {
                    readDrawGrid[(prevY + i) * GRIDWIDTH + (prevX+j)].status = 4;
                    readGrid.cellInfo[(prevY + i) * GRIDWIDTH + (prevX + j)].angle = (float)atan2(y - readDrawGrid[prevY * GRIDWIDTH + prevX].initY, x - readDrawGrid[prevY * GRIDWIDTH + prevX].initX) * (180.0 / PI);
                    readGrid.cellInfo[(prevY + i) * GRIDWIDTH + (prevX + j)].angle -= 180.0;
                    if (readGrid.cellInfo[(prevY + i) * GRIDWIDTH + (prevX + j)].angle < 0)
                        readGrid.cellInfo[(prevY + i) * GRIDWIDTH + (prevX + j)].angle += 360.0;
                }
            }
        }
    }
    prevX = x / GRIDCELLSIZE;
    prevY = y / GRIDCELLSIZE;
}

void checkKeyboard(s_paintInfo& readPaint, s_menuInfo readMenu) {
    switch (readMenu.textField) {
    case 1:
        handleNumbers(0, 255, readPaint.colorArray[readPaint.selectedColor].r);
        break;
    case 2:
        handleNumbers(0, 255, readPaint.colorArray[readPaint.selectedColor].g);
        break;
    case 3:
        handleNumbers(0, 255, readPaint.colorArray[readPaint.selectedColor].b);
        break;
    case 4:
        handleNumbers(0, 19, readPaint.brushSize);
        break;
    }
}

void handleNumbers(int min, int max, unsigned char& number) {
    if (GetKeyPressed() != 0){
        if (IsKeyPressed(KEY_BACKSPACE)) {
            number /= 10;
            if (number < min)
                number = min;
        }
        else {
            unsigned short int tempTest = number;
            unsigned char countDigits = 0;
            unsigned char countDigitsTemp = number;
            do {
                countDigits++;
                countDigitsTemp = countDigitsTemp / 10;
            } while (countDigitsTemp != 0);
            if (IsKeyPressed(KEY_ONE)) {
                tempTest *= 10;
                tempTest += 1;
            }
            else if (IsKeyPressed(KEY_TWO)) {
                tempTest *= 10;
                tempTest += 2;
            }
            else if (IsKeyPressed(KEY_THREE)) {
                tempTest *= 10;
                tempTest += 3;
            }
            else if (IsKeyPressed(KEY_FOUR)) {
                tempTest *= 10;
                tempTest += 4;
            }
            else if (IsKeyPressed(KEY_FIVE)) {
                tempTest *= 10;
                tempTest += 5;
            }
            else if (IsKeyPressed(KEY_SIX)) {
                tempTest *= 10;
                tempTest += 6;
            }
            else if (IsKeyPressed(KEY_SEVEN)) {
                tempTest *= 10;
                tempTest += 7;
            }
            else if (IsKeyPressed(KEY_EIGHT)) {
                tempTest *= 10;
                tempTest += 8;
            }
            else if (IsKeyPressed(KEY_NINE)) {
                tempTest *= 10;
                tempTest += 9;
            }
            else if (IsKeyPressed(KEY_ZERO))
                tempTest *= 10;
            if (tempTest > max)
                number = max;
            else
                number = (unsigned char) tempTest;
        }
    }
}

bool operator==(Color x, Color y) {
    if (x.r != y.r) return false;
    if (x.g != y.g) return false;
    if (x.b != y.b) return false;
    if (x.a != y.a) return false;
    return true;
}

void move(s_gridInfo& readGrid) {

}