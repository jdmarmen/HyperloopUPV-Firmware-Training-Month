#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>
#include <functional>

using Action = std::function<void()>;

class State {
private:
    std::vector<Action> actions; // Vector de acciones a ejecutar

public:
    void add_action(Action action);
    void update();
};

#endif
