class Solution {
public:
    double myPow(double x, int n) 
    {
        if (x == 1)
        {
            return 1;
        }
        
        else if (x == -1)
        {
            if ((n % 2 == 0) || (-n % 2 == 0))
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if (((x < 0.005) && (x > 0) && (n > 3)) || ((x > 0) && n < -20))
        {
            return 0;
        }
        
        else if (n > 0)
        {
            double exponent = x;
            for (int mult_iter = 1; mult_iter < n; mult_iter++)
            {
                x *= exponent;
            }
            
            return x;
        }
        
        else if (n == 0)
        {
            return 1;
        }
        
        else
        {
            double result = 1/x;
            for (int mult_iter = -1; mult_iter > n; mult_iter--)
            {
                result /= x;
            }
            
            return result;
        }
    }
};