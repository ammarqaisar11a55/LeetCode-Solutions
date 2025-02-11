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