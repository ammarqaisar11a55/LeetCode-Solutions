class Solution
{
public:
    int minBitFlips(int start, int goal)
    {

        int ans = 0;

        while (start > 0 || goal > 0)
        {
            if ((start & 1) != (goal & 1))
                ans++;

            start >>= 1;
            goal >>= 1;
        }

        return ans;
    }
};

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {

        return __builtin_popcount(start ^ goal);
    }
};