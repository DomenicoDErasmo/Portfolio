#include <iostream>
#include <stack>
#include <cassert>
#include <unordered_map>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> stack;
        std::unordered_map<char, char> pairs {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        for (size_t i = 0; i < s.length(); i++)
        {
            if (pairs.find(s[i]) == pairs.end())
            {
                if (stack.empty() or pairs[stack.top()] != s[i])
                {
                    return false;
                }
                else
                {
                    stack.pop();
                }
            }
            else
            {
                stack.push(s[i]);
            }
        }
        return stack.empty();
    }
};

int main()
{
    Solution solution;
    assert(solution.isValid("()") == true);
    assert(solution.isValid("()[]{}") == true);
    assert(solution.isValid("(]") == false);
    assert(solution.isValid("(") == false);
    assert(solution.isValid("]") == false);
    assert(solution.isValid("()[") == false);
    std::cout << "Tests ran successfully!\n";
}