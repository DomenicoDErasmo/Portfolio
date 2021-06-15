import java.util.*;

public class BalancedParentheses extends Problem
{
    private char GetParenthesis(int num)
    {
        switch(num)
        {
            case 0:  return '{';
            case 1:  return '(';
            case 2:  return '[';
            case 3:  return '}';
            case 4:  return ')';
            case 5:  return ']';
            default: return '\0';
        }           
    }

    public void GenerateArguments()
    {
        Random rand = new Random();
        int length = rand.nextInt(5) + 10;
        StringBuffer buffer = new StringBuffer();
        for (int i = 0; i < length; i++)
        {
            buffer.append(GetParenthesis(rand.nextInt(6)));
        }
        args.add(buffer.toString());
    }

    private boolean IsBalanced()
    {
        String inputString = (String)args.get(0);
        Stack<Character> s = new Stack<Character>();

        for (int i = 0; i < inputString.length(); i++)
        {
            char ch = inputString.charAt(i);
            if(ch == '(' || ch == '{' || ch == '[')
            {
                s.push(ch);
            }
            else if(ch == ')')
            {
                if (!s.empty() && s.peek() == '(')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else if(ch == '}')
            {
                if (!s.empty() && s.peek() == '{')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else if(ch == ']')
            {
                if (!s.empty() && s.peek() == '[')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return s.empty();
    }

    public void SolveProblem()
    {
        boolean isBalanced = IsBalanced();    
        System.out.println((String)args.get(0));
        System.out.println(isBalanced ? "The string is balanced" : "The string is not balanced");
    }
}
