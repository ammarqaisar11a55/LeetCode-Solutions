class Solution
{
public:
    int oddCells(int m, int n, vector<vector<int>> &indices)
    {

        vector<vector<int>> Grid(m, vector<int>(n, 0));

        for (int i = 0; i < indices.size(); i++)
        {
            // For Rows:
            for (int j = 0; j < n; j++)
            {
                Grid[indices[i][0]][j]++;
            }

            // For Cols:
            for (int k = 0; k < m; k++)
            {
                Grid[k][indices[i][1]]++;
            }
        }

        int Count = 0;

        for (int i = 0; i < Grid.size(); i++)
        {
            for (int j = 0; j < Grid[i].size(); j++)
            {
                if (Grid[i][j] & 1)
                    Count++;
            }
        }

        return Count;
    }
};