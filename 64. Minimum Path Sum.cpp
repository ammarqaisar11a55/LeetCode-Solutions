class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> Dp(grid.size(), vector<int>(grid[0].size(), 0));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (i == 0 && j == 0)
                {
                    Dp[i][j] = grid[i][j];
                }
                else
                {
                    int Top_Element = i > 0 ? Dp[i - 1][j] : INT_MAX;
                    int Left_Element = j > 0 ? Dp[i][j - 1] : INT_MAX;

                    Dp[i][j] = grid[i][j] + min(Top_Element, Left_Element);
                }
            }
        }

        return Dp[Dp.size() - 1][Dp[0].size() - 1];
    }
};