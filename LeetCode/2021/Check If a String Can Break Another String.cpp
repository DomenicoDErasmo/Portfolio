class Solution 
{
public:
    bool checkIfCanBreak(string s1, string s2) 
    {
        // sort the strings
        // check if one can break the other
        bool left_breaks = true, right_breaks = true;
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());
        for (int i = 0; i < s1.length(); i++)
        {
            if(s1[i] < s2[i])
            {
                right_breaks = false;
            }
            if (s1[i] > s2[i])
            {
                left_breaks = false;
            }
        }
        return left_breaks or right_breaks;
    }
};
