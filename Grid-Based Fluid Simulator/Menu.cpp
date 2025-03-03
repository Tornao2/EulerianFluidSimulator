#include "Menu.h"

Menu::Menu(short int getX, short int getY, short int getWidth, short int getHeight) {
	x = getX;
	y = getY;
    width = getWidth;
    height = getHeight;
	textField = 0;
	resetGrid = false;
	displayVelocities = false;
	colorArray[0] = BLACK;
	for (int i = 1; i < 9; i++)
		colorArray[i] = WHITE;
	selectedColor = 1;
	brushSize = 1;
	brushType = color;
    giveMaterial = 20;
}

unsigned char Menu::getGiveMaterial() {
    return giveMaterial;
}

void Menu::setGiveMaterial(unsigned char count) {
    giveMaterial = count;
}

Color Menu::getSelectedColor() {
    return colorArray[selectedColor];
}

unsigned char Menu::getBrushSize() {
    return brushSize;
}

BrushType Menu::getBrush() {
    return brushType;
}

void Menu::drawMenu() {
    DrawRectangle(x, y, width, height, MENUCOLOR);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++) {
            DrawRectangle(x + (j * width / 4) + (width / 16), y + i * height/12 + height / 20, width / 8, width / 8, BLACK);
            DrawRectangle(x + (j * width / 4) + (width / 12), y + i * height / 12 + height / 20 + width / 48, width / 12, width / 12, colorArray[i * 4 + j + 1]);
            DrawText(TextFormat("%i", i * 4 + j + 1), x + (j * width / 4) + (width / 8) - MeasureText(TextFormat("%i", i * 4 + j + 1), FONTSIZE) / 2, y + i * height / 12 + height / 20 + width / 8, FONTSIZE, selectedColor == i * 4 + j + 1 ? DARKGREEN : BLACK);
        }   
    DrawText("Colors", x + width / 2 - MeasureText("Colors", FONTSIZE) / 2, 0, FONTSIZE, BLACK);
    DrawText("Obstruction", x + width / 2 - MeasureText("Obstruction", FONTSIZE) / 2, height*9/40, FONTSIZE, selectedColor == 0 ? DARKGREEN : BLACK);
    if (selectedColor != 0) {
        for (int i = 0; i < 3; i++)
            DrawRectangle(x + (i * 5 - 4) * width / 16 + width*15/48, height * 11 / 40, width / 4, FONTSIZE, (textField - 1) == i ? SELECTCOLOR : WHITE);
        DrawText(TextFormat("%i", colorArray[selectedColor].r), x + width * 3 / 16 - MeasureText(TextFormat("%i", colorArray[selectedColor].r), FONTSIZE) / 2, height * 11 / 40, FONTSIZE, BLACK);
        DrawText(TextFormat("%i", colorArray[selectedColor].g), x + width / 2 - MeasureText(TextFormat("%i", colorArray[selectedColor].g), FONTSIZE) / 2, height * 11 / 40, FONTSIZE, BLACK);
        DrawText(TextFormat("%i", colorArray[selectedColor].b), x + width * 13 / 16 - MeasureText(TextFormat("%i", colorArray[selectedColor].b), FONTSIZE) / 2, height * 11 / 40, FONTSIZE, BLACK);
        DrawText("R", x + width * 3 / 16 - MeasureText("R", FONTSIZE) / 2, height * 5 / 16, FONTSIZE, BLACK);
        DrawText("G", x + width / 2 - MeasureText("G", FONTSIZE) / 2, height * 5 / 16, FONTSIZE, BLACK);
        DrawText("B", x + width * 13 / 16 - MeasureText("B", FONTSIZE) / 2, height * 5 / 16, FONTSIZE, BLACK);
    }
    DrawText("Reset scene", x + width / 2 - MeasureText("Reset scene", FONTSIZE) / 2, height * 23 / 64, FONTSIZE, RED);
    DrawText("Brush size:", x + width / 20, height * 13 / 32, FONTSIZE, BLACK);
    DrawRectangle(x + width * 3 / 4, height * 13 / 32, width / 8, width / 8, textField == 4 ? SELECTCOLOR : WHITE);
    DrawText(TextFormat("%i", brushSize), x + width * 13/16 - MeasureText(TextFormat("%i", brushSize), FONTSIZE) / 2, height * 13 / 32, FONTSIZE, BLACK);
    DrawText("Toggle velocity:", x + width / 80, height * 29 / 64, FONTSIZE*18/20, BLACK);
    DrawRectangle(x + width * 7/ 8, height * 29 / 64, width / 10, width / 10, displayVelocities ? GREEN : RED);
    DrawText("Brush mode:", x + width / 2 - (MeasureText("Brush mode", FONTSIZE)) / 2, height / 2, FONTSIZE, BLACK);
    DrawText("Fluid", x + width * 5 / 24 - (MeasureText("Fluid", FONTSIZE)) / 2, height * 35 / 64, FONTSIZE, brushType == color ? DARKGREEN : BLACK);
    DrawText("Velocity", x + width * 2 / 3 - (MeasureText("Velocity", FONTSIZE)) / 2, height * 35 / 64, FONTSIZE, brushType == vel ? DARKGREEN : BLACK);
    DrawText("Fluid + Velocity", x + width / 2 - (MeasureText("Fluid + Velocity", FONTSIZE)) / 2, height * 38 / 64, FONTSIZE, brushType == colorAndVelocity ? DARKGREEN : BLACK);
}

void Menu::handleNumbers(int min, int max, unsigned char& number) {
    if (GetKeyPressed() != 0) {
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
            if (IsKeyPressed(KEY_ZERO)) 
                tempTest *= 10;
            else 
                for (char i = KEY_ONE; i <= KEY_NINE; i++)
                    if (IsKeyPressed(i)) {
                        tempTest *= 10;
                        tempTest += i - KEY_ONE + 1;
                    }
            if (tempTest > max)
                number = max;
            else
                number = (unsigned char)tempTest;
        }
    }
}

void Menu::checkKeyboard() {
    switch (textField) {
    case 1:
        handleNumbers(0, 255, colorArray[selectedColor].r);
        break;
    case 2:
        handleNumbers(0, 255, colorArray[selectedColor].g);
        break;
    case 3:
        handleNumbers(0, 255, colorArray[selectedColor].b);
        break;
    case 4:
        handleNumbers(0, 19, brushSize);
        break;
    }
}

bool Menu::getResetGrid() {
    return resetGrid;
}

void Menu::setResetGrid(bool setReset) {
    resetGrid = setReset;
}

unsigned char Menu::getTextField() {
    return textField;
}

void Menu::clickMenu(int readX, int readY) {
    textField = 0;
    if (readY >= y + height/20 && readY <= y + height / 20 + width/8) {
        if (readX >= x + (width/16) && readX <= x + (width * 3 / 16))
            selectedColor = 1;
        else if (readX >= x + (width / 16) + width/4 && readX <= x + (width * 3 / 16) + +width / 4)
            selectedColor = 2;
        else if (readX >= x + (width / 16) + width / 2 && readX <= x + (width * 3 / 16) + +width / 2)
            selectedColor = 3;
        else if (readX >= x + (width / 16) + width * 3 / 4 && readX <= x + (width * 3 / 16) + +width * 3/ 4)
            selectedColor = 4;
    }
    else if (readY >= y + height / 20 + height / 12 && readY <= y + height / 20 + width / 8 + height / 12) {
        if (readX >= x + (width / 16) && readX <= x + (width * 3 / 16))
            selectedColor = 5;
        else if (readX >= x + (width / 16) + width / 4 && readX <= x + (width * 3 / 16) + +width / 4)
            selectedColor = 6;
        else if (readX >= x + (width / 16) + width / 2 && readX <= x + (width * 3 / 16) + +width / 2)
            selectedColor = 7;
        else if (readX >= x + (width / 16) + width * 3 / 4 && readX <= x + (width * 3 / 16) + +width * 3 / 4)
            selectedColor = 8;
    }
    else if (readY >= y + height * 9 / 40 && readY <= y + height * 9 / 40 + FONTSIZE)
        selectedColor = 0;
    else if (selectedColor != 0 && readY >= y + height * 11 / 40 && readY <= y + height * 11 / 40 + FONTSIZE) {
        if (readX <= x - 4 * width / 16 + width * 15 / 48 + width/4 && readX >= x - 4 * width / 16 + width * 15 / 48)
            textField = 1;
        else if (readX <= x + width / 16 + width * 15 / 48 + width / 4 && readX >= x + width / 16 + width * 15 / 48)
            textField = 2;
        else if (readX <= x + 6 * width / 16 + width * 15 / 48 + width / 4 && readX >= x + 6 * width / 16 + width * 15 / 48)
            textField = 3;
    }
    else if (readY >= height * 23 / 64 && readY <= height * 23 / 64 + FONTSIZE) 
        resetGrid = true;
    else if (readY <= height * 13 / 32 + width/8 && readY >= height * 13 / 32 && readX >= x + width * 3 / 4 && readX <= x + width * 3 / 4 + width/8)
        textField = 4;
    else if (readY <= height * 29 / 64 + width/10 && readY >= height * 29 / 64 && readX >= x + width * 7 / 8 && readX <= x + width * 7 / 8 + width/10)
        displayVelocities = !displayVelocities;
    else if (readY >= height * 35 / 64 && readY < height * 35 / 64 + FONTSIZE) {
        if (readX >= x + width * 5 / 24 - (MeasureText("Fluid", FONTSIZE)) / 2 && readX <= x + width * 5 / 24 + (MeasureText("Fluid", FONTSIZE)) / 2)
            brushType = color;
        else if (readX >= x + width * 2 / 3 - (MeasureText("Velocity", FONTSIZE)) / 2 && readX <= x + width * 2 / 3 + (MeasureText("Velocity", FONTSIZE)) / 2)
            brushType = vel;
    }
    else if (readY >= height * 38 / 64 && readY <= height * 38 / 64 + FONTSIZE)
        brushType = colorAndVelocity;
}

short int Menu::getWidth() {
    return width;
}

short int Menu::getHeight() {
    return height;
}

void Menu::setTextField(unsigned char fieldNum) {
    textField = fieldNum;
}

