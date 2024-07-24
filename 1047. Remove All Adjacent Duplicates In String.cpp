class Solution
{
public:
    string removeDuplicates(string s)
    {

        stack<char> unique;

        for (int i = 0; i < s.length(); i++)
        {
            if (!unique.empty() && unique.top() == s[i])
            {
                unique.pop();
            }
            else
            {
                unique.push(s[i]);
            }
        }

        string ans;

        while (!unique.empty())
        {
            ans += unique.top();
            unique.pop();
        }

        reverse(begin(ans), end(ans));

        return ans;
    }
};