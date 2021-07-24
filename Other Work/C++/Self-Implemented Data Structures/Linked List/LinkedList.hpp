#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

template <typename T> class LinkedList
{
public:
    LinkedList()
    {
        next = nullptr;
    }
    LinkedList(T data)
    {
        this->data = data;
        next = nullptr;
    }
    T GetData()
    {
        return data;
    }
    void SetData(T data)
    {
        this->data = data;
    }
    LinkedList* GetNext()
    {
        return next;
    }
    void SetNext(LinkedList* next)
    {
        this->next = next;
    }
private:
    T data;
    LinkedList* next;
};

#endif