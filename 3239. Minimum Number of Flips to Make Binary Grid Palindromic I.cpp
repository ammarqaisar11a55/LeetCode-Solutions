class Solution
{
public:
    int minFlips(vector<vector<int>> &grid)
    {
        int Cl_Flips = 0;
        int Ro_Flips = 0;

        int m = grid.size();
        int n = grid[0].size();

        // Checking Rows:

        // cout<<"Row CHECK: "<<endl;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size() / 2; j++)
            {
                if (grid[i][j] != grid[i][n - j - 1])
                {
                    // cout << "[" << i << "," << j << "] == " << "[" << i << "," << grid[i].size() - j - 1 << "]" << endl;
                    Ro_Flips++;
                }
            }
        }

        // Checking Cols:

        // cout<<"COL CHECK: "<<endl;

        for (int i = 0; i < grid.size() / 2; i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] != grid[m - i - 1][j])
                {
                    // cout << "[" << i << "," << j << "] == " << "[" << grid.size() - i - 1 << "," << j << "]" << endl;
                    Cl_Flips++;
                }
            }
        }

        return min(Cl_Flips, Ro_Flips);
    }
};