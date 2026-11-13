class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;

        for (int i = 0; i < m; i++) {
            string current;

            for (int j = 0; j < n; j++) {
                if (i == 0 || j == n - 1) {
                    current.push_back('.');
                } else {
                    current.push_back('#');
                }
            }
            res.push_back(current);
        }

        return res;
    }
};
