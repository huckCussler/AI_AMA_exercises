#include "state.h"

state::state(){
  ms=3;
  mg=0;
  cs=3;
  cg=0;
  bs=1;
  bg=0;
}

state::state(int m, int c, int b, state *p): ms(m), cs(c), bs(b), predecessor(p){
  mg=3-ms;
  cg=3-cs;
  bg=1-bs;
}

void state::print_state(){
  std::cout << "\n";
  std::cout << "m_start: " << ms << "\t\t\tm_goal: " << mg << "\n";
  std::cout << "\tb_start: " << bs << "\tb_goal: " << bg << "\n";
  std::cout << "c_start: " << cs << "\t\t\tc_goal: " << cg << "\n";
  std::cout << "\n";
}

state* state::get_predecessor(){ return predecessor; }

bool state::has_predecessor(){ return predecessor != 0; }

bool state::equals(state *o){
  return ms==o->ms && cs==o->cs && bs==o->bs;
}

std::set<state*> state::get_reachable_states(){
  std::set<state*> reachable_states;
  if(bs){
    // 1 missionary
    if((ms==1 || ms>cs) && (mg+1 >= cg))
      reachable_states.insert(new state(ms-1,cs,0,this));
    // 1 canibal
    if((mg==0 || mg>cg) && cs>=1)
      reachable_states.insert(new state(ms,cs-1,0,this));
    // 2 missionaries
    if((ms==2 || ms>cs+1) && (mg+2 >= cg))
      reachable_states.insert(new state(ms-2,cs,0,this));
    // 2 canibals
    if((mg==0 || mg>cg+1) && cs>=2)
      reachable_states.insert(new state(ms,cs-2,0,this));
    // 1 missionary AND 1 canibal
    if(ms>=1 && cs>=1 && mg >= cg)
      reachable_states.insert(new state(ms-1,cs-1,0,this));
  }
  else{
    // 1 missionary
    if((mg==1 || mg>cg) && (ms+1 >= cs))
      reachable_states.insert(new state(ms+1,cs,1,this));
    // 1 canibal
    if((ms==0 || ms>cs) && cg>=1)
      reachable_states.insert(new state(ms,cs+1,1,this));
    // 2 missionaries
    if((mg==2 || mg>cg+1) && (ms+2 >= cs))
      reachable_states.insert(new state(ms+2,cs,1,this));
    // 2 canibals
    if((ms==0 || ms>cs+1) && cg>=2)
      reachable_states.insert(new state(ms,cs+2,1,this));
    // 1 missionary AND 1 canibal
    if(mg>=1 && cg>=1 && ms >= cs)
      reachable_states.insert(new state(ms+1,cs+1,1,this));
  }
  return reachable_states;
}
