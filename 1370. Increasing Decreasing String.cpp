class Solution
{
public:
    string sortString(string s)
    {

        vector<int> Counts(26, 0);

        for (char c : s)
            Counts[c - 'a']++;

        string ans;

        while (ans.length() < s.length())
        {
            for (char i = 'a'; i <= 'z'; i++)
            {
                if (Counts[i - 'a'] > 0)
                {
                    ans.push_back(i);
                    Counts[i - 'a']--;
                }
            }

            for (char i = 'z'; i >= 'a'; i--)
            {
                if (Counts[i - 'a'] > 0)
                {
                    ans.push_back(i);
                    Counts[i - 'a']--;
                }
            }
        }

        return ans;
    }
};