#include <iostream>
#include <vector>
#include <string>

std::string digitsToString(std::vector<int> digits)
{
    std::string result;
    for (size_t i = 0; i < digits.size(); i++)
    {
        result += std::to_string(digits[i]);
    }
    return result;
}

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        std::vector<int> result = digits;
        int place_to_increment = result.size() - 1;
        while(place_to_increment >= 0 and result[place_to_increment] == 9)
        {
            result[place_to_increment] = 0;
            place_to_increment--;
        }
        if (place_to_increment == -1)
        {
            result.insert(result.begin(), 1);
        }
        else
        {
            result[place_to_increment]++;
        }
        return result;
    }
};

class UnitTest
{
public:
    UnitTest(std::vector<int> digits, std::vector<int> result)
    {
        this->digits = digits;
        this->result = result;
    }
    void RunTest()
    {
        Solution solution;
        std::cout << ((solution.plusOne(digits) == result) ? "Success: " : "Failed: ");
        std::cout << *this << ", got " << digitsToString(solution.plusOne(digits)) << std::endl;
    }
private:
    std::string toString()
    {
        return "UnitTest: {Digits: " + digitsToString(digits) + ", Answer: " + digitsToString(result) + "}";
    }
    friend std::ostream& operator << (std::ostream& out, UnitTest unit_test)
    {
        out << unit_test.toString();
        return out;
    }
    std::vector<int> digits;
    std::vector<int> result;
};

int main()
{
    std::vector<UnitTest> unit_tests
    {
        UnitTest(std::vector<int>{1, 2, 3}, std::vector<int> {1, 2, 4}),
        UnitTest(std::vector<int>{4, 3, 2, 1}, std::vector<int> {4, 3, 2, 2}),
        UnitTest(std::vector<int>{9}, std::vector<int> {1, 0}),
        UnitTest(std::vector<int>{0}, std::vector<int> {1}),
        UnitTest(std::vector<int>{9, 9}, std::vector<int> {1, 0, 0}),
        UnitTest(std::vector<int>{8, 9, 9, 9}, std::vector<int> {9, 0, 0, 0})
    };
    for (size_t i = 0; i < unit_tests.size(); i++)
    {
        unit_tests[i].RunTest();
    }
    return 0;
}