#include <iostream>
#include "DynamicList.hpp"

template <typename T> void PrintList(DynamicList<T>& list)
{
    for (int i = 0; i < list.getSize(); i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    DynamicList<std::string> list(2);
    list[0] = "Hello";
    list[1] = "yo!";
    PrintList(list);

    list[1] = "there!";
    PrintList(list);

    list.append("mizkif");
    PrintList(list);
    
    return 0;
}