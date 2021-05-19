class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = -1;
        int r = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
            {
                l = i;
                for(int j = l; j< nums.size(); j++)
                {
                    if(nums[i] != nums[j])
                    {
                        break;
                    }
                    r = j;
                }
                break;
            }
        }
        return {l,r};
    }
};