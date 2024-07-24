class Solution
{
public:
    string removeStars(string s)
    {

        stack<char> Characters;

        for (int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
                Characters.push(s[i]);

            if (s[i] == '*')
                Characters.pop();
        }

        string ans;

        while (!Characters.empty())
        {
            ans.push_back(Characters.top());
            Characters.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};