public class Solution 
{
    private double GetDistanceFrom(int[] center, int[] point)
    {
        return Math.Sqrt(Math.Pow(center[0] - point[0], 2) + Math.Pow(center[1] - point[1], 2));    
    }
    
    public int[] CountPoints(int[][] points, int[][] queries) 
    {
        int[] pointsInCircles = new int[queries.Length];
        for (int i = 0; i < pointsInCircles.Length; i++)
        {
            int numPointsInCircle = 0;
            for (int j = 0; j < points.Length; j++)
            {
                if (GetDistanceFrom(queries[i], points[j]) <= queries[i][2])
                {
                    numPointsInCircle++;
                }
            }
            pointsInCircles[i] = numPointsInCircle;
        }
        return pointsInCircles;
    }
}