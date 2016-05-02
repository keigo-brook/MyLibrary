#include "myHeahder.h"

// https://ja.wikipedia.org/wiki/トポロジカルソート

const int MAX_V = 100;
struct edge {
    int to, cost;
    bool used;
};

int V;
vector<edge> dag[MAX_V];
// used[n] = [-1|0|1], [一時的|未探索|探索済み]
int used[MAX_V];
// トポロジカルソートされた結果が入るリスト
vector<int> l;

// nからDAGを深さ優先で訪問しトポロジカルソートされたリストを作成 O(|V|+|E|)
// 結果のリストは逆順になる
bool visit(int n) {
    if (used[n] == -1) {
        // 閉路がありDAGでないので中断
        return false;
    } else if (used[n] == 0) {
        used[n] = -1;
        REP(i, dag[n].size()) {
            if (!visit(dag[n][i].to)) {
                return false;
            }
        }
        used[n] = 1;
        l.push_back(n);
    }
    return true;
}

// DFS, 閉路検出なし版
// bool used[MAX_V];
void visit_no_closed_path(int n) {
    if (!used[n]) {
        used[n] = true;
        REP(i, dag[n].size()) {
            visit_no_closed_path(dag[n][i].to);
        }
        l.push_back(n);
    }
}

int topological_sort() {
    // DAGをトポロジカルソート
    REP(i, V) {
        if (!visit(i)) {
            // 閉路あり
            return false;
        }
    }    
    return true;
}

// nからトポロジカルソート
// 入力辺を持たないノードから辺を見ていく
void topological_sort(int n) {
    // 入力辺を持たないすべてのノードの集合
    queue<int> s;
    s.push(n);

    while (!s.empty()) {
        int n = s.front(); s.pop();
        l.push_back(n);
        REP(i, dag[n].size()) {
            edge e = dag[n][i];
            if (e.used) {
                continue;
            }
            e.used = true;
            if (dag[e.to].size() > 0) {
                s.push(e.to);
            }
        }
    }

    // if (グラフに辺が残っている) {
    //     閉路がありDAGでないので中断
    // }
}