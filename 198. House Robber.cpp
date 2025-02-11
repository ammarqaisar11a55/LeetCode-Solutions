/*Only Recusion(TLE):*/

class Solution
{
public:
    int Solve(vector<int> &nums, int i)
    {
        if (i >= nums.size())
        {
            return 0;
        }

        int steal = nums[i] + Solve(nums, i + 2);
        int skip = Solve(nums, i + 1);

        return max(steal, skip);
    }

    int rob(vector<int> &nums)
    {
        return Solve(nums, 0);
    }
};

/*Top-Down + Memoization: */

class Solution
{
public:
    unordered_map<int, int> dp;

    int Solve(vector<int> &nums, int i)
    {
        if (i >= nums.size())
        {
            return 0;
        }

        if (dp.find(i) != dp.end())
        {
            return dp[i];
        }

        int steal = nums[i] + Solve(nums, i + 2);
        int skip = Solve(nums, i + 1);

        dp[i] = max(steal, skip);

        return dp[i];
    }

    int rob(vector<int> &nums)
    {
        return Solve(nums, 0);
    }
};

/*Bottom-Up Tabulation Approach:*/

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }

        vector<int> Dp(n, 0);

        Dp[0] = nums[0];
        Dp[1] = max(Dp[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            Dp[i] = max(Dp[i - 1], Dp[i - 2] + nums[i]);
        }

        return Dp[n - 1];
    }
};

/*Constant Approach:*/

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }

        int BeforePrevious = nums[0];
        int Previous = max(nums[0], nums[1]);

        int res = Previous;

        for (int i = 2; i < n; i++)
        {
            res = max(Previous, BeforePrevious + nums[i]);

            BeforePrevious = Previous;
            Previous = res;
        }

        return res;
    }
};