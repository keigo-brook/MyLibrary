#include "../myHeahder.h"

const int MAX_V = 100;

// d[u][v]は辺(u,v)のコスト(存在しない場合はINF,ただしd[i][i]=0)となる。
int d[MAX_V][MAX_V];
int V;

// 各頂点同士の最短経路を求めるO(N^3)
void warshall_floyd() {
    REP(k, V) {
        REP(i, V) {
            REP(j, V) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void init_warshall_graph() {
    fill(d[0], d[V], INF);
    REP(i, V) {
        d[i][i] = 0;
    }
}


void test_warshall_floyd() {
    // init d
    init_warshall_graph();

    // set all d here

    warshall_floyd();
}