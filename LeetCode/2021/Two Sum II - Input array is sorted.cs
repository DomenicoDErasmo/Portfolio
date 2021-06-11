public static class IntArrayExtension
{
    public static int GetIndex(this int[] nums, int target)
    {
        int left = 0, right = nums.Length;
        while (left <= right && left < nums.Length)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return -1;
    }
}

public class Solution 
{
    private void PrintArray(int[] arr)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            System.Console.Write(arr[i] + ", ");
        }
        System.Console.WriteLine("");
    }
    public int[] TwoSum(int[] nums, int target)
    {
        for (int i = 0; i < nums.Length; i++)
        {
            int second_num = nums.GetIndex(target - nums[i]);
            if (second_num != -1 && second_num != i)
            {
                return (i < second_num) ? new int[2]{i + 1, second_num + 1} : new int[2]{second_num + 1, i + 1};
            }
        }
        
        return new int[2]{-1, -1};
    }
}
