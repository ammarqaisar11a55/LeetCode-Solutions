class Solution
{
public:
    int countAsterisks(string s)
    {

        int bars = 0;
        int count = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '|' && bars == 0)
            {
                bars++;
                continue;
            }

            if (s[i] == '*' && bars == 0)
            {
                count++;
                continue;
            }

            if (s[i] == '|' && bars == 1)
            {
                bars--;
                continue;
            }
        }

        return count;
    }
};