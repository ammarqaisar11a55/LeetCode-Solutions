class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        for (int i = y; i < y + k; i++) {
            int upper_row = x, lower_row = x + k - 1;

            while (lower_row > upper_row) {
                swap(grid[lower_row][i], grid[upper_row][i]);
                lower_row--, upper_row++;
            }
        }

        return grid;
    }
};
