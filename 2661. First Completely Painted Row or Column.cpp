class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> matrix_elements_positions;

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                matrix_elements_positions[mat[i][j]] = {i, j};
            }
        }

        vector<int> rows(mat.size(), 0), cols(mat[0].size(), 0);

        int res = 0;

        for (int i = 0; i < arr.size(); i++) {
            int element = arr[i];

            pair<int, int> position = matrix_elements_positions[element];

            rows[position.first]++;
            cols[position.second]++;

            if (rows[position.first] == mat[0].size() ||
                cols[position.second] == mat.size()) {
                res = i;
                break;
            }
        }

        return res;
    }
};
