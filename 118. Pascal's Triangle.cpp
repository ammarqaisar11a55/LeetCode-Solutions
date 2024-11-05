class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> Ans(numRows);

        for (int i = 0; i < numRows; i++)
        {
            Ans[i].resize(i + 1);
            Ans[i][0] = 1;
            Ans[i][i] = 1;

            for (int j = 1; j < i; j++)
            {
                Ans[i][j] = Ans[i - 1][j - 1] + Ans[i - 1][j];
            }
        }

        return Ans;
    }
};