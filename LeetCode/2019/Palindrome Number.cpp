class Solution 
{
public:
    
    std::vector<int> SplitDigitsIntoVector(int x)
    {
        std::vector<int> digits;
        
        while(x > 0)
        {
            digits.push_back(x % 10);
            x /= 10;
        }
        
        return digits;
    }
    
    bool isPalindrome(int x) 
    {   
        
        if (x < 0)
        {
            return false;
        }
        
        std::vector<int> digits = SplitDigitsIntoVector(x);
        int middle_digit = digits.size() / 2;
        
        // TODO: flesh this out, initialize the upper and lower digit values
        for (int digit_position = 0; digit_position < middle_digit; digit_position++)
        {
            if (digits[digit_position] != digits[digits.size() - digit_position - 1])
            {
                return false;
            }
        }
        
        return true;
    }
};