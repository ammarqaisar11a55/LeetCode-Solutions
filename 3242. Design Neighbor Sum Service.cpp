class NeighborSum
{
public:
    unordered_map<int, pair<int, int>> Mp;
    int rs;
    int cols;
    vector<vector<int>> G;

    NeighborSum(vector<vector<int>> &grid)
    {

        rs = grid.size();
        cols = grid[0].size();

        G = grid;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int k = 0; k < grid[i].size(); k++)
            {
                Mp[grid[i][k]] = {i, k};
            }
        }
    }

    int adjacentSum(int value)
    {

        if (Mp.find(value) == Mp.end())
            return 0;

        int sum = 0;

        int x = Mp[value].first;
        int y = Mp[value].second;

        // left element:

        if (y - 1 >= 0)
            sum += G[x][y - 1];

        // right element:
        if (y + 1 < cols)
            sum += G[x][y + 1];

        // top element:
        if (x - 1 >= 0)
            sum += G[x - 1][y];

        // down element:
        if (x + 1 < rs)
            sum += G[x + 1][y];

        return sum;
    }

    int diagonalSum(int value)
    {

        int sum = 0;

        if (Mp.find(value) == Mp.end())
            return 0;

        int x = Mp[value].first;
        int y = Mp[value].second;

        // top left diagonal
        if (y - 1 >= 0 && x - 1 >= 0)
            sum += G[x - 1][y - 1];

        // top right diagonal
        if (x - 1 >= 0 && y + 1 < cols)
            sum += G[x - 1][y + 1];

        // bottom left diagonal
        if (x + 1 < rs && y - 1 >= 0)
            sum += G[x + 1][y - 1];

        // bottom right diagonal
        if (x + 1 < rs && y + 1 < cols)
            sum += G[x + 1][y + 1];

        return sum;
    }
};