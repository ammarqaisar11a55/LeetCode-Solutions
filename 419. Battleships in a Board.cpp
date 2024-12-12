class Solution
{
public:
    void DFS(vector<vector<char>> &board, int i, int j, vector<vector<int>> &Directions)
    {
        board[i][j] = 'S';

        for (auto D : Directions)
        {
            int New_X = D[0] + i;
            int New_Y = D[1] + j;

            if (New_X >= 0 && New_Y >= 0 && New_X < board.size() && New_Y < board[0].size() && board[New_X][New_Y] == 'X')
                DFS(board, New_X, New_Y, Directions);
        }
    }

    int countBattleships(vector<vector<char>> &board)
    {

        int Count = 0;
        vector<vector<int>> Directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 'X')
                {
                    DFS(board, i, j, Directions);
                    Count++;
                }
            }
        }

        return Count;
    }
};