class Solution
{
public:
    string makeGood(string s)
    {

        stack<char> sk;

        for (int i = 0; i < s.length(); i++)
        {
            if (sk.empty())
            {
                sk.push(s[i]);
                continue;
            }

            char stacktop = sk.top();

            if (isupper(stacktop) && islower(s[i]) && tolower(stacktop) == s[i])
            {
                sk.pop();
            }
            else if (islower(stacktop) && isupper(s[i]) && toupper(stacktop) == s[i])
            {
                sk.pop();
            }
            else
            {
                sk.push(s[i]);
            }
        }

        s.clear();

        while (!sk.empty())
        {
            s += sk.top();
            sk.pop();
        }

        reverse(s.begin(), s.end());

        return s;
    }
};