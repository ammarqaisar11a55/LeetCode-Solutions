class Solution
{
public:
    int minimumOperations(vector<vector<int>> &grid)
    {
        int operations = 0;

        for (int i = 1; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] < grid[i - 1][j])
                {
                    int Current_Required_Operations = grid[i - 1][j] - grid[i][j] + 1;
                    operations += Current_Required_Operations;
                    grid[i][j] += Current_Required_Operations;
                }
                else if (grid[i][j] == grid[i - 1][j])
                {
                    grid[i][j]++;
                    operations++;
                }
            }
        }

        return operations;
    }
};