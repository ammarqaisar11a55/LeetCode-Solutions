class Solution
{
public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        int Rook_i = -1, Rook_j = -1;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 'R')
                {
                    Rook_i = i;
                    Rook_j = j;
                    break;
                }
            }
        }

        if (Rook_i == -1 || Rook_j == -1)
            return 0;

        int res = 0;

        // Left:
        for (int i = Rook_j; i >= 0; i--)
        {
            if (board[Rook_i][i] == 'p')
            {
                res += 1;
                break;
            }
            else if (board[Rook_i][i] == 'B')
                break;
        }

        // Right:
        for (int i = Rook_j; i < 8; i++)
        {
            if (board[Rook_i][i] == 'p')
            {
                res += 1;
                break;
            }
            else if (board[Rook_i][i] == 'B')
                break;
        }

        // Up:
        for (int i = Rook_i; i >= 0; i--)
        {
            if (board[i][Rook_j] == 'p')
            {
                res += 1;
                break;
            }
            else if (board[i][Rook_j] == 'B')
                break;
        }

        // Down:

        for (int i = Rook_i; i < 8; i++)
        {
            if (board[i][Rook_j] == 'p')
            {
                res += 1;
                break;
            }
            else if (board[i][Rook_j] == 'B')
                break;
        }

        return res;
    }
};