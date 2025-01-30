class Solution
{
public:
    void DFS(vector<vector<int>> &grid, int i, int j, int EmptyCells, int &Res)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
            return;

        if (grid[i][j] == 2)
        {
            Res += EmptyCells == -1 ? 1 : 0;
            return;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;

        DFS(grid, i + 1, j, EmptyCells - 1, Res);
        DFS(grid, i - 1, j, EmptyCells - 1, Res);
        DFS(grid, i, j - 1, EmptyCells - 1, Res);
        DFS(grid, i, j + 1, EmptyCells - 1, Res);

        grid[i][j] = temp;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int Res = 0;
        int X, Y;
        int Empty_Cells = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    X = i;
                    Y = j;
                }

                if (grid[i][j] == 0)
                {
                    Empty_Cells++;
                }
            }
        }

        DFS(grid, X, Y, Empty_Cells, Res);

        return Res;
    }
};