class Solution 
{
public:
    int climbStairs(int n) 
    {
        // another way of asking for the nth Filbonacci number!
        if (n == 1)
        {
            return 1;
        }
        int* distinctWays = new int[n];
        distinctWays[0] = 1;
        distinctWays[1] = 2;
        for (int i = 2; i < n; i++)
        {
            distinctWays[i] = distinctWays[i-1] + distinctWays[i-2];
        }
        return distinctWays[n-1];
    }
};
