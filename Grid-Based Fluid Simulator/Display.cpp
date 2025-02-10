#include "Display.h"

Display::Display(short int getWidth, short int getHeight, char getFramerate) {
    screenHeight = getHeight;
    screenWidth = getWidth;
    framerate = getFramerate;
}

void Display::initScreen() {
    InitWindow(screenWidth, screenHeight, "Fluid Simulator");
    SetTargetFPS(framerate);
}

short int Display::getWidth() {
    return screenWidth;
}

short int Display::getHeight() {
    return screenHeight;
}

char Display::getFramerate() {
    return framerate;
}