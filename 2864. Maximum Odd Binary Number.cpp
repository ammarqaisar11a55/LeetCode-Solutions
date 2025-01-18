class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int ones = 0, zeros = 0;

        for (char c : s)
        {
            if (c == '0')
            {
                zeros++;
            }
            else
                ones++;
        }

        string res;

        for (int i = 0; i < zeros; i++)
        {
            res.push_back('0');
        }

        res.push_back('1');
        ones--;

        reverse(res.begin(), res.end());

        for (int i = 0; i < ones; i++)
            res.push_back('1');

        reverse(res.begin(), res.end());

        return res;
    }
};