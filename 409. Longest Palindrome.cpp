class Solution
{
public:
    int longestPalindrome(string s)
    {

        if (s.length() == 1)
        {
            return 1;
        }

        int res = 0;
        unordered_map<char, int> Mp;

        for (char c : s)
            Mp[c]++;

        bool odd_freq_found = false;

        for (auto x : Mp)
        {
            if (x.second % 2 == 0)
            {
                res += x.second;
            }
            else
            {
                res += x.second - 1;
                odd_freq_found = true;
            }
        }

        return odd_freq_found == true ? res + 1 : res;
    }
};