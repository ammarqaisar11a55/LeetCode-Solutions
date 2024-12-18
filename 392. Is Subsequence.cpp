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