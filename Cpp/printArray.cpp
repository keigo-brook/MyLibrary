#include "myHeahder.h"

template<typename T, size_t N> void printArray(T(&array)[N]) {
    REP(i, N) {
        cout << array[i] << " ";
    }
    cout << endl;
}

template<typename T, size_t N, size_t M> void printArray2(T(&array)[N][M]) {
    REP(i, N) {
        cout << "i:" << i << "| ";
        REP(j, M) {cout << array[i][j];
            j == M - 1 ? cout << "\n" : cout << " ";
        }
    }
}

// 1 2 3
// i:0| 2 3 4
// i:1| 5 6 7
// i:2| 8 9 10
// i:0| a b c
// i:1| d e f
// i:2| g h i
void testPrintArray() {
    int a[3] = {1, 2, 3};
    int b[3][3] = {{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
    char c[3][4] = {"abc", "def", "ghi"};
    printArray(a);
    printArray2(b);
    printArray2(c);
}