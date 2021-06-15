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
            arr[i] = rand.nextInt(range) - 2 * range;
        }
        args.add(arr);
    }
	public void SolveProblem ()
    {
        int[] arr = (int[]) args.get(0);
    }
}
