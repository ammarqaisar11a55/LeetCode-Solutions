class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        vector<vector<int>> Res(rowSum.size(), vector<int>(colSum.size(), 0));

        for (int i = 0; i < Res.size(); i++)
        {
            for (int j = 0; j < Res[i].size(); j++)
            {
                Res[i][j] = min(colSum[j], rowSum[i]);
                colSum[j] -= Res[i][j];
                rowSum[i] -= Res[i][j];
            }
        }

        return Res;
    }
};