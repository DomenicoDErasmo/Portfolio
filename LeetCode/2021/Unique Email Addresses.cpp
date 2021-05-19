class Solution {
public:
    
    bool IsPeriod(char a)
    {
        return a == '.' ? 1 : 0;
    }
    
    void RemoveAfterPlus(std::string& email, int at_pos)
    {
        for (int i = 0; i < at_pos; i++)
        {
            if (email[i] == '+')
            {
                email.erase(i, at_pos - i);
                return;
            }
        }
    }
    
    void RemovePeriods(std::string& email, int at_pos)
    {
        for (int i = 0; i < at_pos; i++)
        {
            if (email[i] == '.')
            {
                email.erase(i, 1);
                i--;
                at_pos--;
            }
        }
    }
    
    void ParseEmailSalting(std::vector<std::string>& emails)
    {
        for (int i = 0; i < emails.size(); i++)
        {
            int at_pos = emails[i].find('@');
            RemoveAfterPlus(emails[i], at_pos);
            
            at_pos = emails[i].find('@');
            RemovePeriods(emails[i], at_pos);
        }
    }
    
    void RemoveDuplicateEmails(std::vector<std::string>& emails)
    {
        for(int i = 0; i < emails.size(); i++)
        {
            for(int j = i+1; j < emails.size(); j++)
            {
                if(emails[j] == emails[i])
                {
                    emails.erase(emails.begin() + j);
                    j--;
                }
            }
        }
    }
    
    int numUniqueEmails(vector<string>& emails) 
    {
        std::vector<std::string> unique_emails;
        ParseEmailSalting(emails);
        RemoveDuplicateEmails(emails);
        return emails.size();
    }
};