#include "State.h"

void State::add_action(Action action) {
    actions.push_back(action); // Añadir acción al vector
}

void State::update() {
    for (auto& action : actions) { // Ejecutar cada acción del vector
        action();
    }
}
