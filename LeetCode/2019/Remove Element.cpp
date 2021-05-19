class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        for (int position = 0; position < nums.size(); position++)
        {
            if (nums[position] == val)
            {
                nums.erase(nums.begin() + position);
                position--;
            }
        }
        return nums.size();
    }
};