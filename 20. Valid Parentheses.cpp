class Solution
{
public:
    bool isValid(string s)
    {

        stack<char> Parentheses;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{')
            {
                Parentheses.push(s[i]);
                continue;
            }
            else if (Parentheses.empty())
            {
                return false;
            }
            else if (!Parentheses.empty() && Parentheses.top() != '[' && s[i] == ']')
            {
                return false;
            }
            else if (!Parentheses.empty() && Parentheses.top() != '{' && s[i] == '}')
            {
                return false;
            }
            else if (!Parentheses.empty() && Parentheses.top() != '(' && s[i] == ')')
            {
                return false;
            }
            else
                Parentheses.pop();
        }

        return Parentheses.empty();
    }
};