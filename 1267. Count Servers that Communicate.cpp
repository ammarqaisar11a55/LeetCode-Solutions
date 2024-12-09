class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {

        vector<int> RowsCount(grid.size(), 0), ColsCount(grid[0].size(), 0);

        int Connected_Servers = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    RowsCount[i]++;
                    ColsCount[j]++;
                }
            }
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    if (ColsCount[j] > 1 || RowsCount[i] > 1)
                        Connected_Servers++;
                }
            }
        }

        return Connected_Servers;
    }
};