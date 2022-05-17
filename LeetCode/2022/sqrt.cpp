#include <iostream>
#include <vector>

class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 0, right = sqrt_int_max, guess = (left + right) / 2;
        while (left <= right)
        {
            if (square(guess) == x)
            {
                return guess;
            }
            else if (square(guess) < x)
            {
                left = guess + 1;       // adding to ensure we don't get stuck due to integer truncation
            }
            else
            {
                right = guess - 1;
            }
            guess = (left + right) / 2; // subtracting to ensure we don't get stuck due to integer truncation
        }
        return guess;
    }
private:
    int square(int x)
    {
        return x * x;
    }
    int sqrt_int_max = 46340;
};

class UnitTest
{
public:
    UnitTest(int num, int result)
    {
        this->num = num;
        this->result = result;
    }
    void TestAccuracy()
    {
        Solution solution;
        if (solution.mySqrt(num) == result)
        {
            std::cout << "Success: ";
        }
        else
        {
            std::cout << "Failed: ";
        }
        std::cout << "mySqrt(" << num << ") should equal " << result << ", got " << solution.mySqrt(num) << std::endl;
    }
private:
    int num;
    int result;
};

int main()
{
    std::vector<UnitTest> unit_tests
    {
        UnitTest(8, 2),
        UnitTest(9, 3),
        UnitTest(26, 5),
        UnitTest(INT_MAX, 46340)
    };
    for (size_t i = 0; i < unit_tests.size(); i++)
    {
        unit_tests[i].TestAccuracy();
    }
    return 0;
}