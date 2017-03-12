#ifndef BFS_H
#define BFS_H

#include<vector>
#include "state.h"
#include<queue>

class bfs{
 private:
  state *start;
  state *goal;
  std::set<state*> visited;
  std::queue<state*> frontier;
  std::vector<state*> solution_path;
 public:
  bfs(state*, state*);
  bool try_solve();
  bool is_visited(state*);
  void print_solution();
};

#endif
