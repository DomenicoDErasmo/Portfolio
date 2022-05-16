#include <iostream>
#include <vector>
#include <tuple>

/*
Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/

class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        if (needle == "")
        {
            return 0;
        }
        for (size_t i = 0; i < haystack.length(); i++)
        {
            if (haystack[i] == needle[0] and completesSubstr(haystack, needle, i))
            {                
                return i;
            }
        }
        return -1;
    }
private:
    bool completesSubstr(std::string haystack, std::string needle, int i)
    {
        for (size_t j = 1; j < needle.length(); j++)
        {
            if (haystack[i + j] != needle[j])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    std::vector<std::tuple<std::string, std::string>> tests
    {
        (std::make_tuple("hello", "ll")),
        (std::make_tuple("a", "a")),
        (std::make_tuple("aaa", "aaaa")),
        (std::make_tuple("mississippi", "issip")),
    };
    for (size_t i = 0; i < tests.size(); i++)
    {
        std::string haystack = std::get<0>(tests[i]), needle = std::get<1>(tests[i]);
        std::cout << "Haystack: " << haystack << ", needle: " << needle << std::endl;
        std::cout << "First found at position " << solution.strStr(haystack, needle) << std::endl;
    }

    return 0;
}