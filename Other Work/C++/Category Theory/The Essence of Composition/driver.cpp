#include <iostream>
#include <string>

/*
A composition takes two functions and returns the result of chaining one function after another. I wish to implement the following compositions:
1. Exactly two functions passed
2. A vector of functions that forms a composition (i.e., the n-1st function returns the valid type of the nth, the n-2nd returns the n-1st's arguments...)
*/

template <class first, class second, class third>
first ComposeFunctions(first (*second_function)(second), second (*first_function)(third), third arg)
{
    return second_function(first_function(arg));
}

/*
An identity function takes an object and returns the exact object.
*/

template <class T> T GetIdentity(T obj)
{
    return obj;
}

std::string NumToString(int num);
int AddTwo(int num);

int main()
{
    std::string (*pointer_to_second_function)(int) = NumToString;
    int (*pointer_to_first_function)(int) = AddTwo;
    std::cout << "Testing composition by calling NumToString(AddTwo(1)):\n";
    std::cout << ComposeFunctions(pointer_to_second_function, pointer_to_first_function, 1) << "\n\n";

    std::string test = "hello";
    std::cout << "Testing identity by calling GetIdentity(\"hello\")\n";
    std::cout << GetIdentity(test) << std::endl;

    return 0;
}

std::string NumToString(int num)
{
    switch(num)
    {
        case 0:
            return "zero";
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
        default:
            return "too big";
    }
}

int AddTwo(int num)
{
    return num + 2;
}

