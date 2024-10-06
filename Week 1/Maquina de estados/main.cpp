#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
#include <utility>

#include "State.h"
#include "StateMachine.h"


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