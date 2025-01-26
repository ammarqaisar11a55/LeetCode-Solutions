class Solution
{
public:
    int titleToNumber(string columnTitle)
    {

        unsigned long long int res = 0;

        for (int i = 0; i < columnTitle.length(); i++)
        {
            res = res * 26 + columnTitle[i] - 'A' + 1;
        }

        return res;
    }
};