#include "../myHeahder.h"

// (0, 0), (a, b), (c, d)の面積S = |ad - bc| / 2
double triangle_area(int x1, int y1, int x2, int y2, int x3, int y3) {
    x2 -= x1; x3 -= x1;
    y2 -= y1; y3 -= y1;
    return abs(x2 * y3 - y2 * x3) / 2.0;
}