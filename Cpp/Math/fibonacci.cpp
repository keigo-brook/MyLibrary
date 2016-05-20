/*
 * Created by KeigoOgawa
 * Fibonacci
 */


#include "matrix.cpp"

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

void test_fibonacci() {
    assert(6765 == fib2n(20));
    assert(6765 == fibn(20));
    assert(6765 == fib(20));
}
