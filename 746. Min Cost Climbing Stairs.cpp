/*Top-Down + Memoization Appraoch:*/

class Solution
{
public:
    int Solve(vector<int> &Costs, int ith_stair, unordered_map<int, int> &Dp)
    {
        if (ith_stair >= Costs.size())
        {
            return 0;
        }

        if (Dp.find(ith_stair) != Dp.end())
        {
            return Dp[ith_stair];
        }

        int Jump1 = Costs[ith_stair] + Solve(Costs, ith_stair + 1, Dp);
        int Jump2 = Costs[ith_stair] + Solve(Costs, ith_stair + 2, Dp);

        Dp[ith_stair] = min(Jump1, Jump2);

        return Dp[ith_stair];
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        unordered_map<int, int> Dp;
        return min(Solve(cost, 0, Dp), Solve(cost, 1, Dp));
    }
};

/*Bottom Up Approach:*/

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        if (n == 2)
        {
            return min(cost[0], cost[1]);
        }

        vector<int> Dp(n);

        Dp[0] = cost[0];
        Dp[1] = cost[1];

        for (int i = 2; i < n; i++)
        {
            Dp[i] = min(Dp[i - 1] + cost[i], Dp[i - 2] + cost[i]);
        }

        return min(Dp[n - 1], Dp[n - 2]);
    }
};

/*Constant Space:*/

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        if (n == 2)
        {
            return min(cost[0], cost[1]);
        }

        int BeforePrevious = cost[0];
        int Previous = cost[1];

        for (int i = 2; i < n; i++)
        {
            int res = min(BeforePrevious + cost[i], Previous + cost[i]);

            BeforePrevious = Previous;
            Previous = res;
        }

        return min(Previous, BeforePrevious);
    }
};