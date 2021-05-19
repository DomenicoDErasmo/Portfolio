class Solution {
public:
    int fib(int n) 
    {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1 or n == 2)
        {
            return 1;
        }
        else
        {
            int answer = 1;
            int one_back = 1;
            int two_back = 1;
            for (int i = 2; i < n; i++)
            {
                answer = one_back + two_back;
                two_back = one_back;
                one_back = answer;
            }
            return answer;
        }
    }
};