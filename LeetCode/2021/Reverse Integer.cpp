class Solution 
{
public:
    
  void GetDigits(std::vector<int>& digits, int x)
  {
    while(x != 0)
    {
      digits.push_back(x % 10);
      x /= 10;
    }
  }
    
  void PrintVector(std::vector<int> vec)
  {
    for (int i = 0; i < vec.size(); i++)
    {
      std::cout << vec[i] << ", ";
    }
    std::cout << std::endl;
  }
    
  long ReverseDigits(std::vector<int> digits)
  {
    long num = digits[0];
    for (int i = 1; i < digits.size(); i++)
    {
      num *= 10;
      num += digits[i];
    }
     // std::cout << "num = " << num << ", int(num) = " << int(num) << std::endl;
     return num;
  }
    
  int reverse(int x) 
  {
    bool is_negative = false;
    long num = x;
    if (x < 0)
    {
      is_negative =  true;
      num = -1 * num;
    }
    else if (x < 10)
    {
      return x;
    }
    std::vector<int> digits;
    GetDigits(digits, num);
    num = ReverseDigits(digits);
    // PrintVector(digits);
    // std::cout << "num = " << num << std::endl;
    if (is_negative)
    {
      return (num < -2147483648 or num > 2147483648) ? 0 : -1 * num;
    }
    else
    {
      return num > 2147483647 ? 0 : num;
    }
    
  }
};