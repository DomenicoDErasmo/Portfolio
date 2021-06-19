public class Solution 
{
    public int Max(int left, int right)
    {
        return left > right ? left : right;    
    }
    
    public int MaxSubArray(int[] nums) 
    {
        int sum = 0, maxSum = Int32.MinValue;
        for (int i = 0; i < nums.Length; i++)
        {
            sum += nums[i];
            maxSum = Max(sum, maxSum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxSum;
    }
}