class Solution
{
public:
    bool DFS(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;

        if (grid[i][j] == 1 || grid[i][j] == -1)
            return true;

        grid[i][j] = -1;

        int Water_On_Left = DFS(grid, i, j - 1);
        int Water_On_Right = DFS(grid, i, j + 1);
        int Water_On_Top = DFS(grid, i - 1, j);
        int Water_On_Bottom = DFS(grid, i + 1, j);

        return Water_On_Bottom && Water_On_Top && Water_On_Left && Water_On_Right;
    }

    int closedIsland(vector<vector<int>> &grid)
    {

        int Count_Closed_Islands = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 0 && i != 0 && j != 0 && i != grid.size() - 1 && j != grid[i].size() - 1)
                {

                    if (DFS(grid, i, j))
                    {
                        Count_Closed_Islands++;
                    }
                }
            }
        }

        return Count_Closed_Islands;
    }
};