class Solution
{
public:
    int findPermutationDifference(string s, string t)
    {
        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < s.length(); j++)
            {
                if (s[i] == t[j])
                {
                    ans = ans + abs(i - j);
                }
            }
        }
        return ans;
    }
};