class Solution
{
public:
    int maxDifference(string s)
    {
        int even = INT_MAX;
        int odd = INT_MIN;

        unordered_map<char, int> mp;

        for (char c : s)
        {
            mp[c]++;
        }

        for (auto x : mp)
        {
            if (x.second & 1)
            {
                odd = max(odd, x.second);
            }
            else
                even = min(even, x.second);
        }

        return odd - even;
    }
};