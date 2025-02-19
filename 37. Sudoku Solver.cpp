class Solution
{
public:
    bool Solve(int index, vector<pair<int, int>> &Empty_Cells_Positions, int empty_cells, vector<vector<char>> &board, unordered_map<int, unordered_set<int>> &Rows_elements, unordered_map<int, unordered_set<int>> &Cols_elements, unordered_map<int, unordered_set<int>> &Boxes_elements)
    {
        if (empty_cells == 0)
        {
            return true;
        }

        int i = Empty_Cells_Positions[index].first;
        int j = Empty_Cells_Positions[index].second;

        for (int digits = 1; digits <= 9; digits++)
        {
            if (Rows_elements[i].find(digits) == Rows_elements[i].end())
            {
                if (Cols_elements[j].find(digits) == Cols_elements[j].end())
                {
                    int box_position = ((i / 3) * 3) + (j / 3);

                    if (Boxes_elements[box_position].find(digits) == Boxes_elements[box_position].end())
                    {
                        Rows_elements[i].insert(digits);
                        Cols_elements[j].insert(digits);
                        Boxes_elements[box_position].insert(digits);
                        board[i][j] = '0' + digits;

                        if (Solve(index + 1, Empty_Cells_Positions, empty_cells - 1, board, Rows_elements, Cols_elements, Boxes_elements))
                        {
                            return true;
                        }

                        board[i][j] = '.';
                        Rows_elements[i].erase(digits);
                        Cols_elements[j].erase(digits);
                        Boxes_elements[box_position].erase(digits);
                    }
                }
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        int empty_cells = 0;
        unordered_map<int, unordered_set<int>> Rows_Elements, Cols_Elements, Boxes_element;
        vector<pair<int, int>> Empty_Cells_Positions;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    Empty_Cells_Positions.push_back({i, j});
                    empty_cells++;
                }
                else
                {
                    Rows_Elements[i].insert(board[i][j] - '0');
                    Cols_Elements[j].insert(board[i][j] - '0');
                    int box_position = ((i / 3) * 3) + (j / 3);
                    Boxes_element[box_position].insert(board[i][j] - '0');
                }
            }
        }

        Solve(0, Empty_Cells_Positions, empty_cells, board, Rows_Elements, Cols_Elements, Boxes_element);
    }
};  