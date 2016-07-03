#include "./myHeahder.h"

// maximum bit
const int MAX_N = 16;

// adjacency matrix of bit
int mat[MAX_N];


// add edge from a vertex to another vertex
void add_edge(int from, int to) {
  mat[from] |= (1 << (to));
}

// s: set(0 ~ 2^N), v: vertex(1 ~ N)
// S contain v
bool contain(int s, int v) {
  return s & (1 << v);
}

// v have edge to S
bool have_edge(int s, int v) {
  return (mat[v] & s) == 0 ? false : true;
}

// remove v from S and return the set
int removed_set(int s, int v) {
  return s ^ (1 << v);
}