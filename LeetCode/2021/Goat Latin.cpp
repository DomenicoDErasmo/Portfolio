class Solution 
{
public:
    bool isVowel(char c)
    {
        return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U');
    }
    
    void goatLatin(std::string& word, int word_count)
    {
        std::string a_string(word_count, 'a');
        if (isVowel(word[0]))
        {
            word.append("ma");
        }
        else
        {
            char first_letter = word[0];
            word.erase(0, 1);
            word.append(1, first_letter);
            word.append("ma");
        }
        word.append(a_string);
    }
    
    string toGoatLatin(string sentence) 
    {
        std::stringstream ss(sentence);
        std::string token, result;
        int word_count = 1;
        while(std::getline(ss, token, ' '))
        {
            goatLatin(token, word_count);
            result.append(token);
            result.append(" ");
            word_count++;
        }
        result.pop_back();
        return result;
    }
};
