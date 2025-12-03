class Solution {
public:
    void DFS(int i, int j, int& check, vector<vector<int>>& Grid1,
             vector<vector<int>>& Grid2) {
        if (i < 0 || j < 0 || i >= Grid1.size() || j >= Grid1[0].size() ||
            Grid2[i][j] == 0) {
            return;
        }

        if (Grid1[i][j] == 0) {
            check = -1;
        }
        Grid2[i][j] = 0;

        DFS(i - 1, j, check, Grid1, Grid2);
        DFS(i + 1, j, check, Grid1, Grid2);
        DFS(i, j + 1, check, Grid1, Grid2);
        DFS(i, j - 1, check, Grid1, Grid2);
    }

    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {

        int res = 0;
        int check = 0;

        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[i].size(); j++) {
                if (grid2[i][j] == 1 && grid1[i][j] == 1) {
                    cout << "Explored Paths: " << endl;
                    DFS(i, j, check, grid1, grid2);
                    if (check == 0) {
                        res++;
                    }

                    else
                        check = 0;
                }
            }
        }

        return res;
    }
};
