class Solution 
{
    private void printMatrix(int[][] matrix)
    {
        for (int i = 0; i < matrix.length; i++)
        {
            for (int j = 0; j < matrix[i].length; j++)
            {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.print("\n");
        }
    }
    
    private void initMatrix(int[][] num_moves)
    {
        for (int i = 0; i < num_moves.length; i++)
        {
            num_moves[i][num_moves[0].length-1] = 1;
        }
        for (int i = 0; i < num_moves[0].length; i++)
        {
            num_moves[num_moves.length-1][i] = 1;
        }
    }
    
    private void fillMatrix(int[][] num_moves)
    {
        for (int i = num_moves.length-2; i >= 0; i--)
        {
            for (int j = num_moves[0].length-2; j >= 0; j--)
            {
                num_moves[i][j] = num_moves[i+1][j] + num_moves[i][j+1];
            }
        }
    }
    
    public int uniquePaths(int m, int n)
    {
        // idea: set up an mxn matrix to refer to for previous values
        int[][] num_moves = new int[m][n];
        initMatrix(num_moves);
        fillMatrix(num_moves);
        return num_moves[0][0];
    }
}
