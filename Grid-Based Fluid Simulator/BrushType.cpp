#include "BrushType.h"

bool operator==(Color x, Color y) {
    if (x.r != y.r) return false;
    if (x.g != y.g) return false;
    if (x.b != y.b) return false;
    if (x.a != y.a) return false;
    return true;
}

Color averageColors(Color x, Color y) {
    Color returnCol;
    short int inter = sqrt((x.a *x.a + y.a *y.a) / 2);
    returnCol.a = inter;
    inter = sqrt((x.r *x.r + y.r *y.r) / 2);
    returnCol.r = inter;
    inter = sqrt((x.g * x.g + y.g *y.g) / 2);
    returnCol.g = inter;
    inter = sqrt((x.b * x.b + y.b *y.b) / 2);
    returnCol.b = inter;
    return returnCol;
}

Color calculateAfterFade(Color x, int steps, int fadeStrength) {
    Color returnCol;
    returnCol.r = x.r / steps * (steps - fadeStrength);
    returnCol.g = x.g / steps * (steps - fadeStrength);
    returnCol.b = x.b / steps * (steps - fadeStrength);
    returnCol.a = x.b / steps * (steps - fadeStrength);
    return returnCol;
}