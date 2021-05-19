class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int length = 0;
        
        std::cout << "The size of s is " << s.size() << ".\n";
        
        if (s.size() == 0)
        {
            return 0;
        }
        else
        {
            for (int position = 0; position < s.size(); position++)
            {
                char candidate = s[position];
                int last_letter = 0;
                if ((candidate != ' '))
                {
                    length++;
                    last_letter = position;
                }
                else
                {
                    if (position < s.size() - 1)
                    {
                        char next_candidate = s[position + 1];
                        if (next_candidate != ' ')
                        {
                            length = 0;
                            last_letter = 0;
                        }
                    }
                }
            }
        }
        return length;
    }
};