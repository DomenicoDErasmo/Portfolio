class Solution 
{
    public int getWealthOf(int[] customerAccounts)
    {
        int wealth = 0;
        for (int i = 0; i < customerAccounts.length; i++)
        {
            wealth += customerAccounts[i];
        }
        return wealth;
    }
    
    public int maximumWealth(int[][] accounts) 
    {
        int max = getWealthOf(accounts[0]);
        for (int i = 1; i < accounts.length; i++)
        {
            int currentWealth = getWealthOf(accounts[i]);
            if (currentWealth > max)
            {
                max = currentWealth;
            }
        }
        return max;
    }
}