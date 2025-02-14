/*TLE:*/

class Solution
{
public:
    void DFS(vector<vector<int>> &matrix, int i, int j, int &Min_Path, int Current_Path)
    {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size())
            return;

        Current_Path += matrix[i][j];

        if (i == matrix.size() - 1)
        {
            Min_Path = min(Min_Path, Current_Path);
        }

        DFS(matrix, i + 1, j, Min_Path, Current_Path);
        DFS(matrix, i + 1, j - 1, Min_Path, Current_Path);
        DFS(matrix, i + 1, j + 1, Min_Path, Current_Path);
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {

        int Min_Path = INT_MAX;

        for (int i = 0; i < matrix[0].size(); i++)
        {
            DFS(matrix, 0, i, Min_Path, 0);
        }

        return Min_Path;
    }
};

/*Dp Approach: */

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        vector<vector<int>> DP(matrix.size(), vector<int>(matrix.size(), 0));
        int res = INT_MAX;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                if (i == 0)
                {
                    DP[i][j] = matrix[i][j];
                }
                else
                {
                    int Top_Element = DP[i - 1][j];
                    int Top_Left = j - 1 >= 0 ? DP[i - 1][j - 1] : INT_MAX;
                    int Top_Right = j + 1 < matrix.size() ? DP[i - 1][j + 1] : INT_MAX;
                    DP[i][j] = matrix[i][j] + min(Top_Element, min(Top_Left, Top_Right));
                }

                if (i == matrix.size() - 1)
                {
                    res = min(res, DP[i][j]);
                }
            }
        }

        return res;
    }
};