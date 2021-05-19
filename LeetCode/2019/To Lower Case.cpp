class Solution {
public:
    
    bool IsUpperCase(char current_char)
    {
        if (current_char >= 65 && current_char <= 90)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    string toLowerCase(string str) 
    {
        std::string input_string = str;
        for (int str_index = 0; str_index < str.size(); str_index++)
        {
            char current_char = input_string[str_index];
            if (IsUpperCase(current_char))
            {
                current_char += 32;
                input_string[str_index] = current_char;
            }
        }
        return input_string;
    }
};