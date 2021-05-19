class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) 
    {
        if (arr.size() < 3)
        {
            return false;
        }
        for (int chain_start = 0; chain_start < arr.size() - 2; chain_start++)
        {
            if ((arr[chain_start] % 2 == 1) and (arr[chain_start + 1] % 2 == 1) and (arr[chain_start + 2] % 2 == 1))
            {
                return true;
            }
        }
        return false;
    }
};