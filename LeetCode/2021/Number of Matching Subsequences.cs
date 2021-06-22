public class Solution 
{
    private bool ContainsSubsequence(string s, string word)
    {
        int j = 0;
        for (int i = 0; i < s.Length; i++)
        {
            if (j == word.Length)
            {
                return true;
            }
            else if (s[i] == word[j])
            {
                j++;
            }
        }
        return j == word.Length;
    }
    
    public int NumMatchingSubseq(string s, string[] words) 
    {
        int subsequences = 0;
        var map = new Dictionary<string, bool>();
        for (int i = 0; i < words.Length; i++)
        {
            bool isSubseq = false;
            if (map.TryGetValue(words[i], out isSubseq))
            {
                if (isSubseq)
                {
                    subsequences++;
                }
            }
            else
            {
                isSubseq = ContainsSubsequence(s, words[i]);
                map.Add(words[i], isSubseq);
                if (isSubseq)
                {
                    subsequences++;
                }
            }
        }
        return subsequences;
    }
}