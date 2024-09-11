class Solution
{
public:
    bool checkValid(vector<vector<int>> &matrix)
    {

        for (int i = 0; i < matrix.size(); i++)
        {
            unordered_set<int> Temp;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (Temp.find(matrix[i][j]) != Temp.end())
                {
                    return false;
                }
                else
                    Temp.insert(matrix[i][j]);
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            unordered_set<int> Temp;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (Temp.find(matrix[j][i]) != Temp.end())
                {
                    return false;
                }
                else
                    Temp.insert(matrix[j][i]);
            }
        }

        return true;
    }
};