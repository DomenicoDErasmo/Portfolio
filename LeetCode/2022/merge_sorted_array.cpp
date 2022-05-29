/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, 
where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void printVector(std::vector<int>& nums)
{
    for (size_t i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << ", ";
    }
}

class Solution
{
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        int left = 0, right = 0, current_size = 0;
        while(have_elements_in_either_array(left, m, right, n))
        {
            if (left >= m)
            {
                while(right < n)
                {
                    int i = 0;
                    while ((nums1[i] <= nums2[right]) and i < current_size)
                    {
                        i++;
                    }
                    nums1.insert(nums1.begin() + i, nums2[right]);
                    nums1.pop_back();
                    i = 0;
                    right++;
                    current_size++;
                }
            }
            else if (right >= n)
            {
                return;
            }
            else if (nums1[left] > nums2[right])
            {
                nums1.insert(nums1.begin() + left, nums2[right]);
                nums1.pop_back();
                right++;
                current_size++;
            }
            else
            {
                left++;
                current_size++;
            }
        }
    }
private:
    bool have_elements_in_either_array(int left, int m, int right, int n)
    {
        return left < m or right < n;
    }
};

class UnitTest
{
public:
    UnitTest(std::vector<int> nums1, int m, std::vector<int> nums2, int n, std::vector<int> expected)
    {
        this->nums1 = nums1;
        this->originalNums1 = nums1;
        this->m = m;
        this->nums2 = nums2;
        this->n = n;
        this->expected = expected;
    }
    void test()
    {
        Solution solution;
        solution.merge(nums1, m, nums2, n);
        if (nums1 == expected)
        {
            std::cout << "Passed: ";
        }
        else
        {
            std::cout << "Failed: ";
        }
        std::cout << *this << ", expected output: " << vectorToString(expected) << std::endl;
    }
    friend std::ostream& operator << (std::ostream& out, UnitTest* test)
    {
        out << test->toString();
        return out;
    }
    friend std::ostream& operator << (std::ostream& out, UnitTest test)
    {
        out << test.toString();
        return out;
    }
    std::string toString()
    {
        return "UnitTest=[nums1: " + vectorToString(originalNums1) 
                + ", m: " + std::to_string(m) + ", nums2: " 
                + vectorToString(nums2) + ", n: " + std::to_string(n) 
                + ", result: " + vectorToString(nums1) + "]";
    }
private:
    std::vector<int> nums1, originalNums1, nums2, expected;
    int m, n;

    std::string vectorToString(std::vector<int> vec)
    {
        std::string result = "[";
        for (size_t i = 0; i < vec.size(); i++)
        {
            result += (std::to_string(vec[i]) + ", ");
        }
        return result + "]";
    }
};

int main()
{
    std::vector<UnitTest> tests {
        UnitTest(std::vector<int> {1, 2, 3, 0, 0, 0}, 3, std::vector<int> {2, 5, 6}, 3, std::vector<int> {1, 2, 2, 3, 5, 6}),
        UnitTest(std::vector<int> {1}, 1, std::vector<int> {}, 0, std::vector<int> {1}),
        UnitTest(std::vector<int> {1, 0}, 1, std::vector<int> {1}, 1, std::vector<int> {1, 1}),
        UnitTest(std::vector<int> {4, 5, 6, 0, 0, 0}, 3, std::vector<int> {1, 2, 3}, 3, std::vector<int> {1, 2, 3, 4, 5, 6}),
        UnitTest(std::vector<int> {4, 0, 0, 0, 0, 0}, 1, std::vector<int> {1, 2, 3, 5, 6}, 5, std::vector<int> {1, 2, 3, 4, 5, 6})
    };
    for (size_t i = 0; i < tests.size(); i++)
    {
        tests[i].test();
    }
    return 0;
}