class Solution {
public:
    
    bool canMakeArithmeticProgression(std::vector<int>& arr) 
    {
        // need to review sorting algorithms! can do O(N^2) and maybe MergeSort, need to review Heap, Quick, Counting
        std::sort(arr.begin(), arr.end());
        int last_diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++)
        {
            int diff = arr[i] - arr[i-1];
            if (diff != last_diff)
            {
                return false;
            }
        }
        return true;
    }
};