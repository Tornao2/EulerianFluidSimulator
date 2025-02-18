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
	brushType = new e_brushType;
	*brushType = colorAndVelocity;
	specialType = 0;
}

void Menu::drawMenu() {
    DrawRectangle(x, y, width, height, GREEN);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
            DrawRectangle(x + y * (58 - 15 * j) / 64, (80 + i * 80), width / 8, width / 8, BLACK);
    for (int i = 0; i < 8; i++)
        DrawRectangle(x + width * (58 - 15 * (i % 4)) / 64, 80 + i / 4 * 80 + height / 48, width / 12, width / 12, colorArray[i + 1]);
    /*
    DrawText("Colors", x + width / 2 - MeasureText("Colors", FONTSIZE) / 2, 5, FONTSIZE, BLACK);
    DrawText("1", x + width * 8 / 9 + MeasureText("1", FONTSIZE) / 2, 45, FONTSIZE, selectedColor == 1 ? DARKGREEN : BLACK);
    DrawText("2", x + width * 6 / 9 + MeasureText("2", FONTSIZE) / 2, 45, FONTSIZE, selectedColor == 2 ? DARKGREEN : BLACK);
    DrawText("3", x + width * 4 / 9 + MeasureText("3", FONTSIZE) / 2, 45, FONTSIZE, selectedColor == 3 ? DARKGREEN : BLACK);
    DrawText("4", x + width * 2 / 9 + MeasureText("4", FONTSIZE) / 2, 45, FONTSIZE, selectedColor == 4 ? DARKGREEN : BLACK);
    DrawText("5", x + width * 8 / 9 + MeasureText("5", FONTSIZE) / 2, 125, FONTSIZE, selectedColor == 5 ? DARKGREEN : BLACK);
    DrawText("6", x + width * 6 / 9 + MeasureText("6", FONTSIZE) / 2, 125, FONTSIZE, selectedColor == 6 ? DARKGREEN : BLACK);
    DrawText("7", x + width * 4 / 9 + MeasureText("7", FONTSIZE) / 2, 125, FONTSIZE, selectedColor == 7 ? DARKGREEN : BLACK);
    DrawText("8", x + width * 2 / 9 + MeasureText("8", FONTSIZE) / 2, 125, FONTSIZE, selectedColor == 8 ? DARKGREEN : BLACK);
    DrawText("Obstruction", x + width / 2 - MeasureText("Obstruction", FONTSIZE) / 2, 205, FONTSIZE, selectedColor == 0 ? DARKGREEN : BLACK);
    if (selectedColor != 0) {
        for (int i = 0; i < 3; i++)
            DrawRectangle(x + width * (15 - i * 5) / 16, 250, height / 4, 40, (textField - 1) == i ? SELECTCOLOR : WHITE);
        DrawText(TextFormat("%i", colorArray[selectedColor].r), x + width * 13 / 16 - MeasureText(TextFormat("%i", colorArray[selectedColor].r), FONTSIZE) / 2, 252, FONTSIZE, BLACK);
        DrawText(TextFormat("%i", colorArray[selectedColor].g), x + width / 2 - MeasureText(TextFormat("%i", colorArray[selectedColor].g), FONTSIZE) / 2, 252, FONTSIZE, BLACK);
        DrawText(TextFormat("%i", colorArray[selectedColor].b), x + width * 3 / 16 - MeasureText(TextFormat("%i", colorArray[selectedColor].b), FONTSIZE) / 2, 252, FONTSIZE, BLACK);
        DrawText("R", x + width * 13 / 16 - MeasureText("R", FONTSIZE) / 2, 295, FONTSIZE, BLACK);
        DrawText("G", x + width / 2 - MeasureText("G", FONTSIZE) / 2, 295, FONTSIZE, BLACK);
        DrawText("B", x + width * 3 / 16 - MeasureText("B", FONTSIZE) / 2, 295, FONTSIZE, BLACK);
    }
    DrawText("Reset scene", x + width / 2 - MeasureText("Reset scene", FONTSIZE) / 2, 340, FONTSIZE, RED);
    DrawText("Brush size:", x + width * 19 / 20, 385, FONTSIZE * 3 / 4, BLACK);
    DrawRectangle(x + width / 4, 384, width / 8, height / 10, textField == 4 ? SELECTCOLOR : WHITE);
    DrawText(TextFormat("%i", brushSize), x + width * 3 / 16 - MeasureText(TextFormat("%i", brushSize), FONTSIZE * 3 / 4) / 2, 386, FONTSIZE * 3 / 4, BLACK);
    DrawText("Toggle velocity:", x + width * 19 / 20, 426, FONTSIZE * 3 / 4, BLACK);
    DrawRectangle(x + width / 4, 424, width / 8, height / 10, displayVelocities ? GREEN : RED);
    DrawText("Brush mode:", x + width / 2 - (MeasureText("Brush mode", FONTSIZE)) / 2, 468, FONTSIZE, BLACK);
    DrawText("Color", x + width * 1 / 6 - (MeasureText("Color", FONTSIZE * 3 / 4)) / 2, 508, FONTSIZE * 3 / 4, *brushType == color ? DARKGREEN : BLACK);
    DrawText("Velocity", x + width * 3 / 6 - (MeasureText("Velocity", FONTSIZE * 3 / 4)) / 2, 508, FONTSIZE * 3 / 4, *brushType == vel ? DARKGREEN : BLACK);
    DrawText("Gens", x + width * 5 / 6 - (MeasureText("Gens", FONTSIZE * 3 / 4)) / 2, 508, FONTSIZE * 3 / 4, *brushType == gens ? DARKGREEN : BLACK);
    DrawText("Color + Velocity", x + width / 2 - (MeasureText("Color + Velocity", FONTSIZE * 3 / 4)) / 2, 538, FONTSIZE * 3 / 4, *brushType == colorAndVelocity ? DARKGREEN : BLACK);
    if (*brushType == gens)
        for (int i = 0; i < 4; i++) {
            DrawRectangle(1230 + i * 70, 570, 40, 40, specialType == i + 1 ? SELECTCOLOR : WHITE);
            DrawRectanglePro({ (float)1250 + i * 70, (float)590, 26, 16 }, { 13, 8 }, (float)i * 90, BLACK);
            DrawRectanglePro({ (float)1250 + i * 70, (float)590, 13, 16 }, { 13, 8 }, (float)i * 90, BLUE);
        }
        */
}