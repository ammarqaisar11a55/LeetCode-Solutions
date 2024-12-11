/*Approach #1 : DFS (Time Limit Exceed)*/

class Solution
{
public:
    void DFS(vector<vector<int>> &mat, vector<vector<int>> &Ans, int i, int j, int current_dis)
    {
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || current_dis >= Ans[i][j])
            return;

        Ans[i][j] = current_dis;

        DFS(mat, Ans, i, j + 1, current_dis + 1);
        DFS(mat, Ans, i, j - 1, current_dis + 1);
        DFS(mat, Ans, i + 1, j, current_dis + 1);
        DFS(mat, Ans, i - 1, j, current_dis + 1);
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {

        vector<vector<int>> Ans(mat.size(), vector<int>(mat[0].size(), INT_MAX));

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    DFS(mat, Ans, i, j, 0);
                }
            }
        }

        return Ans;
    }
};

/*Approach #2 : BFS*/

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {

        vector<vector<int>> Ans(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        queue<pair<int, int>> Coordinates;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    Ans[i][j] = 0;
                    Coordinates.push({i, j});
                }
            }
        }

        vector<vector<int>> Directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!Coordinates.empty())
        {
            int X = Coordinates.front().first;
            int Y = Coordinates.front().second;
            Coordinates.pop();

            for (vector<int> XY : Directions)
            {
                int NEW_X = X + XY[0];
                int NEW_Y = Y + XY[1];

                if (NEW_X >= 0 && NEW_Y >= 0 && NEW_X < mat.size() && NEW_Y < mat[0].size())
                {
                    if (Ans[NEW_X][NEW_Y] > Ans[X][Y] + 1)
                    {
                        Ans[NEW_X][NEW_Y] = Ans[X][Y] + 1;
                        Coordinates.push({NEW_X, NEW_Y});
                    }
                }
            }
        }

        return Ans;
    }
};