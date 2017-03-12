#ifndef STATE_H
#define STATE_H

#include<string>
#include<set>
#include<iostream>
#include<cstddef>

class state{
 private:
  int ms;
  int mg;
  int cs;
  int cg;
  int bs;
  int bg;
  state *predecessor;
  
 public:
  state();
  state(int, int, int, state*);
  void print_state();
  bool is_goal_state();
  std::set<state*> get_reachable_states();
  state* get_predecessor();
  bool equals(state*);
  bool has_predecessor();
};


#endif
