public class Solution 
{
    private int GetMin(int left, int right)
    {
        return left < right ? left : right;
    }
    private int GetShortestDistance(string s, char c, int i)
    {
        int left = i, right = i, min = s.Length;
        bool stillSearching = true;
        while(stillSearching)
        {
            if (s[left] == c || s[right] == c)
            {
                stillSearching = false;
            }
            else
            {
                if (left > 0)
                {
                    left--;
                }
                else
                {
                    while(s[right] != c)
                    {
                        right++;
                    }
                    return right - i;
                }
                if (right < s.Length - 1)
                {
                    right++;
                }
                else
                {
                    while(s[left] != c)
                    {
                        left--;
                    }
                    return i - left;
                }
            }
        }
        return GetMin(i - left, right - i);
    }
    
    public int[] ShortestToChar(string s, char c) 
    {
        int[] minDistances = new int[s.Length];
        for (int i = 0; i < minDistances.Length; i++)
        {
            minDistances[i] = GetShortestDistance(s, c, i);
        }
        return minDistances;
    }
}