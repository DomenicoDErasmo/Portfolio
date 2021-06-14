public class Solution 
{
    public int MinPartitions(string n) 
    {
        int max_strings = 0;
        for (int i = 0; i < n.Length; i++)
        {
            
            if (n[i] == '9')
            {
                return 9;
            }
            else if (n[i] - 48 > max_strings)
            {
                max_strings = n[i]-48;
            }
        }
        return max_strings;
    }
}
