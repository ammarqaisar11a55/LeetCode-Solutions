class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {

        unordered_map<int, int> RowsOnes, ColsOnes;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    RowsOnes[i]++;
                    ColsOnes[j]++;
                }
            }
        }

        int Ans = 0;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1 && RowsOnes[i] == 1 && ColsOnes[j] == 1)
                {
                    Ans++;
                }
            }
        }

        return Ans;
    }
};