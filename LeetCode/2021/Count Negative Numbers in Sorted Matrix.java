class Solution 
{
    private int getRowNegatives(int[] row)
    {
        int negatives = 0;
        for (int i = 0; i < row.length; i++)
        {
            if (row[i] < 0)
            {
                return row.length - i;
            }
        }
        return negatives;
    }
    public int countNegatives(int[][] grid) 
    {
        int negatives = 0;
        for (int i = 0; i < grid.length; i++)
        {
            negatives += getRowNegatives(grid[i]);
        }
        return negatives;
    }
}
