class Solution
{
public:
    void DFS(vector<vector<int>> &grid, int i, int j, int &MaxGold, int Current_Path_Gold)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return;

        Current_Path_Gold += grid[i][j];
        MaxGold = max(MaxGold, Current_Path_Gold);

        int Temp = grid[i][j];
        grid[i][j] = 0;

        DFS(grid, i, j - 1, MaxGold, Current_Path_Gold);
        DFS(grid, i, j + 1, MaxGold, Current_Path_Gold);
        DFS(grid, i - 1, j, MaxGold, Current_Path_Gold);
        DFS(grid, i + 1, j, MaxGold, Current_Path_Gold);

        grid[i][j] = Temp;
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {

        int MaxGold = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] != 0)
                {
                    DFS(grid, i, j, MaxGold, 0);
                }
            }
        }

        return MaxGold;
    }
};