// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <iostream>
#include <vector>
#include <set>


void printVector(std::vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << ", ";
    }
    std::cout << std::endl;
}


void printSet(std::set<int> nums)
{
    for (int const& num : nums)
    {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}


class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        int unique_numbers = nums.size();
        std::set<int> previous_nums;
        previous_nums.insert(nums[0]);
        for (int i = 1; i < unique_numbers; i++)
        {
            // duplicate number
            if (previous_nums.find(nums[i]) != previous_nums.end())
            {
                bubble_to_back(nums, i, unique_numbers);
                unique_numbers--;
                i--;
            }
            else
            {
                previous_nums.insert(nums[i]);
            }
        }
        return unique_numbers;
    }
private:
    void bubble_to_back(std::vector<int>& nums, int i, int unique_numbers)
    {
        for (i = i; i < unique_numbers - 1; i++)
        {
            std::swap(nums[i], nums[i + 1]);
        }
    }
};


int main()
{
    std::cout << "Hello world!\n";
    std::vector<std::vector<int>> tests 
    {
        std::vector<int> {1, 1, 2},
        std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8},
        std::vector<int> {1, 2, 3, 4, 4, 5, 6},
        std::vector<int> {1, 1, 2, 3, 4, 5, 6, 7, 8},
        std::vector<int> {1, 1, 2, 3, 3, 4, 5, 6},
        std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 8},
        std::vector<int> {1, 1, 2, 3, 4, 5, 6, 7, 8, 8},
        std::vector<int> {1, 1, 2, 3, 4, 4, 5, 6, 7, 8, 8},
        std::vector<int> {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}
    };
    Solution solution;
    for (size_t i = 0; i < tests.size(); i++)
    {
        std::cout << "Before: ";
        printVector(tests[i]);
        int uniques = solution.removeDuplicates(tests[i]);
        std::cout << "uniques: " << uniques << std::endl;
        std::cout << "After: ";
        printVector(tests[i]);
    }
    return 0;
}