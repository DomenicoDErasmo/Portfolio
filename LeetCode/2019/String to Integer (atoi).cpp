class Solution {
public:
    
    bool IsNumber(char input)
    {
        if((input >= '0') && (input <= '9'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    long CheckForSign(std::string& input)
    {
        if(input[0] == '-')
        {
            input.erase(0, 1);
            return -1;
        }
        else if (input[0] == '+')
        {
            input.erase(0, 1);
            return 1;
        }
        else if (IsNumber(input[0]))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    void RemovePrecedingWhiteSpaces(std::string& input)
    {
        while (input[0] == ' ')
        {
            input.erase(0, 1);
        }
    }
    
    void CheckInBounds(long& input)
    {
        if (input < -2147483648)
        {
            input = INT_MIN;
        }
        else if (input > 2147483647)
        {
            input = INT_MAX;
        }
    }
    
    int myAtoi(string str) 
    {
        std::string copy_str = str;
        int sign, str_pos = 0;
        long result = 0;
        
        RemovePrecedingWhiteSpaces(copy_str);
        sign = CheckForSign(copy_str);
        
        
        while ((IsNumber(copy_str[str_pos])) && (str_pos < copy_str.size()))
        {
            char added_int = copy_str[str_pos];
            result = result * 10 + (added_int - 48);
            long test_bounds = result * sign;
            if (test_bounds < -2147483648)
            {
                return INT_MIN;
            }
            else if (test_bounds > 2147483647)
            {
                return INT_MAX;
            }
            str_pos++;
        }
        
        long solution = result * sign;
        
        return solution;
    }
};