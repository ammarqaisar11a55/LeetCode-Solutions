class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {

        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> Mp;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                Mp[i - j].push(mat[i][j]);
            }
        }

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                mat[i][j] = Mp[i - j].top();
                Mp[i - j].pop();
            }
        }

        return mat;
    }
};