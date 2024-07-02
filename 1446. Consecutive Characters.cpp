class Solution
{
public:
    int maxPower(string s)
    {

        vector<string> Substrings;

        string sub;
        sub.push_back(s[0]);

        for (int i = 1; i < s.length(); i++)
        {
            if (sub[sub.length() - 1] == s[i])
            {
                sub.push_back(s[i]);
            }
            else
            {
                Substrings.push_back(sub);
                sub.clear();
                sub.push_back(s[i]);
            }
        }

        if (!sub.empty())
        {
            Substrings.push_back(sub);
        }

        int ANS = 0;

        for (int i = 0; i < Substrings.size(); i++)
        {
            if (Substrings[i].length() > ANS)
            {
                ANS = Substrings[i].length();
            }
        }

        return ANS;
    }
};