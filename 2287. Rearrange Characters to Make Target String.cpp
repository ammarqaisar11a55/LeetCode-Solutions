class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {

        unordered_map<char, int> s_map, t_map;

        for (char c : s)
            s_map[c]++;

        for (char c : target)
            t_map[c]++;

        int ans = INT_MAX;

        for (char c : target)
        {
            ans = min(ans, s_map[c] / t_map[c]);
        }

        return ans;
    }
};