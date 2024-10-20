class Solution
{
public:
    int minOperations(string s)
    {

        int startwihtone = 0;
        int startwithzero = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] == '0')
                {
                    startwihtone++;
                }
                else if (s[i] == '1')
                {
                    startwithzero++;
                }
            }
            else if (i % 2 != 0)
            {
                if (s[i] == '1')
                {
                    startwihtone++;
                }
                else if (s[i] == '0')
                {
                    startwithzero++;
                }
            }
        }

        return min(startwihtone, startwithzero);
    }
};