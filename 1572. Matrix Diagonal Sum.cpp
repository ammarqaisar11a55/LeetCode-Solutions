class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {

        int primary = 0;
        int secondary = 0;

        for (int i = 0; i < mat.size(); i++)
        {
            primary = primary + mat[i][i];
            secondary = secondary + mat[i][mat[i].size() - i - 1];
        }

        int ans = primary + secondary;

        if (mat.size() % 2 != 0)
        {
            ans = ans - mat[mat.size() / 2][mat.size() / 2];
        }

        return ans;
    }
};