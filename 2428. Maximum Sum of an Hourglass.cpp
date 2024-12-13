class Solution
{
public:
    int maxSum(vector<vector<int>> &grid)
    {

        int MaxSum = 0;

        for (int i = 0; i < grid.size() - 2; i++)
        {
            for (int j = 0; j < grid[i].size() - 2; j++)
            {
                int Current_Hour_Glass_Sum = 0;
                Current_Hour_Glass_Sum += grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                Current_Hour_Glass_Sum += grid[i + 1][j + 1];
                Current_Hour_Glass_Sum += grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
                MaxSum = max(MaxSum, Current_Hour_Glass_Sum);
            }
        }
        return MaxSum;
    }
};