class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        std::vector<int> answer(nums.size(), 0);
        for (int pos = 0; pos < nums.size(); pos++)
        {
            for (int compare = 0; compare < nums.size(); compare++)
            {
                if ((pos != compare) && (nums[pos] > nums[compare]))
                {
                    answer[pos]++;
                }
            }
        }
        return answer;
    }
};