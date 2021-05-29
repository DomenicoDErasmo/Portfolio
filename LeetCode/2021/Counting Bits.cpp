class Solution 
{
    public int[] countBits(int n) 
    {
        int[] answer = new int[n+1];
        answer[0] = 0;
        for (int i = 0; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                answer[i] = answer[i / 2];
            }
            else
            {
                answer[i] = answer[i - 1] + 1;
            }
        }
        return answer;
    }
}
