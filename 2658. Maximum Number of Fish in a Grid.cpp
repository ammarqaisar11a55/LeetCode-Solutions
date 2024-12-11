class Solution
{
public:
    int DFS(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return 0;

        int Total_Fishs = grid[i][j];
        grid[i][j] = 0;

        Total_Fishs += DFS(grid, i, j + 1);
        Total_Fishs += DFS(grid, i, j - 1);
        Total_Fishs += DFS(grid, i + 1, j);
        Total_Fishs += DFS(grid, i - 1, j);

        return Total_Fishs;
    }

    int findMaxFish(vector<vector<int>> &grid)
    {

        int MaxFish = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] > 0)
                {
                    MaxFish = max(MaxFish, DFS(grid, i, j));
                }
            }
        }

        return MaxFish;
    }
};