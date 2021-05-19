class Solution {
public:
    
    int GetSmallestLength(std::vector<string> strs)
    {
        int min = strs[0].size();
        for (int string_index = 1; string_index < strs.size(); string_index++)
        {
            if (strs[1].size() < strs[0].size())
            {
                min = strs[1].size();
            }
        }
        return min;
    }
    
    string longestCommonPrefix(vector<string>& strs) 
    {
        
        if((strs.size() == 0) || (strs[0].size() == 0))
        {
            return "";
        }
        
        std::string result;
        int min_length = GetSmallestLength(strs);
        
        for (int char_index = 0; char_index < min_length; char_index++)
        {
            char candidate = strs[0][char_index];
            for (int string_index = 0; string_index < strs.size(); string_index++)
            {
                if (strs[string_index][char_index] != candidate)
                {
                    return result;
                }
            }
            result.append(1, candidate);
        }
        return result;
    }
};