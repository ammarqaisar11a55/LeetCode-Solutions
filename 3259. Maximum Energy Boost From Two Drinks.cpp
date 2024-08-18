class Solution
{
public:
    long long maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB)
    {
        int n = energyDrinkA.size();

        if (n == 0)
            return 0;

        vector<long long> dpA(n, 0), dpB(n, 0);

        dpA[0] = energyDrinkA[0];
        dpB[0] = energyDrinkB[0];

        // Fill DP arrays
        for (int i = 1; i < n; i++)
        {

            dpA[i] = energyDrinkA[i] + max(dpA[i - 1], (i > 1 ? dpB[i - 2] : 0));

            dpB[i] = energyDrinkB[i] + max(dpB[i - 1], (i > 1 ? dpA[i - 2] : 0));
        }

        return max(dpA[n - 1], dpB[n - 1]);
    }
};