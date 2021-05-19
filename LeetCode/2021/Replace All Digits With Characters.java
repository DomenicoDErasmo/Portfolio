class Solution 
{
    public char shift(char c, int x)
    {
        return (char)((int)(c) + x);
    }
    
    public String replaceDigits(String s) 
    {
        StringBuffer buffer = new StringBuffer(s.length() + 1);
        buffer.insert(0, s);
        int len = buffer.length();
        for (int i = 1; i < len; i = i + 2)
        {
            int shift_num = Character.getNumericValue(buffer.charAt(i));
            buffer.deleteCharAt(i);
            buffer.insert(i, shift(buffer.charAt(i - 1), shift_num));
        }
        return buffer.toString();
    }
}