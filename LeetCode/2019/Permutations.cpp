class Solution {
public:
    
    void swap(std::vector<int>& nums, int first, int second)
    {
        int temp = nums[first];
        nums[first] = nums[second];
        nums[second] = temp;
    }
    
    void FindPermutations(std::vector<std::vector<int>>& result, std::vector<int>& nums, int beginning, int end)
    {
        if (beginning == end)
        {
            result.push_back(nums);
        }
        else
        {
            for (int counter = beginning; counter < end; counter++)
            {
                swap(nums, beginning, counter);
                FindPermutations(result, nums, beginning + 1, end);
                swap(nums, beginning, counter);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        std::vector<std::vector<int>> result;
        FindPermutations(result, nums, 0, nums.size());
        return result;
    }
};