class Solution 
{
    public int GetWordValue(String word)
    {
        int sum = 0;
        for (int i = 0; i < word.length(); i++)
        {
            sum = sum * 10 + ((int)word.charAt(i) - 97);
        }
        return sum;
    }
    public boolean isSumEqual(String firstWord, String secondWord, String targetWord) 
    {
        int firstSum = GetWordValue(firstWord), secondSum = GetWordValue(secondWord), targetSum = GetWordValue(targetWord);
        return firstSum + secondSum == targetSum;
    }
}
