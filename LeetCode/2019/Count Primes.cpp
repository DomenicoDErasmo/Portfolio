class Solution {
public:
    
    bool IsPrime(int candidate)
    {
        for (int possible_factor = 2; possible_factor < (std::sqrt(candidate) + 1); possible_factor++)
        {
            if (candidate % possible_factor == 0)
            {
                // std::cout << candidate << " is a composite number.\n";
                return false;
            }
        }
        // std::cout << candidate << " is a prime number.\n";
        return true;
    }
    
    int countPrimes(int n) 
    {
        if (n < 2)
        {
            return 0;
        }
        else if (n > 2)
        {
            int number_of_primes = 0;
            for (int candidate = 3; candidate < n; candidate++)
            {
                if (IsPrime(candidate))
                {
                    number_of_primes++;
                }
            }
            return number_of_primes + 1;
        }
        return 0;
    }
};