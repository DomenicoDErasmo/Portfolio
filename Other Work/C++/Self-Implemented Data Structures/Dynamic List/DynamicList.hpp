#ifndef DYNAMICLIST_HPP
#define DYNAMICLIST_HPP

#include <iostream>

template <typename T> class DynamicList
{
public:

    DynamicList()
    {
        this->data = new T[10];
        this->size = 10;
        this->capacity = 10;
    }

    DynamicList(int capacity)
    {
        this->data = new T[capacity];
        this->size = capacity;
        this->capacity = capacity;
    }

    ~DynamicList()
    {
        delete[] this->data;
    }

    T& operator[](int i)
    {
        if (i < 0 or i >= capacity)
        {
            std::cout << "Error: accessing out of bounds\n";
            exit(-1);
        }
        return data[i];
    }

    int getSize()
    {
        return size;
    }

    void append(T obj)
    {
        if (capacity <= size)
        {
            ResizeArray();
        }
        data[size] = obj;
        size++;
    }

private:

    void ResizeArray()
    {
        T* new_data = new T[capacity * 2];
        int* x = new int[10];
        for (int i = 0; i < capacity; i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = NULL;
        data = new_data;
        capacity = 2 * capacity;
    }

    T* data;
    int size;
    int capacity;
};

#endif