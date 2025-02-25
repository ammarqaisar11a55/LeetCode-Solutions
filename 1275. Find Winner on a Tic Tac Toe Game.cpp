class Solution
{
public:
    bool Check_for_winner(vector<vector<char>> &Board)
    {
        bool Row1 = Board[0][0] != '*' && Board[0][0] == Board[0][1] && Board[0][1] == Board[0][2];
        bool Row2 = Board[1][0] != '*' && Board[1][0] == Board[1][1] && Board[1][1] == Board[1][2];
        bool Row3 = Board[2][0] != '*' && Board[2][0] == Board[2][1] && Board[2][1] == Board[2][2];

        bool Col1 = Board[0][0] != '*' && Board[0][0] == Board[1][0] && Board[1][0] == Board[2][0];
        bool Col2 = Board[0][1] != '*' && Board[0][1] == Board[1][1] && Board[1][1] == Board[2][1];
        bool Col3 = Board[0][2] != '*' && Board[0][2] == Board[1][2] && Board[1][2] == Board[2][2];

        bool di = Board[0][0] != '*' && Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2];

        bool antidi = Board[0][2] != '*' && Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0];

        return antidi || di || Col1 || Col2 || Col3 || Row1 || Row2 || Row3;
    }

    string tictactoe(vector<vector<int>> &moves)
    {
        vector<vector<char>> Board(3, vector<char>(3, '*'));

        for (int i = 0; i < moves.size(); i++)
        {
            vector<int> Rows_Col = moves[i];
            int Row = Rows_Col[0];
            int Col = Rows_Col[1];

            if (i & 1)
            {
                Board[Row][Col] = 'O';
            }
            else
            {
                Board[Row][Col] = 'X';
            }

            if (i >= 4 && Check_for_winner(Board))
            {
                return i & 1 ? "B" : "A";
            }
        }

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};