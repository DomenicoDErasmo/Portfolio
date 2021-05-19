class Solution {
public:
    
    bool DoesContainSubstring(std::string haystack, std::string needle, int haystack_index)
    {
        for (int needle_index = 0; needle_index < needle.size(); needle_index++)
        {
            if (haystack[haystack_index + needle_index] != needle[needle_index])
            {
                return false;
            }
        }
        return true;
    }
    
    int strStr(string haystack, string needle) 
    {
        if (needle.empty())
        {
            return 0;
        }
        else if (haystack.empty())
        {
            return -1;
        }
        else if (needle.size() > haystack.size())
        {
            return -1;
        }
        else
        {
            for (int haystack_index = 0; haystack_index < haystack.size() - needle.size() + 1; haystack_index++)
            {
                if (haystack[haystack_index] == needle[0])
                {
                    if (DoesContainSubstring(haystack, needle, haystack_index))
                    {
                        return haystack_index;
                    }
                }
            }
            return -1;
        }
    }
};