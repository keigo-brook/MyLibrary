#include "../myHeahder.h"

bool check(double m) {
    return true;
}

// 二分探索
// 単調増加(減少)関数がx=ｋと交わる点を求める
// (1/2)^{n} < 10^-15 <=> n > 50 より, 50回ぐらい回せばdoubleならOK
double binary_search(double h, double l) {
    double m;
    REP(i, 100) {
        m = (h + l) / 2.0;
        if (check(m)) {
            l = m;
        } else {
            h = m;
        }
    }
    return m;
}