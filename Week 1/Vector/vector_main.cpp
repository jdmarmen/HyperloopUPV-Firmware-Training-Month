#include <cstdlib> // for using malloc, realloc, free
#include <cstring> // for using memcpy, memset
#include <iostream>


template <typename T>
class Vector
{
    
    public:

    Vector()
    {}

    ~Vector()
    {
        std::free(data);
    }

    void insert(T value)
    {
        if(size>=capacity)
            reallocate(capacity+capacity/2);

        data[size]=value;
        ++size;
    }

    size_t get_size()const
    {
        return size;
    }

    void erase_last()
    {
        if(size>0)
            --size;
    }

    void erase(size_t index)
    {
        if(index<0 || index>=size)
            throw std::out_of_range("Unavailable position mate!\n");
        else
        {
            memcpy(data+index,data+index+1,(size-index-1)*sizeof(T));
            --size;
        }
    }

    T& at(size_t index)const
    {
         if(index>=size)
            throw std::out_of_range("Unavailable position mate!\n");
        else
            return data[index];
    }

    T& operator[](size_t index)const
    {
        if(index>=size)
            throw std::out_of_range("Unavailable position mate!\n");
        else
            return data[index];
    }

    T* begin()
    {
        return data;
    }
    T* end()
    {
        return data + size;
    }
    private:

    T* data{};
    size_t size{}; //number of elements inside the vector
    size_t capacity{}; //how much memory is available inside the vector to store data, not necessarily full, just reserved

    void reallocate(std::size_t new_capacity)
    {
        if(new_capacity==0)
            new_capacity=sizeof(T)*2; // we are starting to reserve memory for at least, 2 elements
        
        T* new_data=static_cast<T*>(std::malloc(new_capacity*sizeof(T))); 

        if(new_data==nullptr)
            std::cout<<"ERROR: Probably, memory is full mate!\n";
        else
        {
            std::memcpy(new_data,data,size*sizeof(T));
            std::free(data);
        }

        data=new_data;
        capacity=new_capacity;
    }

};

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