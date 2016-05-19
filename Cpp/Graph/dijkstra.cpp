#include "../myHeahder.h"

const int MAX_V = 1000;

// cost[u][v]は辺e=(u,v)のコスト(存在しない場合はINF)
int cost[MAX_V][MAX_V];
// 頂点sからの最短距離
int d[MAX_V];
// すでに使われたかのフラグ
bool used[MAX_V];
// 頂点数
int V;

// 始点sから各頂点への最短距離を求める
// 隣接行列を使う, O(|V|^2)
void dijkstra(int s) {
    fill(d, d + V, INF);
    fill(used, used + V, false);
    d[s] = 0;

    while (true) {
        int v = -1;

        // まだ使われていない頂点のうち距離が最小のものを探す
        for (int u = 0; u < V; ++u) {
            if (!used[u] && (v == -1 || d[u] < d[v])) {
                v = u;
            }
        }

        if (v == -1) {
            break;
        }
        used[v] = true;

        for (int u = 0; u < V; ++u) {
            d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }
}


struct edge {
    int to, cost;
    edge(int to, int cost) : to(to), cost(cost) {}
};
// vector<edge> G(MAX_V);

// Graph上のn個の頂点で, 始点sから各頂点への最短距離の配列を返す
// using priority_queue, O(|E|log|V|)
vector<int> dijkstra1(int s, int n, vector<vector<edge> > &Graph) {
    // pair<int, int>のfirstは最短距離,secondは頂点の番号
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<PII, vector<PII>, greater<PII> > que;
    vector<int> d(n, INF);
    d[s] = 0;
    que.push(PII(0, s));

    while (!que.empty()) {
        PII p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) {
            continue;
        }
        for (edge e : Graph[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(PII(d[e.to], e.to));
            }
        }
    }
    return d;
}