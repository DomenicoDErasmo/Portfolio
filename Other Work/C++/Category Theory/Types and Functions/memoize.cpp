#include <iostream>
#include <utility>
#include <unordered_map>

int Memoize(int(*function)(char), char arg, std::unordered_map<std::pair<int(*)(char), char>, int>& lookup_table)
{
    std::pair<int(*)(char), char> tuple = std::make_pair(function, arg);
    if (lookup_table.find(tuple) == lookup_table.end())
    {
        std::cout << arg << " was already stored for the function!\n";
        int result = (*function)(arg);
        lookup_table.insert({tuple, result});
        return result;
    }
    else
    {
        return lookup_table[tuple];
    }
}

int GetAscii(char ch)
{
    return int(ch);
}

int GetOrderInAlphabetUppercase(char ch)
{
    return int(ch) - 64;
}

int GetOrderInAlphabetLowercase(char ch)
{
    return int(ch) - 96;
}

int main()
{
    std::unordered_map<std::pair<int(*)(char), char>, int> lookup_table;
    int (*ascii)(char) = GetAscii;
    int (*upper)(char) = GetOrderInAlphabetUppercase;
    int (*lower)(char) = GetOrderInAlphabetLowercase;
    int(*pointers[3])(char) = {ascii, upper, lower};
    char inputs[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    for (int i = 0; i < sizeof(pointers) / sizeof(pointers[0]); i++)
    {
        for (int j = 0; j < sizeof(inputs) / sizeof(inputs[0]); j++)
        {
            std::cout << Memoize(pointers[i], inputs[j], lookup_table) << std::endl;
        }
    }
    std::cout << Memoize(ascii, 'a', lookup_table);
    std::cout << Memoize(GetOrderInAlphabetUppercase, 'c', lookup_table);
    std::cout << Memoize(GetOrderInAlphabetLowercase, 'f', lookup_table);
}