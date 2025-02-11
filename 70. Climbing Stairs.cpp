/*Top-Down + Memoization*/

class Solution
{
public:
    int Solve(int n, unordered_map<int, int> &dp)
    {
        if (n < 0)
        {
            return 0;
        }

        if (n == 0)
        {
            return 1;
        }

        if (dp.find(n) != dp.end())
        {
            return dp[n];
        }

        dp[n] = Solve(n - 1, dp) + Solve(n - 2, dp);

        return dp[n];
    }

    int climbStairs(int n)
    {
        unordered_map<int, int> Dp;
        return Solve(n, Dp);
    }
};

/*Bottom Up - Tabulation:*/

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 3)
        {
            return n;
        }

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 2] + dp[i - 1];
        }

        return dp[n];
    }
};