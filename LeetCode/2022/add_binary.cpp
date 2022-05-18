#include <iostream>
#include <string>
#include <vector>

// Given two binary strings a and b, return their sum as a binary string.

class Solution
{
public:
    std::string addBinary(std::string a, std::string b)
    {
        std::string result = "";
        // pad smaller string so they are easier to operate on
        std::string *smaller_string = &(a.length() < b.length() ? a : b), *larger_string = &(a.length() > b.length() ? a : b);
        *smaller_string = std::string(larger_string->length() - smaller_string->length(), '0') + *smaller_string;

        int carry_bit = 0;
        for (int i = a.length() - 1; i >= 0; i--)
        {
            int sum = (int(a[i]) - 48) + (int(b[i]) - 48) + carry_bit;
            if (sum == 0)
            {
                result = "0" + result;
                carry_bit = 0;
            }
            else if (sum == 1)
            {
                result = "1" + result;
                carry_bit = 0;
            }
            else if (sum == 2)
            {
                result = "0" + result;
                carry_bit = 1;
            }
            else if (sum == 3)
            {
                result = "1" + result;
                carry_bit = 1;
            }
        }
        if (carry_bit == 1)
        {
            result = "1" + result;
        }
        return result;
    }
};

class UnitTest
{
public:
    UnitTest(std::string a_in, std::string b_in, std::string expected_in)
    {
        a = a_in;
        b = b_in;
        expected = expected_in;
    }
    void Test()
    {
        Solution solution;
        if (solution.addBinary(a, b) == expected)
        {
            std::cout << "Passed: ";
        }
        else
        {
            std::cout << "Failed: ";
        }
        std::cout << *this << ", got " << solution.addBinary(a, b) << std::endl;
    }
private:
    std::string to_string()
    {
        return "a: " + a + ", b: " + b + ", result: " + expected;
    }
    friend std::ostream& operator << (std::ostream& out, UnitTest unit_test)
    {
        out << unit_test.to_string();
        return out;
    }
    std::string a;
    std::string b;
    std::string expected;
};

int main()
{
    std::vector<UnitTest> unit_tests
    {
        UnitTest("11", "1", "100"),
        UnitTest("1010", "1011", "10101")
    };
    for(size_t i = 0; i < unit_tests.size(); i++)
    {
        unit_tests[i].Test();
    }
    return 0;
}