#include "Draw.h"

void initScreen() {
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Fluid Simulator");
    SetTargetFPS(FRAMERATE);
}

void drawVelocity(gridCell readCell, int readRow, int readCol) {
    DrawRectanglePro({ (float)GRIDCELLSIZE * readCol + GRIDCELLSIZE / 2, (float)GRIDCELLSIZE * readRow + GRIDCELLSIZE / 2, GRIDCELLSIZE * 3 / 4, GRIDCELLSIZE / 2 }, { GRIDCELLSIZE * 3 / 8, GRIDCELLSIZE / 4 }, readCell.angle, { 255, 255, 255, (unsigned char)(readCell.density * 6)});
    DrawRectanglePro({ (float)GRIDCELLSIZE * readCol + GRIDCELLSIZE / 2, (float)GRIDCELLSIZE * readRow + GRIDCELLSIZE / 2, GRIDCELLSIZE * 3 / 8, GRIDCELLSIZE / 2 }, { GRIDCELLSIZE * 3 / 8, GRIDCELLSIZE / 4 }, readCell.angle, { 40, 130, 255, (unsigned char)(readCell.density * 6 )});
}

void drawScene(gridCell readGrid[GRIDHEIGHT*GRIDWIDTH], menuInfo readInfo) {
    DrawRectangle(0, 0, SCREENWIDTH - MENUWIDTH, SCREENHEIGHT, BACKGROUNDCOLOR);
    for (unsigned short int row = 0; row < GRIDHEIGHT; row++)
        for (unsigned short int col = 0; col < GRIDWIDTH; col++) {
            DrawRectangle(GRIDCELLSIZE * col, GRIDCELLSIZE * row, GRIDCELLSIZE, GRIDCELLSIZE, { readGrid[row * GRIDWIDTH + col].cellColor.r, readGrid[row * GRIDWIDTH + col].cellColor.g, readGrid[row * GRIDWIDTH + col].cellColor.b, (unsigned char)(readGrid[row * GRIDWIDTH + col].density * 6) });
            if (readInfo.displayAngles && !(readGrid[row * GRIDWIDTH + col].cellColor == BLACK) && readGrid[row * GRIDWIDTH + col].angle != 360) drawVelocity(readGrid[row * GRIDWIDTH + col], row, col);
            }
}

void drawMenu(paintInfo readPaint, menuInfo readInfo) {
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
            DrawRectangle(SCREENWIDTH - MENUWIDTH * (15 - i * 5) / 16, 250, MENUWIDTH / 4, 40, (readInfo.textField - 1) == i ? SELECTCOLOR : WHITE);
        DrawText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].r), SCREENWIDTH - MENUWIDTH * 13 / 16 - MeasureText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].r), FONTSIZE) / 2, 252, FONTSIZE, BLACK);
        DrawText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].g), SCREENWIDTH - MENUWIDTH / 2 - MeasureText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].g), FONTSIZE) / 2, 252, FONTSIZE, BLACK);
        DrawText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].b), SCREENWIDTH - MENUWIDTH * 3 / 16 - MeasureText(TextFormat("%i", readPaint.colorArray[readPaint.selectedColor].b), FONTSIZE) / 2, 252, FONTSIZE, BLACK);
        DrawText("R", SCREENWIDTH - MENUWIDTH * 13 / 16 - MeasureText("R", FONTSIZE) / 2, 295, FONTSIZE, BLACK);
        DrawText("G", SCREENWIDTH - MENUWIDTH / 2 - MeasureText("G", FONTSIZE) / 2, 295, FONTSIZE, BLACK);
        DrawText("B", SCREENWIDTH - MENUWIDTH * 3 / 16 - MeasureText("B", FONTSIZE) / 2, 295, FONTSIZE, BLACK);
    }
    DrawText("Reset scene", SCREENWIDTH - MENUWIDTH / 2 - MeasureText("Reset scene", FONTSIZE) / 2, 340, FONTSIZE, RED);
    DrawText("Brush size:", SCREENWIDTH - MENUWIDTH * 19 / 20, 385, FONTSIZE * 3 / 4, BLACK);
    DrawRectangle(SCREENWIDTH - MENUWIDTH / 4, 384, MENUWIDTH / 8, MENUWIDTH / 10, readInfo.textField == 4 ? SELECTCOLOR : WHITE);
    DrawText(TextFormat("%i", readPaint.brushSize), SCREENWIDTH - MENUWIDTH * 3 / 16 - MeasureText(TextFormat("%i", readPaint.brushSize), FONTSIZE*3/4) / 2, 386, FONTSIZE*3/4, BLACK);
    DrawText("Toggle angles:", SCREENWIDTH - MENUWIDTH * 19/20, 426, FONTSIZE*3/4, BLACK);
    DrawRectangle(SCREENWIDTH - MENUWIDTH / 4, 424, MENUWIDTH / 8, MENUWIDTH / 10, readInfo.displayAngles ? GREEN : RED);
    DrawText("Brush mode:", SCREENWIDTH - MENUWIDTH/2 - (MeasureText("Brush mode", FONTSIZE))/2, 468, FONTSIZE, BLACK);
    DrawText("Color", SCREENWIDTH - MENUWIDTH * 1 / 6 - (MeasureText("Color", FONTSIZE*3/4)) / 2, 508, FONTSIZE*3/4, readPaint.type == color ? DARKGREEN : BLACK);
    DrawText("Angle", SCREENWIDTH - MENUWIDTH * 3 / 6 - (MeasureText("Angle", FONTSIZE * 3 / 4)) / 2, 508, FONTSIZE * 3 / 4, readPaint.type == angle ? DARKGREEN : BLACK);
    DrawText("Gens", SCREENWIDTH - MENUWIDTH * 5 / 6 - (MeasureText("Gens", FONTSIZE * 3 / 4)) / 2, 508, FONTSIZE * 3 / 4, readPaint.type == gens ? DARKGREEN : BLACK);
    DrawText("Color + Angle", SCREENWIDTH - MENUWIDTH /2  - (MeasureText("Color + Angle", FONTSIZE * 3 / 4)) / 2, 538, FONTSIZE * 3 / 4, readPaint.type == colorAndAngle ? DARKGREEN : BLACK);
    if (readPaint.type == gens)
        for (int i = 0; i < 4; i++) {
            DrawRectangle(1230 + i * 70, 570, 40, 40, readPaint.specialType == i + 1 ? SELECTCOLOR : WHITE);
            DrawRectanglePro({ (float) 1250 + i * 70, (float) 590, 26, 16 }, { 13, 8 }, i * 90, BLACK);
            DrawRectanglePro({ (float)1250 + i * 70, (float)590, 13, 16 }, { 13, 8 }, i * 90, BLUE);
        }
}

void drawScreen(gridCell readGrid[GRIDHEIGHT*GRIDWIDTH], paintInfo readPaint, menuInfo readInfo) {
    BeginDrawing();
    ClearBackground(MENUCOLOR);
    drawScene(readGrid, readInfo);
    drawMenu(readPaint, readInfo);
    EndDrawing();
}

void fillGrid(gridCell readGrid[GRIDHEIGHT*GRIDWIDTH]) {
    for (int row = 0; row < GRIDHEIGHT; row++)
        for (int col = 0; col < GRIDWIDTH; col++) {
            readGrid[row * GRIDWIDTH + col].cellColor = BACKGROUNDCOLOR;
            readGrid[row * GRIDWIDTH + col].density = 0;
            readGrid[row * GRIDWIDTH + col].moveUp = 0;
            readGrid[row * GRIDWIDTH + col].moveDown = 0;
            readGrid[row * GRIDWIDTH + col].moveLeft = 0;
            readGrid[row * GRIDWIDTH + col].moveRight = 0;
            readGrid[row * GRIDWIDTH + col].angle = 360;
        }
}

void fillPaint(paintInfo& readPaint) {
    readPaint.colorArray[0] = BLACK;
    for (int i = 1; i < 9; i++) 
        readPaint.colorArray[i] = WHITE;
    readPaint.selectedColor = 1;
    readPaint.brushSize = 1;
    readPaint.type = colorAndAngle;
    readPaint.specialType = 0;
}

void fillMenu(menuInfo& readInfo){
    readInfo.textField = 0;
    readInfo.resetGrid = false;
    readInfo.displayAngles = false;
}

void clickMenu(paintInfo& readPaint, int x, int y, menuInfo& readInfo) {
    readInfo.textField = 0;
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
            readInfo.textField = 1;
        else if (x < 1390 && x > 1312)
            readInfo.textField = 2;
        else if (x < 1484 && x > 1407)
            readInfo.textField = 3;
    }
    else if (y > 350 && y < 378)
        readInfo.resetGrid = true;
    else if (y < 418 && y > 384 && x > SCREENWIDTH - (MENUWIDTH / 4) && x < SCREENWIDTH - (MENUWIDTH * 1 / 8))
        readInfo.textField = 4;
    else if (y < 458 && y > 424 && x > SCREENWIDTH - (MENUWIDTH / 4) && x < SCREENWIDTH - (MENUWIDTH * 1 / 8))
        readInfo.displayAngles = !readInfo.displayAngles;
    else if (y > 508 && y < 535) {
        if (x > 1218 && x < 1285)
            readPaint.type = gens;
        else if (x > 1295 && x < 1408)
            readPaint.type = angle;
        else if (x > 1415 && x < 1488)
            readPaint.type = color;
        readPaint.specialType = 0;
    }
    else if (y > 538 && y < 565) {
        readPaint.type = colorAndAngle;
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

void clickScene(gridCell readGrid[GRIDHEIGHT * GRIDWIDTH], paintInfo readPaint, int x, int y, int prevX, int prevY, menuInfo& readInfo) {
    readInfo.textField = 0;
    if(readPaint.brushSize != 0) paintScene(readGrid, readPaint, x, y, prevX, prevY);
}

void paintScene(gridCell readGrid[GRIDHEIGHT * GRIDWIDTH], paintInfo readPaint, int x, int y, int prevX, int prevY) {
    unsigned char alphaDelta = 25 / ((readPaint.brushSize + 1) / 2 + 1);
    for(int i = -readPaint.brushSize/2; i <= (readPaint.brushSize-1)/2; i++){
        for (int j = -(readPaint.brushSize / 2 - abs(i)); j <= ((readPaint.brushSize - 1) / 2 - abs(i)); j++) {
            if (y / GRIDCELLSIZE + i >= 0 && y / GRIDCELLSIZE + i < GRIDHEIGHT && x / GRIDCELLSIZE + j >= 0 && x / GRIDCELLSIZE + j < GRIDWIDTH)
            {
                if (readPaint.type == color || readPaint.type == colorAndAngle)
                {
                    readGrid[((y / GRIDCELLSIZE) + i) * GRIDWIDTH + x / GRIDCELLSIZE + j].cellColor = readPaint.colorArray[readPaint.selectedColor];
                    readGrid[((y / GRIDCELLSIZE) + i) * GRIDWIDTH + x / GRIDCELLSIZE + j].density = 25 - (abs(i) + abs(j)) * alphaDelta;
                }
                if ((readPaint.type == angle || readPaint.type == colorAndAngle) && x - prevX != 0)
                {
                    std::cout << sin((y - prevY) / (x - prevX));
                    readGrid[((y / GRIDCELLSIZE) + i) * GRIDWIDTH + x / GRIDCELLSIZE + j].angle = (asin(sin((y - prevY) / (x - prevX))) + 1)*180;
                }
            }
        }
    }
}

void checkKeyboard(paintInfo& readPaint, menuInfo readInfo) {
    switch (readInfo.textField) {
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
                number = tempTest;
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