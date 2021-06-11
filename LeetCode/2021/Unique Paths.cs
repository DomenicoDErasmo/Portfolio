public class Solution 
{
    private void PrintMatrix(int[,] matrix)
    {
        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
            {
                System.Console.Write(matrix[i, j] + ", ");
            }
            System.Console.WriteLine("");
        }
    }
    
    public int UniquePaths(int m, int n) 
    {
        int [,] uniquePaths = new int[m, n];
        for (int i = 0; i < m; i++)
        {
            uniquePaths[i, 0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            uniquePaths[0, i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                uniquePaths[i, j] = uniquePaths[i-1, j] + uniquePaths[i, j-1];
            }
        }
        // PrintMatrix(uniquePaths);
        return uniquePaths[m-1, n-1];
    }
}
