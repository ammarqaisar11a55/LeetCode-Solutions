class Solution
{
public:
    void DFS(vector<vector<int>> &grid, int i, int j, int &Count_Sea_Cells, bool &Reached_Boundry)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return;

        if (i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1)
        {
            Reached_Boundry = true;
        }

        Count_Sea_Cells++;

        grid[i][j] = 0;

        DFS(grid, i, j - 1, Count_Sea_Cells, Reached_Boundry);
        DFS(grid, i, j + 1, Count_Sea_Cells, Reached_Boundry);
        DFS(grid, i - 1, j, Count_Sea_Cells, Reached_Boundry);
        DFS(grid, i + 1, j, Count_Sea_Cells, Reached_Boundry);
    }

    int numEnclaves(vector<vector<int>> &grid)
    {

        int Count = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    bool Reached_Land = false;
                    int Count_Cells = 0;

                    DFS(grid, i, j, Count_Cells, Reached_Land);

                    if (!Reached_Land)
                        Count += Count_Cells;
                }
            }
        }

        return Count;
    }
};