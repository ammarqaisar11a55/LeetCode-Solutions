class Solution
{
public:
    int getMax(vector<vector<int>> &grid, int x, int y)
    {
        int Maxi = INT_MIN;

        for (int i = x; i < x + 3; i++)
        {
            for (int j = y; j < y + 3; j++)
            {
                Maxi = max(Maxi, grid[i][j]);
            }
        }
        return Maxi;
    }

    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {

        int n = grid.size();

        vector<vector<int>> Ans(n - 2, vector<int>(n - 2));

        for (int i = 0; i < Ans.size(); i++)
        {
            for (int j = 0; j < Ans[i].size(); j++)
            {
                Ans[i][j] = getMax(grid, i, j);
            }
        }

        return Ans;
    }
};