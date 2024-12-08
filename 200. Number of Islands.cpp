class Solution
{
public:
    void DFS(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        // Top
        DFS(grid, i - 1, j);
        // Bottom
        DFS(grid, i + 1, j);

        // Left
        DFS(grid, i, j - 1);

        // Right
        DFS(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {

        int Total_islands = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    DFS(grid, i, j);
                    Total_islands++;
                }
            }
        }

        return Total_islands;
    }
};