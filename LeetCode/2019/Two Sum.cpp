class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int first_number, second_number;
        for(first_number = 0; first_number < nums.size(); first_number++)
        {
            for(second_number = 0; second_number < nums.size(); second_number++)
            {
                if ((nums[first_number] + nums[second_number] == target) && (first_number != second_number))
                {
                    vector<int> result = {first_number, second_number};
                    return result;
                }
            }
        }
        return {-1};
    }
};