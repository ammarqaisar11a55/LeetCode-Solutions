class Solution
{
public:
    string findValidPair(string s)
    {

        unordered_map<char, int> mp;

        for (char c : s)
            mp[c]++;

        string res;

        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] != s[i + 1])
            {
                if (mp[s[i]] == s[i] - '0' && mp[s[i + 1]] == s[i + 1] - '0')
                {
                    res += s[i];
                    res += s[i + 1];

                    return res;
                }
            }
        }

        return res;
    }
};