class Solution
{
public:
    int matrixSum(vector<vector<int>> &nums)
    {

        vector<priority_queue<int, vector<int>, less<int>>> Heaps(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                Heaps[i].push(nums[i][j]);
            }
        }

        int Ans = 0;

        while (!Heaps[0].empty())
        {
            int Maxi = INT_MIN;
            for (int i = 0; i < nums.size(); i++)
            {
                Maxi = max(Maxi, Heaps[i].top());
                Heaps[i].pop();
            }

            Ans += Maxi;
        }

        return Ans;
    }
};