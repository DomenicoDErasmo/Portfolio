// A slower solution than your standard if-else but I wanted to refactor it to make a cleaner looking solution
// One can optimize this by just using the keys and vals arrays, but I wanted to play around with SortedDictionary
public class Solution 
{
    private void InitDictionary(ref SortedDictionary<int, string> numToLetter)
    {
        int[] keys = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string[] vals = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < keys.Length; i++)
        {
            numToLetter.Add(keys[i], vals[i]);
        }
    }
    
    public string IntToRoman(int num) 
    {
        string answer = "";
        var numToLetter = new SortedDictionary<int, string>();
        InitDictionary(ref numToLetter);
        while (num > 0)
        {
            foreach(var pair in numToLetter.OrderByDescending(p => p.Key)) 
            {
                if(num >= pair.Key)
                {
                    answer += pair.Value;
                    num -= pair.Key;
                    break;
                }
            }
        }
        return answer;
    }
}