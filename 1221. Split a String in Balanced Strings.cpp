class Solution
{
public:
    int balancedStringSplit(string s)
    {

        int ans = 0;

        int l = 0;
        int r = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'L')
            {
                l++;
            }

            if (s[i] == 'R')
            {
                r++;
            }

            if (l == r)
            {
                ans++;
            }
        }
        return ans;
    }
};