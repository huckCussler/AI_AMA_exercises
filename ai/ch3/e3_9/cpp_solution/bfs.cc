#include "bfs.h"

bfs::bfs(state *s, state *g): start(s), goal(g){}

bool bfs::try_solve(){
  frontier.push(start);

  while(!frontier.empty()){
    state *cur = frontier.front();
    frontier.pop();
    visited.insert(cur);
    if(cur->equals(goal)){
      while(cur->has_predecessor()){
	solution_path.insert(solution_path.begin(), cur);
	cur = cur->get_predecessor();
      }
      solution_path.insert(solution_path.begin(), cur);
      return true;
    }
    for(state* reachable : cur->get_reachable_states())
      if(!is_visited(reachable))
	frontier.push(reachable);
  }
  return false;
}

bool bfs::is_visited(state *c){
  for(state *v : visited)
    if(c->equals(v))
      return true;
  return false;
}

void bfs::print_solution(){
  for(state *s : solution_path)
    s->print_state();
}
