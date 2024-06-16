class Solution
{
public:
    int minimumChairs(string s)
    {
        int ans = 0;
        int chairs = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'E')
            {
                chairs++;
            }
            else
                chairs--;

            ans = max(ans, chairs);
        }
        return ans;
    }
};