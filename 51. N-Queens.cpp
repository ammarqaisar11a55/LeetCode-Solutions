class Solution
{
public:
    void Solve(int Current_Row, int Queens, int N_RS_CLS, vector<string> Board, vector<vector<string>> &Res, unordered_set<int> &Used_Rows, unordered_set<int> &Used_Cols, unordered_set<int> &Used_Di, unordered_set<int> &Used_AntiDi)
    {
        if (Queens == 0)
        {
            Res.push_back(Board);
            return;
        }

        for (int i = Current_Row; i < N_RS_CLS; i++)
        {
            for (int j = 0; j < N_RS_CLS; j++)
            {
                if (Used_Rows.find(i) != Used_Rows.end())
                    continue;

                if (Used_Cols.find(j) != Used_Cols.end())
                    continue;

                if (Used_Di.find(i - j) != Used_Di.end())
                    continue;

                if (Used_AntiDi.find(i + j) != Used_AntiDi.end())
                    continue;

                Board[i][j] = 'Q';
                Used_Rows.insert(i);
                Used_Cols.insert(j);
                Used_Di.insert(i - j);
                Used_AntiDi.insert(i + j);

                Solve(i + 1, Queens - 1, N_RS_CLS, Board, Res, Used_Rows, Used_Cols, Used_Di, Used_AntiDi);

                Board[i][j] = '.';
                Used_Rows.erase(i);
                Used_Cols.erase(j);
                Used_Di.erase(i - j);
                Used_AntiDi.erase(i + j);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> Res;
        unordered_set<int> Used_Rows, Used_Cols, Used_Di, Used_AntiDi;
        vector<string> Board(n, string(n, '.'));
        Solve(0, n, n, Board, Res, Used_Rows, Used_Cols, Used_Di, Used_AntiDi);
        return Res;
    }
};