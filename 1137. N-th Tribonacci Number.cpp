class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        vector<int> Dp(n + 1);

        Dp[0] = 0, Dp[1] = 1, Dp[2] = 1;

        for (int i = 3; i <= n; i++)
        {
            Dp[i] = Dp[i - 1] + Dp[i - 2] + Dp[i - 3];
        }

        return Dp[n];
    }
};