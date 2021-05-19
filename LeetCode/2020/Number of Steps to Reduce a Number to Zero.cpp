class Solution {
public:
    int numberOfSteps (int num) 
    {
        bool num_not_zero = true;
        int total_steps = 0;
        while(num_not_zero)
        {
            if(num == 0)
            {
                num_not_zero = false;
                break;
            }
            if(num % 2 == 1)
            {
                --num;
                ++total_steps;
            }
            else
            {
                num /= 2;
                ++total_steps;
            }
        }
        return total_steps;
    }
};