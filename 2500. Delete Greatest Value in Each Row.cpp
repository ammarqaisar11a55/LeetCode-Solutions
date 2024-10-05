class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {

        vector<priority_queue<int, vector<int>, less<int>>> Heaps(grid.size());

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                Heaps[i].push(grid[i][j]);
            }
        }

        int Ans = 0;

        while (!Heaps[0].empty())
        {
            int Maxi = INT_MIN;
            for (int i = 0; i < grid.size(); i++)
            {
                Maxi = max(Maxi, Heaps[i].top());
                Heaps[i].pop();
            }

            Ans += Maxi;
        }

        return Ans;
    }
};