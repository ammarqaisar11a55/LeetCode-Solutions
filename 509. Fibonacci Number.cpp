class Solution
{
public:
    int fib(int n)
    {

        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        return fib(n - 1) + fib(n - 2);
    }
};

/*Top-Down + Memoization Dp:*/

class Solution
{
public:
    int Solve(int n, unordered_map<int, int> &dp)
    {
        if (n <= 1)
        {
            return n;
        }

        if (dp.find(n) != dp.end())
            return dp[n];

        dp[n] = Solve(n - 1, dp) + Solve(n - 2, dp);

        return dp[n];
    }

    int fib(int n)
    {
        unordered_map<int, int> dp;

        return Solve(n, dp);
    }
};

/*Bottom Up (Tabulation) Dp: */

class Solution
{
public:
    int fib(int n)
    {

        if (n <= 1)
            return n;

        vector<int> DP(n + 1);
        DP[0] = 0;
        DP[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            DP[i] = DP[i - 2] + DP[i - 1];
        }

        return DP[n];
    }
};