#include "../myHeahder.h"

const int MAX_V = 2000;

struct edge {
  int to, cost;
  edge(int to, int cost) : to(to), cost(cost) {}
};

typedef vector<vector <edge> > Graph;
Graph G(MAX_V);

void add_edge(int from, int to, int cost) {
  G[from].push_back(edge(to, cost));
}
