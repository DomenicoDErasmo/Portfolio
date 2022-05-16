#include <iostream>
#include <vector>
#include <tuple>

class Solution
{
public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        int left = 0, right = nums.size(), mid = 0;
        while (left < right)
        {
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
            mid = (left + right) / 2;
        }
        return mid;
    }
};

typedef struct UnitTest
{
    std::vector<int> nums;
    int target;
    int answer;
} UnitTest;

UnitTest BuildUnitTest(std::vector<int> nums, int target, int answer)
{
    UnitTest unit_test;
    unit_test.nums = nums;
    unit_test.target = target;
    unit_test.answer = answer;
    return unit_test;
}

void PrintVector(std::vector<int> vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << ", ";
    }
}

int main()
{
    Solution solution;
    std::vector<UnitTest> unit_tests
    {
        BuildUnitTest(std::vector<int> {1, 3, 5, 6}, 5, 2),
        BuildUnitTest(std::vector<int> {1, 3, 5, 6}, 2, 1),
        BuildUnitTest(std::vector<int> {1, 3, 5, 6}, 7, 4),
    };
    for (size_t i = 0; i < unit_tests.size(); i++)
    {
        UnitTest unit_test = unit_tests[i];
        PrintVector(unit_test.nums);
        std::cout << "would contain " << unit_test.target << " at index " << solution.searchInsert(unit_test.nums, unit_test.target) << ", should be at " << unit_test.answer << std::endl;
    }
    return 0;
}