#include "BrushType.h"

bool operator==(Color x, Color y) {
    if (x.r != y.r) return false;
    if (x.g != y.g) return false;
    if (x.b != y.b) return false;
    if (x.a != y.a) return false;
    return true;
}