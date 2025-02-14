/*Top-Down + Memoization Approach:*/

class Solution
{
public:
    int Solve(int i, vector<int> &Nums, unordered_map<int, int> &dp, int LAST_HOUSE)
    {
        if (i > LAST_HOUSE)
        {
            return 0;
        }

        if (dp.find(i) != dp.end())
        {
            return dp[i];
        }

        int use = Nums[i] + Solve(i + 2, Nums, dp, LAST_HOUSE);
        int SKip = Solve(i + 1, Nums, dp, LAST_HOUSE);

        dp[i] = max(use, SKip);

        return dp[i];
    }

    int rob(vector<int> &nums)
    {
        unordered_map<int, int> Dp;

        if (nums.size() == 1)
            return nums[0];

        int try1 = Solve(0, nums, Dp, nums.size() - 2);
        Dp.clear();
        int try2 = Solve(1, nums, Dp, nums.size() - 1);
        return max(try1, try2);
    }
};