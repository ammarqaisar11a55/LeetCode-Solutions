class Solution
{
public:
    int Calculateleft(vector<vector<int>> &grid, int i, int j)
    {
        unordered_set<int> st;

        while (i >= 0 && j >= 0)
        {
            st.insert(grid[i][j]);
            i--;
            j--;
        }

        return int(st.size());
    }

    int CalculateRight(vector<vector<int>> &grid, int i, int j)
    {
        unordered_set<int> st;

        while (i < grid.size() && j < grid[0].size())
        {
            st.insert(grid[i][j]);
            i++;
            j++;
        }

        return int(st.size());
    }

    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid)
    {

        vector<vector<int>> Res(grid.size(), vector<int>(grid[0].size(), 0));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                Res[i][j] = abs(Calculateleft(grid, i - 1, j - 1) - CalculateRight(grid, i + 1, j + 1));
            }
        }

        return Res;
    }
};