public class MergedTimes extends Problem
{
    private void PrintListOfLists(int[][] arr)
    {
        System.out.print("[");
        for (int i = 0; i < arr.length; i++)
        {
            System.out.print("[" + arr[i][0] + ", " + arr[i][1] + "], ");
        }
        System.out.print("]\n");
    }

    public void GenerateArguments()
    {
        int length = rand.nextInt(5) + 10;
        int [][] list = new int[length][2];
        for (int i = 0; i < length; i++)
        {
            list[i][0] = rand.nextInt(4*length);
            list[i][1] = rand.nextInt(4*length) + list[i][0];
        }
        args.add(list);
    }

    public void SolveProblem()
    {
        /*
        steps:
        1) Sort all intervals in increasing order of start time.
        2) Traverse sorted intervals starting from first interval, 
            do following for every interval.
                a) If current interval is not first interval and it 
                    overlaps with previous interval, then merge it with
                    previous interval. Keep doing it while the interval
                    overlaps with the previous one.         
                b) Else add current interval to output list of intervals.
        */
        int[][] arr = (int[][])args.get(0);
        PrintListOfLists(arr);
    }
}
