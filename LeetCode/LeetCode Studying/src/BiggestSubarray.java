import java.util.*;

public class BiggestSubarray extends Problem
{
    public void GenerateArguments()
    {
        Random rand = new Random();
        int length = rand.nextInt(10) + 10;
        int range = rand.nextInt(10) + 10;
        int[] arr = new int[length];
        for (int i = 0; i < length; i++)
        {
            arr[i] = rand.nextInt(range);
        }
        args.add(arr);
        int window_size = rand.nextInt(2) + 3;
        args.add(window_size);
    }

private void printArray(int[] arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        System.out.print(arr[i] + ", ");
    }
    System.out.print("\n");
}

	public void SolveProblem ()
    {
        int[] arr = (int[]) args.get(0);
        int windowSize = (int) args.get(1);
        int left = 0, right = 0;

        // init currentSum
        int currentSum = 0;
        while (right < windowSize)
        {
            currentSum += arr[right];
            right++;
        }
        int maxSum = currentSum;

        while(right < arr.length - 1)
        {
            currentSum += (arr[right] - arr[left]);
            right++;
            left++;
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
            }
        }

        printArray(arr);
        System.out.println("Window Size: " + windowSize);
        System.out.println("Max Sum: " + maxSum);
    }
}
