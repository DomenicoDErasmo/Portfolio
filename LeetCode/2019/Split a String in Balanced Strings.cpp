class Solution {
public:
    
    int charToInt(char c)
    {
        switch(c)
        {
            case 'L':
                return 1;
                break;
            case 'R':
                return -1;
                break;
            default:
                return 0;
                break;
        }
    }
    
    int balancedStringSplit(string s) 
    {
        int number_of_substrings = 0;
        int LR_balance = 0;
        for (size_t s_index = 0; s_index < s.size(); s_index++)
        {
            char current_letter = s[s_index];
            LR_balance += charToInt(current_letter);
            if (LR_balance == 0)
            {
                number_of_substrings++;
                LR_balance = 0;
            }
        }
        return number_of_substrings;
    }
};