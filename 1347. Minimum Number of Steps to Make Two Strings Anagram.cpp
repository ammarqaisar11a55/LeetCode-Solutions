class Solution
{
public:
    int minSteps(string s, string t)
    {
        vector<int> Freq(26, 0);

        for (char c : s)
            Freq[c - 'a']++;

        for (char c : t)
            Freq[c - 'a']--;

        int res = 0;

        for (int i = 0; i < 26; i++)
        {
            res += abs(Freq[i]);
        }

        return res / 2;
    }
};