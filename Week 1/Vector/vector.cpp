#include "vector.h"

template <typename T>
Vector<T>::Vector() {}

template <typename T>
Vector<T>::~Vector() {
    std::free(data);
}

template <typename T>
void Vector<T>::insert(T value) {
    if (size >= capacity)
        reallocate(capacity + capacity / 2);

    data[size] = value;
    ++size;
}

template <typename T>
size_t Vector<T>::get_size() const {
    return size;
}

template <typename T>
void Vector<T>::erase_last() {
    if (size > 0)
        --size;
}

template <typename T>
void Vector<T>::erase(size_t index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Unavailable position mate!\n");
    else {
        std::memcpy(data + index, data + index + 1, (size - index - 1) * sizeof(T));
        --size;
    }
}

template <typename T>
T& Vector<T>::at(size_t index) const {
    if (index >= size)
        throw std::out_of_range("Unavailable position mate!\n");
    else
        return data[index];
}

template <typename T>
T& Vector<T>::operator[](size_t index) const {
    if (index >= size)
        throw std::out_of_range("Unavailable position mate!\n");
    else
        return data[index];
}

template <typename T>
T* Vector<T>::begin() {
    return data;
}

template <typename T>
T* Vector<T>::end() {
    return data + size;
}

template <typename T>
void Vector<T>::reallocate(std::size_t new_capacity) {
    if (new_capacity == 0)
        new_capacity = sizeof(T) * 2; // Reservar memoria para al menos 2 elementos

    T* new_data = static_cast<T*>(std::malloc(new_capacity * sizeof(T)));

    if (new_data == nullptr)
        std::cout << "ERROR: Probably, memory is full mate!\n";
    else {
        std::memcpy(new_data, data, size * sizeof(T));
        std::free(data);
    }

    data = new_data;
    capacity = new_capacity;
}
