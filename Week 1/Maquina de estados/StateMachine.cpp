#include "StateMachine.h"

StateMachine::StateMachine(State* current) : current_state(current) {}

void StateMachine::update() {
    current_state->update(); // Ejecutar acciones del estado actual
    check_for_transitions(); // Verificar transiciones
}

void StateMachine::check_for_transitions() {
    for (auto& h : map) { // Recorrer el mapa de transiciones
        State* from = h.first;
        std::pair<State*, Transition> to = h.second;

        if (from == current_state && to.second()) { // Si hay una transición válida
            current_state = to.first; // Cambiar estado actual
            break;
        }
    }
}

void StateMachine::add_transition(State* from, State* to, Transition transition) {
    map[from] = std::make_pair(to, transition); // Añadir transición al mapa
}

State* StateMachine::get_state() {
    return current_state; // Devolver el estado actual
}
