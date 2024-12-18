class Solution
{
public:
    vector<vector<int>> Directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool dfs(vector<vector<char>> &grid, int i, int j, int Prev_i, int Prev_j, vector<vector<bool>> &Visited)
    {
        Visited[i][j] = true;

        for (vector<int> Direct : Directions)
        {
            int New_X = i + Direct[0];
            int New_Y = j + Direct[1];

            if (New_X >= 0 && New_Y >= 0 && New_X < grid.size() && New_Y < grid[0].size())
            {
                if (New_X == Prev_i && New_Y == Prev_j)
                    continue;

                if (grid[New_X][New_Y] == grid[i][j])
                {
                    if (Visited[New_X][New_Y])
                    {
                        return true;
                    }
                    else if (dfs(grid, New_X, New_Y, i, j, Visited))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>> &grid)
    {
        vector<vector<bool>> Visited(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (!Visited[i][j])
                {
                    if (dfs(grid, i, j, -1, -1, Visited))
                        return true;
                }
            }
        }

        return false;
    }
};