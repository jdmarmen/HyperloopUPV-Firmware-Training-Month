#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
#include <utility>


using Action = std::function<void()>;
using Transition = std::function<bool()>;

class State
{
    private:

    std::vector <Action> actions{}; //vector full of actions to execute

    public:

    void add_action(Action action)
    {
        actions.push_back(action); // adds action to the vector
    }

    void update()
    {
        for (auto& action:actions) //executes every action from the vector
            action();
    }

};


class StateMachine
{
    private:

    State* current_state{};
    std::unordered_map<State*,std::pair<State*, Transition>> map; //map key is the current state, and its value is a pair that contains another state with the transition needed to change state
    
    void check_for_transitions()
    {
        for(auto& h:map) //runs through each key and value from the map
        {
            State* from=h.first;
            std::pair<State*, Transition>to=h.second;

            if(from==current_state && to.second()) //if we are in the current state and the transition to the second state returns a true, then the current state is changed
            {
                current_state=to.first;
                break;
            }
        }
    }

    public:

    StateMachine(State* current):current_state(current)
    {}

    void update()
    {
        current_state->update(); //executes every action from the actual state
        check_for_transitions(); //checks for transitions so as to change state
    }

    void add_transition(State* from, State* to, Transition transition)
    {
        map[from]=std::make_pair(to,transition); //adds a new key and value to the map
    }

    State* get_state()
    {
        return current_state; //returns the current state in case we need to execute its actions manually or even add newer ones 
    }


};


int main()
{
    State s1,s2;

    Action a1=[]()
    {
        std::cout<<"Action 1 here!\n";
    };

    s1.add_action(a1);    

    Action a2=[]()
    {
        std::cout<<"Action 2 here!\n";
    };
    
    s2.add_action(a2);

    StateMachine sm(&s1);
    
    Transition t1=[]()
    {
        int x=1;
        if(x==1)
        {
            std::cout<<"I'm a transition transitioning!\n";
            return true;
        }
        else
            return false;
    };

    sm.add_transition(&s1,&s2,t1);
    sm.update();
    sm.get_state()->update();
    


    return 0;
}