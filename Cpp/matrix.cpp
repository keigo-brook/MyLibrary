/*
 * Created by KeigoOgawa
 * Matrix
 */


#include "myHeahder.h"

const int MOD = INT_MAX;

typedef vector<ll> vec;
typedef vector<vec> mat;

// calc C = A * B
mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    REP(i, A.size()) {
        REP(k, B.size()) {
            REP(j, B[0].size()) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// calc B = A^n
mat pow(mat A, ll n) {
    mat B(A.size(), vec(A.size()));
    REP(i, A.size()) {
        B[i][i] = 1;
    }
    while (n > 0) {
        if (n & 1) {
            B = mul(B, A);
        }
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
