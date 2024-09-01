class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {

        vector<vector<int>> TwoD(m, vector<int>(n));

        if (m * n != original.size())
        {
            return {};
        }

        int k = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                TwoD[i][j] = original[k];
                k++;
            }
        }

        return TwoD;
    }
};