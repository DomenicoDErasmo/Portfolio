class Solution {
public:
    
    int DigitSum(std::vector<int> digits)
    {
        int sum = 0;
        for (int digit_pos = 0; digit_pos < digits.size(); digit_pos++)
        {
            sum += digits[digit_pos];
        }
        return sum;
    }
    
    int DigitProduct(std::vector<int> digits)
    {
        int product = 1;
        for (int digit_pos = 0; digit_pos < digits.size(); digit_pos++)
        {
            product *= digits[digit_pos];
        }
        return product;
    }
    
    int GetNumberOfDigits(int number)
    {
        int number_of_digits = 0;
        while (number > 0)
        {
            number /= 10;
            number_of_digits++;
        }
        //std::cout << "The number of digits is " << number_of_digits << ".\n";
        return number_of_digits;
    }
    
    std::vector<int> GetDigits(int number)
    {
        std::vector<int> digits;
        int num_digits = GetNumberOfDigits(number);
        for (int digit_pos = num_digits-1; digit_pos >= 0; digit_pos--)
        {
            //std::cout << "digit_pos is " << digit_pos << ", number is " << number << ".\n";
            int place_divisor = pow(10,digit_pos);
            //std::cout << "place_divisor is " << place_divisor << ".\n";
            int digit = number/place_divisor;
            //std::cout << "digit is " << digit << ".\n";
            digits.push_back(digit);
            number = number % (place_divisor);
            //std::cout << "The " << digits.size() << "th number is " << digits.back() << ".\n";
        }
        return digits;
    }
    
    int subtractProductAndSum(int n) 
    {
        std::vector<int> digits = GetDigits(n);
        return (DigitProduct(digits) - DigitSum(digits));
    }
};