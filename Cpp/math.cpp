/*
 * Created by KeigoOgawa
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <cmath>
#include <functional>
#include <vector>

#define INF (int)1e8
#define EPS 1e-10
#define FOR(i, a, b) for (int i=(a);i<(b);i++)
#define RFOR(i, a, b) for (int i=(b)-1;i>=(a);i--)
#define REP(i, n) for (int i=0;i<(n);i++)
#define RREP(i, n) for (int i=(n)-1;i>=0;i--)
#define MIN(a, b) (a>b?b:a)
#define MAX(a, b) (a>b?a:b)
#define debug(x) cout<<#x<<": "<<x<<endl
#define all(a) (a).begin(),(a).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int MOD = INT_MAX;

/******************************************************************************/
 

/* Matrix *********************************************************************/

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

/******************************************************************************/

// fibonacci O(2^n)
int fib2n(int n) {
    if (n == 0 || n == 1 || n == 2) {
        return 1;
    } else {
        return fib2n(n - 1) + fib2n(n - 2);
    }
}

// fibonacci O(n)
int fibn(int n) {
    if (n <= 1) {
        return n;
    }

    int n0 = 0, n1 = 1, current = 0;
    REP(i, n - 1) {
        current = n0 + n1;
        n0 = n1;
        n1 = current;
    }
    return current;
}

// fibonacci O(log n)
ll fib(int n) {
    mat A(2, vec(2));
    A[0][0] = 1; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 0;
    A = pow(A, n);
    return A[1][0];
}

int main() {
    assert(6765 == fib2n(20));
    assert(6765 == fibn(20));
    assert(6765 == fib(20));
}