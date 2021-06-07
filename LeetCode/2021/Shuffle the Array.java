class Solution 
{
    public int[] shuffle(int[] nums, int n) 
    {
        int[] mergedArray = new int[nums.length];
        for (int i = 0; i < n; i++)
        {
            mergedArray[2*i] = nums[i];
            mergedArray[2*i + 1] = nums[i + n];
        }
        return mergedArray;
    }
}