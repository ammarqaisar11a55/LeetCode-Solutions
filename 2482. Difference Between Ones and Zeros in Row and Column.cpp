class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {

        unordered_map<int, int> RowsOnes, ColsOnes, RowsZeros, ColsZeros;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    RowsOnes[i]++;
                    ColsOnes[j]++;
                }
                else
                {
                    RowsZeros[i]++;
                    ColsZeros[j]++;
                }
            }
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                grid[i][j] = RowsOnes[i] + ColsOnes[j] - RowsZeros[i] - ColsZeros[j];
            }
        }

        return grid;
    }
};