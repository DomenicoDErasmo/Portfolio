#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>

class Solution
{
public:
    int lengthOfLastWord(std::string s)
    {
        std::istringstream iss(s);
        std::string temp, previous_word;
        while(std::getline(iss, temp, ' '))
        {
            if (!temp.empty())
            {
                previous_word = temp;
            }
        }
        return previous_word.length();
    }
};

int main()
{
    Solution solution;
    std::vector<std::tuple<std::string, int>> unit_tests
    {
        std::make_tuple("Hello World", 5),
        std::make_tuple("   fly me  to   the moon ", 4),
        std::make_tuple("luffy is still joyboy", 6)
    };
    for (size_t i = 0; i < unit_tests.size(); i++)
    {
        if (solution.lengthOfLastWord(std::get<0>(unit_tests[i])) == std::get<1>(unit_tests[i]))
        {
            std::cout << "SUCCESS: Length of last word of " << std::get<0>(unit_tests[i]) << " calculated as " << solution.lengthOfLastWord(std::get<0>(unit_tests[i])) << std::endl;
        }
        else
        {
            std::cout << "FAIL: Length of last word of " << std::get<0>(unit_tests[i]) << " calculated as " << solution.lengthOfLastWord(std::get<0>(unit_tests[i])) << ", should be " << std::get<1>(unit_tests[i]) << std::endl;
        }
    }
    return 0;
}