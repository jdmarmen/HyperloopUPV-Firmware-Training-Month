#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"
#include <unordered_map>
#include <utility>

using Transition = std::function<bool()>;

class StateMachine {
private:
    State* current_state;
    std::unordered_map<State*, std::pair<State*, Transition>> map; // Mapa de transiciones

    void check_for_transitions();

public:
    StateMachine(State* current);
    void update();
    void add_transition(State* from, State* to, Transition transition);
    State* get_state();
};

#endif
