class Solution
{
public:
    void Solve(string &s, int &res, int index, int temp_count, unordered_map<char, int> &mp)
    {
        if (index >= s.length())
        {
            res = max(res, temp_count);
            return;
        }

        res = max(res, temp_count);

        if (mp[s[index]] - mp[s[index - 1]] == 1)
        {
            Solve(s, res, index + 1, temp_count + 1, mp);
        }
        else
            Solve(s, res, index + 1, 1, mp);
    }

    int longestContinuousSubstring(string s)
    {

        string alphabets = "abcdefghijklmnopqrstuvwxyz";
        unordered_map<char, int> mp;

        for (int i = 0; i < alphabets.size(); i++)
        {
            mp[alphabets[i]] = i;
        }

        int Longest_Length = 0;
        Solve(s, Longest_Length, 1, 1, mp);
        return Longest_Length;
    }
};