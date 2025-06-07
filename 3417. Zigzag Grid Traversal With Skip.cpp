class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> Res;
        int Row = 0, Col = 0;
        bool last_visited_cell_is_included = false;

        while (Row < grid.size()) {
            // Traverse From Left to Right
            Col = 0;
            while (Col < grid[Row].size()) {
                if (last_visited_cell_is_included) {
                    Col++;
                    last_visited_cell_is_included = false;
                    continue;
                }

                last_visited_cell_is_included = true;
                Res.push_back(grid[Row][Col++]);
            }
            Row++;

            if (Row >= grid.size())
                break;

            // Traverse From Right to Left
            Col = grid[Row].size() - 1;

            while (Col >= 0) {
                if (last_visited_cell_is_included) {
                    Col--;
                    last_visited_cell_is_included = false;
                    continue;
                }

                last_visited_cell_is_included = true;
                Res.push_back(grid[Row][Col--]);
            }

            Row++;
        }

        return Res;
    }
};
