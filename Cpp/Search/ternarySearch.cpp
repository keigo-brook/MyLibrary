#include "../myHeahder.h"

double f(double m) {
    return 0;
}

// 三分探索, 凸関数fの極大値xを求める(極小の場合は不等号反転)
// 探索領域を三分割し, f(x)が下に凸なら値が大きい方, 上に凸なら小さい方の外側を捨てる
// h - (h - l) / 3 <=> (2h + l)/3 : 大きい方の境界
// l + (h - l) / 3 <=> (h + 2l)/3 : 小さい方の境界
// (2/3)^{n} < 10^-15 <=> n > 86 より86回ぐらい回せばdoubleならOK
double ternary_search(double h, double l) {
    REP(i, 100) {
        if (f((h * 2 + l) / 3.0) > f((h + l * 2) / 3.0)) {
            l = (h + l * 2) / 3.0;
        } else {
            h = (h * 2 + l) / 3.0;
        }
    }
    return (h + l) / 2.0;
}

void test_ternary_search() {
    // 極値x
    double x = ternary_search(100, 0);
    // 極値xでの値f(x)
    printf("%.10lf\n", f(x));
}