#include "../myHeahder.h"

double f(double m) {
    return m;
}

// 黄金分割探索, 凸関数fの極大値xを求める(極小の場合は不等号反転)
// 領域の分割を再帰的に行うため, 前回のイテレーションでの値を再利用でき, 高速化できる
// ((-1 + √5)/2)^{n} < 10^-15 <=> n > 72より, 72ぐらい回せばdoubleならOK     
const double R = (1 + sqrt(5.0)) / 2.0;
double golden_section_search(double h, double l) {
    double hv = f((h * R + l) / (1 + R));
    double lv = f((h + l * R) / (1 + R));
    REP(i, 100) {
        if (hv > lv) {
            l = (h + l * R) / (1 + R);
            lv = hv;
            hv = f((h * R + l) / (1 + R));
        } else {
            h = (h * R + l) / (1 + R);
            hv = lv;
            lv = f((h + l * R) / (1 + R));
        }
    }
    if (hv > lv) {
        l = (h + l * R) / (1 + R);
    } else {
        h = (h * R + l) / (1 + R);
    }
    return (h + l) / 2.0;
}

void test_golden_section_search() {
    // 極値x
    double x = golden_section_search(100, 0);
    // 極値xでの値f(x)
    printf("%lf\n", f(x));
}