class Solution 
{
    public int sumPrevK(int[] code, int k, int start)
    {
        int result = 0;
        for (int i = 1; i <= k; i++)
        {
            int next = ((start - i) % code.length) + ((start - i) < 0 ? code.length : 0);
            System.out.println(next);
            result += code[next];
        }
        return result;
    }
    public int sumNextK(int[] code, int k, int start)
    {
        int result = 0;
        for (int i = 1; i <= k; i++)
        {
            result += code[(start + i) % code.length];
        }
        return result;
    }
    public int[] decryptLast(int[] code, int k)
    {
        int [] decrypted = new int[code.length];
        for (int i = 0; i < code.length; i++)
        {
            decrypted[i] = sumPrevK(code, k, i);
        }
        return decrypted;
    }
    public int[] decryptNext(int[] code, int k)
    {
        int[] decrypted = new int[code.length];
        for (int i = 0; i < code.length; i++)
        {
            decrypted[i] = sumNextK(code, k, i);
        }
        return decrypted;
    }
    public int[] decrypt(int[] code, int k) 
    {
        if (k < 0)
        {
            return decryptLast(code, -1 * k);
        }
        else if (k == 0)
        {
            return new int[code.length];
        }
        else
        {
            return decryptNext(code, k);
        }
    }
}