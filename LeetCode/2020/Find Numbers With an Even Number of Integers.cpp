class Solution {
public:
    
    bool IsEven(int number)
    {
        if (number % 2 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool HasEvenNumberOfDigits(int input)
    {
        int number_of_digits = 0;
        while (input > 0)
        {
            input /= 10;
            number_of_digits++;
        }
        
        return IsEven(number_of_digits);
        
    }
    
    int findNumbers(vector<int>& nums) 
    {
        int num_even_digits = 0;
        for (int nums_pos = 0; nums_pos < nums.size(); nums_pos++)
        {
            if (HasEvenNumberOfDigits(nums[nums_pos]))
            {
                num_even_digits++;
                std::cout << nums[nums_pos] << " has an even number of digits.\n";
            }
        }
        return num_even_digits;
    }
};