class Solution {
private:
    int unsignedDivide(int dividend, int divisor) {
        int q = 0, r = 0;
        for (int i = 31; i >= 0; i--) {
            r <<= 1;
            r |= (dividend >> i) & 1;
            if (r >= divisor) {
                r -= divisor;
                q |= (1 << i);
            }
        }
        return q;
    }
    
    int division(int dividend, int divisor) {
        bool negative = (divisor < 0) != (dividend < 0);
        if (divisor < 0)
            divisor = flipSign(divisor);
        
        if (dividend < 0)
            dividend = flipSign(dividend);
        
        int quotient = unsignedDivide(dividend, divisor);
        if (negative)
            quotient = flipSign(quotient);
        
        return quotient;
    }
    
    int flipSign(int n) {
        n = ~n;
        if (n < INT_MAX)
            return n + 1;
        return n;
    }
    
    bool willOverflow(int n, int m) {
        return n < (INT_MIN + m) || n > (INT_MAX - m);
    }
    
    bool isPowerOf2(int n) {
        if (n < 0)
            n = flipSign(n);
        return (n & (n - 1)) == 0;
    }
        
public:
    int divide(int dividend, int divisor) {
		// INT_MIN is the largest possible integer. Unless the dividend = INT_MIN, 
		// divisor = INT_MIN is automatically zero.
        if (divisor == INT_MIN && dividend != INT_MIN)
            return 0;
        
		// Perform division for non-obvious use cases.
        int quotient = division(dividend, divisor);

        // Watch out for final edge case
        int offset = 0;
        if (dividend == INT_MIN) {
            // If divisor is a power of 2 and dividend INT_MIN, quotient is off by 1.
            offset = isPowerOf2(divisor);
            
            // if quotient + offset will overflow, reset the offset to 0.
            if (willOverflow(quotient, offset))
                offset = 0;
            else if (quotient < 0)
                offset = flipSign(offset);
        }
        
        return quotient + offset;
    }
};