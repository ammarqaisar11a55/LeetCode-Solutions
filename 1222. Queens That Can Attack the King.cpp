class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens,
                                            vector<int>& king) {
        vector<vector<int>> Res;

        vector<vector<int>> Board(8, vector<int>(8, 0));

        for (vector<int> current_queen : queens) {
            Board[current_queen[0]][current_queen[1]] = 1;
        }

        int sRow = king[0], sCol = king[1];

        // Left:
        for (int i = sCol - 1; i >= 0; i--) {
            if (Board[sRow][i] == 1) {
                Res.push_back({sRow, i});
                break;
            }
        }

        // Right:
        for (int i = sCol + 1; i < 8; i++) {
            if (Board[sRow][i] == 1) {
                Res.push_back({sRow, i});
                break;
            }
        }

        // Up:
        for (int i = sRow - 1; i >= 0; i--) {
            if (Board[i][sCol] == 1) {
                Res.push_back({i, sCol});
                break;
            }
        }

        // Down:
        for (int i = sRow + 1; i < 8; i++) {
            if (Board[i][sCol] == 1) {
                Res.push_back({i, sCol});
                break;
            }
        }

        int i = sRow + 1, j = sCol + 1;

        // Right_Dia
        while (i < 8 && j < 8) {
            if (Board[i][j] == 1) {
                Res.push_back({i, j});
                break;
            }

            i++, j++;
        }

        // Left_Dia

        i = sRow + 1, j = sCol - 1;

        while (i < 8 && j >= 0) {
            if (Board[i][j] == 1) {
                Res.push_back({i, j});
                break;
            }

            i++, j--;
        }

        // Left_anti_dia
        i = sRow - 1, j = sCol - 1;

        while (i >= 0 && j >= 0) {
            if (Board[i][j] == 1) {
                Res.push_back({i, j});
                break;
            }

            i--, j--;
        }

        // Right_anti_dia
        i = sRow - 1, j = sCol + 1;

        while (i >= 0 && j < 8) {
            if (Board[i][j] == 1) {
                Res.push_back({i, j});
                break;
            }

            i--, j++;
        }

        return Res;
    }
};
