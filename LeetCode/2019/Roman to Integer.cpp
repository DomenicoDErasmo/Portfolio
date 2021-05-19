class Solution {
public:
    
    // Steps
    // 1. Convert the string's letters into a vector of integers
    // 2. Add each value to a subtotal starting at 0
    // 3. If a number is greater than the preceding number, add it and subtract the preceding number twice
    
    int LetterToValue(char letter)
    {
        switch (letter)
        {
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
            case 'X':
                return 10;
                break;
            case 'L':
                return 50;
                break;
            case 'C':
                return 100;
                break;
            case 'D':
                return 500;
                break;
            case 'M':
                return 1000;
                break;
            default:
                return 0;
                break;
        }
    }
    
    std::vector<int> ConvertToIntVector(std::string input)
    {
        std::vector<int> string_integers;
        for (int string_position = 0; string_position < input.size(); string_position++)
        {
            char letter = input[string_position];
            string_integers.push_back(LetterToValue(letter));
        }
        return string_integers;
    }
    
    int romanToInt(string s) 
    {
        std::vector<int> converted_letters = ConvertToIntVector(s);
        int total = 0;
        total += converted_letters[0];
        for (int vector_position = 1; vector_position < converted_letters.size(); vector_position++)
        {
            total += converted_letters[vector_position];
            if (converted_letters[vector_position] > converted_letters[vector_position - 1])
            {
                total -= (2 * converted_letters[vector_position - 1]);
            }
        }
        return total;
    }
};