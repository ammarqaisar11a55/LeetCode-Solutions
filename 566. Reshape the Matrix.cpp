class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {

        if (r * c != mat.size() * mat[0].size())
            return mat;

        vector<vector<int>> NG(r, vector<int>(c));

        for (int i = 0; i < r * c; i++)
        {
            NG[i / c][i % c] = mat[i / mat[0].size()][i % mat[0].size()];
        }

        return NG;
    }
};