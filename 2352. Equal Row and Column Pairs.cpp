class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {

        map<vector<int>, int> Mp;

        for (int i = 0; i < grid.size(); i++)
        {
            vector<int> Row;
            for (int j = 0; j < grid[i].size(); j++)
            {
                Row.push_back(grid[i][j]);
            }

            Mp[Row]++;
        }
        int ans = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            vector<int> Col;
            for (int j = 0; j < grid[i].size(); j++)
            {
                Col.push_back(grid[j][i]);
            }

            if (Mp.find(Col) != Mp.end())
                ans += Mp[Col];
        }

        return ans;
    }
};

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {

        unordered_map<string, int> Mp;

        for (int i = 0; i < grid.size(); i++)
        {
            string row;
            for (int j = 0; j < grid[i].size(); j++)
            {
                string digit = to_string(grid[i][j]);
                row += digit;
                row += ' ';
            }

            Mp[row]++;
        }
        int ans = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            string Col;
            for (int j = 0; j < grid[i].size(); j++)
            {
                string digit = to_string(grid[j][i]);
                Col += digit;
                Col += ' ';
            }

            if (Mp.find(Col) != Mp.end())
                ans += Mp[Col];
        }

        return ans;
    }
};