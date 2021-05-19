class Solution {
public:
    
    bool FoundInJewel(char stone, std::string J)
    {
        for (size_t jewel_index = 0; jewel_index < J.size(); jewel_index++)
        {
            if (stone == J[jewel_index])
            {
                return true;
            }
        }
        return false;
    }
    
    int numJewelsInStones(string J, string S) 
    {
        int number_of_jewels = 0;
        for (size_t stone_index = 0; stone_index < S.size(); stone_index++)
        {
            char stone = S[stone_index];
            if (FoundInJewel(stone, J))
            {
                number_of_jewels++;
            }
        }
        return number_of_jewels;
    }
};