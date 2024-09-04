class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {

        unordered_set<int> RowsMinimum, ColsMaximum;
        int cols = matrix[0].size();
        int rows = matrix.size();

        // Rows Traversal for Minimums:
        for (int i = 0; i < rows; i++)
        {
            int Mini = INT_MAX;
            for (int j = 0; j < cols; j++)
            {
                Mini = min(Mini, matrix[i][j]);
            }
            RowsMinimum.insert(Mini);
        }

        // Columns Traversal for Maximums:
        for (int i = 0; i < cols; i++)
        {
            int Maxi = INT_MIN;
            for (int j = 0; j < rows; j++)
            {
                Maxi = max(Maxi, matrix[j][i]);
            }
            ColsMaximum.insert(Maxi);
        }

        vector<int> Ans;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (ColsMaximum.find(matrix[i][j]) != ColsMaximum.end() && RowsMinimum.find(matrix[i][j]) != RowsMinimum.end())
                    Ans.push_back(matrix[i][j]);
            }
        }

        return Ans;
    }
};