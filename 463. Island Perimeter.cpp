class Solution
{
public:
    int DFS(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return 1;

        if (grid[i][j] == -1)
            return 0;

        grid[i][j] = -1;

        int Perimeter = 0;

        Perimeter += DFS(grid, i, j + 1);
        Perimeter += DFS(grid, i, j - 1);
        Perimeter += DFS(grid, i - 1, j);
        Perimeter += DFS(grid, i + 1, j);

        return Perimeter;
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    return DFS(grid, i, j);
                }
            }
        }

        return 0;
    }
};