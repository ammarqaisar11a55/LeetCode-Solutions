class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {

        stack<char> SS, TT;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '#' && !SS.empty())
            {
                SS.pop();
            }
            else if (s[i] != '#')
            {
                SS.push(s[i]);
            }
        }

        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] == '#' && !TT.empty())
            {
                TT.pop();
            }
            else if (t[i] != '#')
            {
                TT.push(t[i]);
            }
        }

        if (SS.size() != TT.size())
            return false;

        while (!SS.empty() && !TT.empty())
        {

            if (SS.top() != TT.top())
                return false;

            SS.pop();
            TT.pop();
        }

        return true;
    }
};