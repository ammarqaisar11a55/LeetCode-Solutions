class Solution {
public:
    void DFS(int i, int j, vector<vector<int>>& Island,
             unordered_set<string>& Found_Cells) {
        string coordinates = to_string(i) + "," + to_string(j);

        if (Found_Cells.find(coordinates) != Found_Cells.end()) {
            return;
        }

        Found_Cells.insert(coordinates);

        // Up

        if (i - 1 >= 0 && j < Island[i].size() &&
            Island[i][j] <= Island[i - 1][j]) {
            DFS(i - 1, j, Island, Found_Cells);
        }

        // Down

        if (i + 1 < Island.size() && j < Island[0].size() &&
            Island[i][j] <= Island[i + 1][j]) {
            DFS(i + 1, j, Island, Found_Cells);
        }

        // Left

        if (i < Island.size() && j - 1 >= 0 &&
            Island[i][j] <= Island[i][j - 1]) {
            DFS(i, j - 1, Island, Found_Cells);
        }

        // Right

        if (i < Island.size() && j + 1 < Island[i].size() &&
            Island[i][j] <= Island[i][j + 1]) {
            DFS(i, j + 1, Island, Found_Cells);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> Res;
        unordered_set<string> reached_from_pacific, reached_from_atlantic;

        // Iterating from Pacific i.e First_Row

        for (int i = 0; i < heights[0].size(); i++) {
            DFS(0, i, heights, reached_from_pacific);
        }

        // Iterating from Pacific i.e First_COl

        for (int i = 0; i < heights.size(); i++) {
            DFS(i, 0, heights, reached_from_pacific);
        }

        /**********************/

        // Iterating from Atlantic i.e Last_Row

        for (int i = 0; i < heights[0].size(); i++) {
            DFS(heights.size() - 1, i, heights, reached_from_atlantic);
        }

        // Iterating from Pacific i.e Last_COl

        for (int i = 0; i < heights.size(); i++) {
            DFS(i, heights[0].size() - 1, heights, reached_from_atlantic);
        }

        // Finding Intersection

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                string coordinates = to_string(i) + "," + to_string(j);

                if (reached_from_atlantic.find(coordinates) !=
                        reached_from_atlantic.end() &&
                    reached_from_pacific.find(coordinates) !=
                        reached_from_pacific.end()) {
                    Res.push_back({i, j});
                }
            }
        }

        return Res;
    }
};
