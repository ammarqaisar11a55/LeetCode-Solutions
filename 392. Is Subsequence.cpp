class Solution
{
public:
    bool isSubsequence(string s, string t)
    {

        stack<char> sk;
        reverse(t.begin(), t.end());

        for (char c : s)
        {
            sk.push(c);
        }

        for (int i = 0; i < t.length(); i++)
        {
            if (sk.empty() == false && t[i] == sk.top())
            {
                sk.pop();
            }
        }

        return sk.empty() == true ? 1 : false;
    }
};

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {

        int S_Index = 0;

        for (int i = 0; i < t.length(); i++)
        {
            if (S_Index < s.length() && s[S_Index] == t[i])
            {
                S_Index++;
            }
        }

        return S_Index >= s.length() ? true : false;
    }
};