class Solution {

public:
    
    bool RepeatChars(std::string string_to_check, char check_for_repeat)
    {
        for (int string_position = 0; string_position <= string_to_check.size(); string_position++)
        {
            if(check_for_repeat == string_to_check[string_position])
            {
                return true;
            }
                
        }
        return false;
    }
    
    int lengthOfLongestSubstring(string s) 
    {
        std::string current_substring;
        char check_for_repeat;
        int max_substring_size = 0;
        for (int string_position = 0; string_position <= s.size(); string_position++)
        {
            check_for_repeat = s[string_position];
            if (RepeatChars(current_substring, check_for_repeat))
            {
                if (current_substring.size() > max_substring_size)
                {
                    max_substring_size = current_substring.size();
                }
                string_position -= (current_substring.size() - 1);
                current_substring.clear();
                current_substring += s[string_position];
            }
            else
            {
                current_substring += check_for_repeat;
            }
        }
        return max_substring_size;
    }
};