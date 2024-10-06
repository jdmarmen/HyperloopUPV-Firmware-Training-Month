#include "vector.h"
#include <iostream>

int main()
{
    Vector<int>v1;
    v1.insert(2);
    v1.insert(6);
    v1.insert(4);
    v1.insert(8);
    /*
    std::cout<<v1[2]<<std::endl;
    v1.erase_last();
    //std::cout<<v1[3];
    v1.erase(0);
    //std::cout<<v1[0]<<std::endl;
    std::cout<<v1.at(0)<<std::endl;
    std::cout<<v1.get_size()<<std::endl;
    */

    
    for(auto& num:v1)
    {
        std::cout<<num<<std::endl;
    }
    /*
    for(int i=0; i<v1.get_size();i++)
        std::cout<<v1[i]<<std::endl;
    */
    
    return 0;
}