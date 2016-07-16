#include "../myHeahder.h"
#include "graph.cpp"

edge visit(int p, int v, Graph &g) {
  edge r(v, 0);
  for (edge e : g[v]) {
    if (e.to != p) {
      edge t = visit(v, e.to, g);
      t.cost += e.cost;
      if (r.cost < t.cost) {
        r = t;
      }
    }
  }
  return r;
}

/*
 * 適当な頂点sから一番遠い頂点rをもとめ, そこから一番遠い頂点tを求める.
 * r-t が直径
 * (r.to, t.to) is farthest pair, t.cost is diameter
 */
int diameter(Graph &g) {
  edge r = visit(-1, 0, g);
  edge t = visit(-1, r.to, g);
  return t.cost;
}
