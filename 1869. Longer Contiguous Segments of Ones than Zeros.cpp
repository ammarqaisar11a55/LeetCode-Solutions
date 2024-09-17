class Solution
{
public:
    bool checkZeroOnes(string s)
    {

        int longestOne = INT_MIN;
        int longestZero = INT_MIN;

        int count = 0;

        // Count for One:
        for (char x : s)
        {
            if (x == '1')
            {
                count++;
            }
            else
            {
                count = 0;
            }
            longestOne = max(longestOne, count);
        }

        count = 0;
        // Count for Zeros:
        for (char x : s)
        {
            if (x == '0')
            {
                count++;
            }
            else
            {
                count = 0;
            }
            longestZero = max(longestZero, count);
        }

        return longestOne > longestZero ? true : false;
    }
};

class Solution
{
public:
    bool checkZeroOnes(string s)
    {

        int longestOne = 0;
        int longestZero = 0;

        int countones = 0;
        int countzeroes = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                countzeroes++;
                countones = 0;
            }

            if (s[i] == '1')
            {
                countones++;
                countzeroes = 0;
            }

            longestOne = max(longestOne, countones);
            longestZero = max(longestZero, countzeroes);
        }

        return longestOne > longestZero ? true : false;
    }
};