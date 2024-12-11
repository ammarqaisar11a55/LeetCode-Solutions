class Solution
{
public:
    bool DFS(vector<vector<char>> &board, int i, int j, int k, string &s)
    {
        if (k == s.length())
            return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != s[k])
            return false;

        char temp = board[i][j];
        board[i][j] = '*';

        bool Top = DFS(board, i - 1, j, k + 1, s);
        bool Down = DFS(board, i + 1, j, k + 1, s);
        bool Left = DFS(board, i, j - 1, k + 1, s);
        bool Right = DFS(board, i, j + 1, k + 1, s);

        board[i][j] = temp;

        return Top || Down || Left || Right;
    }

    bool exist(vector<vector<char>> &board, string word)
    {

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == word[0] && DFS(board, i, j, 0, word))
                    return true;
            }
        }

        return false;
    }
};