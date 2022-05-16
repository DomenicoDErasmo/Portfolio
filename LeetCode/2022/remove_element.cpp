#include <iostream>
#include <vector>

/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, 
then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/

void printVector(std::vector<int> nums)
{
    for (size_t i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << ", ";
    }
    std::cout << std::endl;
}

class Solution 
{
public:
    int removeElement(std::vector<int>& nums, int val) 
    {
        int remaining = nums.size();
        for (size_t i = 0; i < remaining; i++)
        {
            if (nums[i] == val)
            {
                remaining--;
                bubbleToTop(nums, i, remaining);
                i--;
            }
        }
        return remaining;
    }
private:
    void bubbleToTop(std::vector<int>& nums, int i, int remaining)
    {
        for (int j = i; j < remaining; j++)
        {
            std::swap(nums[j], nums[j + 1]);
        }
    }
};

int main()
{
    std::cout << "Hello world!\n";
    std::vector<std::vector<int>> test_arrays = {
        std::vector<int> {3, 2, 2, 3},
        std::vector<int> {0,1,2,2,3,0,4,2}
    };
    std::vector<int> nums_to_remove = {3, 2};
    Solution solution;
    for (size_t i = 0; i < test_arrays.size(); i++)
    {
        std::cout << "Before: ";
        printVector(test_arrays[i]);
        std::cout << "Nums remaining: " << solution.removeElement(test_arrays[i], nums_to_remove[i]) << std::endl;
        std::cout << "After: ";
        printVector(test_arrays[i]);
    }
    return 0;
}