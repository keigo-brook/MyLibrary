#include "myHeahder.h"


const int MAX_N = 50;
const int MAX_M = 50;

// right, up, left, down
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int N, M;
int sx, sy, gx, gy;
int d[MAX_N][MAX_M];

vector<string> maze;

// INF if no path
int bfs() {
    queue<PII> que;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            d[i][j] = INF;
        }
    }

    // push start to queue and init distance by 0
    que.push(PII(sx, sy));
    d[sx][sy] = 0;

    // loop while queue is not empty
    while (que.size()) {
        // take queue front
        PII p = que.front(); que.pop();
        // break if p is goal
        if (p.first == gx && p.second == gy) break;

        // loop 4 directions
        for (int i = 0; i < 4; ++i) {
            // (nx, ny) is a point after move
            int nx = p.first + dx[i], ny = p.second + dy[i];

            // if (nx, ny) is movable and visit first time
            if (0 <= nx && nx < N && 0 <= ny && ny < M 
                && maze[nx][ny] != '#' && d[nx][ny] == INF) {
                // push queue and calc distance from p
                que.push(PII(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}
