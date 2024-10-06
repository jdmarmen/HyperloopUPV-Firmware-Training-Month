#ifndef vector_h
#define vector_h

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
public:
    Vector();
    ~Vector();

    void insert(T value);
    size_t get_size() const;
    void erase_last();
    void erase(size_t index);
    T& at(size_t index) const;
    T& operator[](size_t index) const;

    T* begin();
    T* end();

private:
    T* data{};
    size_t size{};
    size_t capacity{};

    void reallocate(std::size_t new_capacity);
};

#include "vector.cpp" // Incluir la implementación

#endif
