//Approach 1: DFS + DFS (MLE)


class Solution {
public:
    void DFS_To_Collect_Positions(vector<vector<int>>& Grid, int i, int j,
                                  unordered_set<string>& positions) {
        if (i < 0 || j < 0 || i >= Grid.size() || j >= Grid.size() ||
            Grid[i][j] == 0) {
            return;
        }

        Grid[i][j] = 0;
        string pos = to_string(i) + " " + to_string(j);
        positions.insert(pos);

        DFS_To_Collect_Positions(Grid, i + 1, j, positions);
        DFS_To_Collect_Positions(Grid, i - 1, j, positions);
        DFS_To_Collect_Positions(Grid, i, j + 1, positions);
        DFS_To_Collect_Positions(Grid, i, j - 1, positions);

        Grid[i][j] = 1;
    }

    void DFS_To_Calculate_Res(vector<vector<int>>& Grid, int i, int j,
                              unordered_set<string>& positions, int count_flips,
                              int& Res) {
        if (i < 0 || j < 0 || i >= Grid.size() || j >= Grid.size() ||
            Grid[i][j] == -1) {
            return;
        }

        string pos = to_string(i) + " " + to_string(j);

        if (positions.find(pos) != positions.end()) {
            Res = min(Res, count_flips);
            return;
        }

        int current_cell = Grid[i][j];
        Grid[i][j] = -1;

        if (current_cell == 0) {
            count_flips++;
        }

        DFS_To_Calculate_Res(Grid, i + 1, j, positions, count_flips, Res);
        DFS_To_Calculate_Res(Grid, i - 1, j, positions, count_flips, Res);
        DFS_To_Calculate_Res(Grid, i, j + 1, positions, count_flips, Res);
        DFS_To_Calculate_Res(Grid, i, j - 1, positions, count_flips, Res);

        if (current_cell == 0) {
            count_flips--;
        }

        Grid[i][j] = current_cell;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        unordered_set<string> One_Island_Positions;

        bool has_to_stop = false;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    DFS_To_Collect_Positions(grid, i, j, One_Island_Positions);
                    has_to_stop = true;
                    break;
                }
            }
            if (has_to_stop)
                break;
        }

        int res = INT_MAX;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    string pos = to_string(i) + " " + to_string(j);

                    if (One_Island_Positions.find(pos) ==
                        One_Island_Positions.end()) {
                        DFS_To_Calculate_Res(grid, i, j, One_Island_Positions,
                                             0, res);
                    }
                }
            }
        }

        return res;
    }
};

//Approach 2: DFS + BFS
