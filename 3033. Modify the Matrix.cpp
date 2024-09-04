class Solution
{
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
    {

        unordered_map<int, int> Mp;

        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < cols; i++)
        {
            int maxi = INT_MIN;
            for (int j = 0; j < rows; j++)
            {
                maxi = max(maxi, matrix[j][i]);
            }
            Mp[i] = maxi;
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = Mp[j];
                }
            }
        }

        return matrix;
    }
};