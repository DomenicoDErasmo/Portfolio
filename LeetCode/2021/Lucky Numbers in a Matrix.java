class Solution 
{
    public ArrayList<Integer> getMins(int[][] matrix)
    {
        ArrayList<Integer> mins = new ArrayList<Integer>();
        for (int i = 0; i < matrix.length; i++)
        {
            int min = matrix[i][0];
            for (int j = 0; j < matrix[i].length; j++)
            {
                if (matrix[i][j] < min)
                {
                    min = matrix[i][j];
                }
            }
            mins.add(min);
        }
        return mins;
    }
    
    public ArrayList<Integer> getMaxes(int[][] matrix)
    {
        ArrayList<Integer> maxes = new ArrayList<Integer>();
        for (int i = 0; i < matrix[0].length; i++)
        {
            int max = matrix[0][i];
            for (int j = 0; j < matrix.length; j++)
            {
                if (matrix[j][i] > max)
                {
                    max = matrix[j][i];
                }
            }
            maxes.add(max);
        }
        return maxes;
    }
    
    public ArrayList<Integer> getIntersect(ArrayList<Integer> mins, ArrayList<Integer> maxes)
    {
        ArrayList<Integer> intersect = new ArrayList<Integer>();
        for (int i = 0; i < mins.size(); i++)
        {
            if (maxes.contains(mins.get(i)))
            {
                intersect.add(mins.get(i));
            }
        }
        return intersect;
    }
    
    public List<Integer> luckyNumbers (int[][] matrix) 
    {
        // idea:
        //  get mins of rows
        //  get maxes of cols
        //  return vals in both
        ArrayList<Integer> mins = getMins(matrix);
        ArrayList<Integer> maxes = getMaxes(matrix);
        return getIntersect(mins, maxes);
    }
}
