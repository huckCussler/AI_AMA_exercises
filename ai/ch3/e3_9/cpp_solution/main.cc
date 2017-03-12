#include <iostream>
#include "state.h"
#include "bfs.h"

using namespace std;

int main(){ 
  bfs *b = new bfs(new state(), new state(0,0,0,0));

  if(b->try_solve())
    b->print_solution();
}
