class Solution {
public:
    
    bool IsClosingParentheses(char input)
    {
        switch(input)
        {
            case ')':
            case '}':
            case ']':
                return true;
                break;
            default:
                return false;
                break;
        }
    }
    
    bool DoesCloseParentheses(std::vector<char> parentheses_stack)
    {
        std::vector<char>::reverse_iterator reverse_stack = parentheses_stack.rbegin();
        if (((reverse_stack[1] == '(') && (reverse_stack[0] == ')')) ||
            ((reverse_stack[1] == '{') && (reverse_stack[0] == '}')) ||
            ((reverse_stack[1] == '[') && (reverse_stack[0] == ']')))
        {
            return true;
        }
        
        else
        {
            return false;
        }
        
    }
    
    bool isValid(string s) 
    {
        std::vector<char> parentheses_stack;
        
        char added_char = s[0];
        if (s.empty())
        {
            return true;
        }
        else if (s.size() % 2 == 1)
        {
            return false;
        }
        else if (IsClosingParentheses(added_char))
        {
            return false;
        }
        else
        {
            parentheses_stack.push_back(added_char);
            if (s.size() == 1)
            {
                return false;
            }
        }
        
        for (int string_index = 1; string_index < s.size(); string_index++)
        {
            added_char = s[string_index];
            parentheses_stack.push_back(added_char);
            if (IsClosingParentheses(added_char))
            {
                if (DoesCloseParentheses(parentheses_stack))
                {
                    parentheses_stack.pop_back();
                    parentheses_stack.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }
        
        if (!parentheses_stack.empty())
        {
            return false;
        }
        else
        {
            return true;
    
        }
    }
};