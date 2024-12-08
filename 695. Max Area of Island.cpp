class Solution
{
public:
    void DFS(vector<vector<int>> &grid, int i, int j, int &blocks)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == 0)
            return;

        grid[i][j] = 0;

        blocks++;

        DFS(grid, i - 1, j, blocks);
        DFS(grid, i + 1, j, blocks);
        DFS(grid, i, j - 1, blocks);
        DFS(grid, i, j + 1, blocks);
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {

        int Max_Area = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int Current_Island_Area = 0;
                    DFS(grid, i, j, Current_Island_Area);
                    Max_Area = max(Max_Area, Current_Island_Area);
                }
            }
        }

        return Max_Area;
    }
};