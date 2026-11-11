class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        unordered_map<int, unordered_set<int>> counts;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 1)
                    counts[i].insert(j);
            }
        }

        vector<int> res;

        for (int i = 0; i < matrix.size(); i++) {
            res.push_back(counts[i].size());
        }

        return res;
    }
};
